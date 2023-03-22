//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"

Table::Table() {
    numStoolsTable = 4;
    state = TableState::CHOOSING;
    course = Current::APPETIZER;
    isOccupied = false;
    customerNumber = 0;
    cicle = true;
    chosenTable = false;
    initSprite();
    initStoolTable();
    isSit = false;

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

        if(customers.size() > 0){

            for(auto i : customers)
                i.update();
        }
    }
}

void Table::render(sf::RenderTarget &target) {
    target.draw(sprite);

    for(int i = 0 ;i < 4; i++)
        target.draw(dishesPlace[i]);

    if(chosenTable || state == TableState::WAITING_TO_ORDER)
        target.draw(interactionSquare);

    if(customers.size() > 0){
        for(int i = customers.size() -1 ; i >= 0; i--)
            target.draw(customers[i].sprite);
    }


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
    customers.reserve(c.size());
    customerNumber += c.size();
    isOccupied = true;
    timer.restart();
    std::move(c.begin(), c.end(), std::back_inserter(customers));
    c.clear();
}

void Table::setIsOccupied(bool t) {
    isOccupied = t;
}

bool Table::getIsOccupied() {
    return this->isOccupied;
}

void Table::setCustomers(std::vector<Customer>& cust) {
    /*
     * Move all the elements of the passed vector to the one of te customer
     */
    customers.reserve(cust.size());
    std::move(cust.begin(), cust.end(), std::back_inserter(customers));
    cust.clear();
    int i =  0;
    for(auto &it : customers){
        if( i % 2 == 0)
            it.movingStatus = Move::MOVING_RIGHT;
        else if(i % 2 == 1)
            it.movingStatus = Move::MOVING_LEFT;
        i++;
    }
}

std::vector<Customer> &Table::getCustomers() {
    return customers;
}

void Table::ordering() {
    if(timer.getElapsedTime().asSeconds() > TIME_TO_CHOOSE && isSit)
    {
        state = TableState::WAITING_TO_ORDER;
        std::cout << std::endl << "Ready to order" << std::endl;
    }
}

std::vector<Stool> &Table::getStoolTable() {
    return this->stoolTable;
}

void Table::updateBox() {

    if(chosenTable || state == TableState::WAITING_TO_ORDER) {
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

    sprite.setOrigin(30,25);
    interactionSquare.setPosition(sprite.getPosition().x,sprite.getPosition().y - 100);
    setDishesPlace();

}

void Table::setChosenTable(bool t) {
    this->chosenTable = t;

}

sf::RectangleShape Table::getInteractionSquare() {
    return this->interactionSquare;
}

bool Table::getChosenTable() {
    return chosenTable;
}

std::vector<sf::RectangleShape> Table::getDishesPlace() {
    return this->dishesPlace;
}

void Table::setDishesPlace() {

    for(int i = 0; i < 4; i++){
        sf::RectangleShape rectangle;

        rectangle.setSize(this->dishHitbox);
        rectangle.setOrigin(20.f,20.f);
        rectangle.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
        rectangle.setOutlineThickness(1.f);
        rectangle.setFillColor(sf::Color::Transparent);
        dishesPlace.push_back(rectangle);
    }
    float offSetX = 35;
    float offSetY = 25;
    this->dishesPlace[0].setPosition(sprite.getPosition().x-offSetX, sprite.getPosition().y-offSetY);
    this->dishesPlace[1].setPosition(sprite.getPosition().x+offSetX, sprite.getPosition().y-offSetY);
    this->dishesPlace[2].setPosition(sprite.getPosition().x-offSetX, sprite.getPosition().y+offSetY);
    this->dishesPlace[3].setPosition(sprite.getPosition().x+offSetX, sprite.getPosition().y+offSetY);
}

void Table::restartTimer() {
    timer.restart();
}

sf::Time Table::getElapsedTime() {
    return timer.getElapsedTime();
}

void Table::setIsSit(bool t) {
    this->isSit = t;
}

bool Table::getIsSit() {
    return this->isSit;
}

