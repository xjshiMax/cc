/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <iostream>
#include <string>

#include "log_device.h"
#include "file_util.h"
#include "string_util.h"
#include "time_util.h"
#include "log_device_manager.h"
#include "guard.h"
#include "thread_util.h"

namespace bgcc {

    AbstractLogDevice::~AbstractLogDevice() {
    }

    AbstractLogDevice::AbstractLogDevice(
            const char* name,
            int32_t loglevel,
            int32_t split_policy,
            off_t max_size,
            int32_t max_record_interval,
            const char* log_format) :
        _loglevel(loglevel),
        _split_policy(split_policy),
        _max_size(max_size),
        _max_record_interval(max_record_interval) {
            if (_max_size <= 1024*1024) {
                _max_size = 1024*1024;
            }

            if (_max_record_interval <= 0) {
                _max_record_interval = 60;
            }
            strncpy(_name, name, MAX_DEVICE_NAME_LEN);
            strncpy(_log_format, log_format, MAX_LOG_FORMAT_LEN);
        }

    const char* AbstractLogDevice::get_name() const {
        return _name;
    }

    int32_t AbstractLogDevice::get_loglevel() const {
        return _loglevel;
    }

    int32_t AbstractLogDevice::get_split_policy() const {
        return _split_policy;
    }

    off_t AbstractLogDevice::get_max_size() const {
        return _max_size;
    }

    int32_t AbstractLogDevice::get_max_record_interval() const {
        return _max_record_interval;
    }

    const char* AbstractLogDevice::get_log_format() const {
        return _log_format;
    }

    FileLogDevice::FileLogDevice(
            const char* file_path,
            const char* name,
            int32_t loglevel,
            int32_t split_policy,
            off_t max_size,
            int32_t max_record_interval,
            const char* log_format) :
        AbstractLogDevice(name, loglevel, split_policy, max_size, max_record_interval, log_format),
        _fp(NULL) {
            strncpy(_file_path, file_path, MAX_FILE_PATH_LEN);
        }

    FileLogDevice::~FileLogDevice() {
        close();
    }

    bool FileLogDevice::is_opened() const {
        return(NULL != _fp);
    }

    int32_t FileLogDevice::open(void* param) {
        char buffer[BUFSIZ];

        if (false == is_opened()) {
            if (NULL != param) {
                strncat(_file_path, (char*)param, MAX_FILE_PATH_LEN);
            }

            snprintf(buffer, BUFSIZ, "%s", _file_path);
            char* p = strrchr(buffer, '/');
            if (NULL != p) {
                *p = '\0';
                if (0 != FileUtil::create_directories(buffer)) {
                    return -1;
                }
            }

            _fp = fopen(_file_path, "a");
            if (NULL == _fp) {
                return errno;
            }
            struct stat state;
            get_file_stat(state);
            _file_size = state.st_size;

			TimeUtil::gettimeofday(&_create_time, NULL);
        }

		snprintf(buffer, BUFSIZ, "%s", _file_path);
		struct log_message_t log_message = {
			BGCC_LOGLEVEL_NOTICE, 
			"BGCC Version:"VERSION, "=ver=", 
			__FILE__, 
#ifndef _WIN32			
			STR(__LINE__), 
#else
			itoa(__LINE__, buffer, 10),
#endif
            __FUNCTION__,
			_create_time, bgcc::ThreadUtil::self_id()
		};

		write(log_message);

        return 0;
    }

    int32_t FileLogDevice::close(void* param) {
        (void)param;
        if (true == is_opened()) {
            fclose(_fp);
            _fp = NULL;
        }
        return 0;
    }

