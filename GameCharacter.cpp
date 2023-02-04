//
// Created by Paolo Sbarzagli on 31/01/23.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter() {
    //initTexture();
    //initSprite();
}

GameCharacter::~GameCharacter() {

}

void GameCharacter::update() {

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

    this->sprite.setTexture(this->texture);

}

const sf::FloatRect GameCharacter::getBounds() const {
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