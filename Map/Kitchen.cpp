//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"


Kitchen::Kitchen() {
    state = DishState::EMPTY;
    counter = std::make_shared<Counter>();
    waiterOrder = false;
    initSprite();

}

Kitchen::~Kitchen() {
    Dish* d;
    for(int i=0; !dishes.empty(); i++)
    {
        d = dishes.front();
        dishes.pop();
        delete d;
    }
}

void Kitchen::insertNewOrder(Order* o) {
    newOrders.push(o);
    std::cout << "Inserting Order" << std::endl;
    std::queue<Order*> tmp;
    for(int i = 0; i < newOrders.size(); i++)
    {
        std::cout << "Order of table " << newOrders.front()->getTableNumber() << std::endl;
        tmp.push(newOrders.front());
        newOrders.pop();
        newOrders.push(tmp.front());
    }
}

Order* Kitchen::makeNewOrder() {
    current = newOrders.front();
    newOrders.pop();
    return current;
}

void Kitchen::initSprite() {

    sprite.setTexture(*this->texture->getTexture("Kitchen"));
    sprite.setPosition(1200,420);
    sprite.setScale(3.f,3.f);

    interactionSquare.setSize({62,62});
    interactionSquare.setOrigin(31,31);
    interactionSquare.setOutlineThickness(1);
    interactionSquare.setFillColor(sf::Color::Transparent);
    interactionSquare.setPosition(980.f,440.f);


}

bool Kitchen::getIsEmptyPlates() {
    return this->isEmptyPlates;
}

void Kitchen::setIsEmptyPlates(bool t) {
    this->isEmptyPlates = t;
}

const sf::Vector2f Kitchen::getPosition() const {
    return this->sprite.getPosition();
}

Dish *Kitchen::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Kitchen::setDish(Dish* d) {
    this->dishes.push(d);
}

void Kitchen::update() {

}

void Kitchen::render(sf::RenderTarget& target) {
        target.draw(this->sprite);
        if(waiterOrder)
            target.draw(interactionSquare);
}

void Kitchen::setState(DishState ds) {
    state = ds;
}

DishState Kitchen::getState() {
    return this->state;
}

const sf::FloatRect Kitchen::getBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Sprite Kitchen::getSprite() {
    return this->sprite;
}

std::queue<Dish *> &Kitchen::getDishes() {
    return this->dishes;
}

Order* Kitchen::getReadyOrder() {
    current = nullptr;
    if(!readyOrders.empty())
    {
        current = readyOrders.front();
        readyOrders.pop();
    }
    return current;
}

void Kitchen::setReadyOrder(Order* o) {
    readyOrders.push(o);
}

void Kitchen::getWaitingOrder(int tavNum) {
    /*
     * Insert the order that was waiting in the queue of the not ready tables inside the readyQueue
     */
    int i = 100;
    std::queue<Order*> tmp;
    while(i != tavNum && !waitingOrders.empty())
    {
        i = waitingOrders.front()->getTableNumber();
        tmp.push(waitingOrders.front());
        waitingOrders.pop();
    }
    if (i == tavNum)
    {
        while(tmp.size()!=1)
        {
            waitingOrders.push(tmp.front());
            tmp.pop();
        }
        readyOrders.push(tmp.front());
        tmp.pop();
    }
    else
    {
        while(!tmp.empty())
        {
            waitingOrders.push(tmp.front());
            tmp.pop();
        }
    }
}

void Kitchen::setWaitingOrder() {
    waitingOrders.push(current);
    current = nullptr;
}

std::queue<Order*> &Kitchen::getReadyOrders() {
    return readyOrders;
}

std::shared_ptr<Counter> Kitchen::getCounter() const{
    return counter;
}


sf::RectangleShape &Kitchen::getInteractionSquare() {
    return this->interactionSquare;}

void Kitchen::updateBox() {

    if(waiterOrder) {
        interactionSquare.setFillColor(this->boxOpacity);

        if(boxOpacity.a == 255)
            cicle = false;
        if(boxOpacity.a == 0)
            cicle = true;
        if(cicle)
            boxOpacity.a += 5;
        else
            boxOpacity.a-= 5;
    }
}

void Kitchen::setWaiterOrder(bool t) {

    waiterOrder = t;
}
