//
// Created by Sam Pieters on 01/12/2020.
//

#include "Player.h"

turbohikerSFML::Player::Player() : turbohikerSFML::Entity("flash/flash.png") { sf::SoundBuffer sound; }

void turbohikerSFML::Player::display()
{
        sf::Sprite new_sprite = getSprite();

        new_sprite.setOrigin(static_cast<float>(new_sprite.getTextureRect().width) / 2,
                             static_cast<float>(new_sprite.getTextureRect().height / 2));
        // transform the width and height of the object to width and height
        auto S_Width = new_sprite.getTextureRect().width;
        auto S_Height = new_sprite.getTextureRect().height;

        std::pair<float, float> D_Size = {this->getSize().first, this->getSize().second};
        std::pair<float, float> D_Pos = {this->getPosition().first, this->getPosition().second};

        Transformation::Getinstance().convert(D_Pos, D_Size);
        new_sprite.setScale(D_Size.first / S_Width, D_Size.second / S_Height);
        new_sprite.setPosition(D_Pos.first, D_Pos.second);
        new_sprite.setTexture(getTexture());
        getWindowToDrawTo()->draw(new_sprite);

        // IF YELLED -> DISPLAY YELL

        if (this->isYell()) {
                sf::Sprite balloon;
                sf::Texture text_1;
                text_1.loadFromFile("Resources/flash/flash_textballoon.png");
                balloon.setTexture(text_1);
                balloon.setOrigin(0, balloon.getTextureRect().height);
                balloon.setPosition(D_Pos.first, D_Pos.second);
                // Set Textballoon right above the player
                balloon.setScale(0.4, 0.4);

                sf::Font font;
                font.loadFromFile("Resources/BalooBhai-Gujarati.ttf");
                sf::Text text;
                text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
                text.setFont(font);
                text.setString(this->getYelling());
                text.setFillColor(sf::Color::Black);
                text.setCharacterSize(20);
                text.setPosition(balloon.getPosition().x, balloon.getPosition().y);

                sf::FloatRect rectBounds = balloon.getGlobalBounds();
                sf::FloatRect textBounds = text.getGlobalBounds();

                text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                                 rectBounds.top + (rectBounds.height / 2) - textBounds.height);

                getWindowToDrawTo()->draw(balloon);
                getWindowToDrawTo()->draw(text);
        }
}
