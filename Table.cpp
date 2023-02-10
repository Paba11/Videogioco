//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Table.h"


Table::Table() {
    this->state = CHOOSING;
    this->course = APPETIZER;
}

Table::~Table() {

}

int Table::getTavNum() {
    return this->tavNum;
}

void Table::setTavNum(int t) {
    this->tavNum = t;
}

const sf::Vector2f &Table::getPosition() const {
    return this->sprite.getPosition();
}

void Table::initTexture() {

}

void Table::initSprite() {
    this->sprite.setTexture(this->texture);
}

Dish *Table::getDish(int i) {
    return this->dish[i];
}

void Table::setDish(int i, Dish *d) {
    this->dish[i] = d;
}

void Table::update() {

}

void Table::render(sf::RenderTarget target) {

}

TableState Table::getState() {
    return this->state;
}

void Table::setState(int i) {
    switch(i)
    {
        case 1:
            this->state = CHOOSING;
        case 2:
            this->state = WAITING_TO_ORDER;
        case 3:
            this->state = WAITING_DISHES;
        case 4:
            this->state = EATING;
        case 5:
            this->state = ENDED;
    }
}

Order *Table::getOrder() const {
    return this->order;
}

void Table::setOrder() {

}

ActualCourse Table::getCourse() const {
    return this->course;
}

void Table::setCourse(int i) {
    switch(i)
    {
        case 1:
            this->course = APPETIZER;
        case 2:
            this->course = MAINCOURSE;
        case 3:
            this->course = DESSERT;
    }
}
