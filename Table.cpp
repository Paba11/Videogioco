//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"

Table::Table() {
    this->numStoolsTable = 4;
    this->state = CHOOSING;
    this->course = APPETIZER;
    this->isOccupied = false;
    this->customerNumber = 0;
    initSprite();
    initStoolTable();
}

Table::~Table() {
    Customer* deletion;
    while(!this->customers.empty())
    {
        deletion = this->customers.back();
        this->customers.pop_back();
        delete deletion;
    }
}

void Table::update() {
    if(isOccupied)
    {

    }
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

void Table::setState(TableState s) {
    this->state = s;
}

Order *Table::getOrder() const {
    return this->order;
}

void Table::setOrder() {

}

Current Table::getCourse() const {
    return this->course;
}

void Table::setCourse(Current c) {
    this->course = c;
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

void Table::receivingCustomers(Customer* c) {
    this->customers.push_back(c);
    this->customerNumber += 1;
}

void Table::ordering() {

}

void Table::setIsOccupied(bool t) {
    this->isOccupied = t;
}

bool Table::getIsOccupied() {
    return this->isOccupied;
}
