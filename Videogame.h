//
// Created by Ettore Righi on 20/02/23.
//

#ifndef VIDEOGIOCO_VIDEOGAME_H
#define VIDEOGIOCO_VIDEOGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "MainMenu.h"

class Videogame {
public:
    Videogame();
    ~Videogame();


    void update();
    void updateState();

    void render();
    void renderState();
    const bool getWindowIsOpen();
    const bool getQuitGame();
private:
    void initWindow();
    void initStates();


    sf::Event ev;
    sf::VideoMode videoMode;
    sf::RenderWindow* window;

    std::stack <ProgramState*> states;
    bool quitGame;
};


#endif //VIDEOGIOCO_VIDEOGAME_H
