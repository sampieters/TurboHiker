/**
 * \brief Lane class used to position every entity in the world.
 * \details This class is used to move every dynamic entity over the world. It keeps it right and left lane.
 * \author Sam Pieters
 * \date 27 December 2020
 */

#ifndef TURBOHIKER_LANE_H
#define TURBOHIKER_LANE_H

#include <memory>
#include <vector>
#include "../Entity.h"
#include "../../../Utils/CONST.h"

namespace turbohiker {
    class Lane : public Entity {
    private:
        std::shared_ptr<Lane> previous;
        std::shared_ptr<Lane> next;
    public:
        Lane();

        const std::shared_ptr<Lane> &getPrevious() const;

        void setPrevious(const std::shared_ptr<Lane> &previous);

        const std::shared_ptr<Lane> &getNext() const;

        void setNext(const std::shared_ptr<Lane> &next);

        float GetMiddle();
    };
}

#endif //TURBOHIKER_LANE_H