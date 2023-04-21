//
// Created by Ettore Righi on 28/02/23.
//

#ifndef VIDEOGIOCO_BOTTOMBAR_H
#define VIDEOGIOCO_BOTTOMBAR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Textures.h"


class BottomBar {
public:
    BottomBar();
    ~BottomBar();

    void update();
    void updateOrders();
    void render(sf::RenderTarget& target);
    void setOrder(int n);

private:
    void initSprite();
    void initFont();
    void setOrdersPosition();
    std::vector<int> orders;
    std::vector<sf::Text> numOrder;
    std::vector<sf::Sprite> ordersSprite;
    sf::Font font;
    sf::Sprite sprite;
    Textures* texture;

};


#endif //VIDEOGIOCO_BOTTOMBAR_H
