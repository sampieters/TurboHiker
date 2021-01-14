/**
 * \brief Transformation class to go from world coördinates to window coördinates.
 * \author Sam Pieters
 * \date 24 December 2020
 */

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H

#include <vector>
#include <memory>

/** \class Transformation Transformation.h "src/Singletons/Transformation.h"
 * \brief Transformation class to go from world coördinates to window coördinates.
 * \details This class has everything that needs to be set in order to implement this as a singleton.
 *          Source(s) used: https://refactoring.guru/design-patterns/singleton/cpp/example.
 */
class Transformation {
private:
    float window_height;
    float window_width;

    /**
     * \brief Constructor
     *        Set to private because there can be no more than one instance of Transformation.
     */
    Transformation();

public:
    /**
     * \brief Copy Constructor
     *        Singletons should not be cloneable.
     * \param to_copy: The transformation that needs to be copied.
     */
    Transformation(const Transformation& to_copy) = delete;

    /**
     * \brief Assignement operator
     *        Singletons should not be assignable.
     * \param to_assign: The transformation that needs to be assigned from.
     * \return The Transforation after the assignement.
     */
    Transformation operator=(const Transformation& to_assign) = delete;

    /**
     * \brief get the instance of Transformation.
     * \return The only instance of Transformtion.
     */
    static Transformation& Getinstance();

    /**
     * \brief Initializes the size of the window for the transformation.
     * \param width: The width of the window.
     * \param height: The height of the window.
     */
    void SetWindowSize(float width, float height);

    //
    /**
     * \brief Function for conversion of world field to the window field.
     * \param position: The position of the object in the world that needs to be converted to the position of the object in teh window.
     * \param size: The size of the object in the world that needs to be converted to te size of the object in the window;
     */
    void convert(std::pair<float, float>& position, std::pair<float, float>& size) const;
};


#endif //GAME_TRANSFORMATION_H