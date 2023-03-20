//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"

Table::Table() {
    numStoolsTable = 4;
    state = TableState::CHOOSING;
    course = Current::APPETIZER;
    isReady = false;
    isOccupied = false;
    customerNumber = 0;
    cicle = true;
    chosenTable = false;
    initSprite();
    initStoolTable();

}

Table::~Table() {

}

void Table::update() {
    if(this->isOccupied)
    {
        switch(this->state)
        {
            case TableState::CHOOSING:
                ordering();
                break;
            case TableState::WAITING_TO_ORDER:
                break;
        }
    }
}

void Table::render(sf::RenderTarget &target) {
    target.draw(sprite);
    if(chosenTable)
        target.draw(interactionSquare);
}

void Table::initSprite() {

    interactionSquare.setSize({62,62});
    interactionSquare.setOrigin(31,31);
    interactionSquare.setOutlineThickness(1);
    interactionSquare.setFillColor(sf::Color::Transparent);
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

std::shared_ptr<Order> Table::getOrder() {
    return order;
}

void Table::setOrder(const std::shared_ptr<Order>& ord) {
    order.reset();
    order = ord;
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

void Table::receivingCustomers(std::vector<Customer>& c) {
    this->customers.reserve(c.size());
    this->customerNumber += c.size();
    this->isOccupied = true;
    this->timer.restart();
    std::move(c.begin(), c.end(), std::back_inserter(this->customers));
    c.clear();
}

void Table::setIsOccupied(bool t) {
    this->isOccupied = t;
}

bool Table::getIsOccupied() {
    return this->isOccupied;
}

void Table::setCustomers(std::vector<Customer> &cust) {
    /*
     * Move all the elements of the passed vector to the one of te customer
     */
    this->customers.reserve(cust.size());
    std::move(cust.begin(), cust.end(), std::back_inserter(this->customers));
    cust.clear();
}

std::vector<Customer> &Table::getCustomers() {
    return this->customers;
}

void Table::ordering() {
    if(this->timer.getElapsedTime().asSeconds() > TIME_TO_CHOOSE)
    {
        this->state = TableState::WAITING_TO_ORDER;
    }
}

void Table::setIsReady(bool t) {
    this->isReady = t;
}

bool Table::getIsReady() {
    return this->isReady;
}

std::vector<Stool> &Table::getStoolTable() {
    return this->stoolTable;
}

void Table::updateBox() {

    if(chosenTable) {
        interactionSquare.setFillColor(boxOpacity);

        if(boxOpacity.a == 255)
            cicle = false;
        if(boxOpacity.a == 0)
            cicle = true;
        if(cicle)
            boxOpacity.a += 5;
        else
            boxOpacity.a-= 5;


    }

}

void Table::setTable() {

    sprite.setOrigin(30,32);
    interactionSquare.setPosition(sprite.getPosition().x,sprite.getPosition().y - 100);

}

void Table::setChosenTable() {

    this->chosenTable = true;

}

sf::RectangleShape Table::getInteractionSquare() {
    return this->interactionSquare;
}

bool Table::getChosenTable() {
    return chosenTable;
}
