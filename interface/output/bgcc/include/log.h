/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_H_
#define _BGCC2_LOG_H_

// for cross platform integer output
#ifdef _WIN32
#define I32d "%I32d"
#define I32u "%I32u"
#define I64d "%I64d"
#define I64u "%I64u"
#else
#define I32d "%d"
#define I32u "%u"
#define I64d "%ld"
#define I64u "%lu"
#endif
// end for cross platform integer output

#include <sstream>

#include "log_device_manager.h"
#include "thread_util.h"
#include "time_util.h"

#ifdef _WIN32
#define GETTIMEOFDAY bgcc::TimeUtil::gettimeofday
#else
#define GETTIMEOFDAY gettimeofday
#endif

#define BGCC_RAW_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, CONTENT) \
    do { \
        int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
        if (___device_log_level <= LOGLEVEL) { \
            struct timeval ___tv; \
            GETTIMEOFDAY(&___tv, NULL); \
            struct bgcc::log_message_t log_message = { \
                LOGLEVEL, \
                CONTENT, \
                LOGLEVEL_NAME, \
                __FILE__, \
                STR(__LINE__), \
                __FUNCTION__, \
                ___tv, \
				bgcc::ThreadUtil::self_id() \
            }; \
            bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
        } \
    } while(0)

#define BGCC_RAW_TRACE(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",  CONTENT)
#define BGCC_RAW_DEBUG(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",  CONTENT)
#define BGCC_RAW_NOTICE(DEVICE, CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notice", CONTENT)
#define BGCC_RAW_WARN(DEVICE,   CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn",   CONTENT)
#define BGCC_RAW_FATAL(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",  CONTENT)

#define BGCC_STREAM_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, CONTENT) \
	do { \
	int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
	if (___device_log_level <= LOGLEVEL) { \
	std::ostringstream ___ss; \
	___ss << CONTENT; \
	std::string ___str = ___ss.str(); \
struct timeval ___tv; \
	GETTIMEOFDAY(&___tv, NULL); \
struct bgcc::log_message_t log_message = { \
	LOGLEVEL, \
	___str.c_str(), \
	LOGLEVEL_NAME, \
	__FILE__, \
	STR(__LINE__), \
    __FUNCTION__, \
	___tv, \
	bgcc::ThreadUtil::self_id() \
}; \
	bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
	} \
	} while(0)

#define BGCC_STREAM_TRACE(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",   MESSAGE)
#define BGCC_STREAM_DEBUG(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",   MESSAGE)
#define BGCC_STREAM_NOTICE(DEVICE, MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notice",  MESSAGE)
#define BGCC_STREAM_WARN(DEVICE,   MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn",    MESSAGE)
#define BGCC_STREAM_FATAL(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",   MESSAGE)

#ifndef _WIN32

#define BGCC_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, FORMAT_AND_CONTENT...) \
    do { \
        int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
        if (___device_log_level <= LOGLEVEL) { \
            char ___buffer[1024] = {0}; \
            snprintf(___buffer, 1023, FORMAT_AND_CONTENT); \
            struct timeval ___tv; \
            gettimeofday(&___tv, NULL); \
            struct bgcc::log_message_t log_message = { \
                LOGLEVEL, \
                ___buffer, \
                LOGLEVEL_NAME, \
                __FILE__, \
                STR(__LINE__), \
                __FUNCTION__, \
                ___tv, \
                bgcc::ThreadUtil::self_id() \
            }; \
            bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
        } \
    } while(0)

#define BGCC_TRACE(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",  ##FORMAT)
#define BGCC_DEBUG(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",  ##FORMAT)
#define BGCC_NOTICE(DEVICE, FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notic", ##FORMAT)
#define BGCC_WARN(DEVICE,   FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn ",   ##FORMAT)
#define BGCC_FATAL(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",  ##FORMAT)

#else

namespace bgcc
{
    class CTraceFileAndLineInfo
    {
        public:
            CTraceFileAndLineInfo(
                    const char* file_name,
                    int32_t line_no,
                    const char* func_name,
                    int32_t log_level,
                    const char* log_level_name)
                : _file_name(file_name), _line_no(line_no), _func_name(func_name),
                _log_level(log_level), _log_level_name(log_level_name)
        {}


            void __cdecl operator()(const char* device_name, const char* fmt, ...) const
            {
                std::stringstream ss;
                ss << _line_no;
                std::string line_no;
                ss >> line_no;
                va_list ptr; va_start(ptr, fmt);
                int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(device_name);
                if (___device_log_level <= _log_level) {
                    char ___buffer[1024] = {0};
                    _vsnprintf(___buffer, 1023, fmt, ptr);
                    struct ::timeval ___tv;
                    bgcc::TimeUtil::gettimeofday(&___tv, NULL);
                    struct bgcc::log_message_t log_message = {
                        _log_level,
                        ___buffer,
                        _log_level_name,
                        _file_name,
                        line_no.c_str(),
                        _func_name,
                        ___tv, \
                            bgcc::ThreadUtil::self_id()
                    };
                    bgcc::LogDeviceManager::get_instance()->write(device_name, log_message);
                }
                va_end(ptr);
            }

        private:
            const char* const _file_name;
            int32_t _line_no;
            const char* const _func_name;
            int32_t _log_level;
            const char* const _log_level_name;
    };
}

#define BGCC_TRACE bgcc::CTraceFileAndLineInfo(__FILE__, __LINE__, __FUNCTION__, BGCC_LOGLEVEL_TRACE, "trace")
#define BGCC_DEBUG bgcc::CTraceFileAndLineInfo(__FILE__, __LINE__, __FUNCTION__, BGCC_LOGLEVEL_DEBUG, "debug")
#define BGCC_NOTICE bgcc::CTraceFileAndLineInfo(__FILE__, __LINE__, __FUNCTION__, BGCC_LOGLEVEL_NOTICE, "notice")
#define BGCC_WARN bgcc::CTraceFileAndLineInfo(__FILE__, __LINE__, __FUNCTION__, BGCC_LOGLEVEL_WARN, "warn")
#define BGCC_FATAL bgcc::CTraceFileAndLineInfo(__FILE__, __LINE__, __FUNCTION__, BGCC_LOGLEVEL_FATAL, "fatal")


#endif
#endif // _BGCC2_LOG_H_

