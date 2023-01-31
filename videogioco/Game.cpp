//
// Created by Paolo Sbarzagli on 30/01/23.
//

#include "Game.h"

Game::Game() {
    this->window = nullptr;
}

Game::~Game() {

}

void Game::update() {

}

void Game::render() {

}

void Game::initVariables() {

}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(), "VideoGame");
}
