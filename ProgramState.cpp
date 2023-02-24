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

    while (window->pollEvent(ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->quit = true;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->quit = true;
                break;
        }
    }
}

const bool ProgramState::getQuit() const{
    return this->quit;
}
