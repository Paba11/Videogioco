//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_CUSTOMER_H
#define VIDEOGIOCO_CUSTOMER_H


#include "../GameCharacter.h"
#include "../FollowMovement.h"
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

    //Initialize attributes
    void initSprite();
    void initVariables();

    //void collisionCheck(const Map& map);
    void updateAnimations() override;
    void setAnimation();

    //Move the customer
    void move();
    void moveTo();
    void setEndingPosition(sf::Vector2f endingPos, Move direction);
    void setEndingPosition(sf::Vector2f endingPos);
    sf::Sprite sprite; //fixme create a function to set the texture from receivingCustomer.h

    //Getters & Setters
    const sf::Vector2f& getPosition() const;
    std::queue<Move>& getPath();
    void setPath(Move m);

private:
    sf::Vector2f actualPos;
    Mood mood;
    int patience;
    bool moving;
    sf::Vector2f endingPos;

    //Road to move to the table
    std::queue<Move> path;

};


#endif //VIDEOGIOCO_CUSTOMER_H