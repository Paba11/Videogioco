//
// Created by Paolo Sbarzagli on 20/02/23.
//

#ifndef VIDEOGIOCO_ORDERSTATE_H
#define VIDEOGIOCO_ORDERSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Order.h"

class OrderState {
public:
    OrderState();
    ~OrderState();

    Order* getOrder();
    //void setOrder();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

    Order* order;
};


#endif //VIDEOGIOCO_ORDERSTATE_H
