cmake_minimum_required(VERSION 3.16)
project(hasm LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/includes)

# ---- Shared library for common code ----
set(HASM_LIB_SOURCES
    src/constant.cc
    src/helper.cc
)

add_library(hasm_lib ${HASM_LIB_SOURCES})

target_include_directories(hasm_lib PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# ---- Main executable ----
add_executable(hasm main.cc)

target_link_libraries(hasm PRIVATE hasm_lib)

# ---- Tests ----
enable_testing()
find_package(GTest REQUIRED)

add_executable(hasm_tests
    tests/test_parser.cc
    tests/test_translate.cc
)

target_include_directories(hasm_tests PRIVATE ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(hasm_tests
    PRIVATE
        hasm_lib
        GTest::gtest
        GTest::gtest_main
)

