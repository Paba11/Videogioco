//
// Created by Ettore Righi on 20/02/23.
//

#include "Videogame.h"

Videogame::Videogame() {
    initWindow();
    initStates();
    this->quitGame = false;
}


Videogame::~Videogame() {
    delete this->window;

    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Videogame::initWindow() {

    videoMode.width = 1298;
    videoMode.height = 1344;
    //this->window = new sf::RenderWindow;
    this->window = new sf::RenderWindow(this->videoMode, "VideoGame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);


}

void Videogame::render() {

    renderState();
}

void Videogame::update() {

    updateState();

}


void Videogame::initStates() {
    this->states.push(new MainMenu(this->window, &this->states));
}

void Videogame::updateState() {

    if(!this->states.empty()) {
        if(!this->states.top()->getQuit())
            this->states.top()->update();
        if(this->states.top()->getQuit()) {
            this->states.top()->endState(); //FIXME check the terminal when close the game from the window
            delete this->states.top();
            this->states.pop();
        }
    }
    else
        this->quitGame = true;

}

void Videogame::renderState() {

    if(!this->states.empty() && !this->states.top()->getQuit())
        this->states.top()->render();
}

const bool Videogame::getQuitGame() {
    return this->quitGame;
}
