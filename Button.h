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
    Button(float x, float y, float width, float height, sf::Font* font, const std::string& text,
           sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor);

    Button(float x, float y, sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor);
    ~Button();

    void render(sf::RenderTarget& target);
    void update(sf::Vector2f mousePos);
    void changeColor();

    bool isPressed() const;
    sf::CircleShape triangle;
private:
    short unsigned buttonState;
    sf::RectangleShape shape;
    std::string buttonType;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressColor;
};


#endif //VIDEOGIOCO_BUTTON_H
