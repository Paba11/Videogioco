//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_DISH_H
#define VIDEOGIOCO_DISH_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "MealMenu.h"
#include "../Textures.h"

enum class State {READY, COOKING, WAITING, IN_QUEUE};


class Dish {
public:
    //Constructor & Destructor
    Dish();
    ~Dish();

    //Methods to update and display the dish
    void render(sf::RenderTarget& target);
    void update();

    //Methods to initialize the texture and the sprite based on the dish type

    void initSprite();
    void setEmptyDish();

    //Method to have the position of the dish
    const sf::FloatRect getBounds() const;

    //Method to initialize the preparation time of the dish
    virtual void initPreparationTime() = 0;

    //Getters & Setters
    int getTavNum();
    virtual void calculateTime() = 0;
    void setTavNum(int i);
    float getPreparationTime();
    void setPrice(int i);
    int getPrice();
    void setPosition(sf::Vector2f pos);
    virtual void calculatePrice() = 0;
    virtual void setTexture() = 0;
    void setScale(float x, float y);

protected:
    void initTexture();
    Textures* texture;
    sf::Sprite sprite;
    sf::Vector2f direction;
    int tavNum;
    float preparationTime;
    int price;
    State state;
};


#endif //VIDEOGIOCO_DISH_H
