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
#include "../Textures.h"

class Entrance {
public:
    //Constructor & Destructor
    Entrance();
    ~Entrance();

    void setSprite(sf::Sprite& e);
    sf::Sprite getSprite();
    void setIsCustomer(bool t);
    bool getIsCustomer();
    void renderBarrier(sf::RenderTarget &target, int barrierNumber);
    void render(sf::RenderTarget &target);
    void updateBox();

    sf::RectangleShape& getWelcomeSquare();


private:
    sf::Sprite sprite; //fixme move here the sprite of the entrance
    Textures* texture;
    sf::RectangleShape welcomeSquare;
    void initSprite();
    void initTexture();
    sf::Sprite barrier1;
    sf::Sprite barrier2;
    sf::Color boxOpacity = {253,202,78,255};
    bool cicle = true;


    bool isCustomer;

};


#endif //VIDEOGIOCO_ENTRANCE_H
