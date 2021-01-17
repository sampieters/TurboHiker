/**
 * @brief Entity class used for positioning every entity in the world.
 * @details This class is used to get the size and position of an entity relative to the world. It's derived classes are
 *          DynamicEntity and everything in the Static Directory.
 * @author Sam Pieters
 * @date 27 December 2020
 */

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include "../../Utils/Enum.h"
#include <iostream>
#include <memory>

namespace turbohiker {

/** \class Entity Entity.h "src/Logic/Entities/Entity.h"
 * \brief Class that is the entity.
 * \details This class implements everything an entity needs. Like a position and size.
 */
class Entity
{
private:
        EntityType type;
        std::pair<float, float> position;
        std::pair<float, float> size;

public:
        /**
         * \brief Constructor
         * \param position: The position of the entity in the world.
         * \param size: The size of the entity in the world.
         */
        Entity(std::pair<float, float> position, std::pair<float, float> size);

        /**
         * \brief Constructor without parameters.
         */
        Entity();

        /**
         * \brief Function that will display an entity when a visualisation is used.
         */
        virtual void display(){};

        /**
         * \brief Function that updates an entities position or state given an elapsed time.
         * \param elapsedTime: A double that causes the player to move independent from the framerate.
         */
        virtual void update(double elapsedTime){};

        /**
         * \brief Gets the position of the entity.
         * \return The position as pair of floats of an entity.
         */
        const std::pair<float, float>& getPosition() const;

        /**
         * \brief Sets the position of the entity.
         * \param position: The new position of the entity.
         */
        void setPosition(const std::pair<float, float>& position);

        /**
         * \brief Gets the size of the entity.
         * \return A size as pair of floats.
         */
        const std::pair<float, float>& getSize() const;

        /**
         * \brief Sets the size of the entity.
         * @param size: A size as pair of floats.
         */
        void setSize(const std::pair<float, float>& size);

        /**
         * \brief Gets the type of the entity.
         * \return A type as an enumerator.
         */
        EntityType getType() const;

        /**
         * \brief Sets the type of the entity.
         * \param type: A type as an enumerator.
         */
        void setType(EntityType type);
};
}

#endif // TURBOHIKER_ENTITY_H