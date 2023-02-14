cmake_minimum_required(VERSION 3.23)
project(videogioco)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable( videogioco                  main.cpp
                Appetizer.h                 Appetizer.cpp
                Chef.h                      Chef.cpp
                Customer.h                  Customer.cpp
                Dessert.h                   Dessert.cpp
                Dish.h                      Dish.cpp
                DishWasher.h                DishWasher.cpp
                Drink.h                     Drink.cpp
                Game.h                      Game.cpp
                GameCharacter.h             GameCharacter.cpp
                Kitchen.h                   Kitchen.cpp
                MainCourse.h                MainCourse.cpp
                Map.h                       Map.cpp
                Order.h                     Order.cpp
                Recipe.h                    Recipe.cpp
                Table.h                     Table.cpp
                Tray.h                      Tray.cpp
                Waiter.h                    Waiter.cpp
                Washbasin.h                 Washbasin.cpp Stool.cpp Stool.h Textures.cpp Textures.h)


target_link_libraries(videogioco sfml-graphics sfml-audio)
