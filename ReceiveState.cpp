//
// Created by Paolo Sbarzagli on 07/03/23.
//

#include "ReceiveState.h"

ReceiveState::ReceiveState(Map *m) {
    this->map = m;
}

ReceiveState::~ReceiveState() {

}

void ReceiveState::handleInput(GameCharacter& gc, sf::Event ev) {

}

void ReceiveState::update(GameCharacter& gc) {

}


Table* ReceiveState::pickEmptyTable() {
    std::vector<Table> t;
    bool notFound = true;

    while(!this->map->getAllTables().empty() && notFound)
    {
        t.push_back(this->map->getAllTables().back());
        this->map->getAllTables().pop_back();
        if(!t.back().getIsOccupied())
        {
            notFound = false;
            this->table = &t.back();
            this->table->setIsOccupied(true);
            while(!t.empty())
            {
                this->map->getAllTables().push_back(t.back());
                t.pop_back();
            }
        }
    }
    return this->table;
}


Move ReceiveState::checkState(float distX, float distY) {
    Move direction = MOVING_LEFT;
    if(distX != 0 && distY == 0)
    {
        if(distX < 0)
            direction = MOVING_RIGHT;
        else if(distX > 0)
            direction = MOVING_LEFT;
    }
    else if(distX == 0 && distY != 0)
    {
        if(distY < 0)
            direction = MOVING_DOWN;
        else if(distY > 0)
            direction = MOVING_UP;
    }
    else
    {
        //TODO IMPLEMENT CASE IN WHICH BOTH ARE DIFFERENT
    }
    return direction;
}


void ReceiveState::move(FollowMovement customerDirection) {
    /*
     * Move the selected waiter in the specific position indicated
     */
    //TODO: MOVE THE CUSTOMER AND CREATE ANOTHER FUNCTION TO PUT INSIDE HIS QUEUE THE LATEST MOVEMENT MADE BY THE WAITER


}

void ReceiveState::follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status) {
    /*
     * if previous moving status = final moving status then just modify the value of dist
     * if change of direction then set a new breakpoint
     */

    float distX = (prePosition.x - finalPosition.x);
    float distY = (prePosition.y - finalPosition.y);
    Move direction = checkState(distX, distY);
/*
    for(auto & tmp : this->map->getEntrance()->getCustomers())
    {
        if(tmp.getPath().back().getMove() == direction)
            tmp.getPath().back().setDist(finalPosition);
        else
            tmp.setPath(finalPosition, direction);
    }
*/
}