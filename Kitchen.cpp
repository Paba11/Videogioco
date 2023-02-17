//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"


Kitchen::Kitchen() {
    this->state = EMPTY;
    initSprite();

}

Kitchen::~Kitchen() {
    for(int i=0; !this->dishes.empty(); i++)
    {
        delete this->dishes[i];
    }
    delete this->current;
}

void Kitchen::insertNewOrder(Order *o) {
    this->newOrders.push(o);
}

Order* Kitchen::makeNewOrder() {
    this->current = this->newOrders.front();
    this->newOrders.pop();
    return this->current;
}

void Kitchen::initSprite() {

    this->sprite.setTexture(*this->texture->getTexture("Kitchen"));
    this->sprite.setPosition(1020,170);
    this->sprite.setScale(3.f,3.f);
}

void Kitchen::insertWaitingOrder(Order *order) {


}

Order *Kitchen::makeWaitingOrder() {
    return nullptr;
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

Dish *Kitchen::getDish(int i) {
    return this->dishes[i];
}

void Kitchen::setDish(Dish* d) {
    this->dishes.push_back(d);
}

void Kitchen::update() {

}

void Kitchen::render(sf::RenderTarget& target) {
        target.draw(this->sprite);
}

void Kitchen::setState(int i) {
    switch(i)
    {
        case 1:
            this->state = EMPTY;
        case 2:
            this->state = FULL;
    }
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

std::vector<Dish *> &Kitchen::getDishes() {
    return this->dishes;
}

Order* Kitchen::getReadyOrder() {
    this->current = nullptr;
    if(!this->readyOrders.empty())
    {
        this->current = this->readyOrders.front();
        this->readyOrders.pop();
    }
    return this->current;
}

void Kitchen::setReadyOrder(Order *o) {
    this->readyOrders.push(o);
}

void Kitchen::getWaitingOrder(int tavNum) {
    /*
     * Insert the order that was waiting in the queue of the not ready tables inside the readyQueue
     */
    int i = 100;
    std::queue<Order*> tmp;
    while(i != tavNum && !this->waitingOrders.empty())
    {
        i = this->waitingOrders.front()->getTavNum();
        tmp.push(this->waitingOrders.front());
        this->waitingOrders.pop();
    }
    if (i == tavNum)
    {
        while(tmp.size()!=1)
        {
            this->waitingOrders.push(tmp.front());
            tmp.pop();
        }
        this->readyOrders.push(tmp.front());
        tmp.pop();
    }
    else
    {
        while(!tmp.empty())
        {
            this->waitingOrders.push(tmp.front());
            tmp.pop();
        }
    }
}

void Kitchen::setWaitingOrder() {
    this->waitingOrders.push(this->current);
    this->current = nullptr;
}
