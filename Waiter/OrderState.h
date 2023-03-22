//
// Created by Paolo Sbarzagli on 20/02/23.
//

#ifndef VIDEOGIOCO_ORDERSTATE_H
#define VIDEOGIOCO_ORDERSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include "WaiterStates.h"
#include "../Dish/Order.h"
#include "../Map/Map.h"


class OrderState : public WaiterStates {
public:
    //Constructor & Destructor
    explicit OrderState(Table& table);
    ~OrderState();

    //Handle the input
    void handleInput(GameCharacter* gc, sf::Event ev) override;
    void update(GameCharacter* gc) override;

    //Actions of the order state
    void setOrderVariables(const std::shared_ptr<Table>& t);
    Order& takeOrder();
    void randomChoices();
    void generateRandom(int max);

    //Getters & Setters
    Order& getOrder();
    const std::shared_ptr<Table>& getTable();
    void setTable(const std::shared_ptr<Table>& t);
    bool getIsTaken();
    void setIsTaken(bool t);

private:
    void initVariables(Table& t);

    Order order;
    std::shared_ptr<Table> table;
    Current current;
    bool isTaken;
    sf::Clock timer;

    std::random_device rd;
    int random;
};


#endif //VIDEOGIOCO_ORDERSTATE_H
