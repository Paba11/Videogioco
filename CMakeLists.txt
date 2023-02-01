cmake_minimum_required(VERSION 3.23)
project(videogioco)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})


add_executable( videogioco                  main.cpp
                Game.h                      Game.cpp
                GameCharacter.h             GameCharacter.cpp
                Waiter.h                    Waiter.cpp)


target_link_libraries(videogioco sfml-graphics sfml-audio)
