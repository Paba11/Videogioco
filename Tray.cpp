//
// Created by Paolo Sbarzagli on 07/02/23.
//

#include "Tray.h"


Tray::Tray() {
    this->state = TrayState::EMPTY_TRAY;
    initTexture();
    initSprite();
    orderTaken = false;
    initRectangle();
    initDishesPos();
}

Tray::~Tray() {
    Dish* d;
    for(int i = 0; !this->dishes.empty(); i++)
    {
        d = this->dishes.front();
        this->dishes.pop();
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
    for(int i = 0; i < 4; i++)
        target.draw(dishesPos[i]);
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
    return this->state;
}

Dish *Tray::getDish() {
    Dish* d = this->dishes.front();
    this->dishes.pop();
    return d;
}

void Tray::setDish(Dish* d, int n) {
    d->setPosition(dishesPos[n].getPosition());
    d->setScale(2,2);
    this->dishes.push(d);
}

std::queue<Dish *>& Tray::getDishes() {
    return this->dishes;
}

void Tray::setOrderTaken(bool t) {
    orderTaken = t;
}

void Tray::initSprite() {

    blockNotes.setTexture(*this->texture->getTexture("BlockNotes"));
    currentFrame = sf::IntRect (0,0,480,480);
    blockNotes.setTextureRect(this->currentFrame);
    blockNotes.setTextureRect({0,0,480,480});
    blockNotes.setScale(0.2f,0.2f);
    blockNotes.setPosition(50,1240);
}

void Tray::initTexture() {
    texture = new Textures();
}

void Tray::updateAnimation() {

    if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f) {
        //Idle animation

        this->currentFrame.left += 480.f;
        if (this->currentFrame.left >= 960)
            this->currentFrame.left = 0;

        animationTimer.restart();
        blockNotes.setTextureRect(this->currentFrame);
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
        sf::RectangleShape rectangle;

        rectangle.setSize(this->dishHitbox);
        rectangle.setOrigin(42.5f,40.f);
        rectangle.setOutlineColor(sf::Color::White);    //Fixme set trasparent when finished
        rectangle.setOutlineThickness(1.f);
        rectangle.setFillColor(sf::Color::Transparent);
        dishesPos.push_back(rectangle);
    }

    this->dishesPos[0].setPosition(200, 1290.f);
    this->dishesPos[1].setPosition(300, 1290.f);
    this->dishesPos[2].setPosition(400, 1290.f);
    this->dishesPos[3].setPosition(500, 1290.f);
}

