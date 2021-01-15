/**
 * \brief The Entity class, a superclass that allowes to show an entity on a screen.
 * \author Sam Pieters
 * \date 01 December 2020
 */

#ifndef TURBOHIKERSFML_ENTITY_H
#define TURBOHIKERSFML_ENTITY_H

#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../../Logic/Entities/Entity.h"
#include "../../Singletons/Transformation.h"

namespace turbohikerSFML {
    class Entity {
    private:
        std::shared_ptr<sf::RenderWindow> WindowToDrawTo;
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        Entity(const std::string& texture);

        const std::shared_ptr<sf::RenderWindow> &getWindowToDrawTo() const;

        void setWindowToDrawTo(const std::shared_ptr<sf::RenderWindow> &windowToDrawTo);

        const sf::Texture &getTexture() const;

        void setTexture(const sf::Texture &texture);

        const sf::Sprite &getSprite() const;

        void setSprite(const sf::Sprite &sprite);

    };
}

#endif //TURBOHIKERSFML_ENTITY_H
