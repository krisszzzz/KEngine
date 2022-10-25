#ifndef COLOR_BUTTON_H_
#define COLOR_BUTTON_H_

#include "rect_button.h"
#include "drawable.h"

namespace kengine
{
    class ColorButton : public RectButton, Drawable
    {
    public:
        ColorButton( const sf::Vector2i& left,
                     const sf::Vector2i& right,
                     sf::Color color,
                     handler on_push_handler = on_push) :
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

        static void on_push() { printf("ColorButton pushed\n"); }

        sf::Color get_color() { return color_; }
        void set_color( sf::Color color) { color_ = color; }

    private:
        sf::Color color_;
    };
}


#endif

