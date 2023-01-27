#include "shared/textured.h"
#include "std/plugin.h"
#include "shared/texture_man.h"
#include "canvas/canvas_btn.h"

using kengine::CanvasButton;
using kengine::TexturedMan;

int main()
{
    sf::RenderWindow window { sf::VideoMode { 1920, 1080 }, "Cringe" };
    CanvasButton btn { true, "textures/button.png", Pair<int> { 100, 100 }, kengine::Border { { 0, 0 }, { 25, 25 } } };
        

    auto man = TexturedMan::get_instance();

    man->texture_register( &btn);
    man->load_texture();

    uint32_t* pixmap = new uint32_t[1920 * 1080]; 

    sf::Image buttn {};
    sf::Sprite sprite {};
    sf::Texture texture {};
    texture.create( 1920, 1080);

    
    while ( window.isOpen() )
    {
        window.clear( sf::Color::White);
        btn.draw( pixmap, 1920, 1080);
        texture.update( (sf::Uint8*)pixmap);
        sprite.setTexture( texture);
        window.draw( sprite);
        window.display();
    }

    
    return 0;
}

