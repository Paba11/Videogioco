//
// Created by Ettore Righi on 28/02/23.
//

#include <iostream>
#include "BottomBar.h"

BottomBar::BottomBar() {
    this->texture = new Textures();
    initSprite();
    initFont();
    initText();
    isCooking = false;
    isReady = false;

}

BottomBar::~BottomBar() = default;

void BottomBar::update() {

}

void BottomBar::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
    int i=0;
    for(auto &it:numOrder){
        target.draw(ordersSprite[i]);
        target.draw(it);
        i++;
    }
    if(isCooking){
        target.draw(cookingSprite);
        target.draw(cookingText);
    }
    if(isReady) {
        target.draw(readySprite);
        target.draw(readyText);
    }

}

void BottomBar::initSprite() {

    this->sprite.setPosition(5,1210);
    this->sprite.setTexture(*this->texture->getTexture("BottomBar"));
    this->sprite.setScale(0.7f,0.7f);
    sf::Sprite order;
    for(int i=0; i < 6 ; i++){

        order.setTexture(*this->texture->getTexture("BlockNotesBottomBar"));
        order.setOrigin(37,55);
        order.setScale(0.75f, 0.75f);
        ordersSprite.push_back(order);
    }
    setOrdersPosition();

    readySprite.setTexture(*texture->getTexture("BoxBottomBar"));
    readySprite.setOrigin(37, 55);
    readySprite.setScale(0.75f, 0.75f);
    readySprite.setPosition(1100,1170);

    cookingSprite.setTexture(*texture->getTexture("BoxBottomBar"));
    cookingSprite.setOrigin(37, 55);
    cookingSprite.setScale(0.75f, 0.75f);
    cookingSprite.setPosition(720,1170);

}

void BottomBar::setOrder(int n) {
    orders.push_back(n+1);
    updateOrders();
}

void BottomBar::updateOrders() {        //TODO: remove the number when the order is completed
    sf::Text text;
    text.setString(std::to_string(orders.back()));
    text.setFont(font);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::Black);
    float pos = 438 - (float)numOrder.size() * 80;
    text.setPosition(pos,1095);
    numOrder.push_back(text);
}

void BottomBar::setOrdersPosition() {

    ordersSprite[0].setPosition(450,1170);
    ordersSprite[1].setPosition(370,1170);
    ordersSprite[2].setPosition(290,1170);
    ordersSprite[3].setPosition(210,1170);
    ordersSprite[4].setPosition(130,1170);
    ordersSprite[5].setPosition(50,1170);
}

void BottomBar::initFont() {
    if(!this->font.loadFromFile("./Font/8-bit Arcade In.ttf")){
        std::cout << "ERROR::CAN'T LOAD FONT FILE" << std::endl;
    }
}

void BottomBar::initText() {

    cookingText.setFont(font);
    cookingText.setCharacterSize(80);
    cookingText.setFillColor(sf::Color::Black);
    cookingText.setPosition(710, 1095);

    readyText.setFont(font);
    readyText.setCharacterSize(80);
    readyText.setFillColor(sf::Color::Black);
    readyText.setPosition(1090,1095);

}

void BottomBar::setIsCooking(bool t, int n) {
    isCooking = t;
    cookingText.setString(std::to_string(n+1));
}

void BottomBar::setIsReady(bool t, int n) {
    isReady = t;
    readyText.setString(std::to_string(n+1));
}

bool BottomBar::getIsReady() const {
    return isReady;
}
