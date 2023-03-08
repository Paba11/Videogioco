//
// Created by Ettore Righi on 06/03/23.
//

#ifndef VIDEOGIOCO_HOWTOPLAY_H
#define VIDEOGIOCO_HOWTOPLAY_H
#include "ProgramState.h"
#include "Textures.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>


class HowToPlay : public ProgramState{
public:
    HowToPlay(sf::RenderWindow* window, std::stack <ProgramState*>* states);
    ~HowToPlay() override;

    void update() override;
    void updateButtons();
    void updateAnimations();
    void render(sf::RenderTarget* target) override;
    void renderButtons();

    void endState() override;

private:

    sf::VideoMode videoMode;
    sf::Vector2f mousePosView;
    sf::Event ev;
    std::map <std::string, Button*> buttons;

    sf::Font font;
    sf::Sprite background;
    sf::Sprite wasd; //arrows
    sf::Sprite waiter;
    sf::Text moveWaiter;

    sf::Text interactions;

    sf::Sprite jSprite;    // j = lasci ordine, prendi ordine, accompagni i clienti  k = prendi i piatti pieni/vuoti  l = lasci i piatti
    sf::Text jText;

    sf::Sprite kSprite;
    sf::Text kText;

    sf::Sprite lSprite;
    sf::Text lText;

    Textures* texture;
    sf::IntRect waiterCurrentFrame;
    sf::Clock waiterAnimationTimer;
    sf::IntRect wasdCurrentFrame;
    sf::Clock wasdAnimationTimer;

    void initVariables();
    void initFont();
    void initTexts();
    void setText(sf::Text* text);
    void initButtons();
    void initSprites();
    void initWaiterSprite();
    void initWasdSprite();
    void updateMousePosition();




};


#endif //VIDEOGIOCO_HOWTOPLAY_H
