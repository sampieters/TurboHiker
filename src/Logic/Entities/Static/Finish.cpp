/**
 * \brief Finish class is an entity for the finish destination in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Finish.h"

turbohiker::Finish::Finish() {
    this->setPosition({0, 2.5});
    this->setSize({CONST::WORLD::SIZE.first, 0.2});
}
