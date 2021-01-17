/**
 * \brief Finish class is an entity for the finish destination in the world.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_FINISH_H
#define TURBOHIKER_FINISH_H

#include "../../../Utils/CONST.h"
#include "../Entity.h"
#include <memory>

namespace turbohiker {

/** \class Finish Finish.h "src/Logic/Entities/Static/Finish.h"
 * \brief A world consist out of exactly one finish. Competing enemies and players cn finish in the world.
 */
class Finish : public Entity
{
public:
        /**
         * Default constructor of a Finish
         */
        Finish();
};
}

#endif // TURBOHIKER_FINISH_H
