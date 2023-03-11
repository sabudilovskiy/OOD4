#include <iostream>
#include "my_hash.hpp"
#include "magic_enum.hpp"

enum struct HashNames{
    sha256, md5, keccak
};

std::unique_ptr<ood::IHashable> CreateHash(HashNames hash_names){
    switch (hash_names) {
        case HashNames::sha256:
            return std::make_unique<ood::HashSha256>();
        case HashNames::keccak:
            return std::make_unique<ood::HashKeccak>();
        case HashNames::md5:
            return std::make_unique<ood::HashMd5>();
    }
}



int main() {
    std::string type_hash;
    while (type_hash != "end"){
        std::cout << "Введите тип хеша: sha256, md5, keccak. Для завершения работы введите end: ";
        std::cin >> type_hash;
        if (type_hash == "end"){
            break;
        }
        auto hash = magic_enum::enum_cast<HashNames>(type_hash);
        if (hash){
            std::string before_hash;
            std::cout << "Введите шифруемое значение: ";
            std::cin >> before_hash;
            auto after_hash = CreateHash(*hash)->Hash(before_hash);
            std::cout << "Захешированное значение: " << after_hash << '\n';
        }
        else std::cout << "Некорректный тип\n";
    }
}
