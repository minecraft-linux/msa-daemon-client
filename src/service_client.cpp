#include <msa/client/service_client.h>

using namespace msa::client;

simpleipc::client::rpc_call<std::vector<BaseAccountInfo>> ServiceClient::getAccounts() {
    return simpleipc::client::rpc_call<std::vector<BaseAccountInfo>>(
            rpc("msa/get_accounts", nullptr), [](nlohmann::json const& d) {
                std::vector<BaseAccountInfo> ret;
                for (auto const& a : d["accounts"])
                    ret.push_back(BaseAccountInfo::fromJson(a));
                return ret;
            });
}