//
// Created by Ettore Righi on 25/04/23.
//

#include <iostream>
#include "EndGame.h"

EndGame::EndGame(sf::RenderWindow *window, std::stack<ProgramState *> *states, int score) : ProgramState(window, states) {
    this->score = score;
    initText();
    initButtons();
}

EndGame::~EndGame() {

}

void EndGame::update() {
    updateMousePosition();
    updateButtons();
    checkQuit();
}

void EndGame::render(sf::RenderTarget *target) {

    window->clear();
    window->draw(text);
    window->draw(scorePoint);
    renderButtons();


    window->display();

}

void EndGame::endState() {
    std::cout << "Exit From EndGame" << std::endl;
}

void EndGame::initText() {

    if(!this->font.loadFromFile("../Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }
    text.setFont(font);
    text.setString("GAMEOVER");
    text.setCharacterSize(130);
    text.setFillColor(sf::Color::White);
    text.setPosition(430, 450);

    scorePoint.setFont(font);
    scorePoint.setString(std::to_string(score));
    scorePoint.setCharacterSize(90);
    scorePoint.setFillColor(sf::Color::White);
    scorePoint.setPosition(550,600);
}

void EndGame::initButtons() {

    buttons["RESTART"] = new Button(250,1200,150,50,&this->font, "Restart",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));
    buttons["EXIT"] = new Button(850,1200,150,50,&this->font, "QUIT",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));

}

void EndGame::updateMousePosition() {

    mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void EndGame::updateButtons() {

    for(auto it : buttons)
        it.second->update(mousePosView);

    if(buttons["EXIT"]->isPressed()) {
        window->close();
    }
    if(buttons["RESTART"]->isPressed()) {
        this->quit = true;

    }
}

void EndGame::renderButtons() {

    for(auto it : this->buttons)
        it.second->render(*this->window);
}


