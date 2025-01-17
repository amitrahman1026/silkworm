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

#include "schema_config.hpp"

#include "state_index_builders_factory.hpp"

namespace silkworm::db::state {

snapshots::Schema::RepositoryDef make_state_repository_schema() {
    snapshots::Schema::RepositoryDef schema;

    schema.domain(kDomainNameAccounts)
        .tag_override(kDomainAccountsTag);
    schema.domain(kDomainNameStorage)
        .kv_segment_compression_kind(snapshots::seg::CompressionKind::kKeys);
    schema.domain(kDomainNameCode)
        .history_compression_enabled(true)
        .kv_segment_compression_kind(snapshots::seg::CompressionKind::kValues);
    schema.domain(kDomainNameCommitment)
        .without_history()
        .kv_segment_compression_kind(snapshots::seg::CompressionKind::kKeys);
    schema.domain(kDomainNameReceipts);

    schema.inverted_index(kInvIdxNameLogAddress)
        .tag_override(kInvIdxLogAddressTag);
    schema.inverted_index(kInvIdxNameLogTopics);
    schema.inverted_index(kInvIdxNameTracesFrom);
    schema.inverted_index(kInvIdxNameTracesTo);

    return schema;
}

datastore::kvdb::Schema::DatabaseDef make_state_database_schema() {
    datastore::kvdb::Schema::DatabaseDef schema;

    schema.domain(kDomainNameAccounts);
    schema.domain(kDomainNameStorage);
    schema.domain(kDomainNameCode)
        .enable_large_values()
        .values_disable_multi_value();
    schema.domain(kDomainNameCommitment)
        .without_history();
    schema.domain(kDomainNameReceipts);

    schema.inverted_index(kInvIdxNameLogAddress);
    schema.inverted_index(kInvIdxNameLogTopics);
    schema.inverted_index(kInvIdxNameTracesFrom);
    schema.inverted_index(kInvIdxNameTracesTo);

    return schema;
}

std::unique_ptr<snapshots::IndexBuildersFactory> make_state_index_builders_factory() {
    return std::make_unique<StateIndexBuildersFactory>(make_state_repository_schema());
}

snapshots::SnapshotRepository make_state_repository(std::filesystem::path dir_path, bool open) {
    return snapshots::SnapshotRepository{
        std::move(dir_path),
        open,
        make_state_repository_schema(),
        std::make_unique<datastore::StepToTxnIdConverter>(),
        make_state_index_builders_factory(),
    };
}

}  // namespace silkworm::db::state
