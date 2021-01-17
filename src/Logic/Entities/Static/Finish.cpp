/**
 * \brief Finish class is an entity for the finish destination in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#include "Finish.h"

turbohiker::Finish::Finish()
{
        this->setPosition(CONST::FINISH::POSITION);
        this->setSize({CONST::FINISH::SIZE});
        this->setType(EntityType::Finish);
}
