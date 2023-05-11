//
// Created by Paolo Sbarzagli on 07/02/23.
//

/*
 * Used to bring all the plates and drinks in one time at the designed table
 * When the waiter remove the empty plates from the table the texture displayed is the one of the plate's pile
 * When the waiter brings to the table the drinks or the dishes the tray is a container for all the plates
 */

#ifndef VIDEOGIOCO_TRAY_H
#define VIDEOGIOCO_TRAY_H

#include "Dish/Dish.h"
#include "Textures.h"
#include <queue>

enum class TrayState {EMPTY_TRAY, FILLED_TRAY, EMPTY_PLATES};

class Tray {
public:
    //Constructor & Destructor
    Tray();
    ~Tray();

    //Methods to update and render the tray
    void update();
    void render(sf::RenderTarget &target);
    void renderDishes(sf::RenderTarget& target);
    void updateAnimation();
    //Getters & Setters

    //Method to set the tray state
    void setState(TrayState ts);
    TrayState getState();
    Dish* getDish();
    void setDish(Dish* dish, int n);
    std::queue<Dish*>& getDishes();
    void setOrderTaken(bool t);


private:
    void initRectangle();
    void initSprite();
    void initTexture();
    void initDishesPos();
    sf::RectangleShape rectangle;
    sf::Sprite blockNotes;
    bool orderTaken;
    Textures* texture;

    std::queue<Dish*> dishes;
    TrayState state;

    sf::IntRect currentFrame;
    sf::Clock animationTimer;

    std::vector<sf::RectangleShape> dishesPos;
    sf::Vector2f dishHitbox = {85.f,80.f};


};


#endif //VIDEOGIOCO_TRAY_H
