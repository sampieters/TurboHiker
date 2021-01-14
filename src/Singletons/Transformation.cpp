//
// Created by Sam Pieters on 16/11/2020.
//

#include "Transformation.h"

Transformation::Transformation() = default;

Transformation &Transformation::Getinstance()   {
    static Transformation instance;
    return instance;
}

void Transformation::SetWindowSize(float width, float height) {
    window_width = width;
    window_height = height;
}

void Transformation::convert(std::pair<float, float>& position, std::pair<float, float>& size) const {
    float perc_x = window_width/8;
    float perc_y = window_height/6;

    // Set object to the right position in the view
    // ((0,0) is located in center of [-4, 4] x [-3, 3] field but left above in window field)
    position.first = (4 + position.first) * perc_x;
    position.second = (3 - position.second) * perc_y;

    // Set object to the right size in the view
    size.first *= perc_x;
    size.second *= perc_y;
}
