//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"

OrderState::OrderState() {
    initTexture();
    initSprite();
}

OrderState::~OrderState() {
    delete this->order;
}

Order *OrderState::getOrder() {
    return this->order;
}

void OrderState::initTexture() {

}

void OrderState::initSprite() {

}
