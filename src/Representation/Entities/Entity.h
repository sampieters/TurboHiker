/**
 * \brief The Entity class, a superclass that allowes to show an entity on a screen.
 * \author Sam Pieters
 * \date 01 December 2020
 */

#ifndef TURBOHIKERSFML_ENTITY_H
#define TURBOHIKERSFML_ENTITY_H

#include "../../Logic/Entities/Entity.h"
#include "../../Singletons/Transformation.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

namespace turbohikerSFML {

/** \class Entity Entity.h "src/Representation/Entity.h"
 * \brief The visualization of the entity in SFML.
 */
class Entity
{
private:
        std::shared_ptr<sf::RenderWindow> WindowToDrawTo;
        sf::Texture texture;
        sf::Sprite sprite;

public:
        /**
         * \brief Default constructor for the Entity representation.
         * \param texture: The texture given for the entity.
        */
        Entity(const std::string& texture);

        /**
         * \brief returns the window where the entity has to be displayed.
         * \return A shared pointer to a Renderwindow. This is the window too draw the entity to.
        */
        const std::shared_ptr<sf::RenderWindow>& getWindowToDrawTo() const;

        /**
         * \brief Set the window to draw the entity to. This is mostly one window.
         * @param windowToDrawTo: the window to draw to.
         */
        void setWindowToDrawTo(const std::shared_ptr<sf::RenderWindow>& windowToDrawTo);

        /**
         * get the texture of that entity.
         * @return A sf::texture from that entity.
         */
        const sf::Texture& getTexture() const;

        /**
         * The texture for the entity.
         * @param texture: The texture for the entity
         */
        void setTexture(const sf::Texture& texture);

        /**
         * Get the container (rectangle) where the texture needs to be dranw to.
         * @return Sprite, a container in sfml to display a texture.
         */
        const sf::Sprite& getSprite() const;

        /**
         * Sets the sprite/container to display the texture in.
         * @param sprite: The container the texture needs to be stored.
         */
        void setSprite(const sf::Sprite& sprite);
};
}

#endif // TURBOHIKERSFML_ENTITY_H