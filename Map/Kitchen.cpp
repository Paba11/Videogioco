//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Kitchen.h"


Kitchen::Kitchen() {
    state = DishState::EMPTY;
    counter = std::make_shared<Counter>();
    waiterOrder = false;
    initTexture();
    initSprite();

}

Kitchen::~Kitchen() {
    /*
    Dish* d;
    for(int i=0; !dishes.empty(); i++)
    {
        d = dishes.front();
        dishes.pop();
        delete d;
    }
     */
}

void Kitchen::insertNewOrder(std::shared_ptr<Order>& o) {
    std::shared_ptr<Order> ord(o);
    readyOrders.push(ord);
    std::cout << "Inserting Order" << std::endl;
    std::queue<std::shared_ptr<Order>> tmp;
    for(int i = 0; i < readyOrders.size(); i++)
    {
        std::cout << "Order of table " << readyOrders.front()->getTableNumber() << std::endl;
        std::shared_ptr<Order> orde = readyOrders.front();
        readyOrders.pop();
        tmp.push(orde);
        tmp.pop();
        readyOrders.push(orde);
        orde.reset();
    }

}

std::shared_ptr<Order>& Kitchen::makeNewOrder() {
    current = readyOrders.front();
    readyOrders.pop();
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

    cornerSprite.setTexture(*this->texture->getTexture("BlockNotes"));
    cornerSprite.setTextureRect({0,0,480,480});
    cornerSprite.setScale(0.05f,0.05f);
    cornerSprite.setPosition(interactionSquare.getPosition().x - 31, interactionSquare.getPosition().y - 31);

    pan.setTexture(*this->texture->getTexture("Pan"));          //padella
    panFrame = sf::IntRect(0, 0, 30, 30);
    pan.setTextureRect(panFrame);
    pan.setScale(3.f, 3.f);
    pan.setPosition(1190,460);

    pot.setTexture(*this->texture->getTexture("Pot"));          //pentola
    potFrame = sf::IntRect(0, 0, 24, 24);
    pot.setTextureRect(potFrame);
    pot.setScale(3.f, 3.f);
    pot.setPosition(1218,410);







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

void Kitchen::update() {
    updateBox();
    updateAnimations();
}

void Kitchen::render(sf::RenderTarget& target) {
        target.draw(this->sprite);
        if(waiterOrder) {
            target.draw(interactionSquare);
            target.draw(cornerSprite);
        }
        target.draw(pan);
        target.draw(pot);
}

void Kitchen::setState(DishState ds) {
    state = ds;
}

DishState Kitchen::getState() {
    return state;
}

const sf::FloatRect Kitchen::getBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Sprite Kitchen::getSprite() {
    return this->sprite;
}

std::shared_ptr<Order>& Kitchen::getReadyOrder() {
    current = nullptr;
    if(!readyOrders.empty())
    {
        current = readyOrders.front();
        readyOrders.pop();
    }
    return current;
}

void Kitchen::setReadyOrder(std::shared_ptr<Order>& o) {
    readyOrders.push(o);
}

void Kitchen::getWaitingOrder(int tavNum) {
    /*
     * Insert the order that was waiting in the queue of the not ready tables inside the readyQueue
     */
    int i = 100;
    std::queue<std::shared_ptr<Order>> tmp;
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

std::queue<std::shared_ptr<Order>> &Kitchen::getReadyOrders() {
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

void Kitchen::initTexture() {

    texture = new Textures;
}

void Kitchen::updateAnimations() {

    switch(state){

        case DishState::EMPTY:
            potFrame.left = 0;
            panFrame.left = 0;
            pot.setTextureRect(potFrame);
            pan.setTextureRect(panFrame);
            break;

        case DishState::COOKING:
            potFrame.left = 24;
            panFrame.left = 30;
            pot.setTextureRect(potFrame);
            pan.setTextureRect(panFrame);
            break;

        case DishState::ALMOST_READY:
            potFrame.left = 48;
            panFrame.left = 60;
            pot.setTextureRect(potFrame);
            pan.setTextureRect(panFrame);
            break;


    }

}
