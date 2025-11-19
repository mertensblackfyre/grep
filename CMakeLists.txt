cmake_minimum_required(VERSION 3.16)
project(hasm LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/includes)

set(SOURCES
    main.cc
    src/constant.cc
    src/helper.cc
)


add_library(hasm_lib STATIC ${HASM_SOURCES})

target_include_directories(hasm_lib
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# ---- Main executable ----
add_executable(hasm src/main.cpp)
target_link_libraries(hasm PRIVATE hasm_lib)

# ---- Test executable ----
set(TEST_SOURCES
    tests/test_parser.cpp
    # add other test files here
)

add_executable(hasm_tests ${TEST_SOURCES})
target_link_libraries(hasm_tests PRIVATE hasm_lib gtest gtest_main)

# Enable testing and discover tests
enable_testing()
include(GoogleTest)
gtest_discover_tests(hasm_tests)

