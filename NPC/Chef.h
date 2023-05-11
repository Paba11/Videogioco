//
// Created by Paolo Sbarzagli on 07/02/23.
//

#ifndef VIDEOGIOCO_CHEF_H
#define VIDEOGIOCO_CHEF_H

#include "../GameCharacter.h"
#include "../Dish/Dish.h"
#include "../Dish/Order.h"
#include "../Score.h"
#include "../Dish/Appetizer.h"
#include "../Dish/MainCourse.h"
#include "../Dish/Dessert.h"
#include "../Map/Kitchen.h"
#include <vector>
#include "../Textures.h"


enum class Do {WAIT, COOK, DO};


class Chef final : public GameCharacter {
public:
    //Constructor & Destructor
    Chef();
    ~Chef() override;

    //Chef actions
    void setAnimation();
    void updateAnimations() override;
    void cook();
    void checkOrder();
    void createObjects();

    //Update and render
    void update() override;
    void updateBar();
    void renderBar(sf::RenderTarget& target);

    //Getters & Setters
    void setDishes(Dish& d);
    Dish* getDish();
    void setOrder(std::shared_ptr<Order>& o);
    std::shared_ptr<Order>& getOrder();
    void setKitchen(std::shared_ptr<Kitchen>& k);
    const std::shared_ptr<Kitchen>& getKitchen();
    void setTime(float f);
    void setState(Do d);
    Do getDo();
    bool getIsReady();
    std::vector<Dish*>& getDishes();

private:
    //Methods' override to init the texture and the sprite
    void initSprite() override;
    void setTextureDishes(Dish* d, Apt t);
    void initBar();
    sf::RectangleShape greyBar;
    sf::RectangleShape greenBar;

    //Attributes of the Chef
    Do state;
    Dish* dish;
    std::vector<Dish*> dishes;
    std::shared_ptr<Order> order;
    std::shared_ptr<Kitchen> kitchen;
    float time;
    sf::Clock clock;
    bool isReady;
    float totalBarIteration = 30;
    float actualBarIteration = 0;
};


#endif //VIDEOGIOCO_CHEF_H
