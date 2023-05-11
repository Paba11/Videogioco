# 'Google_test' is the subproject name
cmake_minimum_required(VERSION 3.23)
project(Google_tests)

set(GOOGLETEST_VERSION 1.9.0)

set(GOOGLE_TEST_SOURCES
        ChefTest.cpp
        CustomerTest.cpp
        MapTest.cpp
        RunTests.cpp
        WaiterTest.cpp)
enable_testing()

set(gtest_SOURCE_DIR, ./lib/googletest/)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Prova)


add_subdirectory(./lib/googletest-main)

add_executable(Google_Tests ${GOOGLE_TEST_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Google_Tests PRIVATE gtest gtest_main sfml-system sfml-network sfml-graphics sfml-window core)