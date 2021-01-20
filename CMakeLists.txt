cmake_minimum_required(VERSION 3.16)
project(simple_http_parser C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_COMPILER_IS_GNUCC TRUE)


if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif ()

# Dependencies
# If dependencies are managed with conan, we set the CMake module path (where
# CMake looks for dependencies) to the current build folder.
if (EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conaninfo.txt)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
endif ()

find_package(CUnit REQUIRED)
find_package(CURL REQUIRED)

set(COMMON_SRC
        src/common/hash_table.c
        src/common/clone.c
        )
add_library(common STATIC ${COMMON_SRC})
target_include_directories(
        common
        PUBLIC
        inc
)

add_executable(common_tests test/common/test_hash_table.c test/common/test_main.c test/common/test_clone.c)
target_include_directories(
        common
        PUBLIC
        inc
)
target_link_libraries(common_tests
        PRIVATE
        CUnit::CUnit
        CURL::libcurl
        common)

add_executable(simple_http_parser main.c)
target_link_libraries(simple_http_parser
        PRIVATE
        CUnit::CUnit
        CURL::libcurl
        common)