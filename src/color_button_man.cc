#include "color_button_man.h"

using kengine::ColorButtonMan;

#define THIS (*this)

void
ColorButtonMan::on_push( sf::Event::EventType event_type)
{
    if ( event_type == sf::Event::MouseButtonPressed )
    {
        for ( std::size_t i = 0; i < get_n_button(); i++ )
        {
            if ( THIS[i].is_push() )
            {
                THIS[i].on_push();
            }
        }
    }
}

void
ColorButtonMan::draw( sf::RenderWindow* win)
{
    for ( std::size_t i = 0; i < get_n_draws(); i++ )
    {
        THIS[i].draw( win);
    }
}
