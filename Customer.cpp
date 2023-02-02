//
// Created by Paolo Sbarzagli on 02/02/23.
//

#include "Customer.h"

Customer::Customer() {
    this->mood = GOOD;
    this->patience = 100;

}

Customer::~Customer() {

}

void Customer::update() {
    GameCharacter::update();
}

void Customer::render() {

}
