//
// Created by Ettore Righi on 20/02/23.
//

#ifndef VIDEOGIOCO_PROGRAMSTATE_H
#define VIDEOGIOCO_PROGRAMSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Textures.h"
#include <stack>
#include <map>

class ProgramState {

public:
    ProgramState(sf::RenderWindow* window, std::stack <ProgramState*>* states);
    virtual ~ProgramState();
    virtual void update() = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void endState() = 0;
    void checkQuit();
    const bool getQuit() const;

protected:
    std::stack <ProgramState*>* states;
    bool quit;
    sf::RenderWindow* window;
    sf::Event ev;
    Textures* textures;

private:


};


#endif //VIDEOGIOCO_PROGRAMSTATE_H
