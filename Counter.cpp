//
// Created by Ettore Righi on 21/02/23.
//

#include "Counter.h"

Counter::Counter() {

    this->texture = new Textures();
    initSprite();
    setDirtyDishes();
    setChefDishes();
}

Counter::~Counter() {

}

void Counter::initSprite() {

    this->sprite.setTexture(*this->texture->getTexture("Counter"));
    this->sprite.setPosition(1020,170);
    this->sprite.setScale(3.f,3.f);

}

void Counter::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
    target.draw(this->placeForDirtyDishes);

    for(int i = 0; i < 4; i++)
        target.draw(this->chefDishes[i]);
}

const sf::FloatRect Counter::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Counter::setDirtyDishes() {

    this->placeForDirtyDishes.setSize(this->dishHitbox);
    this->placeForDirtyDishes.setPosition(1020.f,260.f);
    this->placeForDirtyDishes.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
    this->placeForDirtyDishes.setOutlineThickness(1.f);
    this->placeForDirtyDishes.setFillColor(sf::Color::Transparent);
    //this->placeForDirtyDishes.setTexture(this->texture->getTexture("Main1")); //work but only without both outline/Fill


}

void Counter::setChefDishes() {

    for(int i = 0; i < 4; i++){
        sf::RectangleShape rectangle;

        rectangle.setSize(this->dishHitbox);
        rectangle.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
        rectangle.setOutlineThickness(1.f);
        rectangle.setFillColor(sf::Color::Transparent);
        chefDishes.push_back(rectangle);
    }

    this->chefDishes[0].setPosition(1020.f, 400.f);
    this->chefDishes[1].setPosition(1020.f, 480.f);
    this->chefDishes[2].setPosition(1100.f, 550.f);
    this->chefDishes[3].setPosition(1200.f, 550.f);
}
