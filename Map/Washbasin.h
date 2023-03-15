//
// Created by Paolo Sbarzagli on 10/02/23.
//

#ifndef VIDEOGIOCO_WASHBASIN_H
#define VIDEOGIOCO_WASHBASIN_H

#include "../Textures.h"
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
    sf::Vector2f getPosition();
    const sf::Sprite getSprite();
    int getNumPlates();
    void setNumPlates(int i);

private:
    //Set The texture and the sprite
    Textures* texture = new Textures;
    sf::Sprite sprite;
    void initSprite();
    bool isPlates;
    int numPlates;

};


#endif //VIDEOGIOCO_WASHBASIN_H
