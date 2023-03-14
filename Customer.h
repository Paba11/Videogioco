//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_CUSTOMER_H
#define VIDEOGIOCO_CUSTOMER_H


#include "GameCharacter.h"
#include "FollowMovement.h"
#include <queue>

#define TOTAL_OFFSET 50

enum Mood {EXCELLENT, GOOD, NORMAL, BAD};

class Customer final : public GameCharacter {
public:
    //Constructor & Destructor
    Customer();
    explicit Customer(sf::Vector2f dist);
    ~Customer() override;

    //Methods to update and display the customer on the screen
    void update();
    void move();
    void initSprite();
    void initVariables();

    //void collisionCheck(const Map& map);
    void updateAnimations() override;
    void setAnimation();

    void updateMoving(sf::Sprite& previous);
    void moveTo();
    void setEndingPosition(sf::Vector2f endingPos, Move direction);
    sf::Sprite sprite; //fixme create a function to set the texture from receivingCustomer.h

    //Getters & Setters
    const sf::Vector2f& getPosition() const;
    std::queue<Move>& getPath();
    void setPath(Move m);
    void setOffsetX(float x);
    float getOffsetX();
    void setOffsetY(float y);
    float getOffsetY();
    float getTotalOffset();

private:
    sf::Vector2f actualPos;
    Mood mood;
    int patience;
    bool moving;
    sf::Vector2f endingPos;
    sf::Clock clock;

    //Road to move to the table
    std::queue<Move> path;
    float offsetX, offsetY;
    sf::Vector2f prevPos;

};


#endif //VIDEOGIOCO_CUSTOMER_H
