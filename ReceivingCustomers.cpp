//
// Created by Paolo Sbarzagli on 24/02/23.
//

#include "ReceivingCustomers.h"


ReceivingCustomers::ReceivingCustomers(Map* m) {
    this->map = m;
    this->isClose = false;
}

ReceivingCustomers::~ReceivingCustomers() {

}

bool ReceivingCustomers::receive() {
    this->table = pickEmptyTable();
    //TODO: ISSUE TO THE GAMER THE SELECTED TABLE
    /*
    if(!distanceTable(table))
    {

    }
     */
}

void ReceivingCustomers::setCustomers(std::vector<Customer>& c) {
    while(!c.empty())
    {
        this->customer = &c.back();
        c.pop_back();
        this->customers.push_back(*this->customer);
    }

}


Table *ReceivingCustomers::pickEmptyTable() {
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

std::vector<Customer>& ReceivingCustomers::getCustomers() {
    return this->customers;
}


void ReceivingCustomers::setCustomer(Customer &customer) {
    this->customers;
}


void ReceivingCustomers::collisionManagement() {

}

void ReceivingCustomers::moveToChair(sf::Sprite waiter) {

    for (int i = 0; i < this->customers.size(); i++)
    {
        sf::Vector2f direction = waiter.getPosition() - customers[i].getPosition();
        direction = sf::Vector2f(direction.x / std::abs(direction.x), direction.y / std::abs(direction.y));
        customers[i].sprite.move(direction * 10.f);
    }
}

void ReceivingCustomers::move(FollowMovement customerDirection) {
    /*
     * Move the selected waiter in the specific position indicated
     */
    //TODO: MOVE THE CUSTOMER AND CREATE ANOTHER FUNCTION TO PUT INSIDE HIS QUEUE THE LATEST MOVEMENT MADE BY THE WAITER


}
/*
void ReceivingCustomers::follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status) {

     * if previous moving status = final moving status then just modify the value of dist
     * if change of direction then set a new breakpoint


    float distX = (prePosition.x - finalPosition.x);
    float distY = (prePosition.y - finalPosition.y);
    Move direction = checkState(distX, distY);

    for(auto & tmp : this->customers)
    {
        if(tmp.getPath().back().getMove() == direction)
            tmp.getPath().back().setDist(finalPosition);
        else
            tmp.setPath(finalPosition, direction);
    }

}
*/
Move ReceivingCustomers::checkState(float distX, float distY) {
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
















