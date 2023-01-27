#ifndef TEXTURED_H
#define TEXTURED_H

#include "shared/non_copyable.h"
#include <SFML/System/Vector2.hpp>
#include <string.h>
#include <SFML/Graphics.hpp>

namespace kengine
{
    typedef std::pair<sf::Vector2u, sf::Vector2u> Border;

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
        // { 0, 0 }, { 0, 0 } default value of border
        Textured( const char* texture_path,
                  const Border& border = { { 0, 0 }, { 0, 0 } }) :
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

        bool use_image_border() const
        {
            if ( texture_left_ == texture_right_ &&
                 texture_left_ == sf::Vector2u { 0, 0 } )
            {
                return true;
            }

            return false;
        }

        void set_left( const sf::Vector2u& left)
        {
            texture_left_ = left;
        }

        void set_right( const sf::Vector2u& right)
        {
            texture_right_ = right;
        }
        
        const sf::Vector2u& get_left() const
        {
            return texture_left_;
        }

        sf::Vector2u& get_left()
        {
            return texture_left_;
        }

        const sf::Vector2u& get_right() const
        {
            return texture_right_;
        }

        sf::Vector2u& get_right()
        {
            return texture_right_;
        }

    private:
        char* texture_path_;
        sf::Vector2u texture_left_;
        sf::Vector2u texture_right_;
    };
    
}

#endif
