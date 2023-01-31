//
// Created by Paolo Sbarzagli on 30/01/23.
//

#ifndef VIDEOGIOCO_GAME_H
#define VIDEOGIOCO_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class Game {
public:
    //Constructor & Destructor
    Game();
    ~Game();

    //Methods to update the game and display the correct images
    void update();
    void render();

    //Method to manage the events
    void pollEvents();

    //Method to check if the window is still open, so if the game is running
    const bool getWindowIsOpen();

private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    void initVariables();
    void initWindow();

};


#endif //VIDEOGIOCO_GAME_H
