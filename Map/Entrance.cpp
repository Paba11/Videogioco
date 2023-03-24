//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "Entrance.h"

Entrance::Entrance() {
    initTexture();
    initSprite();
    this->isCustomer = false;
    this->customerReceived = false;


}

Entrance::~Entrance() {
    delete texture;
}

void Entrance::initSprite() {

    barrier1.setTexture(*this->texture->getTexture("Barrier"));
    barrier2.setTexture(*this->texture->getTexture("Barrier"));
    barrier1.setPosition(1200.f,860.f);
    barrier1.setScale(0.1f,0.1f);
    barrier2.setPosition(1200.f,940.f);
    barrier2.setScale(0.1f,0.1f);

    welcomeSquare.setSize({62,62});
    welcomeSquare.setOrigin(31,31);
    welcomeSquare.setOutlineThickness(1);
    welcomeSquare.setFillColor(sf::Color::Transparent);
    welcomeSquare.setPosition(920,910);

    cornerSprite.setTexture(*this->texture->getTexture("Customer1"));
    cornerSprite.setTextureRect({0, 0, 32, 32});
    cornerSprite.setOrigin(16,16);
    cornerSprite.setPosition(welcomeSquare.getPosition().x + 31, welcomeSquare.getPosition().y - 31);

}

void Entrance::initTexture() {
    this->texture = new Textures();

}

void Entrance::setSprite(sf::Sprite& e) {
    this->sprite = e;
}

sf::Sprite Entrance::getSprite() {
    return this->sprite;
}

void Entrance::setIsCustomer(bool t) {
    this->isCustomer = t;
}

bool Entrance::getIsCustomer() {
    return this->isCustomer;
}

void Entrance::renderBarrier(sf::RenderTarget &target, int barrierNumber) {

    if(barrierNumber == 1)
        target.draw(barrier1);
    else
        target.draw(barrier2);
}

void Entrance::render(sf::RenderTarget &target) {
    if(customerReceived) {
        target.draw(this->welcomeSquare);
        target.draw(cornerSprite);
    }
}

void Entrance::updateBox() {

    if(customerReceived) {
        welcomeSquare.setFillColor(this->boxOpacity);

        if(boxOpacity.a == 255)
            cicle = false;
        if(boxOpacity.a == 0)
            cicle = true;
        if(cicle)
            boxOpacity.a += 5;
        else
            boxOpacity.a-= 5;
    }

}

sf::RectangleShape &Entrance::getWelcomeSquare() {
    return this->welcomeSquare;
}

void Entrance::setCustomerReceived(bool t) {
    this->customerReceived = t;
}




