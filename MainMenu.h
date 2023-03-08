//
// Created by Ettore Righi on 18/02/23.
//

#ifndef VIDEOGIOCO_MAINMENU_H
#define VIDEOGIOCO_MAINMENU_H


#include <SFML/Graphics.hpp>
#include "Textures.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "ProgramState.h"
#include "ChoosingCharacter.h"
#include "HowToPlay.h"

class MainMenu : public ProgramState{

public:
    MainMenu(sf::RenderWindow* window, std::stack <ProgramState*>* states);
    ~MainMenu() override;
    void update() override;
    void updateMousePosition();
    void initFonts();
    void render(sf::RenderTarget* target) override;
    void renderButtons();
    void updateButtons();
    const bool getWindowIsOpen();
    void pollEvents();

    void endState() override;

private:
    Textures* texture;
    sf::Sprite background;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Vector2f mousePosView;
    sf::Font font;

    std::map <std::string, Button*> buttons;
    void initButtons();
    void initBackground();
    void initTexture();
    void initWindow();

};


#endif //VIDEOGIOCO_MAINMENU_H
