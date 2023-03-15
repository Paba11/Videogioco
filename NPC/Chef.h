//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_CHEF_H
#define VIDEOGIOCO_CHEF_H

#include "../GameCharacter.h"
#include "../Dish/Dish.h"
#include "../Dish/Order.h"
#include "../Map/Kitchen.h"
#include <vector>
#include "../Textures.h"


enum Do {WAIT, COOK, DO};


class Chef final : public GameCharacter {
public:
    //Constructor & Destructor
    Chef();
    ~Chef();

    //Chef actions
    void move();
    void setAnimation();
    void cook();
    void checkOrder();

    //Update and render
    void update() override;

    //Getters & Setters
    void setDishes(Dish& d);
    Dish* getDish();
    void setOrder();
    Order* getOrder();
    void updateAnimations() override;
    void setKitchen(Kitchen* k);
    Kitchen* getKitchen();

private:
    //Methods' override to init the texture and the sprite
    Textures* texture;
    void initSprite() override;

    //Attributes of the Chef
    float speed;
    int ability;
    Do state;
    Dish* dish;
    std::vector<Dish*> dishes;
    Order* order;
    Kitchen* kitchen;
    sf::Time time;
    sf::Clock clock;

};


#endif //VIDEOGIOCO_CHEF_H
