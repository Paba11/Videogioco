//
// Created by Paolo Sbarzagli on 10/02/23.
//

#ifndef VIDEOGIOCO_WASHBASIN_H
#define VIDEOGIOCO_WASHBASIN_H

#include "../Textures.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Washbasin {
public:
    //Constructor & Destructor
    Washbasin();
    ~Washbasin();

    //Methods to update and render the tray
    void update();
    void updateBox();

    void render(sf::RenderTarget& target);

    //Position of Washbasin

    //Getters & Setters
    bool getIsPlates() const;
    void setIsPlates(bool t);
    sf::Vector2f getPosition();
    sf::Sprite getSprite();
    int getNumPlates() const;
    void setNumPlates(int i);
    void setTakenDirtyDish(bool t);


private:
    //Set The texture and the sprite
    Textures* texture = new Textures;
    sf::Sprite sprite;
    void initSprite();
    bool isPlates;
    int numPlates;

    sf::RectangleShape interactionSquare;
    sf::Color boxOpacity = {253,202,78,255};
    bool cicle;
    bool takenDirtyDish;
    sf::Sprite cornerSprite;

};


#endif //VIDEOGIOCO_WASHBASIN_H
