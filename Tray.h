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

#include "Dish.h"
#include <queue>

#define MAX_DISHES 4
enum TrayState {EMPTY_TRAY = 1, FILLED_TRAY, EMPTY_PLATES};

class Tray {
public:
    //Constructor & Destructor
    Tray();
    ~Tray();

    //Methods to update and render the tray
    void update();
    void render(sf::RenderTarget &target);

    //Getters & Setters
    const sf::Vector2f& getPosition() const;

    //Method to set the tray state
    void setState(TrayState ts);
    TrayState getState();
    Dish* getDish();
    void setDish(Dish* dish);
    std::queue<Dish*>& getDishes();


private:
    void initTexture();
    void initSprite();
    sf::Texture texture;
    sf::Sprite sprite;

    std::queue<Dish*> dishes;
    TrayState state;

};


#endif //VIDEOGIOCO_TRAY_H
