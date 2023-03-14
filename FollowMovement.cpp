//
// Created by Paolo Sbarzagli on 28/02/23.
//

#include "FollowMovement.h"

FollowMovement::FollowMovement() {

}

FollowMovement::FollowMovement(Move m, sf::Vector2f d) {
    this->move = m;
    this->dist = d;
}

FollowMovement::~FollowMovement() {

}

void FollowMovement::initDistance() {

}

sf::Vector2f FollowMovement::getDist() {
    return this->dist;
}

void FollowMovement::setDist(sf::Vector2f d) {
    this->dist = d;
}

Move FollowMovement::getMove() {
    return this->move;
}

void FollowMovement::setMove(Move m) {
    this->move = m;
}

float FollowMovement::distanceTwoCharacters(GameCharacter* g1, GameCharacter* g2) {

    float g1X, g1Y, g2X, g2Y;
    g1X = g1->getPosition().x;
    g1Y = g1->getPosition().y;
    g2X = g2->getPosition().x;
    g2Y = g2->getPosition().y;

    if(g1X == g2X)
        return abs(g1Y - g2Y);
    if(g1Y == g2Y)
        return abs(g1X - g2X);
}


