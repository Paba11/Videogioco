//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_CUSTOMER_H
#define VIDEOGIOCO_CUSTOMER_H


#include "GameCharacter.h"
#include "FollowMovement.h"
#include <queue>

enum Mood {EXCELLENT, GOOD, NORMAL, BAD};

class Customer final : public GameCharacter {
public:
    //Constructor & Destructor
    Customer();
    Customer(sf::Vector2f dist);
    ~Customer();

    //Methods to update and display the customer on the screen
    void update(bool waitMove, sf::Sprite previous);
    void move();
    void moveToTable();
    void setSprite();
    void initVariables();
    void moveToChair(sf::Vector2f pos);
    //void collisionCheck(const Map& map);
    void updateAnimations() override;
    void setAnimation();
    //void moveToChair();
    void updateMoving(sf::Sprite& previous);
    void moveTo();
    void setEndingPosition(sf::Vector2f endingPos, Move direction);
    void setEndingDirection(sf::Vector2f endingPos, Move direction);
    sf::Sprite sprite; //fixme create a function to set the texture from receivingCustomer.h

    //Getters & Setters
    const sf::Vector2f& getPosition() const;
    std::queue<sf::Vector2f>& getPath();
    void setPath(sf::Vector2f dist);
    void setOffsetX(float x);
    float getOffsetX();
    void setOffsetY(float y);
    float getOffsetY();

private:
    sf::Vector2f actualPos;
    Mood mood;
    int patience;
    bool moving;
    bool movingToTable;
    sf::Vector2f endingPos;
    sf::Clock clock;

    //Road to move to the table
    std::queue<sf::Vector2f> path;
    FollowMovement* followMovement;
    float offsetX, offsetY;
    sf::Vector2f prevPos;

};


#endif //VIDEOGIOCO_CUSTOMER_H
