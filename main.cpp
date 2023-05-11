#include <iostream>

#include "Videogame.h"


int main() {
    //Init game engine
    Videogame videogame;
    srand(static_cast<unsigned>(time(nullptr)));
    while(!videogame.getQuitGame()){

        videogame.update();


        videogame.render();

    }
}
