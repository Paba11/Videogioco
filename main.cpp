#include <iostream>

#include "Videogame.h"

int main() {
    //Init game engine
    Videogame videogame;
    srand(static_cast<unsigned>(time(0)));
    while(videogame.getWindowIsOpen()){

        videogame.update();


        videogame.render();

    }
    //Game loop
    /*
    Game game;

    while (game.getWindowIsOpen())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
     */

}
