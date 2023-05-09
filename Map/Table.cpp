//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"

Table::Table() {

    initTexture();
    initSprite();
    numStoolsTable = 4;
    state = TableState::CHOOSING;
    course = Current::APPETIZER;
    isOccupied = false;
    customerNumber = 0;
    cicle = true;
    chosenTable = false;
    initStoolTable();
    isSit = false;
    humor = INITIAL_HUMOR;
    isSetFinalScore = false;
    isNotSatisfied = false;
}

Table::~Table() {

}

void Table::update() {
    if(isOccupied)
    {
        if(state == TableState::CHOOSING)
            ordering();

        if(state == TableState::IS_LEAVING)
            leaveTable();

        if(state == TableState::EATING)
            eating();

        if(state != TableState::CHOOSING && state != TableState::IS_LEAVING)

        if(customers.size() > 0){

            for(auto &i : customers)
                i.update();
        }

        updateCornerSprite();
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){   //fixme: use for testing
            int n = 0;
            for(auto &i : customers) {
                i.leftTheTable(n);
                i.setLeaving(true);
                n++;
            }

        }
        */
    }
        //std::cout << "Table " << tavNum << " humor: " << humor << std::endl;
}


void Table::render(sf::RenderTarget &target) {
    target.draw(sprite);

    //for(int i = 0 ;i < 4; i++)
    //   target.draw(dishesPlace[i]);

    if(chosenTable || state == TableState::WAITING_TO_ORDER) {
        target.draw(interactionSquare);
        target.draw(cornerSprite);
    }

    if(customers.size() > 0){
        for(int i = customers.size() -1 ; i >= 0; i--)
            target.draw(customers[i].sprite);
    }
    if(state == TableState::EATING) {
        renderBar(target);
    }
    renderDishes(target);
}

void Table::initSprite() {

    interactionSquare.setSize({62,62});
    interactionSquare.setOrigin(31,31);
    interactionSquare.setOutlineThickness(1);
    interactionSquare.setFillColor(sf::Color::Transparent);
}

int Table::getTavNum() {
    return tavNum;
}

void Table::setTavNum(int t) {
    tavNum = t;
}

const sf::Vector2f &Table::getPosition() const {
    return this->sprite.getPosition();
}

Dish *Table::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Table::setDish(Dish *d, int n) {
    d->setPosition(dishesPlace[n].getPosition());
    d->setScale(1.2, 1.2);
    dishes.push(d);
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
    customerNumber = cust.size();
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
    interactionSquare.setPosition(sprite.getPosition().x,sprite.getPosition().y - 80);
    cornerSprite.setPosition(interactionSquare.getPosition().x + 31, interactionSquare.getPosition().y - 31);
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
    this->dishesPlace[0].setPosition(sprite.getPosition().x-offSetX, sprite.getPosition().y+offSetY);
    this->dishesPlace[1].setPosition(sprite.getPosition().x+offSetX, sprite.getPosition().y+offSetY);
    this->dishesPlace[2].setPosition(sprite.getPosition().x-offSetX, sprite.getPosition().y-offSetY);
    this->dishesPlace[3].setPosition(sprite.getPosition().x+offSetX, sprite.getPosition().y-offSetY);
}

void Table::restartTimer() {
    timer.restart();
}

void Table::setIsSit(bool t) {
    isSit = t;
}

bool Table::getIsSetFinalScore() {
    return isSetFinalScore;
}

void Table::initTexture() {
    texture = new Textures();
}

void Table::updateCornerSprite() {

    switch(state){

        case TableState::CHOOSING:
            cornerSprite.setTexture(*this->texture->getTexture("Customer1"));
            cornerSprite.setTextureRect({0, 0, 32, 32});
            cornerSprite.setOrigin(16,16);
            break;

        case TableState::WAITING_TO_ORDER:
            cornerSprite.setTexture(*this->texture->getTexture("BlockNotes"));
            cornerSprite.setTextureRect({0,0,480,480});
            cornerSprite.setScale(0.05f,0.05f);
            cornerSprite.setPosition(interactionSquare.getPosition().x + 31, interactionSquare.getPosition().y - 31);
            break;

        case TableState::WAITING_DISHES:
            cornerSprite.setTexture(*texture->getTexture("HAMBURGER"));
            cornerSprite.setTextureRect({0,0,32,30});
            cornerSprite.setScale(0.5, 0.5);
            break;

        case TableState::ENDED:
            cornerSprite.setTexture(*texture->getTexture("EmptyDish"));
            break;

    }
}



