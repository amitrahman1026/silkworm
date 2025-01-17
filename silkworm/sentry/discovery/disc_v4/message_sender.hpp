/*
   Copyright 2023 The Silkworm Authors

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

#pragma once

#include "enr/message_sender.hpp"
#include "find/message_sender.hpp"
#include "ping/message_sender.hpp"

namespace silkworm::sentry::discovery::disc_v4 {

struct MessageSender
    : ping::MessageSender,
      enr::MessageSender,
      find::MessageSender {
};

}  // namespace silkworm::sentry::discovery::disc_v4
