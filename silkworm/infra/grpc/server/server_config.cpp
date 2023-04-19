/*
   Copyright 2022 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "server_config.hpp"

#include <utility>

namespace silkworm::rpc {

ServerConfig::ServerConfig(std::shared_ptr<grpc::ServerCredentials> credentials)
    : address_uri_{kDefaultAddressUri},
      credentials_(std::move(credentials)) {
}

void ServerConfig::set_address_uri(const std::string& address_uri) noexcept {
    address_uri_ = address_uri;
}

void ServerConfig::set_credentials(std::shared_ptr<grpc::ServerCredentials> credentials) noexcept {
    credentials_ = std::move(credentials);
}

void ServerConfig::set_context_pool_settings(concurrency::ContextPoolSettings settings) noexcept {
    context_pool_settings_ = settings;
}

}  // namespace silkworm::rpc