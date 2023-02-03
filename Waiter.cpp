//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "Waiter.h"

Waiter::Waiter() {
    initTexture();
    initSprite();
    this->state = STANDING;
    this->speed = 10;
    this->isClose = false;
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

    this->sprite.setScale(0.3f, 0.3f);
}

void Waiter::updateMovement(sf::Event ev) {
    switch(this->state)
    {
        case STANDING:
            if (ev.key.code == sf::Keyboard::A)
            {
                this->state = MOVING_LEFT;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::D)
            {
                this->state = MOVING_RIGHT;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::W)
            {
                this->state = MOVING_UP;
                //setAnimation();
                move();
            }
            else if (ev.key.code == sf::Keyboard::S)
            {
                this->state = MOVING_DOWN;
                //setAnimation();
                move();
            }
            break;
    }
    this->state = STANDING;
    //setAnimation();
}

void Waiter::move() {
    switch(this->state)
    {
        case MOVING_LEFT:
            this->sprite.move(this->speed * (-1.0f), this->speed * (0.f));
            break;
        case MOVING_RIGHT:
            this->sprite.move(this->speed * (1.0f), this->speed * (0.f));
            break;
        case MOVING_UP:
            this->sprite.move(this->speed * (0.f), this->speed * (-1.0f));
            break;
        case MOVING_DOWN:
            this->sprite.move(this->speed * (0.f), this->speed * (1.0f));
            break;
        case STANDING:
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

void Waiter::interact(sf::Event ev) {
    switch(ev.type)
    {
        case ev.KeyPressed:
            if(ev.key.code == sf::Keyboard::J)
            {
                if(this->order && distanceT())
                    giveOrder();
                else if(distanceK())
                    takeOrder();
            }
            else if(ev.key.code == sf::Keyboard::K)
            {
                if(this->dish && distanceT())
                    putDown();
                else if(distanceK())
                    pickUp();
            }
            isClose = false;
            break;

    }
}

bool Waiter::distanceK() {

}

void Waiter::pickUp() {

}

void Waiter::putDown() {

}

void Waiter::takeOrder() {

}

void Waiter::giveOrder() {

}

bool Waiter::distanceT() {
    return false;
}

const sf::Vector2f &Waiter::getPosition() const {
    return this->sprite.getPosition();
}


