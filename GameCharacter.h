//
// Created by Paolo Sbarzagli on 31/01/23.
//

#ifndef VIDEOGIOCO_GAMECHARACTER_H
#define VIDEOGIOCO_GAMECHARACTER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum Move {MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT, STANDING};
enum Actions {DOING_NOTHING, RECEIVING_CUSTOMERS, TAKING_ORDER, LEAVING_ORDER, TAKING_DISHES,
    LEAVING_DISHES, TAKING_EMPTY_DISHES, LEAVING_EMPTY_DISHES};

class GameCharacter {
public:
    //Constructor & Destructor
    GameCharacter();
    virtual ~GameCharacter();

    //Method to Update GameCharacter variables and to display it on the screen
    virtual void update();
    virtual void updateAnimations();
    void render(sf::RenderTarget& target);

    //Method to have the borders of the GameCharacter
    sf::FloatRect getBounds();

    //Methods to modify GameCharacter position
    void setPositionW(sf::Vector2f pos);
    void setPositionW(float x, float y);
    std::map<std::string, bool> validMovement;
    void initValidMovement();
    sf::FloatRect getGlobalHitbox();

    //Getters & Setters
    void setEvent(sf::Event ev);
    Move getMovingStatus();
    Move movingStatus;
    const sf::Vector2f& getPosition() const;
    sf::FloatRect& getHitbox();
    sf::Sprite& getSprite();
    Actions getState();
    void setState(Actions a);

protected:
    sf::Sprite sprite;
    sf::FloatRect hitbox = {15.f,40.f,25.f,10.f};
    sf::Texture texture;
    sf::IntRect currentFrame;
    sf::Clock animationTimer;
    sf::Event ev;
    float speed;
    Move preMovingStatus;

    Actions state;

    //Method to init the texture and the sprite
    virtual void initTexture();
    virtual void initSprite();

};


#endif //VIDEOGIOCO_GAMECHARACTER_H
