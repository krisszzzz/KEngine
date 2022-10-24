#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>

namespace kengine
{

    typedef void (*handler)();

    class AbstractButton
    {
    public:
        AbstractButton() : left_(), right_(), on_click_() {};
        AbstractButton( sf::Vector2i left, sf::Vector2i right, handler on_click) :
            left_(left), right_(right), on_click_(on_click) {};

        virtual void draw( sf::RenderWindow* window);
        virtual ~AbstractButton() = default;

        int is_click();
        // check is button right and left corners actually left and right
        int is_valid();

        void set_left( const sf::Vector2i& left) { left_ = left; }
        
        void set_right( const sf::Vector2i& right) { right_ = right; }

        void set_on_click( handler on_click) { on_click_ = on_click; }

        handler get_on_click() { return on_click_; }

        sf::Vector2i& get_left() { return left_; }

        const sf::Vector2i& get_left() const { return left_; }

        sf::Vector2i& get_right() { return right_; }

        const sf::Vector2i& get_right() const { return right_; }

    private:
        sf::Vector2i left_;
        sf::Vector2i right_; 
        handler on_click_;
    };

    class Pen;

    class ColorButton : public AbstractButton
    {
    public:
        ColorButton( sf::Vector2i left, 
                     sf::Vector2i right, 
                     handler event_handler = &on_click) :
            AbstractButton( left, right, event_handler), 
            color_(), 
            pen_() 
        {};


        ColorButton(): AbstractButton(), color_(), pen_() {};

        void draw( sf::RenderWindow* window) override;

        void set_color( sf::Color color) { color_ = color; }

        sf::Color get_color() { return color_; }

        Pen* get_pen() { return pen_; }

        static void on_click() { printf( "ColorButton is pushed\n"); }

    private:
        sf::Color color_;
        Pen* pen_;

    };


    class ButtonMgr
    {
    public:    
        ButtonMgr( const std::size_t button_count) :
            vbuttons_ ()
        {
            vbuttons_.reserve( button_count);
        };

        ButtonMgr() : vbuttons_() {};

        void on_click();

        void add_button( AbstractButton* button);
        void draw( sf::RenderWindow* window);

        const AbstractButton*
        operator[]( const std::size_t button_indx) const
        {
            return vbuttons_.at( button_indx);
        }

        AbstractButton*
        operator[]( const std::size_t button_indx)
        {
            return vbuttons_.at( button_indx);
        }

        std::vector<AbstractButton*>& 
        get_buttons() 
        {
            return vbuttons_;
        }

    private:
        std::vector<AbstractButton*> vbuttons_;
    };

}

#endif

