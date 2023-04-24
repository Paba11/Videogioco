cmake_minimum_required (VERSION 3.23)
project(Google_Tests)

set(GOOGLETEST_VERSION 1.9.0)

set(GOOGLE_TEST_SOURCES
        RunTests.cpp
        MapTest.cpp)
enable_testing()

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${SFML_INCLUDE_DIR})

add_executable(Google_Tests ${GOOGLE_TEST_SOURCES})

target_link_libraries(Google_Tests gtest gtest_main sfml-system sfml-network sfml-graphics sfml-window core)

