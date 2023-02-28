//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_CUSTOMER_H
#define VIDEOGIOCO_CUSTOMER_H


#include "GameCharacter.h"

enum Mood {EXCELLENT, GOOD, NORMAL, BAD};

class Customer final : public GameCharacter {
public:
    //Constructor & Destructor
    Customer();
    ~Customer();

    //Methods to update and display the customer on the screen
    void update();
    void move();
    void setSprite();
    //
    void updateAnimations() override;
    void setAnimation();
    void moveToChair();
    void moveTo();
    void setEndingPosition(sf::Vector2f endingPos, Move direction);
    sf::Sprite sprite; //fixme create a funtion to set the texture from receivingCustomer.h

private:
    sf::Vector2f actualPos;
    Mood mood;
    int patience;
    bool moving;
    sf::Vector2f endingPos;

};


#endif //VIDEOGIOCO_CUSTOMER_H
