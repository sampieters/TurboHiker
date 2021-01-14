//
// Created by Sam Pieters on 21/12/2020.
//

#ifndef TURBOHIKER_BUTTON_H
#define TURBOHIKER_BUTTON_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Object.h"

class Scoreboard: public sf::Drawable {
private:
    sf::RectangleShape back;
    sf::Text score;
public:
    Scoreboard(std::string file, sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


class Background: public sf::Drawable {
private:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite spirte;
public:
    Background(std::string texture);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


class Button: public sf::Drawable {
private:
    sf::RectangleShape button;
    sf::Texture texture;
    sf::Text text;
    sf::SoundBuffer click;

public:
    // Constructor
    // With text
    Button(const std::string& content, sf::Vector2f B_Size, int T_Size, sf::Color B_Color, sf::Color T_Color);
    // Without text
    Button(sf::Vector2f B_Position, sf::Vector2f B_Size, sf::Color B_Color);
    // ButtonLayout
    void setButtonColor(sf::Color color);
    sf::Color getButtonColor();

    void setTexture(const std::string& texture);
    const sf::Texture* getTexture();

    void setPosition(sf::Vector2f point);
    sf::Vector2f getPosition();

    void setOrigin(sf::Vector2f point);
    sf::Vector2f getOrigin();

    void setSize(sf::Vector2f size);
    sf::Vector2f getSize();

    void setOutlineColor(sf::Color color);
    sf::Color getOutlineColor();

    void setOutlineSize(float size);
    float getOutlineSize();

    void setCurveCorners(int curve);
    int getCurveCorners();

    void setClickSound(sf::SoundBuffer buffer);

    bool isMouseOver(sf::Vector2i mouse);


    void layoutclick(bool clicked, float clickdepth, sf::Color color=sf::Color::Transparent);

    // TextLayout
    void setTextColor(sf::Color color);
    void setFont(sf::Font &fonts);
    void setFontSize(unsigned int size);
    void keepTextinButton(bool keep);

    // Transformations
    void Scale(sf::Vector2f targetSize);
    void Rotate();
    void Transform();
    void CenterHorizontal(sf::RenderWindow& window);
    void CenterVertical(sf::RenderWindow& window);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::string getText() const;

    void setText(const std::string& text);
};

#endif //TURBOHIKER_BUTTON_H
