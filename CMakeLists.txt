cmake_minimum_required(VERSION 3.16)
project(simple_http_parser C)

set(CMAKE_C_STANDARD 11)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Catch2 REQUIRED)

set(COMMON_SRC
        src/common/hash_table.c
        )
add_library(common STATIC ${COMMON_SRC})
target_include_directories(
        common
        PUBLIC
        inc
)

add_executable(common_tests test/common/test_hash_table.c)
target_link_libraries(common_tests PRIVATE Catch2::Catch2)

add_executable(simple_http_parser main.c)
target_link_libraries(simple_http_parser
        PRIVATE
        common)