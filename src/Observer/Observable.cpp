//
// Created by Sam Pieters on 15/12/2020.
//

#include "Observable.h"

void Observable::AttachObserver(const std::shared_ptr<Observer> &observer) {
    observers.push_back(observer);
}

void Observable::DetachObserver(const std::shared_ptr<Observer> &observer) {
    //observers.remove(observer);
}

void Observable::NotifyObservers(Event event) {
    for(auto& obs: observers) {
        if (auto o = obs.lock()) {
            o->OnNotify(event);
        }
    }
}
