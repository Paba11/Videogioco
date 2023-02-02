//
// Created by Paolo Sbarzagli on 02/02/23.
//

#ifndef VIDEOGIOCO_DISH_H
#define VIDEOGIOCO_DISH_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum Type {APPETIZER = 1, MAIN_COURSE, DESSERT, DRINK};
enum Appetizer {NACHOS = 1};
enum Main {HAMBURGER = 1, MEAT, CHICKEN, MEATBALLS};
enum Dessert {CHOCOLATE_CAKE = 1, CHEESE_CAKE, JELLY};
enum Drink {};

class Dish {
public:
    //Constructor & Destructor
    Dish(float dirX, float dirY, float speed, int type, int subType);
    ~Dish();

    //Methods to update and display the dish
    void render();
    void update();

    //Methods to initialize the texture and the sprite based on the dish type
    void initTexture(int subType);
    void initSprite();

    //Methods to select the right texture
    void selectAppetizer(int subType);
    void selectMain(int subType);
    void selectDessert(int subType);
    void selectDrink(int subType);

    //Method to have the position of the dish
    const sf::FloatRect getBounds() const;

private:
    sf::Texture* texture;
    sf::Sprite sprite;
    sf::Vector2f direction;
    float speed;
    Type type;
    Appetizer appetizer;
    Main main;
    Dessert dessert;
    Drink drink;
};


#endif //VIDEOGIOCO_DISH_H
