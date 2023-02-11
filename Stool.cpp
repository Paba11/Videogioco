//
// Created by Ettore Righi on 11/02/23.
//

#include "Stool.h"

Stool::Stool() {

}

Stool::~Stool() {

}

void Stool::initSprite() {
    if (!this->texture.loadFromFile("../Textures/new_textures/Sgabello.png"))
    {
        std::cout << "ERROR::TABLE::CAN'T LOAD TEXTURE FILE" << std::endl;
    }
}

void Stool::initTexture() {
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(2.f,2.f);
}
