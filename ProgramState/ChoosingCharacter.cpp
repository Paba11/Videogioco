//
// Created by Ettore Righi on 02/03/23.
//

#include <iostream>
#include "ChoosingCharacter.h"
#include "Game.h"

ChoosingCharacter::ChoosingCharacter(sf::RenderWindow* window, std::stack <ProgramState*>* states) : ProgramState(window, states) {

    initFonts();
    initText();
    initSprite();
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

    if(!this->quit) { //fixme
        this->window->clear();
        this->window->draw(this->background);
        this->window->draw(this->text);
        this->renderButtons();
        this->window->draw(waiter);
        this->window->display();
    }
}

void ChoosingCharacter::renderButtons() {

    for(auto it : this->buttons)
        it.second->render(*this->window);

}

void ChoosingCharacter::endState() {

    std::cout << "Exit from ChoosingCharacter" << std::endl;
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



void ChoosingCharacter::initSprite() {

    this->waiter.setTexture(*this->textures->getTexture("Waiter"));
    this->currentFrame = sf::IntRect (0,0,50,50);
    this->waiter.setTextureRect(this->currentFrame);
    this->waiter.setOrigin(25,25);
    this->waiter.setScale(4.f,4.f);
    this->waiter.setPosition(1298/2,1344/2);

    this->background.setTexture(*this->textures->getTexture("ChoosingCharacterBackground"));

}




void ChoosingCharacter::pollEvents() {

    while (window->pollEvent(ev))
    {
        switch (ev.type)
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
        this->waiter.setTexture(*this->textures->getTexture("Waiter"));
    else
        this->waiter.setTexture(*this->textures->getTexture("Waiter_Female_1"));
}

void ChoosingCharacter::initText() {

    this->text.setString("Choose your waiter");
    this->text.setFont(this->font);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(100);
    this->text.setOutlineThickness(10);
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setPosition(280, 100);
}


