/*
   Copyright 2024 The Silkworm Authors

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

#include "../datastore/snapshots/snapshot_repository.hpp"
#include "../datastore/snapshots/snapshot_settings.hpp"

namespace silkworm::db::test_util {

snapshots::SnapshotRepository make_repository(snapshots::SnapshotSettings settings);

}  // namespace silkworm::db::test_util