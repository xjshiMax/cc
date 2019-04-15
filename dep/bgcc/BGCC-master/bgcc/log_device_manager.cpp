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
#include <sstream>

#ifdef _WIN32
#include "process.h"
#endif

#include "bgcc_common.h"
#include "log_device_manager.h"
#include "log_device.h"
#include "conf_loader.h"
#include "conf_unit.h"
#include "bgcc_error.h"
#include "string_util.h"

namespace bgcc {

    void load_default_device() {
        char buffer[BUFSIZ];
        int32_t ret;

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(0);
        }

        ILogDevice* default_device = new(std::nothrow) FileLogDevice(
                "./bgcc.log", "bgcc", BGCC_LOGLEVEL_WARN,
                BGCC_LOG_SPLIT_POLICY_BY_SIZE, 500*1024*1024, -1,
                "%D [%N] %T {%F(%L)} %C");
        if (NULL == default_device) {
            std::cerr << "Create default device `bgcc' failed." << std::endl;
            exit(0);
        }

        std::ostringstream oss;
        oss << getpid();
        ret = default_device->open(const_cast<char*>(oss.str().c_str()));
        if (0 != ret) {
            std::cerr << "Open default device failed: " << bgcc_strerror_r(ret, buffer, BUFSIZ) << std::endl;
            delete default_device;
            exit(0);
        }

