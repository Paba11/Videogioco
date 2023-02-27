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
    void setSprite(int numberCustomer);
    //
    void updateAnimations() override;
    void moveToChair();
    sf::Sprite sprite; //fixme create a funtion to set the texture from receivingCustomer.h


private:
    Mood mood;
    int patience;

};


#endif //VIDEOGIOCO_CUSTOMER_H
