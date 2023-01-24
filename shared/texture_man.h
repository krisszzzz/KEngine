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

        //void get_texture( const char* texture_path)
        sf::Image& get_texture( const size_t indx)
        {
            return ptextures_[indx];
        }

        const sf::Image& get_texture( const size_t indx) const
        {
            return ptextures_[indx];
        }

    private:
        TexturedMan() : vtextured_(), ptextures_() {};
        
        std::vector<Textured*> vtextured_;
        sf::Image* ptextures_;
    };};

#endif
