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

void ReceivingCustomers::setGeneratedCustomers(int numberCustomer, int textureNumber) {


    if(numberCustomer == 4) {
        this->customers.back().sprite.setPosition(1550, 830);   //1000, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1300, 830}, MOVING_LEFT);

        std::cout << "4" << std::endl;
    }
    else if(numberCustomer == 3) {
        this->customers.back().sprite.setPosition(1500, 830);   //1000, 800
        this->customers.back().setEndingPosition(sf::Vector2f{1200, 830}, MOVING_LEFT);

        std::cout << "3" << std::endl;

    }
    else if(numberCustomer == 2) {
        this->customers.back().sprite.setPosition(1450, 830);   //1100, 700
        this->customers.back().setEndingPosition(sf::Vector2f{1100, 830}, MOVING_LEFT);

        std::cout << "2" << std::endl;

    }
    else if(numberCustomer == 1) {
        this->customers.back().sprite.setPosition(1400, 830); //always generated
        this->customers.back().setEndingPosition(sf::Vector2f{1000, 830}, MOVING_LEFT);
        std::cout << "1" << std::endl;

    }
    if(textureNumber-1 % 4 == 0)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer1"));
    if(textureNumber-1 % 4 == 1)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer2"));
    if(textureNumber-1 % 4 == 2)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer3"));
    if(textureNumber-1 % 4 == 3)
        this->customers.back().sprite.setTexture(*this->texture->getTexture("Customer4"));


    this->customers.back().setSprite();
    std::cout << "set customer" << std::endl;


}

void ReceivingCustomers::setCustomer(Customer &customer) {
    this->customers;
}



void ReceivingCustomers::collisionManagement() {

}

void ReceivingCustomers::moveToChair(std::queue<FollowMovement>& direction) {

    FollowMovement customerMovement;
    if(direction.size() > 60)
    {
        customerMovement = direction.front();
        direction.pop();
        for (int i = 0; i < this->customers.size(); i++)
        {
            move(customerMovement);

        }
    }
}

void ReceivingCustomers::move(FollowMovement customerDirection) {
    /*
     * Move the selected waiter in the specific position indicated
     */
    //TODO: MOVE THE CUSTOMER AND CREATE ANOTHER FUNCTION TO PUT INSIDE HIS QUEUE THE LATEST MOVEMENT MADE BY THE WAITER


}

void ReceivingCustomers::follow(sf::Vector2f prePosition, sf::Vector2f finalPosition, Move status) {
    /*
     * if previous moving status = final moving status then just modify the value of dist
     * if change of direction then set a new breakpoint
     */

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
    return direction;
}















