/**
 * \brief Lane class used to position every entity in the world.
 * \details This class is used to move every dynamic entity over the world. It keeps it right and left lane.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_LANE_H
#define TURBOHIKER_LANE_H

#include "../../../Utils/CONST.h"
#include "../Entity.h"
#include <memory>
#include <vector>

namespace turbohiker {
/** \class Lane Lane.h "src/Logic/Entities/Static/Lane.h"
 * \brief A world consist out of one or multiple lanes. The lanes are the legal space where an entity can move in.
 * \details A lane is a line that the entities can moved on. When initialized succesfully, every dynamic entity will be
 * in the middle of their assigned lane. A lane takes the whole y-coördinate of the world and as x-coördinate, the
 * size of the world divided by the amount of lanes that is needed. This is done to guarantee the dynamic change of lanes.
 */
class Lane : public Entity
{
private:
        std::shared_ptr<Lane> previous;
        std::shared_ptr<Lane> next;

public:
        /**
         * The default constructur of a lane;
         */
        Lane();

        /**
         * \brief Gets the lane that is to the left or previous of the current lane.
         * \return The lane on the left of the lane that uses this function. If there is no lane on that side, the
         * function will give  nullptr back.
         */
        const std::shared_ptr<Lane>& getPrevious() const;

        /**
         * \brief Sets the lane that is to the left of the current lane.
         * \param previous: The lane that is set to the left of the current lane.
         */
        void setPrevious(const std::shared_ptr<Lane>& previous);

        /**
         * \brief Gets the lane that is to the right or next of the current lane.
         * \return The lane on the right of the lane that uses this function. If there is no lane on that side, the
         * function will give  nullptr back.
         */
        const std::shared_ptr<Lane>& getNext() const;

        /**
         * \brief Sets the lane that is to the right of the current lane.
         * \param next: The lane that is set to the right of the current lane.
         */
        void setNext(const std::shared_ptr<Lane>& next);

        /**
         * \brief Get the middle of a lane. This function is used to get the proper x-coôrdinate when an entity is moved.
         * \return A float that is the x-ccoördinate of the middle of the lane, relative to the world.
         */
        float GetMiddle();
};
}

#endif // TURBOHIKER_LANE_H