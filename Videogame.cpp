//
// Created by Ettore Righi on 20/02/23.
//

#include "Videogame.h"

Videogame::Videogame() {
    initWindow();
    initStates();
    quitGame = false;
}


Videogame::~Videogame() {
    delete window;

    while(!states.empty()){
        delete states.top();
        states.pop();
    }
}

void Videogame::initWindow() {

    videoMode.width = 1298;
    videoMode.height = 1344;
    //this->window = new sf::RenderWindow;
    window = new sf::RenderWindow(videoMode, "VideoGame");
    window->setFramerateLimit(144);
    window->setVerticalSyncEnabled(false);


}

void Videogame::render() {

    renderState();
}

void Videogame::update() {

    updateState();

}


void Videogame::initStates() {
    states.push(new MainMenu(window, &states));
}

void Videogame::updateState() {

    if(!states.empty()) {
        if(!states.top()->getQuit())
            states.top()->update();
        if(states.top()->getQuit()) {
            states.top()->endState(); //FIXME check the terminal when close the game from the window
            delete states.top();
            states.pop();
        }
    }
    else
        quitGame = true;

}

void Videogame::renderState() {

    if(!this->states.empty() && !this->states.top()->getQuit())
        this->states.top()->render(nullptr);
}

const bool Videogame::getQuitGame() {
    return quitGame;
}
