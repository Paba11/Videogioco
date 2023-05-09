cmake_minimum_required(VERSION 3.23)
project(videogioco)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.5.1_2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        Waiter/ActionState.h        Waiter/ActionState.cpp
        Dish/Appetizer.h            Dish/Appetizer.cpp
        Button.h                    Button.cpp
        NPC/Chef.h                  NPC/Chef.cpp
        Map/Counter.h               Map/Counter.cpp
        NPC/Customer.h              NPC/Customer.cpp
        Dish/Dessert.h              Dish/Dessert.cpp
        Dish/Dish.h                 Dish/Dish.cpp
        NPC/DishWasher.h            NPC/DishWasher.cpp
        Map/Entrance.h              Map/Entrance.cpp
        ProgramState/Game.h         ProgramState/Game.cpp
        GameCharacter.h             GameCharacter.cpp
        Map/Kitchen.h               Map/Kitchen.cpp
        Level.h                     Level.cpp
        LevelHeader.h
        ProgramState/MainMenu.h     ProgramState/MainMenu.cpp
        Dish/MainCourse.h           Dish/MainCourse.cpp
        Map/Map.h                   Map/Map.cpp
        Dish/MealMenu.h
        Dish/Order.h                Dish/Order.cpp
        Waiter/OrderState.h         Waiter/OrderState.cpp
        ProgramState/ProgramState.h ProgramState/ProgramState.cpp
        Waiter/ReceiveState.h       Waiter/ReceiveState.cpp
        Map/Stool.h                 Map/Stool.cpp
        Score.h                     Score.cpp
        Map/Table.h                 Map/Table.cpp
        Textures.h                  Textures.cpp
        Tray.h                      Tray.cpp
        Videogame.h                 Videogame.cpp
        Waiter/Waiter.h             Waiter/Waiter.cpp
        Waiter/WaiterStates.h       Waiter/WaiterStates.cpp
        Map/Washbasin.h             Map/Washbasin.cpp
        BottomBar.cpp               BottomBar.h
        ProgramState/ChoosingCharacter.cpp ProgramState/ChoosingCharacter.h
        ProgramState/HowToPlay.cpp  ProgramState/HowToPlay.h
        ProgramState/EndGame.cpp    ProgramState/EndGame.h)

add_executable(videogioco                  main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(core PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

target_link_libraries(videogioco PRIVATE sfml-system sfml-network sfml-graphics sfml-window core)

add_subdirectory(Google_Tests)