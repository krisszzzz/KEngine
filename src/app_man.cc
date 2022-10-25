#include "app_man.h"

using kengine::AppMan;

void
AppMan::draw()
{
    for ( std::size_t i = 0; i < vwidgets_.size(); i++ )
    {
        vwidgets_.at( i)->draw( window_);
    }
}

void
AppMan::on_push()
{
    sf::Event event {};
    while ( window_->pollEvent( event) )
    {
        for ( std::size_t i = 0; i < vbutton_ctls_.size(); i++ )
        {
            vbutton_ctls_.at( i)->on_push( event.type);
        }
    }
}

