//
// Created by Ettore Righi on 20/02/23.
//

#include "ProgramState.h"

ProgramState::ProgramState(sf::RenderWindow* window, std::stack <ProgramState*>* states) {

    this->states = states;
    this->window = window;
}

ProgramState::~ProgramState() {

}

void ProgramState::checkQuit() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->quit = true;
    if(!this->window->isOpen())
        this->quit = true;
}

const bool ProgramState::getQuit() const{
    return this->quit;
}
