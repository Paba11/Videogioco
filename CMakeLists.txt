cmake_minimum_required(VERSION 3.23)
project(videogioco)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable( videogioco                  main.cpp
                Appetizer.h                 Appetizer.cpp
                Bill.h                      Bill.cpp
                Chef.h                      Chef.cpp
                Customer.h                  Customer.cpp
                Dessert.h                   Dessert.cpp
                Dish.h                      Dish.cpp
                DishWasher.h                DishWasher.cpp
                Drink.h                     Drink.cpp
                Entrance.h                  Entrance.cpp
                Game.h                      Game.cpp
                GameCharacter.h             GameCharacter.cpp
                Kitchen.h                   Kitchen.cpp
                MainCourse.h                MainCourse.cpp
                Map.h                       Map.cpp
                MealMenu.h
                Order.h                     Order.cpp
                OrderState.h                OrderState.cpp
                Recipe.h                    Recipe.cpp
                Stool.h                     Stool.cpp
                Table.h                     Table.cpp
                Textures.h                  Textures.cpp
                Tray.h                      Tray.cpp
                Waiter.h                    Waiter.cpp
                Washbasin.h                 Washbasin.cpp MainMenu.cpp MainMenu.h Button.cpp Button.h Videogame.cpp Videogame.h ProgramState.cpp ProgramState.h Counter.cpp Counter.h)


target_link_libraries(videogioco sfml-graphics sfml-audio)
