//
// Created by Ettore Righi on 19/02/23.
//

#ifndef VIDEOGIOCO_BUTTON_H
#define VIDEOGIOCO_BUTTON_H

#include "Textures.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum BtnState {IDLE, PRESSED, HOVER};

class Button {
public:
    Button(float x, float y, float width, float height, sf::Font* font, std::string text,
           sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor);
    ~Button();

    void render(sf::RenderTarget& target);
    void update(sf::Vector2f mousePos);
    void changeColor();
    void textSetPosition();

    bool isPressed();
private:
    short unsigned buttonState;
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressColor;
};


#endif //VIDEOGIOCO_BUTTON_H
