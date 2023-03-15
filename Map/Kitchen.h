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
#include "../Dish/Dish.h"
#include "../Dish/Order.h"
#include "Table.h"
#include "../Tray.h"
#include "../Dish/Recipe.h"
#include "../Textures.h"
#include "Counter.h"
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
    //void insertWaitingOrder(Order* order);
    //Order* makeWaitingOrder();

    //Update and render of the kitchen textures
    void update();
    void render(sf::RenderTarget& target);

    //Methods to manage orders
    Order* getReadyOrder();
    std::queue<Order*>& getReadyOrders();
    void setReadyOrder(Order* order);
    void getWaitingOrder(int tavNum);
    void setWaitingOrder();

    //Getters & Setters
    bool getIsEmptyPlates();
    void setIsEmptyPlates(bool t);
    const sf::Vector2f getPosition() const;
    Dish* getDish();
    void setDish(Dish* dish);
    std::queue<Dish*>& getDishes();
    void setState(int i);
    DishState getState();
    const sf::Sprite getSprite();
    const sf::FloatRect getBounds() const;
    Counter* getCounter();


private:
    //Initialize the Kitchen texture and sprite
    Textures* texture = new Textures;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

    std::queue<Dish*> dishes;
    std::queue<Order*> newOrders;
    std::queue<Order*> waitingOrders;
    std::queue<Order*> readyOrders;
    Order* current;
    int count;
    bool isEmptyPlates;
    DishState state;
    Recipe recipe;
    Counter* counter;
};


#endif //VIDEOGIOCO_KITCHEN_H
