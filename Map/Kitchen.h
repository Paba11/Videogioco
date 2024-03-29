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
#include "../Textures.h"
#include "Counter.h"
#include "../BottomBar.h"
#include <queue>





class Kitchen {
public:
    //Constructor & Destructor
    Kitchen();
    ~Kitchen();

    //Method to insert and remove orders
    void insertNewOrder(std::shared_ptr<Order>& order);


    //Update and render of the kitchen textures
    void update();
    void render(sf::RenderTarget& target);
    void updateAnimations();

    void updateBox();


    //Methods to manage orders
    std::shared_ptr<Order>& getReadyOrder();
    std::queue<std::shared_ptr<Order>>& getReadyOrders();
    void setReadyOrder(std::shared_ptr<Order>& order);
    void getWaitingOrder(int tavNum);
    void setWaitingOrder();

    //Getters & Setters
    sf::Vector2f getPosition() const;
    void setState(DishState ds);
    DishState getState();
    sf::Sprite getSprite();
    std::shared_ptr<Counter> getCounter() const;
    std::shared_ptr<BottomBar> getBottomBar() const;
    sf::RectangleShape& getInteractionSquare();
    void setWaiterOrder(bool t);
    void setReadyDishes(bool t);
    std::queue<std::shared_ptr<Order>>& getWaitingOrders();

private:
    //Initialize the Kitchen texture and sprite
    Textures* texture;
    sf::Sprite sprite;
    sf::Sprite pan;
    sf::Sprite pot;
    sf::IntRect panFrame;
    sf::IntRect potFrame;
    sf::Clock animationTimer;
    void initTexture();
    void initSprite();

    std::queue<std::shared_ptr<Order>> waitingOrders;
    std::queue<std::shared_ptr<Order>> readyOrders;
    std::shared_ptr<Order> current;
    DishState state;
    std::shared_ptr<Counter> counter;
    std::shared_ptr<BottomBar> bottomBar;

    sf::RectangleShape interactionSquare;
    sf::Color boxOpacity = {253,202,78,255};
    bool cicle = true;
    bool waiterOrder;
    sf::Sprite cornerSprite;
    bool dishesReady;

};


#endif //VIDEOGIOCO_KITCHEN_H
