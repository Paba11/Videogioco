//
// Created by Ettore Righi on 19/02/23.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text,
               sf::Color idleColor, sf::Color hoverColor, sf::Color pressColor) {

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

Button::~Button() {

}

void Button::render(sf::RenderTarget& target) {

    target.draw(this->shape);
    target.draw(this->text);
}

void Button::update(sf::Vector2f  mousePos) {

    this->buttonState = IDLE;
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->buttonState = HOVER;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState = PRESSED;
        }
    }
    changeColor();
}

void Button::changeColor() {

    switch(this->buttonState){

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

bool Button::isPressed() {
    if(this->buttonState == PRESSED)
        return true;
    else
        return false;
}

void Button::textSetPosition() {

}
