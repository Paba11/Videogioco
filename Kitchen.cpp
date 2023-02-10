//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"


Kitchen::Kitchen() {
    this->state = EMPTY;
}

Kitchen::~Kitchen() {
    for(int i=0; i < MAX_DISHES; i++)
    {
        delete this->dish[i];
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

void Kitchen::initTexture() {

}

void Kitchen::initSprite() {

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
    return this->dish[i];
}

void Kitchen::setDish(int i, Dish* d) {
    this->dish[i] = d;
}

void Kitchen::update() {

}

void Kitchen::render(sf::RenderTarget target) {

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
