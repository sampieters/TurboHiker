//
// Created by Sam Pieters on 15/12/2020.
//

#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <memory>
#include "../Utils/Enum.h"

class Observer {
public:
    virtual ~Observer() = default;

    virtual void OnNotify(Event event) = 0;
};

#endif //GAME_OBSERVER_H