#pragma once

#include <daemon_utils/daemon_launcher.h>

namespace msa {
namespace client {

class ServiceClient;

class ServiceLauncher : protected daemon_utils::daemon_launcher {

private:
    std::string data_path;
    std::string executable_path;

    static std::string getDefaultDataPath();

protected:
    std::vector<std::string> get_arguments() override {
        return {executable_path, "-d", data_path};
    }

public:
    ServiceLauncher(std::string const& executable_path, std::string const& data_path = getDefaultDataPath()) :
            daemon_launcher(data_path + "/service"), data_path(data_path), executable_path(executable_path) {}


    std::shared_ptr<ServiceClient> createClient();

};

}
}