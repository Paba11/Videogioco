//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_CHEF_H
#define VIDEOGIOCO_CHEF_H

#include "GameCharacter.h"
#include "Dish.h"
#include "Order.h"
#include "Textures.h"


enum Do {WAIT, COOK, DO};


class Chef final : public GameCharacter {
public:
    //Constructor & Destructor
    Chef();
    ~Chef();

    //Chef actions
    void updateMovement(int action);
    void update() override;
    void move();
    void setAnimation();
    void updateAnimations() override;

private:
    //Methods' override to init the texture and the sprite
    Textures* texture;
    void initSprite() override;

    //Attributes of the Chef
    float speed;
    int ability;
    Do state;
    Dish* dish;
    Order* order;
    bool isClose;

};


#endif //VIDEOGIOCO_CHEF_H
