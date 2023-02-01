//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"


Game::Game() {
    initVariables();
    initWindow();
    initWaiter();
}

Game::~Game() {
    delete this->window;
    delete this->waiter;
}

void Game::update() {
    this->pollEvents();
    this->updateMousePos();
}

void Game::render() {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    this->window->clear();

    //Draw Game
    this->waiter->render(*this->window);

    this->window->display();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    /*
     * Initialize the window of the game with a specific size and a name on the toolbar
     * It also limits the speed rate of the computer in order to not overflow the game
     * and not disable the vertical synchronization
     */

    this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "VideoGame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

const bool Game::getWindowIsOpen() {
    return this->window->isOpen();
}

void Game::pollEvents() {
    /*
     * Manage the events
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
                else
                    waiter->updateMovement(this->ev);
                break;
        }
    }

}

void Game::updateMousePos() {
    /*
     * Set the variable mousePos to the pixel in which the mouse is pointing (respect to the game window)
     */
    this->mousePos = sf::Mouse::getPosition(*this->window);
}

void Game::initWaiter() {
    this->waiter = new Waiter();
}


