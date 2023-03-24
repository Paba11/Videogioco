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

    sprite.setTexture(*this->texture->getTexture("Counter"));
    sprite.setPosition(1020,170);
    sprite.setScale(3.f,3.f);

}

void Counter::render(sf::RenderTarget& target) {
    target.draw(sprite);
    target.draw(placeForDirtyDishes);

    for(int i = 0; i < 4; i++)
        target.draw(chefDishes[i]);
}

const sf::FloatRect Counter::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Counter::setDirtyDishes() {

    placeForDirtyDishes.setSize(this->dishHitbox);
    placeForDirtyDishes.setOrigin(42.5f,40.f);
    placeForDirtyDishes.setPosition(1062.5f,300.f);
    placeForDirtyDishes.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
    placeForDirtyDishes.setOutlineThickness(1.f);
    placeForDirtyDishes.setFillColor(sf::Color::Transparent);
    //this->placeForDirtyDishes.setTexture(this->texture->getTexture("Main1")); //work but only without both outline/Fill


}

void Counter::setChefDishes() {

    for(int i = 0; i < 4; i++){
        sf::RectangleShape rectangle;

        rectangle.setSize(this->dishHitbox);
        rectangle.setOrigin(42.5f,40.f);
        rectangle.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
        rectangle.setOutlineThickness(1.f);
        rectangle.setFillColor(sf::Color::Transparent);
        chefDishes.push_back(rectangle);
    }

    this->chefDishes[0].setPosition(1062.5f, 440.f);
    this->chefDishes[1].setPosition(1062.5f, 520.f);
    this->chefDishes[2].setPosition(1142.5f, 590.f);
    this->chefDishes[3].setPosition(1242.5f, 590.f);
}

sf::RectangleShape &Counter::getPlaceDirtyDishes() {
    return this->placeForDirtyDishes;
}

std::vector<sf::RectangleShape> Counter::getPlaceChefDishes() {
    return this->chefDishes;
}

Dish *Counter::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Counter::setDish(Dish* d) {
    this->dishes.push(d);
}

std::queue<Dish *> &Counter::getDishes() {
    return this->dishes;
}