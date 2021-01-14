/**
 * \brief Transformation class to go from world coördinates to window coördinates.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_STOPWATCH_H
#define GAME_STOPWATCH_H

#include <chrono>

/** \class StopWatch StopWatch.h "src/Singletons/StopWatch.h"
 * \brief Stopwatch class used to let the game run independent from the frame rat.
 * \details This class has everything that needs to be set in order to implement this as a singleton.
 *          Source(s) used: https://refactoring.guru/design-patterns/singleton/cpp/example.
 */
class StopWatch {
private:
    std::chrono::system_clock::duration duration;
    std::chrono::system_clock::time_point last_start;
    bool running;

    /**
     * \brief Constructor
     *        Set to private because there can be no more than one instance of Transformation.
     */
    StopWatch();

public:
    /**
     * \brief Copy Constructor
     *        Singletons should not be cloneable.
     * \param to_copy: The transformation that needs to be copied.
     */
    StopWatch(const StopWatch& to_copy) = delete;

    /**
     * \brief Assignement operator
     *        Singletons should not be assignable.
     * \param to_assign: The stopwatch that needs to be assigned from.
     * \return The stopwatch after the assignement.
     */
    StopWatch operator=(StopWatch *to_assign) = delete;

    /**
     * \brief get the instance of Stopwatch.
     * \return The only instance of Stopwatch.
     */
    static StopWatch& Getinstance();

    /**
     * \brief Initializes and starts the Stopwatch.
     */
    void Start();

    /**
     * \brief Stops the Stopwatch.
     */
    void Stop();

    /**
     * \brief Resets the Stopwatch but keeps running.
     */
    void Reset();

    /**
     * \brief Get the elapsed time between the last reset point (or creation of the clock) till the current time.
     * \return The elpased time in milliseconds.
     */
    double GetElapsedTime();
};


#endif //GAME_STOPWATCH_H
