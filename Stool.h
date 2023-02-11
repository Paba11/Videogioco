//
// Created by Ettore Righi on 11/02/23.
//

#ifndef VIDEOGIOCO_STOOL_H
#define VIDEOGIOCO_STOOL_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>


class Stool {
public:
    Stool();
    ~Stool();
    void initSprite();
    void initTexture();


private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //VIDEOGIOCO_STOOL_H
