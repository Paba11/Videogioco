//
// Created by Ettore Righi on 19/02/23.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
               sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor) {

    this->buttonType = "Rectangle";
    this->shape.setSize(sf::Vector2f(width,height));
    this->shape.setPosition(sf::Vector2f(x,y));
    this->buttonState = IDLE;
    this->font = font;
     this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(50);
    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y - this->text.getGlobalBounds().height / 2.f
            );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->pressColor = pressColor;
    this->shape.setFillColor(this->idleColor);

}

Button::Button(float x, float y,
               sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor) {

    this->buttonType = "Triangle";
    this->triangle = sf::CircleShape (20,3);
    this->triangle.setOrigin(20,20);
    this->triangle.setPosition(sf::Vector2f(x,y));
    this->buttonState = IDLE;

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->pressColor = pressColor;
    this->shape.setFillColor(this->idleColor);

}

Button::~Button() {

}

void Button::render(sf::RenderTarget& target) {

    if(this->buttonType == "Rectangle") {
        target.draw(this->shape);
        target.draw(this->text);
    }
    else if(this->buttonType == "Triangle")
        target.draw(this->triangle);
}

void Button::update(sf::Vector2f  mousePos) {

    this->buttonState = IDLE;
    if(this->buttonType == "Rectangle") {
        if (this->shape.getGlobalBounds().contains(mousePos)) {
            this->buttonState = HOVER;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                this->buttonState = PRESSED;
            }
        }
    }
    else if(this->buttonType == "Triangle"){
        if (this->triangle.getGlobalBounds().contains(mousePos)) {
            this->buttonState = HOVER;
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                this->buttonState = PRESSED;
            }
        }
    }
    changeColor();
}

void Button::changeColor() {

    if(this->buttonType == "Rectangle") {
        switch (this->buttonState) {

            case IDLE :
                this->shape.setFillColor(idleColor);
                break;
            case HOVER:
                this->shape.setFillColor(hoverColor);
                break;
            case PRESSED:
                this->shape.setFillColor(pressColor);
                break;
        }
    }
    else if(this->buttonType == "Triangle"){
        switch (this->buttonState) {

            case IDLE :
                this->triangle.setFillColor(idleColor);
                break;
            case HOVER:
                this->triangle.setFillColor(hoverColor);
                break;
            case PRESSED:
                this->triangle.setFillColor(pressColor);
                break;
        }
    }

}

bool Button::isPressed() {
    if(this->buttonState == PRESSED)
        return true;
    else
        return false;
}




