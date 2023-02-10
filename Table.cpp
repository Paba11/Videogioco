//
// Created by Ettore Righi on 04/02/23.
//

#include "Table.h"


Table::Table() {
    this->state = CHOOSING;
    this->course = APPETIZER;
    initTexture();
    initSprite();
}

Table::~Table() {

}

void Table::update() {

}

void Table::render(sf::RenderTarget &target) {

    target.draw(this->sprite);
}


void Table::initTexture() {
  /*  if (!this->texture.loadFromFile("../Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::TABLE::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
    */
}

void Table::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    // this->sprite.setTexture(this->texture);

    //this->sprite.setScale(3.5, 3.5);
}

int Table::getTavNum() {
    return this->tavNum;
}

void Table::setTavNum(int t) {
    this->tavNum = t;
}

const sf::Vector2f &Table::getPosition() const {
    return this->sprite.getPosition();
}

Dish *Table::getDish(int i) {
    return this->dish[i];
}

void Table::setDish(int i, Dish *d) {
    this->dish[i] = d;
}

TableState Table::getState() {
    return this->state;
}

void Table::setState(int i) {
    switch(i)
    {
        case 1:
            this->state = CHOOSING;
        case 2:
            this->state = WAITING_TO_ORDER;
        case 3:
            this->state = WAITING_DISHES;
        case 4:
            this->state = EATING;
        case 5:
            this->state = ENDED;
    }
}

Order *Table::getOrder() const {
    return this->order;
}

void Table::setOrder() {

}

ActualCourse Table::getCourse() const {
    return this->course;
}

void Table::setCourse(int i) {
    switch(i)
    {
        case 1:
            this->course = APPETIZER;
        case 2:
            this->course = MAINCOURSE;
        case 3:
            this->course = DESSERT;
    }
}
