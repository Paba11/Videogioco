//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Chef.h"


Chef::Chef() {
    initSprite();
    this->state = WAIT;
}

Chef::~Chef() {
    delete this->dish;
}


void Chef::initSprite() {
    /*
     * Set the texture on the sprite, resize it and locate the chef in the right position
     */
    this->texture = new Textures(); //FIXME move the texture pointer in the GameCharachter class (also for waiter)
    this->sprite.setTexture(*this->texture->getTexture("Chef"));
    this->currentFrame = sf::IntRect (0,0,40,40);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.5f, 3.5f);
    this->sprite.setPosition(1100,400);

    //this->sprite.setPosition();
}

void Chef::setAnimation() {

    if(this->state == WAIT)
        this->currentFrame.top = 0.f;

    else if(this->state == COOK)
        this->currentFrame.top = 40.f;

    this->sprite.setTextureRect(this->currentFrame);
}

void Chef::setDishes(Dish& d) {
    this->dishes.push_back(&d);
}

Dish *Chef::getDish() {
    Dish* d = this->dishes.back();
    this->dishes.pop_back();
    return d;
}

void Chef::cook() {
    //TODO: SELECT THE CURRENT DISH AND COOK IT FOR THE RIGHT TIME
    switch(order->getCurrent())
    {
        //case ::APPETIZER:
            //if (this->clock.getElapsedTime() >= this->order->getAppetizers(i)) {

        //} else
            updateAnimations();
    }
}

void Chef::setOrder() {
    order = this->kitchen->getReadyOrder();
}

std::shared_ptr<Order> Chef::getOrder() {
    std::shared_ptr<Order> o = std::move(order);
    order = nullptr;
    return o;
}

void Chef::checkOrder() {
    if(!kitchen->getReadyOrders().empty())
    {
        setOrder();
        state = COOK;
        setAnimation();
        clock.restart();
    }
}

void Chef::update() {

    if(!order && state == WAIT)
    {
        checkOrder();
    }
    if(state == COOK)
    {
        cook();
    }
    setAnimation();
    updateAnimations();
}

void Chef::updateAnimations() {

    if(animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        currentFrame.left += 40.f;
        if (currentFrame.left >= 120)
            currentFrame.left = 0;

        animationTimer.restart();
        sprite.setTextureRect(currentFrame);
    }
}

void Chef::setKitchen(Kitchen *k) {
    kitchen = k;
}

Kitchen *Chef::getKitchen() {
    return kitchen;
}

