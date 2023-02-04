//
// Created by Ettore Righi on 04/02/23.
//

#include <iostream>
#include "Table.h"

Table::Table() {

}

Table::~Table() {

}

void Table::update() {

}

void Table::render(sf::RenderTarget &target) {

}

void Table::initTable() {


}

void Table::initTexture() {
    if (!this->texture.loadFromFile("../Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Table::initSprite() {
    /*
     * Set the texture on the sprite and resize it
     */
    this->sprite.setTexture(this->texture);

    this->sprite.setScale(0.3f, 0.3f);
}
