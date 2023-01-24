#ifndef CANVAS_BUTTON_H
#define CANVAS_BUTTON_H

#include <SFML/Graphics.hpp>
#include "std/plugin.h"
#include "shared/textured.h"

namespace kengine
{
    
    class CanvasButton : public IWidget, public Textured 
    {
    public:
        CanvasButton( bool update,
                      const char* texture_path,
                      const Border& border) :
            Textured( texture_path, border),
            update_(update) {};
        
        void draw( uint32_t* pixmap, int width, int height) override; 
        
        void set_pos( Pair<int> /* point */) override {};

        Pair<int> get_pos() override { return Pair<int> {}; };

        Pair<int> get_size() override { return Pair<int> {}; };

        void contains( Pair<int> /* point */) override {};

        void on_mouse_move( Pair<int> /* point */) override {};
        void on_mouse_release( Pair<int> /* point */) override {};
        void on_mouse_press( Pair<int> /* point */) override {};

        void on_key_press( int /* key */) override {};
        void on_key_release( int /* key */) override {};

        ~CanvasButton() = default;

    private:
        bool update_; // need to redraw a texture or not
    };


}

#endif
