/**
 * \author Sam Pieters
 * \date 16 November 2020
 */

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() { srand(time(nullptr)); };

RandomNumberGenerator& RandomNumberGenerator::Getinstance()
{
        static RandomNumberGenerator instance;
        return instance;
}

float RandomNumberGenerator::generate_float(float min, float max)
{
        float number = ((float)rand() / RAND_MAX) * (max - min) + min;

        float pow_10 = pow(10.0f, 1);
        float test = round(number * pow_10) / pow_10;
        return test;
}

int RandomNumberGenerator::generate_int(int min, int max) { return min + (rand() % max); }