    int32_t FileLogDevice::write(const struct log_message_t& log_message) {
        if (get_loglevel() > log_message.loglevel) {
            return 0;
        }

        char buffer[1024] = {0};
        int32_t split_policy;
        int32_t nformated;

        nformated = format_log_message(buffer, 1022, log_message);
        split_policy = get_split_policy();

        {
            Guard<Mutex> guard(&_mutex);

            if (!is_opened()) {
                return -1;
            }

            if (BGCC_LOG_SPLIT_POLICY_BY_TIME == split_policy) {
                if (exec_time_split_policy() != 0) {
                    return -1;
                }
            } else {
                if (exec_size_split_policy(nformated) != 0) {
                    return -1;
                }
            }

            if (!is_opened()) {
                return -1;
            }

            fwrite(buffer, nformated, 1, _fp);
            _file_size += nformated;

            fflush(_fp);
        }

        return 0;
    }

    int32_t FileLogDevice::exec_time_split_policy() {
        struct timeval now;
		TimeUtil::gettimeofday(&now, NULL);

        if (now.tv_sec - _create_time.tv_sec >= get_max_record_interval()) {
            close();

            char buffer[BUFSIZ];
            snprintf(buffer, BUFSIZ, "%s%s", _file_path, create_filename_suffix().c_str());
            rename(_file_path, buffer);

            if (open() != 0) {
                return -1;
            }
        }
        return 0;
    }

    std::string FileLogDevice::create_filename_suffix() {
        return "_" + TimeUtil::get_date() + TimeUtil::get_time() + "_" + StringUtil::rand_string();
    }

    int32_t FileLogDevice::exec_size_split_policy(size_t len) {
        off_t size_will = (off_t)(_file_size + len);

        if (size_will > get_max_size()) {
            close();

            char buffer[BUFSIZ];
            snprintf(buffer, BUFSIZ, "%s%s", _file_path, create_filename_suffix().c_str());
            rename(_file_path, buffer);

            if (open() != 0) {
                return -1;
            }
        }
        return 0;
    }

    int32_t FileLogDevice::get_file_stat(struct stat& state) const {
        int32_t fd;

        if (!is_opened()) {
            return -1;
        }

        fd = fileno(_fp);
        if (-1 == fstat(fd, &state)) {
            return errno;
        }
        return 0;
    }

    int32_t FileLogDevice::format_log_message(char* logbuf, int32_t logbufsiz, const struct log_message_t& log_message) {
        int32_t logbufused = 0;
        const char* pc = _log_format;
		const char* sep = NULL;

        while (*pc) {
            if ('%' != *pc) {
                logbuf[logbufused++] = *pc;
            } else {
                ++pc; /** 查看%的下一个字符*/
                if (*pc) {
                    switch(*pc) {
                    case '%':
                        logbuf[logbufused++] = '%';
                        continue;
                        break;
                    case 'C':
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, log_message.content, logbufsiz - logbufused);
                        break;
                    case 'N':
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, log_message.loglevel_name, logbufsiz - logbufused);
                        break;
                    case 'F':
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, log_message.filename, logbufsiz - logbufused);
                        break;
					case 'f':
						sep = strrchr(log_message.filename, FileUtil::SEP);
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, (sep ? sep + 1 : log_message.filename), logbufsiz - logbufused);
                        break;
                    case 'U':
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, log_message.func_name, logbufsiz - logbufused);
                        break;
                    case 'L':
                        logbufused += StringUtil::xstrncpy(logbuf + logbufused, log_message.line, logbufsiz - logbufused);
                        break;
                    case 'D':
                        logbufused += TimeUtil::strftimeval(logbuf + logbufused, logbufsiz - logbufused, &log_message.tv);
                        break;
                    case 'T':
                        logbufused += snprintf(logbuf + logbufused, logbufsiz - logbufused, "%lld", log_message.tid);
                        break;
                    default:
                        logbuf[logbufused++] = '%';
                        logbuf[logbufused++] = *pc;
                    }
                } else {
                    logbuf[logbufused++] = '%';
                    break;
                }
            }

            ++pc;
        }

        logbuf[logbufused++] = '\n';
        logbuf[logbufused] = '\0';
        return logbufused;
    }
}

