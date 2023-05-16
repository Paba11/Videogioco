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
    target.draw(sprite);
    for(int i=0; i<orders.size() ; i++){
        target.draw(ordersSprite[i]);
        target.draw(numOrder[i]);
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

        order.setTexture(*this->texture->getTexture("BoxBottomBar"));
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
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(ordersSprite[orders.size()-1].getPosition().x,ordersSprite[orders.size()-1].getPosition().y - 10);
    if(numOrder.size() != orders.size())
        numOrder.push_back(text);
    else
        numOrder[orders.size()-1] = text;
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
    sf::FloatRect textRect = cookingText.getLocalBounds();
    cookingText.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    cookingText.setPosition(cookingSprite.getPosition().x, cookingSprite.getPosition().y -10);

}

void BottomBar::setIsReady(bool t, int n) {
    isReady = t;
    readyText.setString(std::to_string(n+1));
    sf::FloatRect textRect = readyText.getLocalBounds();
    readyText.setOrigin(textRect.left + textRect.width/2.0f,
                          textRect.top  + textRect.height/2.0f);
    readyText.setPosition(readySprite.getPosition().x, readySprite.getPosition().y -10);
}

bool BottomBar::getIsReady() const {
    return isReady;
}

void BottomBar::delOrder(int n) {

    orders.erase(find(orders.begin(),orders.end(),n+1));

    for(int i = 0; i < orders.size(); i++){
        numOrder[i].setString(std::to_string(orders[i]));
        sf::FloatRect textRect = numOrder[i].getLocalBounds();
        numOrder[i].setOrigin(textRect.left + textRect.width/2.0f,
                       textRect.top  + textRect.height/2.0f);
        numOrder[i].setPosition(ordersSprite[i].getPosition().x,ordersSprite[i].getPosition().y - 10);
    }



}
