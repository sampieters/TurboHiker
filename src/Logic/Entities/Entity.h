/**
 * @brief Entity class used for positioning every entity in the world.
 * @details This class is used to get the size and position of an entity relative to the world. It's derived classes are
 *          DynamicEntity and everything in the Static Directory.
 * @author Sam Pieters
 * @date 27 December 2020
 */

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <iostream>

namespace turbohiker {
    class Entity {
    private:
        std::pair<float, float> position;
        std::pair<float, float> size;
        bool active;

    public:
        // CONSTRUCTOR
        Entity(std::pair<float, float> position, std::pair<float, float> size, float speed);

        Entity();

        // GETTERS AND SETTERS
        const std::pair<float, float> &getPosition() const;

        void setPosition(const std::pair<float, float> &position);

        const std::pair<float, float> &getSize() const;

        void setSize(const std::pair<float, float> &size);

        // OWN FUNCTIONS
        virtual void display() {};

        virtual void update(double elapsedTime) {};
    };
}

#endif //TURBOHIKER_ENTITY_H