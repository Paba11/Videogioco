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
#include "Order.h"
#include "Map.h"

#define MAX_DRINKS 4;
#define MAX_APPETIZERS 4;
#define MAX_MAIN_DISHES 6;
#define MAX_DESSERT 3;

//TODO: CHANGE TEXTURE WHILE THE CUSTOMERS ARE ORDERING, IN ORDER TO SELECT THE RIGHT DISHES AND QUANTITY


class OrderState : public WaiterStates {
public:
    //Constructor & Destructor
    OrderState(Map* map);
    ~OrderState();

    //Handle the input
    void handleInput(GameCharacter& gc, sf::Event ev) override;

    //Texture and updating
    void manageOrder();
    void setAnimation();
    void update();
    void render();
    bool select();

    //Actions of the order state
    void setOrderVariables(Table* t, Order* o);
    void setAppetizers();
    void setMainCourses();
    void setDesserts();
    void setDrinks();

    //Getters & Setters
    Order* getOrder();
    void setOrder(Order* o);
    Table* getTable();
    void setTable(Table* t);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

    Order* order;
    Table* table;
    Map* map;
    Current current;
    int cursor;
    int actualMax;
    bool flag;
};


#endif //VIDEOGIOCO_ORDERSTATE_H
