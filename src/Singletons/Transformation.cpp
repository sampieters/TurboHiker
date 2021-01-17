/**
 * \author Sam Pieters
 * \date 24 December 2020
 */

#include "Transformation.h"
#include "src/Utils/CONST.h"

Transformation::Transformation() = default;

Transformation& Transformation::Getinstance()
{
        static Transformation instance;
        return instance;
}

void Transformation::SetWindowSize(float width, float height)
{
        window_width = width;
        window_height = height;
}

void Transformation::convert(std::pair<float, float>& position, std::pair<float, float>& size) const
{
        float perc_x = window_width / CONST::WORLD::SIZE.first;
        float perc_y = window_height / CONST::WORLD::SIZE.second;

        /* Set object to the right position in the view. (0,0) is located in the center of [LEFT, RIGHT] x [BOTTOM, TOP]
         * in the world but (0, 0) is located [LEFT, 0] x [0, TOP] in the window field */
        position.first = ((CONST::WORLD::SIZE.first/2) + position.first) * perc_x;
        position.second = ((CONST::WORLD::SIZE.second/2) - position.second) * perc_y;

        /* Set object to the right size in the view (window). */
        size.first *= perc_x;
        size.second *= perc_y;
}
