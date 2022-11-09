#ifndef COLOR_BUTTON_H_
#define COLOR_BUTTON_H_

#include <assert.h>
#include "button/rect_button.h"
#include "abstract/drawable.h"

namespace kengine
{
    class ColorButton : public RectButton, public Drawable
    {
    public:
        ColorButton( const sf::Vector2i& left,
                     const sf::Vector2i& right,
                     sf::Color color,
                     handler on_push_handler = print) :
            RectButton( left, right, on_push_handler), 
            Drawable(),
            color_(color)
        {};

        ColorButton() :
            RectButton(),
            Drawable(),
            color_()
        {};

        void draw( sf::RenderWindow* win) override;
        static void print(void*) { assert(!"ColorButton pushed"); };

        sf::Color get_color() { return color_; }
        void set_color( sf::Color color) { color_ = color; }

    private:
        sf::Color color_;
    };
}


#endif

