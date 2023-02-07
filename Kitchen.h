//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_KITCHEN_H
#define VIDEOGIOCO_KITCHEN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Dish.h"
#include "Order.h"
#include "Table.h"
#include <queue>


#define MAX_TABLES 10

class Kitchen {
public:
    //Constructor & Destructor
    Kitchen();
    ~Kitchen();

    //Method to insert and remove orders
    void insertNewOrder(Order* order);
    Order* makeNewOrder();
    void insertWaitingOrder(Order* order);
    Order* makeWaitingOrder();

    //Methods to manage orders

    //Getters & Setters
    bool getIsEmptyPlates();
    void setIsEmptyPlates(bool t);

private:
    //Initialize the Kitchen texture and sprite
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

    Dish* dish;
    std::queue<Order*> newOrders;
    Order* waitingOrders[MAX_TABLES];
    std::queue<Order*> readyOrders;
    Order* current;
    int count;
    bool isEmptyPlates;
};


#endif //VIDEOGIOCO_KITCHEN_H
