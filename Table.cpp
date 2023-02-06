//
// Created by Ettore Righi on 04/02/23.
//

#include <iostream>
#include "Table.h"

Table::Table() {
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
