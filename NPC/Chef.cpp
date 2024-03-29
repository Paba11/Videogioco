//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Chef.h"
//TODO: ELABORATE THE TIME TO WAIT FOR THE PREPARATION

Chef::Chef() {
    dish = nullptr;
    initSprite();
    initBar();
    state = Do::WAIT;
    isReady = false;
    time = 0;
}

Chef::~Chef() = default;


void Chef::initSprite() {
    /*
     * Set the texture on the sprite, resize it and locate the chef in the right position
     */
    sprite.setTexture(*texture->getTexture("Chef"));
    currentFrame = sf::IntRect (0,0,40,40);
    sprite.setTextureRect(currentFrame);
    sprite.setScale(3.5f, 3.5f);
    sprite.setPosition(1100,400);

    //this->sprite.setPosition();
}

void Chef::setAnimation() {

    if(state == Do::WAIT)
        currentFrame.top = 0.f;

    else if(state == Do::COOK)
        currentFrame.top = 40.f;

    sprite.setTextureRect(currentFrame);
}

void Chef::setDishes(Dish& d) {
    dishes.push_back(&d);
}

void Chef::cook() {

    if (clock.getElapsedTime().asSeconds() >= time && kitchen->getCounter()->getState() != DishState::FULL
        && state == Do::COOK)
    {
        isReady = true;
        kitchen->getCounter()->setState(DishState::FULL);
        int i=0;
        for(auto & it: dishes)
        {
            kitchen->getCounter()->setDish(it, i);
            i++;
        }
        dishes.clear();
        kitchen->setReadyDishes(true);
        state = Do::WAIT;

        if(order->getCurrent() != Current::END)
        {
            kitchen->setWaitingOrder();
            std::cout << "Set the plate in the kitchen" << std::endl;
            kitchen->getBottomBar()->setIsCooking(false, 0);
            kitchen->getBottomBar()->setIsReady(true, order->getTableNumber());
        }

        order = nullptr;
        std::cout << "The plate is ready" << std::endl;
        kitchen->setState(DishState::EMPTY);
        actualBarIteration = 0;

    }
    else if (state == Do::COOK) {
        std::cout << "Still cooking" << std::endl;
        if(clock.getElapsedTime().asSeconds() >= time * 3/4)
            kitchen->setState(DishState::ALMOST_READY);
        if(clock.getElapsedTime().asSeconds() >= time * actualBarIteration/totalBarIteration){
            actualBarIteration++;
            updateBar();
        }
    }

}

void Chef::setOrder(std::shared_ptr<Order>& o) {
    order.reset();
    order = o;
}

std::shared_ptr<Order>& Chef::getOrder() {
    return order;
}

void Chef::checkOrder() {
    if(!kitchen->getReadyOrders().empty() && state != Do::COOK)
    {
        setOrder(kitchen->getReadyOrder());
        state = Do::COOK;
        kitchen->setState(DishState::COOKING);
        kitchen->getBottomBar()->setIsCooking(true, order->getTableNumber());
        setAnimation();
        createObjects();
        greenBar.setSize({0,10});
        greenBar.setFillColor(sf::Color::Green);
        clock.restart();
    }
}

void Chef::update() {
    checkOrder();
    cook();
    setAnimation();
    updateAnimations();
}

void Chef::updateAnimations() {

    if(animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        currentFrame.left += 40.f;
        if (currentFrame.left >= 120)
            currentFrame.left = 0;

        animationTimer.restart();
        sprite.setTextureRect(currentFrame);
    }
}

void Chef::setKitchen(std::shared_ptr<Kitchen>& k) {
    kitchen.reset();
    kitchen = k;
}

void Chef::createObjects() {
    switch(order->getCurrent())
    {
        case Current::APPETIZER:
            order->setCurrent(Current::MAIN_DISH);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new Appetizer(order->getAppetizers().back());
                dish->setTavNum(order->getTableNumber());
                //setTextureDishes(dish, order->getAppetizers().back());
                dishes.push_back(dish);
                order->getAppetizers().pop_back();
            }
            break;
        case Current::MAIN_DISH:
            order->setCurrent(Current::DESSERT);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new MainCourse(order->getMainCourses().back());
                dish->setTavNum(order->getTableNumber());
                dishes.push_back(dish);
                order->getMainCourses().pop_back();
            }
            break;
        case Current::DESSERT:
            order->setCurrent(Current::END);
            for(int i = 0; i < order->getPeopleNumber(); i++)
            {
                dish = new Dessert(order->getDesserts().back());
                dish->setTavNum(order->getTableNumber());
                dishes.push_back(dish);
                order->getDesserts().pop_back();
            }
            break;
        case Current::END:
            break;
    }
    if(!dishes.empty())
    {
        time = 0;
        for(auto & it: dishes)
        {
            time += it->getPreparationTime();
        }
        time /= float(dishes.size());
    }
}

void Chef::initBar() {

    greyBar.setSize({totalBarIteration,10});
    greyBar.setPosition(1240,530);
    greyBar.setFillColor(sf::Color::Black);

    greenBar.setSize({0,10});
    greenBar.setPosition(1240,530);
    greenBar.setFillColor(sf::Color::Green);

}

void Chef::renderBar(sf::RenderTarget &target) {
    if(state == Do::COOK) {
        target.draw(greyBar);
        target.draw(greenBar);
    }

}

void Chef::updateBar() {
    if(greenBar.getSize().x == 30)
        greenBar.setFillColor(sf::Color::Red);
    else if(state == Do::COOK){
        greenBar.setSize({greenBar.getSize().x+1, greenBar.getSize().y});
    }
}

void Chef::setTime(float f) {
    time = f;
}

void Chef::setState(Do d) {
    state = d;
}

Do Chef::getDo() {
    return state;
}

bool Chef::getIsReady() const {
    return isReady;
}

std::vector<Dish *> &Chef::getDishes() {
    return dishes;
}

