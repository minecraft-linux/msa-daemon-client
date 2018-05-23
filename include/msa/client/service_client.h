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


    /**
     * List the accounts that the user has signed in with.
     * You probably should use pickAccount instead to let the user select an account, which also lets the user sign in
     * if no accounts are registered, and then store the account id.
     * @return a rpc_call that contains a list of basic account information (without tokens)
     */
    simpleipc::client::rpc_call<std::vector<BaseAccountInfo>> getAccounts();

    /**
     * Opens an UI that lets the user select an account.
     * @param clientId application's client id
     * @param cobrandId brand id (used for the login page style, optional)
     * @return a rpc_call that contains an account id (CID)
     */
    simpleipc::client::rpc_call<std::string> pickAccount(std::string const& clientId,
                                                         std::string const& cobrandId = std::string());

};

}
}