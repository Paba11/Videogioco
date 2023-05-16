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
    void setIsCooking(bool t, int n);
    void setIsReady(bool t, int n);
    bool getIsReady() const;
    void delOrder(int n);

private:
    void initSprite();
    void initFont();
    void initText();
    void setOrdersPosition();
    std::vector<int> orders;
    std::vector<sf::Text> numOrder;
    std::vector<sf::Sprite> ordersSprite;
    sf::Font font;
    sf::Sprite sprite;

    sf::Sprite cookingSprite;
    sf::Text cookingText;
    bool isCooking;

    sf::Sprite readySprite;
    sf::Text readyText;
    bool isReady;

    Textures* texture;

};


#endif //VIDEOGIOCO_BOTTOMBAR_H
