#include <iostream>

#include "Videogame.h"


int main() {
    //Init game engine
    Videogame videogame;
    srand(static_cast<unsigned>(time(0)));
    while(!videogame.getQuitGame()){

        videogame.update();


        videogame.render();

    }
}
