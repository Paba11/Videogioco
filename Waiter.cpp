//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"

Waiter::Waiter() {
    initTexture();
    initSprite();
    this->state = STANDING;
}

Waiter::~Waiter() {

}

void Waiter::initTexture() {
    if (!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Waiter::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setTexture(this->texture);

    this->sprite.setScale(0.5f, 0.5f);
}

void Waiter::updateMovement(sf::Event ev) {
    switch(this->state)
    {
        case STANDING:
            if (ev.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                this->state = MOVING_LEFT;
                setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                this->state = MOVING_RIGHT;
                setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                this->state = MOVING_UP;
                setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                this->state = MOVING_DOWN;
                setAnimation();
                move();
            }
            break;
    }
    this->state = STANDING;
    setAnimation();
}

void Waiter::move() {
    switch(this->state)
    {
        case MOVING_LEFT:
            this->sprite.move(-1.0f, 0.f);
            break;
        case MOVING_RIGHT:
            this->sprite.move(1.0f, 0.f);
            break;
        case MOVING_UP:
            this->sprite.move(0.f, 1.0f);
            break;
        case MOVING_DOWN:
            this->sprite.move(0.f, -1.0f);
            break;
    }
}

void Waiter::setAnimation() {
    switch(this->state)
    {
        case MOVING_LEFT:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_RIGHT:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_UP:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case MOVING_DOWN:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
        case STANDING:
            if(!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
            {
                std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
            }
            break;
    }
}

