//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"


Kitchen::Kitchen() {
    state = DishState::EMPTY;
    counter = std::make_unique<Counter>();
    initSprite();

}

Kitchen::~Kitchen() {
    Dish* d;
    for(int i=0; !dishes.empty(); i++)
    {
        d = dishes.front();
        dishes.pop();
        delete d;
    }
}

void Kitchen::insertNewOrder(const std::shared_ptr<Order>& o) {
    newOrders.push(o);
}

std::shared_ptr<Order> Kitchen::makeNewOrder() {
    current = newOrders.front();
    this->newOrders.pop();
    return this->current;
}

void Kitchen::initSprite() {

    this->sprite.setTexture(*this->texture->getTexture("Kitchen"));
    this->sprite.setPosition(1200,420);
    this->sprite.setScale(3.f,3.f);
}

bool Kitchen::getIsEmptyPlates() {
    return this->isEmptyPlates;
}

void Kitchen::setIsEmptyPlates(bool t) {
    this->isEmptyPlates = t;
}

const sf::Vector2f Kitchen::getPosition() const {
    return this->sprite.getPosition();
}

Dish *Kitchen::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Kitchen::setDish(Dish* d) {
    this->dishes.push(d);
}

void Kitchen::update() {

}

void Kitchen::render(sf::RenderTarget& target) {
        target.draw(this->sprite);
}

void Kitchen::setState(DishState ds) {
    state = ds;
}

DishState Kitchen::getState() {
    return this->state;
}

const sf::FloatRect Kitchen::getBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Sprite Kitchen::getSprite() {
    return this->sprite;
}

std::queue<Dish *> &Kitchen::getDishes() {
    return this->dishes;
}

std::shared_ptr<Order> Kitchen::getReadyOrder() {
    current = nullptr;
    if(!readyOrders.empty())
    {
        current = readyOrders.front();
        readyOrders.pop();
    }
    return current;
}

void Kitchen::setReadyOrder(std::shared_ptr<Order> o) {
    readyOrders.push(o);
}

void Kitchen::getWaitingOrder(int tavNum) {
    /*
     * Insert the order that was waiting in the queue of the not ready tables inside the readyQueue
     */
    int i = 100;
    std::queue<std::shared_ptr<Order>> tmp;
    while(i != tavNum && !waitingOrders.empty())
    {
        i = waitingOrders.front()->getTableNumber();
        tmp.push(waitingOrders.front());
        waitingOrders.pop();
    }
    if (i == tavNum)
    {
        while(tmp.size()!=1)
        {
            waitingOrders.push(tmp.front());
            tmp.pop();
        }
        readyOrders.push(tmp.front());
        tmp.pop();
    }
    else
    {
        while(!tmp.empty())
        {
            waitingOrders.push(tmp.front());
            tmp.pop();
        }
    }
}

void Kitchen::setWaitingOrder() {
    this->waitingOrders.push(this->current);
    this->current = nullptr;
}

std::queue<std::shared_ptr<Order>> &Kitchen::getReadyOrders() {
    return this->readyOrders;
}

Counter *Kitchen::getCounter() {
    return counter.get();
}
