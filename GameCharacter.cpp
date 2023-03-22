//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "GameCharacter.h"


GameCharacter::GameCharacter() {
    //initTexture();
    //initSprite();
    //setPositionW(100,100); //FiXME delete
    initValidMovement();
}

GameCharacter::~GameCharacter() {

}

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

void GameCharacter::setEvent(sf::Event e) {
    this->ev = e;
}

const sf::Vector2f &GameCharacter::getPosition() const {
    return this->sprite.getPosition();
}

Move GameCharacter::getMovingStatus() {
    return this->movingStatus;
}

sf::FloatRect& GameCharacter::getHitbox() {
    return this->hitbox;
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

sf::Vector2f GameCharacter::getPrevPos() {
    return this->prevPos;
}

sf::Vector2f GameCharacter::getCurrPos() {
    return this->currPos;
}

Move GameCharacter::getDirection() {
    return this->dir;
}

void GameCharacter::setMovingStatus(Move m) {
    this->movingStatus = m;
}

