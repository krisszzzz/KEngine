#include "button/color_button_man.h"
#include "app_man/app_man.h"
#include <SFML/Window/Event.hpp>

using kengine::ColorButton;
using kengine::ColorButtonMan;

int main()
{
    ColorButton but_1 { sf::Vector2i { 0, 0 }, 
                        sf::Vector2i { 100, 100 }, 
                        sf::Color::Green };
    ColorButton but_2 { sf::Vector2i { 0, 600 }, 
                        sf::Vector2i { 100, 700 },
                        sf::Color::Blue };
    ColorButton but_3 { sf::Vector2i { 0, 1100 }, 
                        sf::Vector2i { 100, 1200 },
                        sf::Color::Yellow };

    sf::RenderWindow window { sf::VideoMode { 1920, 1200 }, "Cringe" };
    ColorButtonMan button { 3 };

    button.add_button( but_1);
    button.add_button( but_2);
    button.add_button( but_3);

    kengine::AppMan app { &window, 1, 1 };
    app.add_man( &button);

    while ( window.isOpen() )
    {
        window.clear( sf::Color::Cyan);
        app.on_action();
        app.draw();
 
        window.display();

    }
}
