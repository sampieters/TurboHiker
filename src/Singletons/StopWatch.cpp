//
// Created by Sam Pieters on 17/11/2020.
//

#include "StopWatch.h"

StopWatch::StopWatch(): running(false), duration(std::chrono::system_clock::duration::zero()) {};

StopWatch &StopWatch::Getinstance() {
    static StopWatch instance;
    return instance;
}

void StopWatch::Start() {
    if (!running) {
        last_start = std::chrono::system_clock::now();
        running = true;
    }
}

void StopWatch::Stop() {
    if (running) {
        duration += (std::chrono::system_clock::now() - last_start);
        running = false;
    }
}

void StopWatch::Reset() {
    last_start = std::chrono::system_clock::now();
}

double StopWatch::GetElapsedTime() {
    double temp = duration.count();
    if (running) {
        temp += (std::chrono::system_clock::now() - last_start).count();
    }
    return temp;
}