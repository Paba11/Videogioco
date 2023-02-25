//
// Created by Ettore Righi on 20/02/23.
//

#include "Videogame.h"

Videogame::Videogame() {
    initWindow();
    initStates();
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
    this->window = new sf::RenderWindow(videoMode, "VideoGame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);

}

void Videogame::render() {

    this->window->clear();
    this->window->display();
    renderState();
}

void Videogame::update() {

    pollEvents();
    updateState();

}

void Videogame::pollEvents() {

    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                else {
                    //this->waiter->updateMovement();
                    //this->waiter->interact(this->map);
                }
                break;
        }
    }

}

const bool Videogame::getWindowIsOpen() {
    return this->window->isOpen();
}

void Videogame::initStates() {
    this->states.push(new MainMenu(this->window, &this->states));
}

void Videogame::updateState() {

    if(!this->states.empty()) {
        this->states.top()->update();
        if(this->states.top()->getQuit()) {
            this->states.top()->endState(); //FIXME check the terminal when close the game from the window
            delete this->states.top();
            this->states.pop();
        }
    }
    else
        this->window->close();
}

void Videogame::renderState() {

    if(!this->states.empty())
        this->states.top()->render();
}
