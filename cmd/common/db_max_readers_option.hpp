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

#include <CLI/CLI.hpp>

namespace silkworm::cmd::common {

//! \brief Set up option for maximum number of database readers
void add_option_db_max_readers(CLI::App& cli, uint32_t& max_readers);

}  // namespace silkworm::cmd::common
