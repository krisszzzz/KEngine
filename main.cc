#include "std/plugin.h"
#include "shared/texture_man.h"
#include "canvas/canvas_btn.h"
#include <stdint.h>

using kengine::CanvasButton;
using kengine::TexturedMan;

int main()
{
    sf::RenderWindow window { sf::VideoMode { 1920, 1200 }, "Cringe" };
    CanvasButton btn { true, "textures/button.png", kengine::Border {} };

    auto man = TexturedMan::get_instance();

    man->texture_register( &btn);
    man->load_texture();

    uint32_t* pixmap = new uint32_t[1920 * 1200]; 

    sf::Sprite sprite {};
    sf::Texture texture {};
    texture.create( 1920, 1200);
    
    while ( window.isOpen() )
    {
        window.clear( sf::Color::Cyan);
        btn.draw( pixmap, 1920, 1200);
        texture.update( (sf::Uint8*)pixmap);
        sprite.setTexture( texture);
        window.draw( sprite);
        window.display();

    }

    
    return 0;
}

