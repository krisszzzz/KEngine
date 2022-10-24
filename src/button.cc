
#include "button.h"
#include <cstdio>

int AbstractButton::is_valid()
{
    if ( left_.x > right_.x || 
         left_.y < right_.y )
    {
        printf( "The left corner and right corner are switched."
                "The is_click() function working wrong in this case\n"
                "Info: addr = %p, left = (%d, %d), right = (%d, %d)\n", 
                this, left_.x, left_.y, right_.x, right_.y
                );

        return 0;
    }

    return 1;
}


#define BETWEEN(coord) mouse_pos.coord < right_.coord &&   \
                       mouse_pos.coord > left_.coord

int 
AbstractButton::is_click() 
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition();

    return ( BETWEEN( x) && BETWEEN( y) );
}

void
ColorButton::draw( sf::RenderWindow* window)
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor( get_color());
    rectangle.setOrigin( static_cast<float>(get_left().x), 
                         static_cast<float>(get_left().y));

    rectangle.setSize( 
        sf::Vector2f { static_cast<float>(get_left().x - get_right().x),
                       static_cast<float>(get_right().y - get_left().y) }
                      );

    window->draw( rectangle);

}


void 
ButtonMgr::add_button( AbstractButton* button)
{
    vbuttons_.push_back( button);
}


void
ButtonMgr::on_click()
{
    for ( std::size_t i = 0; i < vbuttons_.size(); i++ )
    {
        if ( (*this)[i]->is_click() )
        {
            handler on_click = (*this)[i]->get_on_click();
            on_click();
        }
    }
}

void 
ButtonMgr::draw()
