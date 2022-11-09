#ifndef ABSTRACT_BUTTON_CTL_H_
#define ABSTRACT_BUTTON_CTL_H_
#include <SFML/Window/Event.hpp>

namespace kengine
{
    class AbstractCtl 
    {
    public:
        virtual ~AbstractCtl() = default;
        virtual void on_action( sf::Event::EventType event_type) = 0;
    };
}

#endif

