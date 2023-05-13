//
// Created by Ettore Righi on 25/04/23.
//

#include <iostream>
#include "EndGame.h"

EndGame::EndGame(sf::RenderWindow *window, std::stack<ProgramState *> *states, int score, int servedCustomer,
                 int servedTable, int goneTable) : ProgramState(window, states) {
    this->score = score;
    this->servedTable = servedTable;
    this->servedCustomer = servedCustomer;
    this->goneTable = goneTable;
    initText();
    initButtons();
    setExtraInfo();
}

EndGame::~EndGame() = default;

void EndGame::update() {
    updateMousePosition();
    updateButtons();
    checkQuit();
}

void EndGame::render(sf::RenderTarget *target) {

    window->clear();
    window->draw(gameOver);
    window->draw(scorePoint);
    window->draw(sCustomer);
    window->draw(sTable);
    window->draw(gTable);
    renderButtons();


    window->display();

}

void EndGame::endState() {
    std::cout << "Exit From EndGame" << std::endl;
}

void EndGame::initText() {

    if(!this->font.loadFromFile("./Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }
    gameOver.setFont(font);
    gameOver.setString("GAMEOVER");
    gameOver.setCharacterSize(130);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setPosition(390, 200);

    scorePoint.setFont(font);
    scorePoint.setString(std::to_string(score));
    scorePoint.setCharacterSize(90);
    scorePoint.setFillColor(sf::Color::White);
    sf::FloatRect textRect = scorePoint.getLocalBounds();
    scorePoint.setOrigin(textRect.left + textRect.width/2.0f,
                         textRect.top  + textRect.height/2.0f);
    scorePoint.setPosition(1298/2.f,1344/2.f -200);

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

void EndGame::setExtraInfo() {

    sf::FloatRect textRect;

    sCustomer.setFont(font);
    sCustomer.setString("Served Customer " + std::to_string(servedCustomer));
    sCustomer.setCharacterSize(50);
    sCustomer.setFillColor(sf::Color::White);
    textRect = sCustomer.getLocalBounds();
    sCustomer.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    sCustomer.setPosition(1298/2.f,700);

    sTable.setFont(font);
    sTable.setString("Served Table " + std::to_string(servedTable));
    sTable.setCharacterSize(50);
    sTable.setFillColor(sf::Color::White);
    textRect = sTable.getLocalBounds();
    sTable.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    sTable.setPosition(1298/2.f,800);

    gTable.setFont(font);
    gTable.setString("Gone Table " + std::to_string(goneTable));
    gTable.setCharacterSize(50);
    gTable.setFillColor(sf::Color::White);
    textRect = gTable.getLocalBounds();
    gTable.setOrigin(textRect.left + textRect.width/2.0f,
                     textRect.top  + textRect.height/2.0f);
    gTable.setPosition(1298/2.f,900);

}


