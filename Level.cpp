//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "Level.h"

Level::Level() {
    lvl = Lvl::FIRST_TABLE;
    clock.restart();
    totalCustomerNumber = 0;
    initVariables();
}

Level::~Level() {

}


void Level::initVariables() {
    switch(lvl)
    {
        case Lvl::FIRST_TABLE:
            customerArrival = FIRST_TABLE_ARRIVAL;
            difficulty = LEVEL_ONE_DIFFICULTY;
            lvl = Lvl::FIRST;
            break;
        case Lvl::FIRST:
            customerArrival = LEVEL_ONE_ARRIVALS;
            difficulty = LEVEL_ONE_DIFFICULTY;
            break;
        case Lvl::SECOND:
            customerArrival = LEVEL_TWO_ARRIVALS;
            difficulty = LEVEL_TWO_DIFFICULTY;
            break;
        case Lvl::THIRD:
            customerArrival = LEVEL_THREE_ARRIVALS;
            difficulty = LEVEL_THREE_DIFFICULTY;
            break;
    }
}

void Level::initLevel(Lvl l) {
    lvl = l;
    initVariables();
}

Lvl Level::getLevel() {
    return lvl;
}

void Level::setLevel(Lvl l) {
    lvl = l;
}

float Level::getCustomerArrival() {
    return customerArrival;
}

void Level::setCustomerArrival(float c) {
    customerArrival = c;
}

void Level::addTotalCustomerNumber() {
    totalCustomerNumber++;
}

int Level::getTotalCustomerNumber() {
    return totalCustomerNumber;
}

void Level::update() {
    if(totalCustomerNumber > 20 && lvl == Lvl::FIRST)
    {
        lvl = Lvl::SECOND;
        initVariables();
    }
    else if(totalCustomerNumber > 40 && lvl == Lvl::SECOND)
    {
        lvl = Lvl::THIRD;
        initVariables();
    }
    if(clock.getElapsedTime().asSeconds() > 1200)
    {
        customerArrival = 40;
    }
}

float Level::getDifficulty() {
    return difficulty;
}

