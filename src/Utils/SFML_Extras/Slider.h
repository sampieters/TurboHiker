//
// Created by Sam Pieters on 02/01/2021.
//

#ifndef TURBOHIKER_SLIDER_H
#define TURBOHIKER_SLIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Slider: public sf::Drawable {
    sf::RectangleShape slider;
    sf::RectangleShape axis;
    sf::Font font;
    sf::Text text;
    int minValue;
    int maxValue;
    int xCord;
    int yCord;
    int axisWidth;
    int axisHeight;
    int sliderWidth;
    int sliderHeight;
    float sliderValue;
public:
    Slider(int x, int y);
    sf::Text returnText(int x, int y, std::string z, int fontSize);
    void create(int min, int max);
    void logic(sf::RenderWindow &window);
    float getSliderValue();
    void setSliderValue(float newValue);
    void setSliderPercentValue(float newPercentValue);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //TURBOHIKER_SLIDER_H
