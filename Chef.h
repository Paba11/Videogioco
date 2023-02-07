//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_CHEF_H
#define VIDEOGIOCO_CHEF_H

#include "GameCharacter.h"
#include "Dish.h"
#include "Order.h"


enum Do {WAITING, COOKING, READY};


class Chef final : public GameCharacter {
public:
    //Constructor & Destructor
    Chef();
    ~Chef();

    //Chef actions
    void updateMovement(int action);
    void move();
    void setAnimation();

private:
    //Methods' override to init the texture and the sprite
    void initTexture() override;
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
