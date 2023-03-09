//
// Created by Ettore Righi on 18/02/23.
//

#include <iostream>
#include <functional>
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(sf::RenderWindow* window, std::stack <ProgramState*>* states) : ProgramState(window, states){

    initFonts();
    initTexture();
    initBackground();
    initButtons();
    this->ev.type = sf::Event::Closed;

}

MainMenu::~MainMenu() {


    for(auto it : this->buttons)
        delete it.second;
}

void MainMenu::update() {

    updateMousePosition();
    pollEvents();
    updateButtons();
    checkQuit();


}

void MainMenu::render(sf::RenderTarget* target) {
    /*
     * Clear the window, draw the objects of the game for the related actions and placement, displays it.
     */
    if(this->window->isOpen()) {
        this->window->clear();
        this->window->draw(this->background);
        this->renderButtons();
        this->window->display();
    }
    this->checkQuit();

}

const bool MainMenu::getWindowIsOpen() {
    return this->window->isOpen();
}


void MainMenu::initBackground() {
    /*
     * Initialize the map texture and connect it to a sprite
     */

    this->background.setTexture(*this->texture->getTexture("MainMenu"));
    this->background.setScale(1.f,1.f);

}

void MainMenu::initTexture() {
    this->texture = new Textures();
}



void MainMenu::updateMousePosition() {
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void MainMenu::initFonts() {

    if(!this->font.loadFromFile("../Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }
}

void MainMenu::pollEvents() {

    while (this->window->pollEvent(this->ev)) {

    }
}

void MainMenu::initButtons() {

    this->buttons["PLAY"] = new Button(250,1200,150,50,&this->font, "Play",
                                  sf::Color(70,70,70,200),
                                  sf::Color(150,150,150,255),
                                  sf::Color(20,20,20,200));
    this->buttons["EXIT"] = new Button(800,1200,150,50,&this->font, "QUIT",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));

    this->buttons["HOWTO"] = new Button(500,1200,150,50,&this->font, "CONTROLS",
                                        sf::Color(70,70,70,200),
                                        sf::Color(150,150,150,255),
                                        sf::Color(20,20,20,200));
}


void MainMenu::updateButtons() {

    for(auto it : this->buttons)
        it.second->update(this->mousePosView);

    if(buttons["EXIT"]->isPressed()) {
        this->quit = true;
    }
    if(buttons["PLAY"]->isPressed()) {
        this->quit = true;
        this->states->push(new ChoosingCharacter(this->window, this->states));
    }
    if(buttons["HOWTO"]->isPressed()) {
        this->states->push(new HowToPlay(this->window, this->states));
    }


}



void MainMenu::renderButtons() {

    for(auto it : this->buttons)
        it.second->render(*this->window);

}

void MainMenu::endState() {

    std::cout << "Exit From Main Menu" << std::endl;

}



