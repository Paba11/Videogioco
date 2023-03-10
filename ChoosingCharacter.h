//
// Created by Ettore Righi on 02/03/23.
//

#ifndef VIDEOGIOCO_CHOOSINGCHARACTER_H
#define VIDEOGIOCO_CHOOSINGCHARACTER_H


#include "ProgramState.h"
#include "Button.h"

class ChoosingCharacter : public ProgramState{
public:
    ChoosingCharacter(sf::RenderWindow* window, std::stack <ProgramState*>* states);
    ~ChoosingCharacter() override ;

    void update() override;
    void updateButtons();
    void updateAnimations();
    void pollEvents();

    void render(sf::RenderTarget* target) override;
    void renderButtons();

    void endState() override;


private:

    std::map <std::string, Button*> buttons;
    sf::Sprite waiter;
    Textures* texture;
    sf::Vector2f mousePosView;
    sf::Font font;
    sf::IntRect currentFrame;
    sf::Clock animationTimer;
    int chosedTexture;
    sf::Sprite background;
    sf::Text text;



    void initVariables();
    void initButtons();
    void initSprite();
    void updateMousePosition();
    void initFonts();
    void changeTexture();
    void initText();





};


#endif //VIDEOGIOCO_CHOOSINGCHARACTER_H
