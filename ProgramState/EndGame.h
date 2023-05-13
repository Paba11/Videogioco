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
    EndGame(sf::RenderWindow* window, std::stack <ProgramState*>* states, int score, int servedCustomer,
            int servedTable, int goneTable);
    ~EndGame() override;

    void update() override;
    void updateButtons();
    void updateMousePosition();

    void render(sf::RenderTarget* target) override;
    void renderButtons();
    void endState() override;
private:

    void initText();
    void initButtons();
    void setExtraInfo();

    sf::Text gameOver;
    sf::Font font;
    int score;

    int servedCustomer;
    sf::Text sCustomer;

    int servedTable;
    sf::Text sTable;

    int goneTable;
    sf::Text gTable;

    sf::Text scorePoint;

    std::map <std::string, Button*> buttons;
    sf::Vector2f mousePosView;
};


#endif //VIDEOGIOCO_ENDGAME_H
