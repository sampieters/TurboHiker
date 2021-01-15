//
// Created by Sam Pieters on 07/12/2020.
//

#ifndef TURBOHIKERSFML_LANE_H
#define TURBOHIKERSFML_LANE_H

#include "../../../Logic/Entities/Static/Lane.h"
#include "../Entity.h"
#include <memory>

namespace turbohikerSFML {
class Lane : public Entity, public turbohiker::Lane
{
public:
        Lane();

        void display() override;
};
} // namespace turbohikerSFML

#endif // TURBOHIKERSFML_LANE_H