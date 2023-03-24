//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Chef.h"


Chef::Chef() {
    initSprite();
    this->state = WAIT;
    isReady = false;
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
    dishes.push_back(&d);
}

Dish *Chef::getDish() {
    Dish* d = dishes.back();
    dishes.pop_back();
    return d;
}

void Chef::cook() {

    if (this->clock.getElapsedTime().asSeconds() >= time && kitchen->getState() != DishState::FULL)
    {
        isReady = true;
        kitchen->setState(DishState::FULL);
        for(auto & it: dishes)
        {
            kitchen->setDish(it);
        }
        dishes.clear();
        state = WAIT;

        if(order->getCurrent() != Current::END)
        {
            kitchen->setWaitingOrder();
        }
        else
            bill->setFinishedOrder(order);

        order = nullptr;
    }
}

void Chef::setOrder(std::shared_ptr<Order>& o) {
    order = o;
}

std::shared_ptr<Order>& Chef::getOrder() {
    return order;
}

void Chef::checkOrder() {
    if(!kitchen->getReadyOrders().empty() && state != COOK)
    {
        setOrder(kitchen->getReadyOrder());
        kitchen->getReadyOrders().pop();
        state = COOK;
        setAnimation();
        clock.restart();
        createObjects();
        calculateTime();
    }
}

void Chef::update() {
    checkOrder();
    setState();
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

void Chef::setKitchen(std::shared_ptr<Kitchen>& k) {
    kitchen.reset();
    kitchen = k;
}

const std::shared_ptr<Kitchen>& Chef::getKitchen() {
    return kitchen;
}

void Chef::setState() {
    if(state == COOK)
    {
        cook();
    }
}

void Chef::createObjects() {
    switch(order->getCurrent())
    {
        case Current::APPETIZER:
            order->setCurrent(Current::MAIN_DISH);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new Appetizer(order->getAppetizers().back());
                dishes.push_back(dish);
                order->getAppetizers().pop_back();
            }
            break;
        case Current::MAIN_DISH:
            order->setCurrent(Current::DESSERT);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new MainCourse(order->getMainCourses().back());
                dishes.push_back(dish);
                order->getMainCourses().pop_back();
            }
            break;
        case Current::DESSERT:
            order->setCurrent(Current::END);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new Dessert(order->getDesserts().back());
                dishes.push_back(dish);
                order->getDesserts().pop_back();
            }
            break;
    }
    calculateTime();
}

void Chef::calculateTime() {
    time = 0;
    for(auto & it: dishes)
    {
        if(it->getPreparationTime() > time)
            time = it->getPreparationTime();
    }
}

void Chef::setBill(std::shared_ptr<Bill>& b) {
    bill.reset();
    bill = b;
}

