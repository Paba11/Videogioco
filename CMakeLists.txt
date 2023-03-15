cmake_minimum_required(VERSION 3.23)
project(videogioco)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable( videogioco                  main.cpp
                ActionState.h               ActionState.cpp
                Appetizer.h                 Appetizer.cpp
                Bill.h                      Bill.cpp
                Button.h                    Button.cpp
                Chef.h                      Chef.cpp
                Counter.h                   Counter.cpp
                Customer.h                  Customer.cpp
                Dessert.h                   Dessert.cpp
                Dish.h                      Dish.cpp
                DishWasher.h                DishWasher.cpp
                Drink.h                     Drink.cpp
                Entrance.h                  Entrance.cpp
                FollowMovement.h            FollowMovement.cpp
                Game.h                      Game.cpp
                GameCharacter.h             GameCharacter.cpp
                Kitchen.h                   Kitchen.cpp
                Level.h                     Level.cpp
                LevelHeader.h
                MainMenu.h                  MainMenu.cpp
                MainCourse.h                MainCourse.cpp
                Map.h                       Map.cpp
                MealMenu.h
                Order.h                     Order.cpp
                OrderState.h                OrderState.cpp
                ProgramState.h              ProgramState.cpp
                ReceiveState.h              ReceiveState.cpp
                Recipe.h                    Recipe.cpp
                Stool.h                     Stool.cpp
                Table.h                     Table.cpp
                Textures.h                  Textures.cpp
                Tray.h                      Tray.cpp
                Videogame.h                 Videogame.cpp
                Waiter.h                    Waiter.cpp
                WaiterStates.h              WaiterStates.cpp
                Washbasin.h                 Washbasin.cpp BottomBar.cpp BottomBar.h ChoosingCharacter.cpp ChoosingCharacter.h HowToPlay.cpp HowToPlay.h)


target_link_libraries(videogioco sfml-graphics sfml-audio)
