//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "GameCharacter.h"


GameCharacter::GameCharacter() {
    movingStatus = Move::STANDING;
    speed = 0;
    preMovingStatus = Move::STANDING;
    dir=Move::STANDING;
    state = Actions::DOING_NOTHING;
    initValidMovement();
}

GameCharacter::~GameCharacter() = default;

void GameCharacter::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void GameCharacter::initTexture() {
    /*
     * Load a texture from a file
     */
}

void GameCharacter::initSprite() {
    /*
     * Set the texture on the sprite
     */

    //this->sprite.setTexture(this->texture);

}

sf::FloatRect GameCharacter::getBounds() {
    return this->sprite.getGlobalBounds();
}

void GameCharacter::setPositionW(sf::Vector2f pos) {
    /*
     * Set the position of the waiter inside the map
     */
    this->sprite.setPosition(pos);

}

void GameCharacter::setPositionW(float x, float y) {
    /*
     * Set the position of the waiter inside the map
     */
    this->sprite.setPosition(x, y);
}

void GameCharacter::initValidMovement() {
    validMovement["Right"] = true;
    validMovement["Left"] = true;
    validMovement["Up"] = true;
    validMovement["Down"] = true;
}

sf::FloatRect GameCharacter::getGlobalHitbox() {
    return this->sprite.getTransform().transformRect(hitbox);
}


const sf::Vector2f &GameCharacter::getPosition() const {
    return sprite.getPosition();
}

Move GameCharacter::getMovingStatus() const {
    return this->movingStatus;
}


sf::Sprite &GameCharacter::getSprite() {
    return this->sprite;
}

Actions GameCharacter::getState() {
    return this->state;
}

void GameCharacter::setState(Actions a) {
    this->state = a;
}

void GameCharacter::setMovingStatus(Move m) {
    this->movingStatus = m;
}

float GameCharacter::getSpeed() const {
    return speed;
}

