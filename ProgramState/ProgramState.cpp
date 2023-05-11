//
// Created by Ettore Righi on 20/02/23.
//

#include "ProgramState.h"

ProgramState::ProgramState(sf::RenderWindow* window, std::stack <ProgramState*>* states) {

    this->states = states;
    this->window = window;
    this->quit = false;
    this->textures = new Textures();
}

ProgramState::~ProgramState() = default;

void ProgramState::checkQuit() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->quit = true;
    if(!this->window->isOpen())
        this->quit = true;
}

bool ProgramState::getQuit() const{
    return this->quit;
}
