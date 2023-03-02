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
    void update(bool waitMove);
    void move();
    void setSprite();
    void initVariables();
    void moveToChair(const sf::Sprite& sp, float offset);
    //void collisionCheck(const Map& map);
    void updateAnimations() override;
    void setAnimation();
    //void moveToChair();
    void updateMoving();
    void moveTo();
    void setEndingPosition(sf::Vector2f endingPos, Move direction);
    sf::Sprite sprite; //fixme create a function to set the texture from receivingCustomer.h

    //Getters & Setters
    const sf::Vector2f& getPosition() const;
    std::queue<FollowMovement>& getPath();
    void setPath(sf::Vector2f dist, Move move);

private:
    sf::Vector2f actualPos;
    Mood mood;
    int patience;
    bool moving;
    sf::Vector2f endingPos;

    //Road to move to the table
    std::queue<FollowMovement> path;
    FollowMovement* followMovement;
    int initialRoad;

};


#endif //VIDEOGIOCO_CUSTOMER_H
