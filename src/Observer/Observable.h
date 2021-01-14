//
// Created by Sam Pieters on 15/12/2020.
//

#ifndef GAME_OBSERVABLE_H
#define GAME_OBSERVABLE_H

#include <iostream>
#include <list>
#include <memory>
#include "Observer.h"


class Observable {
private:
    std::list<std::weak_ptr<Observer>> observers;

public:
    void AttachObserver(const std::shared_ptr<Observer>& observer);

    void DetachObserver(const std::shared_ptr<Observer>& observer);

    void NotifyObservers(Event event);
};


#endif //GAME_OBSERVABLE_H
