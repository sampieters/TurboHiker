/**
 * \brief The Finish visualization class, a class that allows to show a finish on a screen.
 * \author Sam Pieters
 * \date 18 December 2020
 */


#ifndef TURBOHIKERSFML_FINISH_H
#define TURBOHIKERSFML_FINISH_H

#include "../../../Logic/Entities/Static/Finish.h"
#include "../Entity.h"

#include <memory>

namespace turbohikerSFML {
/** \class Finish Finish.h "src/Representation/Static/Finish.h"
 * \brief Visualization of a finish. It is important that the finish is drawn after the lanes, otherwise the
 * finish will be drawn under the lane.
 */
class Finish : public Entity, public turbohiker::Finish
{
public:
        /**
         * \brief Default constructor for the Finish representation.
         */
        Finish();

        /**
         * \brief Function that displays the finish on the window.
         */
        void display() override;
};
} // namespace turbohikerSFML

#endif // TURBOHIKERSFML_FINISH_H