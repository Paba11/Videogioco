//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "Level.h"

Level::Level() {
    this->lvl = FIRST;
    this->isPassed = false;
    initVariables();
}

Level::~Level() {

}


void Level::initVariables() {
    switch(this->lvl)
    {
        case FIRST:
            this->initialHumor = LEVEL_ONE_HUMOR;
            this->customerArrival = LEVEL_ONE_ARRIVALS;
            this->maxTables = LEVEL_ONE_MAX_TABLES;
            this->totalCustomerNumber = LEVEL_ONE_TOT_CUSTOMERS;
            break;
        case SECOND:
            this->initialHumor = LEVEL_TWO_HUMOR;
            this->customerArrival = LEVEL_TWO_ARRIVALS;
            this->maxTables = LEVEL_TWO_MAX_TABLES;
            this->totalCustomerNumber = LEVEL_TWO_TOT_CUSTOMERS;
            break;
        case THIRD:
            this->initialHumor = LEVEL_THREE_HUMOR;
            this->customerArrival = LEVEL_THREE_ARRIVALS;
            this->maxTables = LEVEL_THREE_MAX_TABLES;
            this->totalCustomerNumber = LEVEL_THREE_TOT_CUSTOMERS;
            break;
    }
}

void Level::initLevel(Lvl l) {
    this->lvl = l;
    initVariables();
}

Lvl Level::getLevel() {
    return this->lvl;
}

void Level::setLevel(Lvl l) {
    this->lvl = l;
}

bool Level::getIsPassed() {
    return this->isPassed;
}

void Level::setIsPassed(bool t) {
    this->isPassed = t;
}

float Level::getCustomerArrival() {
    return this->customerArrival;
}

void Level::setCustomerArrival(float c) {
    this->customerArrival = c;
}

void Level::reduceTotalCustomerNumber() {
    this->totalCustomerNumber--;
}

int Level::getTotalCustomerNumber() {
    return this->totalCustomerNumber;
}

