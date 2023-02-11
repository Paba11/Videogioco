//
// Created by Paolo Sbarzagli on 10/02/23.
//

#ifndef VIDEOGIOCO_WASHBASIN_H
#define VIDEOGIOCO_WASHBASIN_H

#include "DishWasher.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Washbasin {
public:
    //Constructor & Destructor
    Washbasin();
    ~Washbasin();

    //Methods to update and render the tray
    void update();
    void render(sf::RenderTarget& target);

    //Position of Washbasin

    //Getters & Setters
    bool getIsPlates() const;
    void setIsPlates(bool t);

private:
    //Set The texture and the sprite
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();
    bool isPlates;

};


#endif //VIDEOGIOCO_WASHBASIN_H
