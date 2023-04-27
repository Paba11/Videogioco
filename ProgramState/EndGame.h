//
// Created by Ettore Righi on 25/04/23.
//

#ifndef VIDEOGIOCO_ENDGAME_H
#define VIDEOGIOCO_ENDGAME_H


#include "ProgramState.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Button.h"


class EndGame : public ProgramState{

public:
    EndGame(sf::RenderWindow* window, std::stack <ProgramState*>* states, int score);
    ~EndGame() override;

    void update() override;
    void updateButtons();
    void updateMousePosition();

    void render(sf::RenderTarget* target) override;
    void renderButtons();
    void endState() override;
private:
    sf::Text text;
    sf::Font font;
    int score;
    sf::Text scorePoint;

    std::map <std::string, Button*> buttons;
    sf::Vector2f mousePosView;


    void initText();
    void initButtons();
};


#endif //VIDEOGIOCO_ENDGAME_H
