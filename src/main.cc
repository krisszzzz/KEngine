#include "button.h"
#include <SFML/Window/Event.hpp>

int main()
{
    ColorButton* but_1 = new ColorButton { sf::Vector2i { 0, 0 }, sf::Vector2i { 100, 100 } };
    ColorButton but_2 { sf::Vector2i { 0, 600 }, sf::Vector2i { 100, 700 } };
    ColorButton but_3 { sf::Vector2i { 0, 1100 }, sf::Vector2i { 100, 1200 } };

    printf( "but_1 = %p\n", but_1);

    sf::RenderWindow window { sf::VideoMode { 1920, 1200 }, "Cringe" };
    ButtonMgr button { 3 };

    button.add_button( but_1);
    button.add_button( &but_2);
    button.add_button( &but_3);

    sf::Event event {};

    while ( window.isOpen() )
    {
        while ( window.pollEvent( event) )
        {
            if ( event.type == sf::Event::KeyPressed )
            {
                printf( "Key pressed\n");
            }

            if ( event.type == sf::Event::MouseButtonPressed )
            {
                button.on_click();
            }
        }

        window.clear(sf::Color::Cyan);

        window.display();

    }
}
