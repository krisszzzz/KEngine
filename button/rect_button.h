#ifndef RECT_BUTTON_H_
#define RECT_BUTTON_H_

#include "abstract/abstract_button.h"

namespace kengine
{
    class RectButton : public AbstractButton
    {
    public:
        RectButton() : AbstractButton(), left_(), right_() {};
        RectButton( const sf::Vector2i& left, 
                    const sf::Vector2i& right,
                    handler on_push_hdlr) :
            AbstractButton( on_push_hdlr), 
            left_(left), 
            right_(right)
        {};
        
        int is_valid();

        void set_left(  const sf::Vector2i& left)  { left_ = left; }
        void set_right( const sf::Vector2i& right) { right_ = right; }

        sf::Vector2i& get_left()  { return left_; }
        sf::Vector2i& get_right() { return right_; }

        const sf::Vector2i& get_left()  const { return left_; }
        const sf::Vector2i& get_right() const { return right_; }

    private:
        sf::Vector2i left_;
        sf::Vector2i right_;
    };

}

#endif