        if (0 != manager->add_device(default_device)) {
            std::cerr << "Add device `bgcc' failed" << std::endl;
            delete default_device;
            exit(0);
        }
    }

    static int32_t get_loglevel_from_logdev_confunit(bgcc2::ConfUnit& logdev) {
        std::string level_valstr = logdev["level"].to_string();

        int32_t level_value;
        if ("TRACE" == level_valstr) {
            level_value = BGCC_LOGLEVEL_TRACE;
        }
        else if ("DEBUG" == level_valstr) {
            level_value = BGCC_LOGLEVEL_DEBUG;
        }
        else if ("NOTICE" == level_valstr) {
            level_value = BGCC_LOGLEVEL_NOTICE;
        }
        else if ("WARN" == level_valstr) {
            level_value = BGCC_LOGLEVEL_WARN;
        }
        else if ("FATAL" == level_valstr) {
            level_value = BGCC_LOGLEVEL_FATAL;
        }
        else {
            std::cerr << "specify an invalid log level string " << level_valstr << std::endl;
            exit(-1);
        }

        return level_value;
    }

    static int32_t get_split_policy_from_logdev_confunit(bgcc2::ConfUnit& logdev) {
        std::string split_policy_valstr = logdev["split_policy"].to_string();
        int32_t split_policy_value;

        if ("SIZE" == split_policy_valstr) {
            split_policy_value = BGCC_LOG_SPLIT_POLICY_BY_SIZE;
        }
        else if ("TIME" == split_policy_valstr) {
            split_policy_value = BGCC_LOG_SPLIT_POLICY_BY_TIME;
        }
        else {
            std::cerr << "specify an invalid log split policy string " << split_policy_valstr << std::endl;
            exit(-1);
        }

        return split_policy_value;
    }

    static int64_t get_maxsize_from_logdev_confunit(bgcc2::ConfUnit& logdev, int32_t split_policy) {
        int64_t maxsize_value = 0;

        if (split_policy == BGCC_LOG_SPLIT_POLICY_BY_SIZE) {
            maxsize_value = logdev["max_size"].to_integer();
        }

        return maxsize_value;
    }

    static int32_t get_life_circle_from_logdev_confunit(bgcc2::ConfUnit& logdev, int32_t split_policy) {
        int32_t life_circle_value = 0;

        if (split_policy == BGCC_LOG_SPLIT_POLICY_BY_TIME) {
            life_circle_value = (int32_t)logdev["life_circle"].to_integer();
        }

        return life_circle_value;
    }

    void load_conf_device(const char* conf_filepath) {
        int32_t ret;

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(-1);
        }

        bgcc2::ConfUnit root;
        if (!bgcc2::ConfLoader::load_conf(conf_filepath, root)) {
            std::cerr << "failed to load conf " << conf_filepath << std::endl;
            exit(-1);
        }

        try {
            bgcc2::ConfUnit& logdevs = root["log_devices"];

            if (!logdevs.is_array()) {
                std::cerr << "log_devices is not an array" << std::endl;
                exit(-1);
            }

            bgcc2::ConfUnit::const_iterator citr;
            int32_t i;
            for (citr = logdevs.begin(), i = 1; citr != logdevs.end(); ++citr, ++i) {
                bgcc2::ConfUnit& logdev = **citr;

                int32_t level_value = get_loglevel_from_logdev_confunit(logdev);
                std::string device_name_valstr = logdev["device_name"].to_string();
                std::string filepath_valstr = logdev["filepath"].to_string();
                int32_t split_policy_value = get_split_policy_from_logdev_confunit(logdev);
                int64_t maxsize_value = get_maxsize_from_logdev_confunit(logdev, split_policy_value);
                int32_t life_circle_value = get_life_circle_from_logdev_confunit(logdev, split_policy_value);
                std::string layout_valstr = logdev["layout"].to_string();

                ILogDevice* device = new(std::nothrow) FileLogDevice(
                        filepath_valstr.c_str(), device_name_valstr.c_str(), level_value,
                        split_policy_value, (off_t)maxsize_value, life_circle_value,
                        layout_valstr.c_str());
                if (NULL == device ) {
                    std::cerr << "Create device " << i << " failed." << std::endl;
                    exit(-1);
                }

                std::ostringstream oss;
                oss << getpid();
                if (0 != (ret = device->open(const_cast<char*>(oss.str().c_str())))) {
                    std::cerr << "failed to Open device " << i << ": " << device_name_valstr << std::endl;
                    exit(-1);
                }

                if (0 != manager->add_device(device)) {
                    std::cerr << "Add device " << i << " failed" << std::endl;
                    exit(-1);
                }
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            exit(-1);
        }
    }

    void log_open(const char* conf_filepath) {
        if (NULL != conf_filepath) {
            load_conf_device(conf_filepath);
        }

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(0);
        }

        if (false == manager->is_device_exist("bgcc")) {
            load_default_device();
        }
    }

    int32_t log_close() {
        return 0;
    }

    LogDeviceManager::LogDeviceManager() {
    }

    LogDeviceManager* LogDeviceManager::get_instance() {
        static LogDeviceManager logger;
        return &logger;
    }

    LogDeviceManager::~LogDeviceManager() {
        std::vector<ILogDevice*>::iterator itr;
        for (itr = _devices.begin(); itr != _devices.end(); ++itr) {
            delete *itr;
        }
        _devices.clear();
    }

    bool LogDeviceManager::is_device_exist(const char* device_name) {
        return get_device(device_name) != NULL;
    }

    int32_t LogDeviceManager::add_device(ILogDevice* device) {
        if (is_device_exist(device->get_name())) {
            return -1;
        }

        _devices.push_back(device);
        return 0;
    }

    int32_t LogDeviceManager::get_device_loglevel(const char* device_name) {
        ILogDevice* device = get_device(device_name);

        if (NULL == device) {
            device = get_device("bgcc");
        }

        if (NULL != device) {
            return device->get_loglevel();
        }
        else {
            return BGCC_LOGLEVEL_NOLOG;
        }
    }

    ILogDevice* LogDeviceManager::get_device(const char* device_name) {
        std::vector<ILogDevice*>::iterator itr;
        for (itr = _devices.begin(); itr != _devices.end(); ++itr) {
            if (strcmp((*itr)->get_name(), device_name) == 0) {
                return *itr;
            }
        }
        return NULL;
    }

    int32_t LogDeviceManager::write(const char* device_name,
            const struct log_message_t& log_message) {
        ILogDevice* device = get_device(device_name);

        if (NULL == device) {
            device = get_device("bgcc");
        }

        if (NULL != device) {
            return device->write(log_message);
        }
        else {
            return -1;
        }
    }
}

