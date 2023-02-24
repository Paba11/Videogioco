//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"

Table::Table() {
    this->state = CHOOSING;
    this->course = APPET;
    initSprite();
    initStoolTable();
}

Table::~Table() {

}

void Table::update() {

}

void Table::render(sf::RenderTarget &target) {

    target.draw(this->sprite);
}

void Table::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    // this->sprite.setTexture(this->texture);

    //this->sprite.setScale(3.5, 3.5);
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

Dish *Table::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Table::setDish(Dish *d) {
    this->dishes.push(d);
}

TableState Table::getState() {
    return this->state;
}

void Table::setState(int i) {
    switch(i)
    {
        case 0:
            this->state = CHOOSING;
        case 1:
            this->state = WAITING_TO_ORDER;
        case 2:
            this->state = WAITING_DISHES;
        case 3:
            this->state = EATING;
        case 4:
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
        case 0:
            this->course = APPET;
        case 1:
            this->course = MAINCOURSE;
        case 2:
            this->course = DESS;
        case 3:
            this->course = END;
    }
}

void Table::posStool(float x, float y) {
    stoolTable[0].sprite.setPosition(x -60,y+10);
    stoolTable[1].sprite.setPosition(x -60,y+75);
    stoolTable[2].sprite.setPosition(x +120,y+10);
    stoolTable[3].sprite.setPosition(x +120,y+75);

}

void Table::initStoolTable() {
    for(int i=0; i< numStoolsTable; i++){
        Stool s;
        stoolTable.push_back(s);
    }
}

std::queue<Dish *> Table::getDishes() {
    return this->dishes;
}

void Table::setCustomerNumber(int i) {
    this->customerNumber = i;
}

int Table::getCustomerNumber() {
    return this->customerNumber;
}
