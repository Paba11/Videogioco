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
#include "Tray.h"
#include "Recipe.h"
#include "Textures.h"
#include <queue>


#define MAX_TABLES 10

enum DishState {EMPTY, FULL};

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

    //Update and render of the kitchen textures
    void update();
    void render(sf::RenderTarget& target);

    //Methods to manage orders

    //Getters & Setters
    bool getIsEmptyPlates();
    void setIsEmptyPlates(bool t);
    const sf::Vector2f getPosition() const;
    Dish* getDish(int i);
    void setDish(int i, Dish* dish);
    void setState(int i);
    DishState getState();
    const sf::FloatRect getBounds() const;



private:
    //Initialize the Kitchen texture and sprite
    Textures* texture = new Textures;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

    Dish* dish[MAX_DISHES];
    std::queue<Order*> newOrders;
    Order* waitingOrders[MAX_TABLES];
    std::queue<Order*> readyOrders;
    Order* current;
    int count;
    bool isEmptyPlates;
    DishState state;
    Recipe recipe;
};


#endif //VIDEOGIOCO_KITCHEN_H
