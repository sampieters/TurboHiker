/**
 * \brief Classes that implements the observer pattern.
 * \author Sam Pieters
 * \date 15 December 2020
 */

#include "Observable.h"
#include "algorithm"

void Observable::AttachObserver(const std::shared_ptr<Observer>& observer) { observers.push_back(observer); }

void Observable::DetachObserver(const std::shared_ptr<Observer>& observer)
{
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
                observers.erase(it);
        }
}

void Observable::NotifyObservers(Event event)
{
        for (auto& obs : observers) {
                if (auto o = obs) {
                        o->OnNotify(event);
                }
        }
}
