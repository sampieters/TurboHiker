/**
 * \brief Classes that implements the observer pattern.
 * \author Sam Pieters
 * \date 15 December 2020
 */

#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "../Utils/Enum.h"
#include <memory>

/** \class Observer Observer.h "src/Logic/Observer/Observer.h"
 * \brief Class that is a part of the observer pattern. Implements the observer.
 * \details This is the observer class. Every observer does something when notified. An observer will be notified when
 * an observable notifies his list of observers.
 *          Source(s) used: https://refactoring.guru/design-patterns/state/cpp/example
 */
class Observer
{
public:
        /**
         * \brief Default destructor for the game.
         */
        virtual ~Observer() = default;

        /**
         * A virtual function that will do something when an observer is notified.
         * \param event: An enumerator (can be found in src/Utils/Enum.h)
         */
        virtual void OnNotify(Event event) = 0;
};

#endif // GAME_OBSERVER_H