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

    //Methods
    void update();
    void render();

private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    void initVariables();
    void initWindow();

};


#endif //VIDEOGIOCO_GAME_H
