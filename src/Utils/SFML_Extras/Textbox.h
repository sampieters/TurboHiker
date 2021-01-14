//
// Created by Sam Pieters on 02/01/2021.
//

#ifndef TURBOHIKER_TEXTBOX_H
#define TURBOHIKER_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <memory>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox: public sf::Drawable {
private:
    sf::Text textbox;
    sf::RectangleShape background;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit = 0;
    bool hidden = false;

    void deleteLastChar();
    void inputLogic(int charTyped);

public:
    Textbox(int size, sf::Color color, bool sel);

    void typedOn(sf::Event input);
    void setFont(sf::Font &fonts);
    void setBackground(sf::Color filling, sf::Color outline, sf::Vector2f size);
    void setPosition(sf::Vector2f point);
    void setOrigin(sf::Vector2f point);
    void setBackground(const sf::RectangleShape &background);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    void setSelected(bool sel);
    bool isHasLimit() const;
    int getLimit() const;
    const sf::RectangleShape &getBackground() const;
    sf::Vector2f getPosition();
    void setText(const std::string& content);
    std::string getText();
    void setHidden(bool hidden);
    bool isMouseOver(sf::Vector2i mouse);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //TURBOHIKER_TEXTBOX_H
