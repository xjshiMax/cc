#include <stdio.h>
#include <assert.h>

#include <bgcc.h>
using namespace bgcc;

#define ASSERT_EQ(x, y) assert(x==y)

struct log_device {
    std::string level;
    std::string device_name;
    std::string filepath;
    std::string split_policy;
    int64_t max_size;
    std::string layout;
};

int main(int argc, char** args)
{
	bgcc2::ConfUnit px_conf;
    if (!bgcc2::ConfLoader::load_conf("proxy.conf", px_conf)) {
        std::cerr << "failed to load proxy's conf" << std::endl;
        return 1;
    }

    try {
        // runtime section
        int64_t runtime_port = px_conf["runtime"]["port"].to_port();
        ASSERT_EQ(runtime_port, 123);

        int64_t runtime_max_processor = px_conf["runtime"]["max-processor"].to_integer();
        ASSERT_EQ(runtime_max_processor, 10);

        int64_t runtime_callback_timeout = px_conf["runtime"]["callback-timeout"].to_integer();
        ASSERT_EQ(runtime_callback_timeout, 200);

        std::string runtime_passwd = px_conf["runtime"]["passwd"].to_string();
        ASSERT_EQ(runtime_passwd, "123456");

        // sc-mgr section
        bgcc2::ConfUnit& sc_mgr = px_conf["sc-mgr"];
        bool sc_mgr_enabled = sc_mgr["enabled"].to_bool();
        ASSERT_EQ(sc_mgr_enabled, true);

        std::string sc_mgr_main_ip = sc_mgr["main-ip"].to_ipv4();
        ASSERT_EQ(sc_mgr_main_ip, "192.168.99.1");

        //int64_t sc_mgr_main_port = sc_mgr["main-port"].to_port();
        //ASSERT_EQ(sc_mgr_main_port, 9080);

        //std::string sc_mgr_slave_ip = sc_mgr["slave-ip"].to_ipv4();
        //ASSERT_EQ(sc_mgr_slave_ip, "192.168.99.2");

        //int64_t sc_mgr_slave_port = sc_mgr["slave-port"].to_port();
        //ASSERT_EQ(sc_mgr_slave_port, 9080);

        //// bus-mgr section
        //bgcc2::ConfUnit& bus_mgr = px_conf["bus-mgr"];
        //std::string bus_mgr_main_ip = bus_mgr["main-ip"].to_ipv4();
        //ASSERT_EQ(bus_mgr_main_ip, "192.168.99.1");

        //uint16_t bus_mgr_main_port = (uint16_t)bus_mgr["main-port"].to_port();
        //ASSERT_EQ(bus_mgr_main_port, 9080);

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    bgcc2::ConfUnit bgcc_conf;
    if (!bgcc2::ConfLoader::load_conf("bgcc.conf", bgcc_conf)) {
        std::cerr << "failed to load bgcc's conf" << std::endl;
        return 1;
    }

    struct log_device devices[] = {
        {"DEBUG", "bgcc", "./log/bgcc.log", "SIZE", 500000000, "%D [%N] %T {%F(%L)} %C"},
        {"TRACE", "px", "./log/px.log", "SIZE", 500000000, "%D [%N] %T {%F(%L)} %C"}
    };

    try {
        const bgcc2::ConfUnit& log_devices = bgcc_conf["log_devices"];
        for (bgcc2::ConfUnit::const_iterator citr = log_devices.begin(); citr != log_devices.end(); citr++) {
            bgcc2::ConfUnit& log_device = **citr;
            size_t i = std::distance(log_devices.begin(), citr);

            ASSERT_EQ(log_device["level"].to_string(), devices[i].level);
            ASSERT_EQ(log_device["device_name"].to_string(), devices[i].device_name);
            ASSERT_EQ(log_device["filepath"].to_string(), devices[i].filepath);
            ASSERT_EQ(log_device["split_policy"].to_string(), devices[i].split_policy);
            ASSERT_EQ(log_device["max_size"].to_integer(), devices[i].max_size);
            ASSERT_EQ(log_device["layout"].to_string(), devices[i].layout);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
