#include <iostream>
#include "Game.h"

int main() {
    //Init game engine
    Game game;

    //Game loop
    while (game.getWindowIsOpen())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

}
