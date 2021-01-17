/**
 * \brief The enemy visualization class, a class that allows to show an enemy of a certain type on a screen.
 * \author Sam Pieters
 * \date 04 December 2020
 */

#ifndef TURBOHIKERSFML_ENEMY_H
#define TURBOHIKERSFML_ENEMY_H

#include "../../../Logic/Entities/Dynamic/Enemy.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {
/** \class Enemy Enemy.h "src/Representation/Dynamic/Enemy.h"
 * \brief Visualization and audio of the Enemy. This allows to draw the enemy on the window and play sound prompts with
 * a corresponding action.
 */
class Enemy : public Entity
{
        std::shared_ptr<sf::SoundBuffer> buffer;
        std::shared_ptr<sf::Sound> sound;

public:
        /**
         * \brief Default constructor for the Enemy representation.
         * \param texture: texture given to the enemy.
         */
        Enemy(const std::string& texture);

        /**
         * Get the buffer. The buffer needs to be held as a member because when initialized and gone out of scope. The
         * buffer will not exists anymore and the sound has undefined behaviour.
         * \return The buffer.
         */
        const std::shared_ptr<sf::SoundBuffer>& getBuffer() const;

        /**
         * Get the buffer. The buffer needs to be held as a member because when initialized and gone out of scope. The
         * buffer will not exists anymore and the sound has undefined behaviour.
         * \param buffer: The buffer needed to be loaded in the sound.
         */
        void setBuffer(const std::shared_ptr<sf::SoundBuffer>& buffer);

        /**
         * Gets the sound that will be played when interacting with the world. This needs to be held for the same reasons
         * as the buffer. The sound needs to be held as a member because when initialized and gone out of scope. The
         * sound will cease to exists anymore and the sound has undefined behaviour.
         * \return The sound of the enemy when yelled at.
         */
        const std::shared_ptr<sf::Sound>& getSound() const;

        /**
         * Sets the sound that will be played when interacting with the world. This needs to be held for the same reasons
         * as the buffer. The sound needs to be held as a member because when initialized and gone out of scope. The
         * sound will cease to exists anymore and the sound has undefined behaviour.
         * \param The sound of the enemy when yelled at.
         */
        void setSound(const std::shared_ptr<sf::Sound>& sound);
};

/** \class Competing Enemy.h "src/Representation/Dynamic/Enemy.h"
 * \brief Visualization and audio of the Competing enemy. This allows to draw the enemy on the window and play sound prompts with
 * a corresponding action.
 */
class Competing : public Enemy, public turbohiker::Competing
{
public:
        /**
         * \brief Default constructor for the Competing representation.
         */
        Competing();

        /**
         * \brief Function that displays the competing enemy on the window.
         */
        void display() override;
};

/** \class Static Enemy.h "src/Representation/Dynamic/Enemy.h"
 * \brief Visualization and audio of the Static enemy. This allows to draw the enemy on the window and play sound prompts with
 * a corresponding action.
 */
class Static : public Enemy, public turbohiker::Static
{
public:
        /**
         * \brief Default constructor for the Static representation.
         */
        Static();

        /**
         * \brief Function that displays the static enemy on the window.
         */
        void display() override;
};

/** \class Attacking Enemy.h "src/Representation/Dynamic/Enemy.h"
 * \brief Visualization and audio of the Attacking enemy. This allows to draw the enemy on the window and play sound prompts with
 * a corresponding action.
 */
class Attacking : public Enemy, public turbohiker::Attacking
{
public:
        /**
         * \brief Default constructor for the Attacking representation.
         */
        Attacking();

        /**
         * \brief Function that displays the attacking enemy on the window.
         */
        void display() override;
};
}

#endif // TURBOHIKERSFML_ENEMY_H