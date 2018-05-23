#pragma once

#include <simpleipc/client/service_client.h>
#include <simpleipc/client/rpc_call.h>
#include "account.h"

namespace msa {
namespace client {

class ServiceClient : public simpleipc::client::service_client {

public:
    ServiceClient(const std::string& path) : service_client(path) {}

    ServiceClient(std::unique_ptr<simpleipc::client::service_client_impl> impl) : service_client(std::move(impl)) {}


    simpleipc::client::rpc_call<std::vector<BaseAccountInfo>> getAccounts();

};

}
}