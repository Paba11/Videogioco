//
// Created by Ettore Righi on 11/02/23.
//

#include "Stool.h"

Stool::Stool() {
    initSprite();
}

Stool::~Stool() = default;

void Stool::initSprite() {
    sprite.setScale(2.f,2.f);
}

