//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_MAP_H
#define VIDEOGIOCO_MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Map {
public:
    //Constructor & Destructor
    Map();
    ~Map();


private:
    sf::Texture texture;
    sf::Sprite sprite;

};


#endif //VIDEOGIOCO_MAP_H
