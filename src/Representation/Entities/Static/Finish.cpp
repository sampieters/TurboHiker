/**
 * \brief The Finish visualization class, a class that allows to show a finish on a screen.
 * \author Sam Pieters
 * \date 18 December 2020
 */

#include "Finish.h"

turbohikerSFML::Finish::Finish() : turbohikerSFML::Entity("finish.png") {}

void turbohikerSFML::Finish::display()
{
        sf::Sprite new_sprite = getSprite();

        new_sprite.setOrigin(static_cast<float>(new_sprite.getTextureRect().width) / 2,
                             static_cast<float>(new_sprite.getTextureRect().height / 2));
        /* transform the width and height of the object to width and height */
        auto S_Width = new_sprite.getTextureRect().width;
        auto S_Height = new_sprite.getTextureRect().height;

        std::pair<float, float> D_Size = {this->getSize().first, this->getSize().second};
        std::pair<float, float> D_Pos = {this->getPosition().first, this->getPosition().second};

        Transformation::Getinstance().convert(D_Pos, D_Size);

        new_sprite.setScale(D_Size.first / S_Width, D_Size.second / S_Height);
        new_sprite.setPosition(D_Pos.first, D_Pos.second);
        new_sprite.setTexture(getTexture());

        getWindowToDrawTo()->draw(new_sprite);
}
