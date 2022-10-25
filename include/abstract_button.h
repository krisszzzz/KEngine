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
        AbstractButton() : on_push_hdlr_() {};
        AbstractButton( handler on_push_hdlr) :
            on_push_hdlr_(on_push_hdlr) {};

        virtual int is_push() = 0;
        virtual ~AbstractButton() = default;

        void set_on_push( handler on_push_hdlr) { on_push_hdlr_ = on_push_hdlr; }
        handler get_on_push() { return on_push_hdlr_; }
        void on_push() { on_push_hdlr_(); }
      
    private:
        handler on_push_hdlr_;
    };

}

#endif

