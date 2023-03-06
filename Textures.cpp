//
// Created by Ettore Righi on 14/02/23.
//

#include <iostream>
#include "Textures.h"

Textures::Textures() {
    loadTexture();
}

Textures::~Textures() {

}

sf::Texture* Textures::getTexture(std::string name) {
    // See if we have already loaded this texture
    return textures[name];
}


 void Textures::loadTexture() {

    textures["RestaurantMap"] = new sf::Texture();
    if(!textures["RestaurantMap"]->loadFromFile("../Textures/new_textures/Mappa.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE MAP FILE" << std::endl;
    }
    textures["Table"] = new sf::Texture();
    if(!textures["Table"]->loadFromFile("../Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE TABLE FILE" << std::endl;
    }
     textures["Waiter"] = new sf::Texture();
     if (!this->textures["Waiter"]->loadFromFile("../Textures/new_textures/Waiter_Male_1.png"))
     {
         std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Washbasin"] = new sf::Texture();
     if (!this->textures["Washbasin"]->loadFromFile("../Textures/new_Textures/Lavabo.png"))
     {
         std::cout << "ERROR::Washbasin::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Kitchen"] = new sf::Texture();
     if (!this->textures["Kitchen"]->loadFromFile("../Textures/new_textures/Cucina.png"))
     {
         std::cout << "ERROR::KITCHEN::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Stool"] = new sf::Texture();
     if (!this->textures["Stool"]->loadFromFile("../Textures/new_textures/Sgabello Rosso.png"))
     {
         std::cout << "ERROR::STOOL::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Tree"] = new sf::Texture();
     if (!this->textures["Tree"]->loadFromFile("../Textures/new_textures/Albero.png"))
     {
         std::cout << "ERROR::TREE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Entrance"] = new sf::Texture();
     if (!this->textures["Entrance"]->loadFromFile("../Textures/new_textures/Ingresso.png"))
     {
         std::cout << "ERROR::ENTRANCE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["MainMenu"] = new sf::Texture();
     if (!this->textures["MainMenu"]->loadFromFile("../Textures/new_textures/MainMenu.png"))
     {
         std::cout << "ERROR::MAINMENU::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Chef"] = new sf::Texture();
     if (!this->textures["Chef"]->loadFromFile("../Textures/new_textures/Chef.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Counter"] = new sf::Texture();
     if (!this->textures["Counter"]->loadFromFile("../Textures/new_textures/Bancone.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Dishwasher"] = new sf::Texture();
     if (!this->textures["Dishwasher"]->loadFromFile("../Textures/new_textures/Dishwasher.png"))
     {
         std::cout << "ERROR::DISHWASHER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Main1"] = new sf::Texture();
     if (!this->textures["Main1"]->loadFromFile("../Textures/Main1.png"))
     {
         std::cout << "ERROR::Main1::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer1"] = new sf::Texture();
     if (!this->textures["Customer1"]->loadFromFile("../Textures/new_textures/Cliente1.png"))
     {
         std::cout << "ERROR::Customer1::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer2"] = new sf::Texture();
     if (!this->textures["Customer2"]->loadFromFile("../Textures/new_textures/Cliente2.png"))
     {
         std::cout << "ERROR::Customer2::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer3"] = new sf::Texture();
     if (!this->textures["Customer3"]->loadFromFile("../Textures/new_textures/Cliente3.png"))
     {
         std::cout << "ERROR::Customer3::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer4"] = new sf::Texture();
     if (!this->textures["Customer4"]->loadFromFile("../Textures/new_textures/Cliente4.png"))
     {
         std::cout << "ERROR::Customer4::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["BottomBar"] = new sf::Texture();
     if (!this->textures["BottomBar"]->loadFromFile("../Textures/new_textures/BarraOrdini.png"))
     {
         std::cout << "ERROR::BottomBar::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Barrier"] = new sf::Texture();
     if (!this->textures["Barrier"]->loadFromFile("../Textures/new_textures/Transenne.png"))
     {
         std::cout << "ERROR::Barrier::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Waiter_Female_1"] = new sf::Texture();
     if (!this->textures["Waiter_Female_1"]->loadFromFile("../Textures/new_textures/Waiter_Female_1.png"))
     {
         std::cout << "ERROR::WaiterFemale::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["ChoosingCharacterBackground"] = new sf::Texture();
     if (!this->textures["ChoosingCharacterBackground"]->loadFromFile("../Textures/new_textures/SfondoSceltaCameriere.png"))
     {
         std::cout << "ERROR::ChoosingCharacterBackground::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["WASD"] = new sf::Texture();
     if (!this->textures["WASD"]->loadFromFile("../Textures/new_textures/WASD.png"))
     {
         std::cout << "ERROR::WASD::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["jKey"] = new sf::Texture();
     if (!this->textures["jKey"]->loadFromFile("../Textures/new_textures/TastoJ.png"))
     {
         std::cout << "ERROR::jKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["kKey"] = new sf::Texture();
     if (!this->textures["kKey"]->loadFromFile("../Textures/new_textures/TastoK.png"))
     {
         std::cout << "ERROR::kKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["lKey"] = new sf::Texture();
     if (!this->textures["lKey"]->loadFromFile("../Textures/new_textures/TastoL.png"))
     {
         std::cout << "ERROR::lKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }


}

