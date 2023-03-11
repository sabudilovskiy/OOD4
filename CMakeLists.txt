cmake_minimum_required(VERSION 3.20)
project(OOD4)
set(CMAKE_CXX_STANDARD 20)

include(conan_libraries/conan_paths.cmake)
find_package(GTest)
find_package(magic_enum)

add_library(${PROJECT_NAME}_hash
        libraries/hash/crc32.h
        libraries/hash/crc32.cpp
        libraries/hash/digest.cpp
        libraries/hash/hash.h
        libraries/hash/hmac.h
        libraries/hash/keccak.h
        libraries/hash/keccak.cpp
        libraries/hash/md5.h
        libraries/hash/md5.cpp
        libraries/hash/sha1.h
        libraries/hash/sha1.cpp
        libraries/hash/sha3.h
        libraries/hash/sha3.cpp
        libraries/hash/sha256.h
        libraries/hash/sha256.cpp
        )

add_library(${PROJECT_NAME}_objs
        src/my_hash.hpp
        src/empty.cpp)

include_directories(libraries)
target_link_libraries(${PROJECT_NAME}_objs PRIVATE ${PROJECT_NAME}_hash)

#Main
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objs)
target_link_libraries(${PROJECT_NAME} PRIVATE magic_enum::magic_enum)
include_directories(src)