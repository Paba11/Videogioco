//
// Created by Ettore Righi on 04/02/23.
//

#ifndef VIDEOGIOCO_TABLE_H
#define VIDEOGIOCO_TABLE_H


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Table {
public:
    Table();
    virtual ~Table();
    void update();
    void render(sf::RenderTarget& target);
    void initTexture() ;
    void initSprite();
    sf::Sprite sprite;
    sf::Texture texture;

private:

};


#endif //VIDEOGIOCO_TABLE_H
