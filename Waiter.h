//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "Dish.h"
#include "GameCharacter.h"
#include "Order.h"
#include "Tray.h"
#include "Kitchen.h"
#include "Washbasin.h"
#include "Map.h"
#include "Textures.h"
#include <cmath>

#define INTERACT 1;

enum Genre {BOY, GIRL};
enum Actions {MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT, STANDING,
        TAKING_ORDER, LEAVING_ORDER, TAKING_DISHES, LEAVING_DISHES, TAKING_EMPTY_DISHES, LEAVING_EMPTY_DISHES};
enum Position {IS_CLOSE_TABLE, IS_CLOSE_KITCHEN, IS_CLOSE_DISHWASHER, IS_CLOSE_NOTHING};


class Waiter final : public GameCharacter {
public:
    //Constructor & Destructor
    Waiter();
    ~Waiter();

    //Method to manage the game events
    //void pollEvent();

    //Method to move the waiter
    void updateMovement();
    void updateCentre();
    void update() override;
    void move();
    void setAnimation();

    //Methods to interact with the customer
    void interact();
    Table* distanceTable();
    Kitchen* distanceKitchen();
    Washbasin* distanceWashbasin();
    Textures* texture = new Textures;
    void pickUp(Kitchen* kitchen);
    void pickUp(Table* table);
    void putDown(Table* table);
    void putDown(Washbasin* washbasin);
    void takingOrder(Table* table);
    void leavingOrder(Kitchen* kitchen);
    void updateAnimations() override;

    //Getters & Setters
    const sf::Vector2f& getPosition() const;
    Actions getState();
    Map* getMap();
    void setMap(Map* map);


protected:
    //Methods' override to initialize the texture and the sprite
    void initSprite() override;

    //Attributes of the waiter
    float speed;
    int ability;
    Genre genre;
    Actions state;
    Actions preState;
    Order* order;
    Position isClose;
    Tray* tray;
    Map* map;
    float centreWaiterX, centreWaiterY;

};


#endif //VIDEOGIOCO_WAITER_H
