//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Chef.h"


Chef::Chef() {

}

Chef::~Chef() {
    delete this->dish;
    delete this->order;
}

void Chef::initTexture() {
    if (!this->texture.loadFromFile("../Textures/MaleWaiter.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    };
}

void Chef::initSprite() {
    /*
     * Set the texture on the sprite, resize it and locate the chef in the right position
     */

    this->sprite.setTexture(this->texture);

    this->sprite.setScale(0.3f, 0.3f);

    //this->sprite.setPosition();
}

void Chef::updateMovement(int action) {
    switch(action)
    {
        case 1:

    }

}

void Chef::move() {

}

void Chef::setAnimation() {

}
