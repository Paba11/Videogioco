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


class Counter {
public:
    Counter();
    ~Counter();
    void render(sf::RenderTarget& target);
    const sf::FloatRect getBounds() const;
    sf::RectangleShape& getPlaceDirtyDishes();
    std::vector<sf::RectangleShape> getPlaceChefDishes();
    void setDirtyDishes();
    void setChefDishes();

    //Set the dishes on the counter
    Dish* getDish();
    void setDish(Dish* dish);
    std::queue<Dish *>& getDishes();

private:
    std::queue<Dish*> dishes;
    sf::Sprite sprite;
    sf::RectangleShape placeForDirtyDishes;
    std::vector <sf::RectangleShape> chefDishes;
    Textures* texture;

    sf::Vector2f dishHitbox = {85.f,80.f};

    void initSprite();

};


#endif //VIDEOGIOCO_COUNTER_H
