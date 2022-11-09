#include "app_man/app_man.h"

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
AppMan::on_action()
{
    sf::Event event {};
    while ( window_->pollEvent( event) )
    {
        for ( std::size_t i = 0; i < vctls_.size(); i++ )
        {
            printf("OK");
            vctls_.at( i)->on_action( event.type);
        }
    }
}

