//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_GAMECHARACTER_H
#define VIDEOGIOCO_GAMECHARACTER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class GameCharacter {
public:
    //Constructor & Destructor
    GameCharacter();
    ~GameCharacter();

    //Method to Update GameCharacter variables and to display it on the screen
    void update();
    void render(sf::RenderTarget& target);

protected:
    sf::Sprite sprite;
    sf::Texture texture;

    //Method to init the texture and the sprite
    virtual void initTexture();
    virtual void initSprite();

};


#endif //VIDEOGIOCO_GAMECHARACTER_H
