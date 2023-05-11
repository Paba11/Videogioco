//
// Created by Paolo Sbarzagli on 20/02/23.
//

#include "OrderState.h"


OrderState::OrderState(Table& t) {
    table = &t;
    initVariables(t);
    current = Current::APPETIZER;
    isTaken = false;
    random = 0;
}

OrderState::~OrderState() = default;

void OrderState::handleInput(std::shared_ptr<GameCharacter>& gc, sf::Event ev) {

}

void OrderState::update(std::shared_ptr<GameCharacter>& gc) {

}

void OrderState::randomChoices() {

    switch(current)
    {
        case Current::APPETIZER:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(1);
                order->setAppetizer(random);
            }
            break;
        case Current::MAIN_DISH:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(3);
                order->setMainCourse(random);
            }
            break;
        case Current::DESSERT:
            for(int i = 0; i < table->getCustomers().size(); i++)
            {
                generateRandom(2);
                order->setDessert(random);
            }
            break;
        case Current::END:
            break;
    }
}

void OrderState::initVariables(Table& t) {
    order = std::make_shared<Order>();
    table = &t;
    order->setTableNumber(table->getTavNum());
    order->setPeopleNumber(table->getCustomerNumber());
    timer.restart();
}

std::shared_ptr<Order>& OrderState::takeOrder() {
    if(!isTaken)
    {
        map->getKitchen()->setWaiterOrder(true);
        randomChoices();
        current = Current::MAIN_DISH;
        randomChoices();
        current = Current::DESSERT;
        randomChoices();
        isTaken = true;
    }
    return order;
}

void OrderState::generateRandom(int max) {
    std::mt19937 gen(this->rd());
    std::uniform_int_distribution<> distrib(0, max);
    this->random = distrib(gen);
}

bool OrderState::getIsTaken() const {
    return isTaken;
}

void OrderState::setMap(const std::shared_ptr<Map>& m) {

    map.reset();
    map = m;

}