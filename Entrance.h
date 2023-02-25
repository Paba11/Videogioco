//
// Created by Paolo Sbarzagli on 24/02/23.
//

#ifndef VIDEOGIOCO_ENTRANCE_H
#define VIDEOGIOCO_ENTRANCE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Entrance {
public:
    //Constructor & Destructor
    Entrance();
    ~Entrance();

    void setSprite(sf::Sprite& e);
    sf::Sprite getSprite();
    void setIsCustomer(bool t);
    bool getIsCustomer();

private:
    sf::Sprite sprite;
    void initSprite();
    void initTexture();

    bool isCustomer;

};


#endif //VIDEOGIOCO_ENTRANCE_H
