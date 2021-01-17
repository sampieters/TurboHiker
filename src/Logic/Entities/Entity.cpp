/**
 * @brief Entity class used for positioning every entity in the world.
 * @details This class is used to get the size and position of an entity relative to the world. It's derived classes are
 *          DynamicEntity and everything in the Static Directory.
 * @author Sam Pieters
 * @date 27 December 2020
 */

#include "Entity.h"

const std::pair<float, float>& turbohiker::Entity::getPosition() const { return position; }

void turbohiker::Entity::setPosition(const std::pair<float, float>& position) { Entity::position = position; }

const std::pair<float, float>& turbohiker::Entity::getSize() const { return size; }

void turbohiker::Entity::setSize(const std::pair<float, float>& size) { Entity::size = size; }

turbohiker::Entity::Entity() = default;

turbohiker::Entity::Entity(std::pair<float, float> position, std::pair<float, float> size)
    : position(std::move(position)), size(std::move(size))
{
}

EntityType turbohiker::Entity::getType() const { return type; }

void turbohiker::Entity::setType(EntityType type) { Entity::type = type; }
