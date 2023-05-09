# 'Google_test' is the subproject name
cmake_minimum_required(VERSION 3.23)
project(Google_tests)

set(GOOGLETEST_VERSION 1.9.0)

set(GOOGLE_TEST_SOURCES
        RunTests.cpp
        MapTest.cpp
        WaiterTest.cpp)

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest/)

add_executable(Google_Tests ${GOOGLE_TEST_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Google_Tests PRIVATE gtest gtest_main sfml-system sfml-network sfml-graphics sfml-window core)