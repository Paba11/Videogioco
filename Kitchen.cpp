//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"

Kitchen::Kitchen() {

}

Kitchen::~Kitchen() {
    delete this->dish;
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
