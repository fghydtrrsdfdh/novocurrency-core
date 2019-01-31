// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

struct MutationRecord final {
    int64_t change;
    int64_t timestamp;
    std::string txHash;

    MutationRecord(int64_t change_,
                   int64_t timestamp_,
                   std::string txHash_)
    : change(std::move(change_))
    , timestamp(std::move(timestamp_))
    , txHash(std::move(txHash_))
    {}
};
