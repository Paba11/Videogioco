//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Tray.h"


Tray::Tray() {
    texture = nullptr;
    state = TrayState::EMPTY_TRAY;
    initTexture();
    initSprite();
    orderTaken = false;
    initRectangle();
    initDishesPos();
}

Tray::~Tray() {
    Dish* d;
    for(int i = 0; !dishes.empty(); i++)
    {
        d = dishes.front();
        dishes.pop();
        delete d;
    }
}

void Tray::update() {

    updateAnimation();
}

void Tray::render(sf::RenderTarget &target) {
    target.draw(rectangle);
        if(orderTaken)
            target.draw(blockNotes);
    renderDishes(target);
  //  for(int i = 0; i < 4; i++)
  //      target.draw(dishesPos[i]);
}

void Tray::initRectangle() {

    rectangle.setSize({1300.f, 100.f});
    rectangle.setOrigin(650.f,50.f);
    rectangle.setPosition(650.f,1294.f);
    rectangle.setFillColor({40,33,33,255});

}



void Tray::setState(TrayState ts) {
    this->state = ts;
}


TrayState Tray::getState() {
    return state;
}

Dish *Tray::getDish() {
    Dish* d = dishes.front();
    dishes.pop();
    return d;
}

void Tray::setDish(Dish* d, int n) {
    d->setPosition(dishesPos[n].getPosition());
    d->setScale(2,2);
    dishes.push(d);
}

std::queue<Dish *>& Tray::getDishes() {
    return dishes;
}

void Tray::setOrderTaken(bool t) {
    orderTaken = t;
}

void Tray::initSprite() {

    blockNotes.setTexture(*texture->getTexture("BlockNotes"));
    currentFrame = sf::IntRect (0,0,480,480);
    blockNotes.setTextureRect(currentFrame);
    blockNotes.setTextureRect({0,0,480,480});
    blockNotes.setScale(0.2f,0.2f);
    blockNotes.setPosition(50,1240);
}

void Tray::initTexture() {
    texture = new Textures();
}

void Tray::updateAnimation() {

    if(animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        currentFrame.left += 480.f;
        if (currentFrame.left >= 960)
            currentFrame.left = 0;

        animationTimer.restart();
        blockNotes.setTextureRect(currentFrame);
    }
}

void Tray::renderDishes(sf::RenderTarget &target) {

    std::queue<Dish*> tmp;
    Dish* ptr;
    for(int i = 0; i < dishes.size(); i++)
    {
        ptr = dishes.front();
        dishes.pop();
        ptr->render(target);
        tmp.push(ptr);
        tmp.pop();
        dishes.push(ptr);
    }
}

void Tray::initDishesPos() {


    for(int i = 0; i < 4; i++){
        sf::RectangleShape rect;

        rect.setSize(dishHitbox);
        rect.setOrigin(42.5f,40.f);
        rect.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
        rect.setOutlineThickness(1.f);
        rect.setFillColor(sf::Color::Transparent);
        dishesPos.push_back(rect);
    }

    dishesPos[0].setPosition(200, 1290.f);
    dishesPos[1].setPosition(300, 1290.f);
    dishesPos[2].setPosition(400, 1290.f);
    dishesPos[3].setPosition(500, 1290.f);
}

