//
// Created by Ettore Righi on 06/03/23.
//

#include <iostream>
#include "HowToPlay.h"

HowToPlay::HowToPlay(sf::RenderWindow *window, std::stack<ProgramState *> *states) : ProgramState(window, states) {
    initWindow();
    initVariables();
    initSprites();
    initFont();
    initButtons();
    initTexts();
}

HowToPlay::~HowToPlay() {

}

void HowToPlay::update() {

    updateMousePosition();
    updateButtons();
    updateAnimations();
    checkQuit();
}

void HowToPlay::updateButtons() {

    for (auto it: this->buttons)
        it.second->update(this->mousePosView);

    if (buttons["BACK"]->isPressed()) {   //Fixme it close the app
        this->quit = true;
    }

}

void HowToPlay::render(sf::RenderTarget *target) {

    this->window->clear();
    //this->window->draw(this->background);

    this->window->draw(moveWaiter);
    this->window->draw(waiter);
    this->window->draw(wasd);

    this->window->draw(interactions);

    this->window->draw(jSprite);
    this->window->draw(jText);

    this->window->draw(kSprite);
    this->window->draw(kText);

    this->window->draw(lSprite);
    this->window->draw(lText);

    renderButtons();
    this->window->display();

}

void HowToPlay::renderButtons() {

    for(auto it : this->buttons)
        it.second->render(*this->window);

}

void HowToPlay::endState() {

    std::cout << "Exit from HowToPlay" << std::endl;
}

void HowToPlay::initVariables() {

    this->texture = new Textures();

}

void HowToPlay::initWindow() {

    videoMode.width = 1298;
    videoMode.height = 1344;
    this->window->create(this->videoMode, "Videogame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void HowToPlay::initFont() {

    if(!this->font.loadFromFile("../Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }

}

void HowToPlay::initButtons() {

    this->buttons["BACK"] = new Button(1000,1200,150,50,&this->font, "BACK",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));

}

void HowToPlay::initTexts() {

    setText(&moveWaiter);
    moveWaiter.setString("Move the waiter");
    moveWaiter.setPosition(320,50);


    setText(&interactions);
    this->interactions.setString("Interactions");
    this->interactions.setPosition(320, 500);

    this->jText.setString("Press J to take or leave order and to interact with the customer");
    this->jText.setPosition(300,700);
    this->jText.setFont(this->font);

    this->kText.setString("Press K to take the dishes");
    this->kText.setPosition(300,800);
    this->kText.setFont(this->font);

    this->lText.setString("Press L to leave the dishes");
    this->lText.setPosition(300,900);
    this->lText.setFont(this->font);



}

void HowToPlay::initSprites() {

    this->background.setTexture(*this->texture->getTexture("ChoosingCharacterBackground"));
    initWasdSprite();
    initWaiterSprite();

    this->jSprite.setTexture(*this->texture->getTexture("jKey"));
    this->jSprite.setScale(3.f, 3.f);
    this->jSprite.setPosition(100,700);

    this->kSprite.setTexture(*this->texture->getTexture("kKey"));
    this->kSprite.setScale(3.f, 3.f);
    this->kSprite.setPosition(100,800);

    this->lSprite.setTexture(*this->texture->getTexture("lKey"));
    this->lSprite.setScale(3.f, 3.f);
    this->lSprite.setPosition(100,900);


}

void HowToPlay::updateAnimations() {

    if(this->waiterAnimationTimer.getElapsedTime().asSeconds() >= 0.3f) { //Waiter
        //Idle animation

        this->waiterCurrentFrame.left += 50.f;
        if (this->waiterCurrentFrame.left >= 150)
            this->waiterCurrentFrame.left = 0;

        this->waiterAnimationTimer.restart();
        this->waiter.setTextureRect(this->waiterCurrentFrame);
    }

    if(this->wasdAnimationTimer.getElapsedTime().asSeconds() >= 1.5f) { //Waiter
        //Idle animation

        this->wasdCurrentFrame.left += 70.f;
        if (this->wasdCurrentFrame.left >= 280) {
            this->wasdCurrentFrame.left = 0;
            this->waiterCurrentFrame.top = 200.f;
        }
        if(wasdCurrentFrame.left / 70 == 1)
            this->waiterCurrentFrame.top = 100.f;
        else if(wasdCurrentFrame.left / 70 == 2)
            this->waiterCurrentFrame.top = 50.f;
        else if(wasdCurrentFrame.left / 70 == 3)
            this->waiterCurrentFrame.top = 150.f;

        this->wasdAnimationTimer.restart();
        this->waiter.setTextureRect(this->waiterCurrentFrame);
        this->wasd.setTextureRect(this->wasdCurrentFrame);

    }
}

void HowToPlay::initWaiterSprite() {


    this->waiter.setTexture(*this->texture->getTexture("Waiter"));
    this->waiterCurrentFrame = sf::IntRect (0,200.f,50,50);
    this->waiter.setTextureRect(this->waiterCurrentFrame);
    this->waiter.setOrigin(25,25);
    this->waiter.setScale(4.f,4.f);
    this->waiter.setPosition(500,350);

}

void HowToPlay::initWasdSprite() {

    this->wasd.setTexture(*this->texture->getTexture("WASD"));
    this->wasdCurrentFrame = sf::IntRect (0,0,70,37);
    this->wasd.setTextureRect(this->wasdCurrentFrame);
    this->wasd.setScale(3.f,3.f);
    this->wasd.setPosition(100,350);

}

void HowToPlay::updateMousePosition() {

    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void HowToPlay::setText(sf::Text* text) {

    text->setFont(this->font);
    text->setFillColor(sf::Color::White);
    text->setCharacterSize(100);
    text->setOutlineThickness(10);
    text->setOutlineColor(sf::Color::Black);
    text->setPosition(320, 500);


}
