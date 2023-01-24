#include "canvas/canvas_btn.h"
#include "shared/texture_man.h"

namespace kengine
{
    void
    CanvasButton::draw( uint32_t* pixmap, int width, int height)
    {
        if ( update_ )
        {
            TexturedMan* texture_man = TexturedMan::get_instance();
            sf::Image image = texture_man->get_texture( 0);

            for ( size_t y = 0; y < image.getSize().y; y++ )
            {
                for ( size_t x = 0; x < image.getSize().x; x++ )
                {
                    size_t pixel_indx = x + y * width; 
                    pixmap[pixel_indx] = image.getPixel(x, y).toInteger();
                }
            }

            update_ = 0;
        }
    }
};
