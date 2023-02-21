//
// Created by Ettore Righi on 21/02/23.
//

#ifndef VIDEOGIOCO_COUNTER_H
#define VIDEOGIOCO_COUNTER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Textures.h"


class Counter {
public:
    Counter();
    ~Counter();
    void render(sf::RenderTarget& target);
    const sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    Textures* texture;

    void initSprite();

};


#endif //VIDEOGIOCO_COUNTER_H
