#ifndef ABSTRACT_BUTTON_CTL_H_
#define ABSTRACT_BUTTON_CTL_H_
#include <SFML/Window/Event.hpp>

namespace kengine
{
    class AbstractButtonCtl 
    {
    public:
        AbstractButtonCtl( std::size_t n_buttons) :
            n_buttons_(n_buttons)
        {};
        AbstractButtonCtl() :
            n_buttons_(0)
        {};

        virtual ~AbstractButtonCtl() = default;
        virtual void on_push( sf::Event::EventType event_type) = 0;

        std::size_t get_n_button() const { return n_buttons_; }
        void set_n_button( std::size_t n_buttons) { n_buttons_ = n_buttons; }
    private:
        std::size_t n_buttons_;
    };
}

#endif

