/**
 * \brief Classes that implements the observer pattern.
 * \author Sam Pieters
 * \date 15 December 2020
 */

#ifndef GAME_OBSERVABLE_H
#define GAME_OBSERVABLE_H

#include "Observer.h"
#include <iostream>
#include <list>
#include <memory>

/** \class Observable Observable.h "src/Logic/Observer/Observable.h"
 * \brief Class that is a part of the observer pattern. Implements the observable.
 * \details This is the observable class. Every observable is observed by a number of observers.
 *          Source(s) used: https://refactoring.guru/design-patterns/state/cpp/example
 */
class Observable
{
private:
        std::list<std::shared_ptr<Observer>> observers;

public:
        /**
         * \brief Functions that attaches an observer to an observable
         * \param observer: The observer that needs to be attached to the observable.
         */
        void AttachObserver(const std::shared_ptr<Observer>& observer);

        /**
         * \brief Functions that dettaches an observer to an observable
         * \param observer: The observer that needs to be detached from the observable.
         */
        void DetachObserver(const std::shared_ptr<Observer>& observer);

        /**
         * \brief Function that notifies every observer from the list.
         * \param event: An enumerator (can be found in src/Utils/Enum.h)
         */
        void NotifyObservers(Event event);
};

#endif // GAME_OBSERVABLE_H
