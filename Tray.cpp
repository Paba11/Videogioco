//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Tray.h"


Tray::Tray() {
    this->state = TrayState::EMPTY_TRAY;
    initTexture();
    initSprite();
    orderTaken = false;
    initRectangle();
}

Tray::~Tray() {
    Dish* d;
    for(int i = 0; !this->dishes.empty(); i++)
    {
        d = this->dishes.front();
        this->dishes.pop();
        delete d;
    }
}

void Tray::update() {

    updateAnimation();
}

void Tray::render(sf::RenderTarget &target) {
    target.draw(rectangle);
        if(orderTaken)
            target.draw(blockNotes);
}

void Tray::initRectangle() {

    rectangle.setSize({1300.f, 100.f});
    rectangle.setOrigin(650.f,50.f);
    rectangle.setPosition(650.f,1294.f);
    rectangle.setFillColor({40,33,33,255});

}



void Tray::setState(TrayState ts) {
    this->state = ts;
}


TrayState Tray::getState() {
    return this->state;
}

Dish *Tray::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Tray::setDish(Dish* d) {
    this->dishes.push(d);
}

std::queue<Dish *>& Tray::getDishes() {
    return this->dishes;
}

void Tray::setOrderTaken(bool t) {
    orderTaken = t;
}

void Tray::initSprite() {

    blockNotes.setTexture(*this->texture->getTexture("BlockNotes"));
    currentFrame = sf::IntRect (0,0,480,480);
    blockNotes.setTextureRect(this->currentFrame);
    blockNotes.setTextureRect({0,0,480,480});
    blockNotes.setScale(0.2f,0.2f);
    blockNotes.setPosition(50,1240);
}

void Tray::initTexture() {
    texture = new Textures();
}

void Tray::updateAnimation() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        this->currentFrame.left += 480.f;
        if (this->currentFrame.left >= 960)
            this->currentFrame.left = 0;

        animationTimer.restart();
        blockNotes.setTextureRect(this->currentFrame);
    }
}

