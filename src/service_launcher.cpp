#include <msa/client/service_launcher.h>
#include <msa/client/service_client.h>
#include <EnvPathUtil.h>

using namespace msa::client;

std::string ServiceLauncher::getDefaultDataPath() {
    return EnvPathUtil::getDataHome() + "/msa";
}

std::shared_ptr<ServiceClient> ServiceLauncher::createClient() {
    std::shared_ptr<ServiceClient> ret (new ServiceClient(open()));
    ret->send_hello_message();
    return ret;

}