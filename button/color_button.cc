#include "button/color_button.h"

using kengine::ColorButton;

void
ColorButton::draw( sf::RenderWindow* win)
{
    sf::RectangleShape rectangle {};
    rectangle.setFillColor( get_color());
    rectangle.setPosition( static_cast<float>(get_left().x), 
                           static_cast<float>(get_left().y));

    rectangle.setSize( 
        sf::Vector2f { static_cast<float>(get_right().x - get_left().x),
                       static_cast<float>(get_right().y - get_left().y) }
                      );

    win->draw( rectangle);
}

