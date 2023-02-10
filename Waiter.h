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
    void updateMovement(sf::Event ev);
    void move();
    void setAnimation();

    //Methods to interact with the customer
    void interact(sf::Event ev);
    Table* distanceTable(const Map& map);
    Kitchen* distanceKitchen(const Map& map);
    Washbasin* distanceWashbasin(const Map& map);
    void pickUp();
    void putDown();
    void takingOrder();
    void leavingOrder();

    //Getters & Setters
    const sf::Vector2f& getPosition() const;

protected:
    //Methods' override to initialize the texture and the sprite
    void initTexture() override;
    void initSprite() override;

    //Attributes of the waiter
    float speed;
    int ability;
    Genre genre;
    Actions state;
    Order* order;
    Position isClose;
    Tray* tray;

};


#endif //VIDEOGIOCO_WAITER_H
