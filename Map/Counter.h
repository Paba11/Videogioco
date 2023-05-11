//
// Created by Ettore Righi on 21/02/23.
//

#ifndef VIDEOGIOCO_COUNTER_H
#define VIDEOGIOCO_COUNTER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Textures.h"
#include "../Dish/Dish.h"
#include <queue>

enum class DishState {EMPTY, FULL, COOKING, ALMOST_READY};

class Counter {
public:
    Counter();
    ~Counter();
    void render(sf::RenderTarget& target);
    void renderDishes(sf::RenderTarget& target);
    sf::FloatRect getBounds() const;
    sf::RectangleShape& getPlaceDirtyDishes();
    std::vector<sf::RectangleShape> getPlaceChefDishes();
    void setDirtyDishes();
    void setChefDishes();

    //Set the dishes on the counter
    void setState(DishState ds);
    DishState getState();
    Dish* getDish();
    void setDish(Dish* dish, int i);
    std::queue<Dish *>& getDishes();

private:
    std::queue<Dish*> dishes;
    sf::Sprite sprite;
    sf::RectangleShape placeForDirtyDishes;
    std::vector <sf::RectangleShape> chefDishes;
    Textures* texture;
    DishState state;

    sf::Vector2f dishHitbox = {85.f,80.f};

    void initSprite();

};


#endif //VIDEOGIOCO_COUNTER_H
