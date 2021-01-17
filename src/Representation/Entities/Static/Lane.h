/**
 * \brief The Lane visualization class, a class that allows to show a lane on a screen.
 * \author Sam Pieters
 * \date 07 December 2020
 */

#ifndef TURBOHIKERSFML_LANE_H
#define TURBOHIKERSFML_LANE_H

#include "../../../Logic/Entities/Static/Lane.h"
#include "../Entity.h"
#include <memory>

namespace turbohikerSFML {

/** \class Lane Lane.h "src/Representation/Static/Lane.h"
 * \brief Visualization of a lane. It is important that the lanes is drawn before the other entities, otherwise the
 * entities will be drawn under the lanes. The lanes form the background of a game window.
 */
class Lane : public Entity, public turbohiker::Lane
{
public:
        /**
        * \brief Default constructor for the Lane representation.
        */
        Lane();

        /**
         * \brief Function that displays the lane on the window.
         */
        void display() override;
};
}

#endif // TURBOHIKERSFML_LANE_H