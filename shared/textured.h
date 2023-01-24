#ifndef TEXTURED_H
#define TEXTURED_H

#include "shared/non_copyable.h"
#include <string.h>
#include <SFML/Graphics.hpp>

namespace kengine
{
    typedef std::pair<sf::Vector2i, sf::Vector2i> Border;


    /**
       @brief class that provide minimum API for working
       with textures
     */
    
    class Textured
    {
    public:
        // Non-copyable class
        NON_COPYABLE( Textured);

        // No default constructor
        Textured( const char* texture_path,
                  const Border& border) :
            texture_path_(),
            texture_left_(),
            texture_right_()
        {
            texture_path_ = strdup( texture_path);
            texture_left_ = border.first;
            texture_right_ = border.second;
        }

        void set_texture_path( const char* texture_path)
        {
            texture_path = strdup( texture_path);
        }

        char* get_texture_path() const
        {
            return texture_path_;
        }

        const sf::Vector2i& get_left() const
        {
            return texture_left_;
        }

        sf::Vector2i& get_left()
        {
            return texture_left_;
        }

        const sf::Vector2i& get_right() const
        {
            return texture_right_;
        }

        sf::Vector2i& get_right()
        {
            return texture_right_;
        }

    private:
        char* texture_path_;
        sf::Vector2i texture_left_;
        sf::Vector2i texture_right_;
        
    };

    /**
       @brief Class for creating objects that use textures but
       have specific shape that should be displayed correctly
     */

    template <typename Shape>
    class ShapeTextured : public Textured
    {
    public:
        
        ShapeTextured<Shape>( const char* texture_path, const Shape& shape) :
            Textured( texture_path, get_border( shape))
        {};

        ShapeTextured<Shape>( const char* texture_path, const Border& border) :
            Textured( texture_path, border)
        {};

        // get the border of texture
        static Border get_border( const Shape& shape);
    };
}

#endif
