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
#include "WaiterStates.h"
#include "../Dish/Order.h"
#include "../Map/Map.h"


class OrderState : public WaiterStates {
public:
    //Constructor & Destructor
    OrderState(Map* map);
    ~OrderState();

    //Handle the input
    void handleInput(GameCharacter& gc, sf::Event ev) override;
    void update(GameCharacter& gc) override;

    //Actions of the order state
    void setOrderVariables(Table* t);
    void randomOrder();

    //Getters & Setters
    Order* getOrder();
    void setOrder(Order* o);
    Table* getTable();
    void setTable(Table* t);

private:
    void initVariables(Map* map);

    Order* order;
    Table* table;
    Map* map;
    Current current;
};


#endif //VIDEOGIOCO_ORDERSTATE_H
