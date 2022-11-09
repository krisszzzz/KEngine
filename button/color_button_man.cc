#include "button/color_button_man.h"

using kengine::ColorButtonMan;

#define THIS (*this)

// for ColorButtonMan action is pushing the buttons
void
ColorButtonMan::on_action( sf::Event::EventType event_type)
{
    if ( event_type == sf::Event::MouseButtonPressed )
    {
        for ( std::size_t i = 0; i < get_n_objects(); i++ )
        {
            if ( is_action( THIS[i]) )
            {
                THIS[i].on_action(); // button on_action
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
