#pragma once
#include "hash/sha256.h"
#include "hash/md5.h"
#include "hash/keccak.h"

namespace ood {

    template<typename Hash, typename String>
    std::string UseHash(const String &string) {
        Hash hash;
        static constexpr auto size_elem = sizeof(std::remove_cvref<decltype(string[0])>);
        return hash(string.data(), string.size() * size_elem);
    }

    struct IHashable {
        virtual std::string Hash(const std::string &string) = 0;
    };

    template<typename Derived>
    struct HashableBase : IHashable {
        std::string Hash(const std::string &string) override {
            return UseHash<typename Derived::HashType>(string);
        }
    };

    struct HashSha256 : HashableBase<HashSha256> {
        using HashType = SHA256;
    };

    struct HashMd5 : HashableBase<HashMd5> {
        using HashType = MD5;
    };

    struct HashKeccak : HashableBase<HashKeccak> {
        using HashType = Keccak;
    };

}