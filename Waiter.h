//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "Dish.h"
#include "GameCharacter.h"
#include "Order.h"

enum Genre {BOY, GIRL};
enum Actions {MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT, STANDING};

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
    bool distanceT();
    bool distanceK();
    void pickUp();
    void putDown();
    void takeOrder();
    void giveOrder();

    //Getters & Setters
    const sf::Vector2f& getPosition() const;

protected:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
    void initSprite() override;

    //Attributes of the waiter
    float speed;
    int ability;
    Genre genre;
    Actions state;
    Dish* dish;
    Order* order;
    bool isClose;

};


#endif //VIDEOGIOCO_WAITER_H
