//
// Created by Sam Pieters on 18/12/2020.
//

#ifndef TURBOHIKERSFML_FINISH_H
#define TURBOHIKERSFML_FINISH_H

#include "../Entity.h"
#include "../../../Logic/Entities/Static/Finish.h"

#include <memory>

namespace turbohikerSFML {
    class Finish : public Entity, public turbohiker::Finish {
    public:
        Finish();
        void display() override;

    };
}

#endif //TURBOHIKERSFML_FINISH_H