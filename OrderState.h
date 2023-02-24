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
#include "Order.h"
#include "Table.h"

#define MAX_DRINKS 4;
#define MAX_APPETIZERS 4;
#define MAX_MAIN_DISHES 6;
#define MAX_DESSERT 3;

//TODO: CHANGE TEXTURE WHILE THE CUSTOMER ARE ORDERING, IN ORDER TO SELECT THE RIGHT DISHES AND QUANTITY


class OrderState {
public:
    //Constructor & Destructor
    OrderState();
    ~OrderState();

    //Texture and updating
    void manageOrder();
    void setAnimation();
    void update();
    bool select();

    //Actions of the order state
    void setOrderVariables(Table* t);
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
    Current current;
    int cursor;
    int actualMax;
    bool flag;
};


#endif //VIDEOGIOCO_ORDERSTATE_H
