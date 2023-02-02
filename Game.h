//
// Created by Paolo Sbarzagli on 30/01/23.
//

#ifndef VIDEOGIOCO_GAME_H
#define VIDEOGIOCO_GAME_H

#include <map>
#include <vector>
#include "Waiter.h"
#include "Map.h"
#include "Customer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class Game {
public:
    //Constructor & Destructor
    Game();
    ~Game();

    //Method to initialize all the textures needed inside the game
    void initTexture();

    //Methods to update the game and display the correct images
    void update();
    void render();
    void renderMap();

    //Method to manage the events
    void pollEvents();

    //Method that update the position of the mouse relative to the game window
    void updateMousePos();

    //Method to check if the window is still open, so if the game is running
    const bool getWindowIsOpen();

    //Getter & Setter for the attributes
    std::map<std::string, sf::Texture*>& getTextures();

private:
    //Group of textures uploaded in a container, each one is accessible by his own name
    std::map<std::string, sf::Texture*> textures;

    //
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::Vector2i mousePos;

    //GameCharacters and objects
    Waiter* waiter;
    Dish* dish;
    Customer* customer;

    //BackGround;
    sf::Sprite background;

    //Text
    sf::Font font;
    sf::Text text;

    void initVariables();
    void initWindow();
    void initWaiter();
    void initBackground();

};


#endif //VIDEOGIOCO_GAME_H