void Table::renderDishes(sf::RenderTarget &target) {

    std::queue<Dish*> tmp;
    Dish* ptr;
    for(int i = 0; i < dishes.size(); i++)
    {
        ptr = dishes.front();
        dishes.pop();
        ptr->render(target);
        tmp.push(ptr);
        tmp.pop();
        dishes.push(ptr);
    }
}

void Table::eating() {

    if(this->timer.getElapsedTime().asSeconds() >= eatingTime) {
        changeDishesSprite();
        state = TableState::ENDED;
        actualBarIteration = 0;
        chosenTable = true;
    }
    if(timer.getElapsedTime().asSeconds() >= eatingTime * actualBarIteration/totalBarIteration){
        actualBarIteration++;
        updateBar();
    }

}

void Table::changeDishesSprite() {

    std::queue<Dish*> tmp;
    Dish* ptr;
    for(int i = 0; i < dishes.size(); i++)
    {
        ptr = dishes.front();
        dishes.pop();
        ptr->setEmptyDish();
        tmp.push(ptr);
        tmp.pop();
        dishes.push(ptr);
    }
}

void Table::initBar() {

    greyBar.setSize({totalBarIteration,10});
    greyBar.setPosition(sprite.getPosition().x - 10, sprite.getPosition().y + 90);
    greyBar.setFillColor(sf::Color::Black);

    greenBar.setSize({0,10});
    greenBar.setPosition(sprite.getPosition().x - 10, sprite.getPosition().y + 90);
    greenBar.setFillColor(sf::Color::Green);
}

void Table::renderBar(sf::RenderTarget &target) {
    target.draw(greyBar);
    target.draw(greenBar);
}

void Table::updateBar() {

    if(state == TableState::EATING){
        greenBar.setSize({greenBar.getSize().x+1, greenBar.getSize().y});
    }
    if(state == TableState::ENDED)
        greenBar.setSize({0, greenBar.getSize().y});
}

void Table::updateHumor() {
    switch(state)
    {
        case TableState::CHOOSING:
            break;
        case TableState::WAITING_TO_ORDER:
            if(scoreTimer.getElapsedTime().asSeconds() > 20)
                humor -= (int)(5 * difficulty);
            else if(scoreTimer.getElapsedTime().asSeconds() > 40)
                humor -= (int)(7 * difficulty);
            else
                humor -= (int)(3 * difficulty);
            break;
        case TableState::WAITING_DISHES:
            if(scoreTimer.getElapsedTime().asSeconds() > 20)
                humor -= (int)(5 * difficulty);
            else if(scoreTimer.getElapsedTime().asSeconds() > 40)
                humor -= (int)(7 * difficulty);
            else
                humor -= (int)(3 * difficulty);
            break;
        case TableState::EATING:
            break;
        case TableState::ENDED:
            state = TableState::IS_LEAVING;
            break;
        case TableState::LEFT:
            reInitTable();
            break;
    }
    if(humor < 500 && state != TableState::IS_LEAVING)
    {
        isNotSatisfied = true;
        state = TableState::IS_LEAVING;
    }
}

void Table::setIsSetFinalScore(bool t) {
    isSetFinalScore = t;
}

void Table::setHumor(int i) {
    humor = i;
}

int Table::getHumor() {
    return humor;
}

void Table::reInitTable() {
    if(isSetFinalScore)
    {
        numStoolsTable = 4;
        state = TableState::CHOOSING;
        course = Current::APPETIZER;
        isOccupied = false;
        customerNumber = 0;
        cicle = true;
        chosenTable = false;
        isSit = false;
        humor = 500;
        isSetFinalScore = false;
        order.reset();
        isNotSatisfied = false;
        while (!dishes.empty())
        {
            dishes.pop();
        }
    }
}

void Table::leaveTable() {
    //TODO: when customer exit the restaurant reset the customer vector
    int n = 0;
    for(auto &i : customers) {
        i.leftTheTable(n);
        i.setLeaving(true);
        n++;
    }
    switch(tavNum)
    {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
}

void Table::restartScoreTimer() {
    scoreTimer.restart();
}

bool Table::getIsNotSatisfied() {
    return isNotSatisfied;
}

void Table::setIsNotSatisfied(bool t) {
    isNotSatisfied = t;
}

void Table::setDifficulty(float i) {
    difficulty = i;
}


