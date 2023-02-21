//
// Created by Paolo Sbarzagli on 30/01/23.
//

#ifndef VIDEOGIOCO_GAME_H
#define VIDEOGIOCO_GAME_H

#include <map>
#include <vector>
#include "Waiter.h"
#include "DishWasher.h"
#include "Map.h"
#include "Customer.h"
#include "Table.h"
#include "Textures.h"
#include "ProgramState.h"
#include "Chef.h"
#include "Counter.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <list>

class Game : public ProgramState{
public:
    //Constructor & Destructor
    Game(sf::RenderWindow* window, std::stack <ProgramState*>* states);
    ~Game() override;

    //Method to initialize all the textures needed inside the game
   // void initTexture();

    void endState() override;

    //Methods to update the game and display the correct images
    void update() override;
    void render(sf::RenderTarget* target) override;
    void renderMap();
    void updateCollision();
    void windowsCollision();
    void collision();
    void collisionManagement();


    //Method to manage the events
    void pollEvents();

    //Method that update the position of the mouse relative to the game window
    void updateMousePos();

    //Method to check if the window is still open, so if the game is running
    const bool getWindowIsOpen();

    //Getter & Setter for the attributes


private:
    //Group of textures uploaded in a container, each one is accessible by his own name
    //std::map<std::string, sf::Texture*> textures;
    //std::vector<Table> allTables;
    //
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::Vector2i mousePos;

    //GameCharacters and objects
    Waiter* waiter;
    Chef* chef;
    Dish* dish;
    Map* map;
    Kitchen* kitchen;
    Counter* counter;
    Washbasin* washbasin;
    Customer* customer;
    DishWasher* dishWasher;
    Textures* texture;
    //Table* table;


    //BackGround;
    sf::Sprite background;
    //sf::Sprite table;

    //Text
    sf::Font font;
    sf::Text text;

    //Initialize all the game objects and attributes
    void initVariables();
    void initWindow();
    void initWaiter();
    void initChef();
    void initBackground();
    void initTables();
    void initPosTables();
    void initMap();
    void initTexture();
    void initDishWasher();
    int numTables=6;


};


#endif //VIDEOGIOCO_GAME_H
