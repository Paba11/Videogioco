//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"


Game::Game() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete this->window;
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    this->window->clear();

    //Draw Game

    this->window->display();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    /*
     * initialize the window of the game with a specific size and a name on the toolbar
     */
    this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "VideoGame");
}

const bool Game::getWindowIsOpen() {
    return this->window->isOpen();
}

void Game::pollEvents() {
    /*
     * Manage the events of the game take as input from the user in order to do the right actions
     */
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
                //else if ()
                break;
        }
    }

}


