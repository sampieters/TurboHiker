//
// Created by Sam Pieters on 16/11/2020.
//

#ifndef GAME_RANDOMNUMBERGENERATOR_H
#define GAME_RANDOMNUMBERGENERATOR_H

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <random>
#include <memory>

/** \class RandomNumberGenerator RandomNumberGenerator.h "src/Singletons/RandomNumberGenerator.h"
 * \brief Class for generating random int or float between a min and max value.
 * \details This class has everything that needs to be set in order to implement this as a singleton.
 *          Source(s) used: https://refactoring.guru/design-patterns/singleton/cpp/example.
 */
class RandomNumberGenerator {
private:
    /**
     * \brief Constructor
     *        Set to private because there can be no more than one instance of RandomNumberGenerator.
     */
    RandomNumberGenerator();

public:
    /**
     * \brief Copy Constructor
     *        Singletons should not be cloneable.
     * \param to_copy: The RandomNumberGenerator that needs to be copied.
     */
    RandomNumberGenerator(const RandomNumberGenerator& to_copy) = delete;

    /**
     * \brief Assignement operator
     *        Singletons should not be assignable.
     * \param to_assign: The RandomNumberGenerator that needs to be assigned from.
     * \return The Transforation after the assignement.
     */
    RandomNumberGenerator operator=(const RandomNumberGenerator& to_assign) = delete;

    /**
     * \brief get the instance of RandomNumberGeneration.
     * \return The only instance of RandomNumberGeneration.
     */
    static RandomNumberGenerator& Getinstance();

    /**
     * \brief generates a float between a minimum valeue and a maximum value.
     * \return The generated number.
     */
    float generate_float(float min, float max);

    /**
     * \brief generates a integer between a minimum valeue and a maximum value.
     * \return The generated number.
     */
    static int generate_int(int min, int max);
};

#endif //GAME_RANDOMNUMBERGENERATOR_H