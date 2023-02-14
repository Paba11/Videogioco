//
// Created by Ettore Righi on 14/02/23.
//

#ifndef VIDEOGIOCO_TEXTURES_H
#define VIDEOGIOCO_TEXTURES_H


#include <map>
#include <SFML/Graphics.hpp>

class Textures {
public:
    Textures();
    ~Textures();
    std::map <std::string,sf::Texture*> textures;
    sf::Texture* getTexture(std::string name);

private:
    void loadTexture();
};


#endif //VIDEOGIOCO_TEXTURES_H
