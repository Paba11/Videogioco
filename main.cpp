#include <iostream>
#include "Game.h"

int main() {
    //Init game engine
    Game game;
    srand(static_cast<unsigned>(time(0)));
    //Game loop
    while (game.getWindowIsOpen())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

}
