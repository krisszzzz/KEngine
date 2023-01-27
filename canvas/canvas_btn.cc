#include "canvas/canvas_btn.h"
#include "shared/texture_man.h"

namespace kengine
{
    void
    CanvasButton::draw( uint32_t* pixmap, int width, int height)
    {
        size_t texture_width = get_right().x - get_left().x;
        size_t texture_height = get_right().y - get_left().y;

        if ( pos_.y + texture_height > height || pos_.x + texture_width > width )
        {
            fprintf( stderr, "Texture size %lux%lu is bigger than screen size %dx%d",
                     texture_width, texture_height, width, height);
            return;
        }

        if ( update_ )
        {
            TexturedMan* texture_man = TexturedMan::get_instance();
            sf::Image image = texture_man->get_texture( 0);

            for ( size_t y = 0; y < texture_height; y++ )
            {
                for ( size_t x = 0; x < texture_width; x++ )
                {
                    size_t pixel_indx = x + pos_.x + (y + pos_.y) * width; 

                    // Note:
                    // you cannot use toInteger function and copy the whole
                    // 32-bit RGBA color, because it will be problem with further
                    // copying because of endians (different order of byte accessing in
                    // machine word)
                    
                    uint8_t* rgba_ptr = (uint8_t*)(pixmap + pixel_indx);
                    sf::Color curr_color = image.getPixel( x + get_left().x, y + get_left().y);  

                    rgba_ptr[0] = curr_color.r;
                    rgba_ptr[1] = curr_color.g;
                    rgba_ptr[2] = curr_color.b;
                    rgba_ptr[3] = curr_color.a;
                }
            }

            update_ = 0;
        }
    }
};
