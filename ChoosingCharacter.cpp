//
// Created by Ettore Righi on 02/03/23.
//

#include <iostream>
#include "ChoosingCharacter.h"
#include "Game.h"

ChoosingCharacter::ChoosingCharacter(sf::RenderWindow* window, std::stack <ProgramState*>* states) : ProgramState(window, states) {

    initVariables();
    initSprite();
    initWindow();
    initFonts();
    initButtons();
    this->chosedTexture = 0;
}

ChoosingCharacter::~ChoosingCharacter() {

}

void ChoosingCharacter::update() {
    updateMousePosition();
    updateAnimations();
    pollEvents();
    updateButtons();
    checkQuit();
}

void ChoosingCharacter::updateButtons() {

    for(auto it : this->buttons)
        it.second->update(this->mousePosView);

    if(buttons["EXIT"]->isPressed()) {   //FIXME close the application
        this->quit = true;
        this->window->close();
    }
    if(buttons["PLAY"]->isPressed()) {
        this->quit = true;
        this->states->push(new Game(this->window, this->states, abs(this->chosedTexture) % 2));
    }
    if(buttons["NEXT"]->isPressed()){
        this->chosedTexture++;
        changeTexture();
    }
    if(buttons["PREVIOUS"]->isPressed()){
        this->chosedTexture--;
        changeTexture();
    }

}

void ChoosingCharacter::render(sf::RenderTarget* target) {

    this->window->clear();
    this->renderButtons();
    this->window->draw(waiter);
    this->window->display();
    this->checkQuit();
}

void ChoosingCharacter::renderButtons() {

    for(auto it : this->buttons)
        it.second->render(*this->window);

}

void ChoosingCharacter::endState() {

}

void ChoosingCharacter::initVariables() {

    this->texture = new Textures();


}

void ChoosingCharacter::initButtons() {

    //TODO: move the play/exit button to the bottom of the window
    this->buttons["PLAY"] = new Button(800,1200,150,50,&this->font, "Play",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));
    this->buttons["EXIT"] = new Button(1000,1200,150,50,&this->font, "QUIT",
                                       sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));

    this->buttons["PREVIOUS"] = new Button(500,700,sf::Color(70,70,70,200),
                                           sf::Color(150,150,150,255),
                                           sf::Color(20,20,20,200));

    this->buttons["NEXT"] = new Button(800,700,sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,255),
                                       sf::Color(20,20,20,200));


    this->buttons["NEXT"]->triangle.setRotation(90);
    this->buttons["PREVIOUS"]->triangle.setRotation(-90);
}

void ChoosingCharacter::initFonts() {

    if(!this->font.loadFromFile("../Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }
}

void ChoosingCharacter::initWindow() {
    /*
     * Initialize the window of the game with a specific size and a name on the toolbar
     * It also limits the speed rate of the computer in order to not overflow the game
     * and not disable the vertical synchronization
     */

    videoMode.width = 1298;
    videoMode.height = 1344;
    this->window = new sf::RenderWindow(videoMode, "VideoGame");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void ChoosingCharacter::initSprite() {

    this->waiter.setTexture(*this->texture->getTexture("Waiter"));
    this->currentFrame = sf::IntRect (0,0,50,50);
    this->waiter.setTextureRect(this->currentFrame);
    this->waiter.setOrigin(25,25);
    this->waiter.setScale(4.f,4.f);
    this->waiter.setPosition(1298/2,1344/2);

}




void ChoosingCharacter::pollEvents() {

    while (window->pollEvent(ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void ChoosingCharacter::updateMousePosition() {
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void ChoosingCharacter::updateAnimations() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        this->currentFrame.left += 50.f;
        if (this->currentFrame.left >= 150)
            this->currentFrame.left = 0;

        this->animationTimer.restart();
        this->waiter.setTextureRect(this->currentFrame);
    }

}

void ChoosingCharacter::changeTexture() {

    if(abs(this->chosedTexture) % 2 == 0)
        this->waiter.setTexture(*this->texture->getTexture("Waiter"));
    else
        this->waiter.setTexture(*this->texture->getTexture("Waiter_Female_1"));
}


