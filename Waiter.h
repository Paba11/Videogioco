//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_WAITER_H
#define VIDEOGIOCO_WAITER_H

#include "GameCharacter.h"

enum Type {BOY, GIRL};
enum Actions {MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT, STANDING};

class Waiter final : public GameCharacter {
public:
    //Constructor & Destructor
    Waiter();
    ~Waiter();

    //Method to manage the game events
    void pollEvent();

    //Method to move the waiter
    void updateMovement(sf::Event ev);
    void move();
    void setAnimation();

protected:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
    void initSprite() override;

    //Attributes of the waiter
    int speed;
    int ability;
    Type type;
    Actions state;

};


#endif //VIDEOGIOCO_WAITER_H
