#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>

namespace kengine
{
    typedef void (*handler)(void*);

    class AbstractButton
    {
    public:
        AbstractButton() : on_action_hdlr_() {};
        AbstractButton( handler on_action_hdlr) :
            on_action_hdlr_(on_action_hdlr) {};

        void set_on_action( handler on_action_hdlr) { on_action_hdlr_ = on_action_hdlr; }
        handler get_on_action() { return on_action_hdlr_; }
        void on_action() { on_action_hdlr_( this); }
      
    private:
        handler on_action_hdlr_;
    };

}

#endif

