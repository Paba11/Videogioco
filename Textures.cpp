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
    if(!textures["RestaurantMap"]->loadFromFile("./Textures/new_textures/Mappa.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE MAP FILE" << std::endl;
    }
    textures["Table"] = new sf::Texture();
    if(!textures["Table"]->loadFromFile("./Textures/new_textures/Tavolo.png"))
    {
        std::cout << "ERROR::GAME::CAN'T LOAD TEXTURE TABLE FILE" << std::endl;
    }
     textures["Waiter"] = new sf::Texture();
     if (!this->textures["Waiter"]->loadFromFile("./Textures/new_textures/Waiter_Male_1.png"))
     {
         std::cout << "ERROR::WAITER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Washbasin"] = new sf::Texture();
     if (!this->textures["Washbasin"]->loadFromFile("./Textures/new_Textures/Lavabo.png"))
     {
         std::cout << "ERROR::Washbasin::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Kitchen"] = new sf::Texture();
     if (!this->textures["Kitchen"]->loadFromFile("./Textures/new_textures/Cucina.png"))
     {
         std::cout << "ERROR::KITCHEN::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Stool"] = new sf::Texture();
     if (!this->textures["Stool"]->loadFromFile("./Textures/new_textures/Sgabello Rosso.png"))
     {
         std::cout << "ERROR::STOOL::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Tree"] = new sf::Texture();
     if (!this->textures["Tree"]->loadFromFile("./Textures/new_textures/Albero.png"))
     {
         std::cout << "ERROR::TREE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Entrance"] = new sf::Texture();
     if (!this->textures["Entrance"]->loadFromFile("./Textures/new_textures/Ingresso.png"))
     {
         std::cout << "ERROR::ENTRANCE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["MainMenu"] = new sf::Texture();
     if (!this->textures["MainMenu"]->loadFromFile("./Textures/new_textures/MainMenu.png"))
     {
         std::cout << "ERROR::MAINMENU::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Chef"] = new sf::Texture();
     if (!this->textures["Chef"]->loadFromFile("./Textures/new_textures/Chef.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Counter"] = new sf::Texture();
     if (!this->textures["Counter"]->loadFromFile("./Textures/new_textures/Bancone.png"))
     {
         std::cout << "ERROR::CHEF::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Dishwasher"] = new sf::Texture();
     if (!this->textures["Dishwasher"]->loadFromFile("./Textures/new_textures/Dishwasher.png"))
     {
         std::cout << "ERROR::DISHWASHER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer1"] = new sf::Texture();
     if (!this->textures["Customer1"]->loadFromFile("./Textures/new_textures/Cliente1.png"))
     {
         std::cout << "ERROR::Customer1::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer2"] = new sf::Texture();
     if (!this->textures["Customer2"]->loadFromFile("./Textures/new_textures/Cliente2.png"))
     {
         std::cout << "ERROR::Customer2::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer3"] = new sf::Texture();
     if (!this->textures["Customer3"]->loadFromFile("./Textures/new_textures/Cliente3.png"))
     {
         std::cout << "ERROR::Customer3::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Customer4"] = new sf::Texture();
     if (!this->textures["Customer4"]->loadFromFile("./Textures/new_textures/Cliente4.png"))
     {
         std::cout << "ERROR::Customer4::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["BottomBar"] = new sf::Texture();
     if (!this->textures["BottomBar"]->loadFromFile("./Textures/new_textures/BarraOrdini.png"))
     {
         std::cout << "ERROR::BottomBar::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Barrier"] = new sf::Texture();
     if (!this->textures["Barrier"]->loadFromFile("./Textures/new_textures/Transenne.png"))
     {
         std::cout << "ERROR::Barrier::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Waiter_Female_1"] = new sf::Texture();
     if (!this->textures["Waiter_Female_1"]->loadFromFile("./Textures/new_textures/Waiter_Female_1.png"))
     {
         std::cout << "ERROR::WaiterFemale::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["ChoosingCharacterBackground"] = new sf::Texture();
     if (!this->textures["ChoosingCharacterBackground"]->loadFromFile("./Textures/new_textures/SfondoSceltaCameriere.png"))
     {
         std::cout << "ERROR::ChoosingCharacterBackground::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["WASD"] = new sf::Texture();
     if (!this->textures["WASD"]->loadFromFile("./Textures/new_textures/WASD.png"))
     {
         std::cout << "ERROR::WASD::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["jKey"] = new sf::Texture();
     if (!this->textures["jKey"]->loadFromFile("./Textures/new_textures/TastoJ.png"))
     {
         std::cout << "ERROR::jKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["kKey"] = new sf::Texture();
     if (!this->textures["kKey"]->loadFromFile("./Textures/new_textures/TastoK.png"))
     {
         std::cout << "ERROR::kKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["lKey"] = new sf::Texture();
     if (!this->textures["lKey"]->loadFromFile("./Textures/new_textures/TastoL.png"))
     {
         std::cout << "ERROR::lKey::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["HAMBURGER"] = new sf::Texture();
     if (!this->textures["HAMBURGER"]->loadFromFile("./Textures/Main1.png"))
     {
         std::cout << "ERROR::HAMBURGER::CAN'T LOAD TEXTURE FILE" << std::endl;
     }  //
     textures["MEAT"] = new sf::Texture();
     if (!this->textures["MEAT"]->loadFromFile("./Textures/Main2.png"))
     {
         std::cout << "ERROR::MEAT::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["MEATBALLS"] = new sf::Texture();
     if (!this->textures["MEATBALLS"]->loadFromFile("./Textures/Main3.png"))
     {
         std::cout << "ERROR::MEATBALLS::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["CHICKEN"] = new sf::Texture();
     if (!this->textures["CHICKEN"]->loadFromFile("./Textures/Main4.png"))
     {
         std::cout << "ERROR::CHICKEN::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["NACHOS"] = new sf::Texture();
     if (!this->textures["NACHOS"]->loadFromFile("./Textures/Appetizer1.png"))
     {
         std::cout << "ERROR::NACHOS::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["OMELETTE"] = new sf::Texture();
     if (!this->textures["OMELETTE"]->loadFromFile("./Textures/Appetizer2.png"))
     {
         std::cout << "ERROR::OMELETTE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["CHOCOLATE_CAKE"] = new sf::Texture();
     if (!this->textures["CHOCOLATE_CAKE"]->loadFromFile("./Textures/Dessert1.png"))
     {
         std::cout << "ERROR::CHOCOLATE_CAKE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["CHEESE_CAKE"] = new sf::Texture();
     if (!this->textures["CHEESE_CAKE"]->loadFromFile("./Textures/Dessert2.png"))
     {
         std::cout << "ERROR::CHEESE_CAKE::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["JELLY"] = new sf::Texture();
     if (!this->textures["JELLY"]->loadFromFile("./Textures/Dessert3.png"))
     {
         std::cout << "ERROR::JELLY::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["EmptyDish"] = new sf::Texture();
     if (!this->textures["EmptyDish"]->loadFromFile("./Textures/EmptyDish.png"))
     {
         std::cout << "ERROR::EmptyDish::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["BlockNotes"] = new sf::Texture();
     if (!this->textures["BlockNotes"]->loadFromFile("./Textures/BlockNotes.png"))
     {
         std::cout << "ERROR::BlockNotes::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Pan"] = new sf::Texture();
     if (!this->textures["Pan"]->loadFromFile("./Textures/Padella.png"))
     {
         std::cout << "ERROR::Pan::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["Pot"] = new sf::Texture();
     if (!this->textures["Pot"]->loadFromFile("./Textures/Pentola.png"))
     {
         std::cout << "ERROR::Pot::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["BlockNotesBottomBar"] = new sf::Texture();
     if (!this->textures["BlockNotesBottomBar"]->loadFromFile("./Textures/BlockNotes BottomBar.png"))
     {
         std::cout << "ERROR::BlockNotesBottomBar::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
     textures["BoxBottomBar"] = new sf::Texture();
     if (!this->textures["BoxBottomBar"]->loadFromFile("./Textures/Box BottomBar.png"))
     {
         std::cout << "ERROR::BoxBottomBar::CAN'T LOAD TEXTURE FILE" << std::endl;
     }
}

