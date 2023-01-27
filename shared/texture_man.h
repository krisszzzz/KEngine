#ifndef TEXTURE_MAN_H
#define TEXTURE_MAN_H

#include "shared/textured.h"
#include <unordered_map>

namespace kengine
{
    class TexturedMan
	{
    public:
        NON_COPYABLE( TexturedMan);
        
        void load_texture()
        {
            ptextures_ = new sf::Image[vtextured_.size()];
            
            for ( std::size_t i = 0; i < vtextured_.size(); i++ )
            {
                ptextures_[i].loadFromFile( vtextured_.at( i)->get_texture_path());
                
                if ( vtextured_.at( i)->use_image_border() )
                {
                    vtextured_.at( i)->set_left( sf::Vector2u { 0, 0 });
                    vtextured_.at( i)->set_right( ptextures_[i].getSize());
                }
            }

        }

        void texture_register( Textured* textured)
        {
            vtextured_.push_back( textured);
        }

        const std::vector<Textured*>& get_vtextured() const
        {
            return vtextured_;
        }

        static TexturedMan* get_instance()
        {
            static TexturedMan instance {};
            return &instance;
        }

        sf::Image& get_texture( const size_t indx)
        {
            return ptextures_[indx];
        }

        const sf::Image& get_texture( const size_t indx) const
        {
            return ptextures_[indx];
        }

    private:
        // Singleton pattern require private constructor
        TexturedMan() : vtextured_(), ptextures_() {};
        
        std::vector<Textured*> vtextured_;
        sf::Image* ptextures_;
    };};

#endif
