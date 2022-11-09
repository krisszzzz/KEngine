#ifndef APP_MAN_H_
#define APP_MAN_H_

#include "abstract/abstract_widget.h"
#include "abstract/abstract_ctl.h"
#include <vector>

namespace kengine
{
    class AppMan
    {
    public:
        AppMan( sf::RenderWindow* window,
                std::size_t n_widgets, 
                std::size_t n_button_ctls) :
        window_(window),
        vwidgets_(),
        vctls_()
        {
            vwidgets_.reserve( n_widgets);
            vctls_.reserve( n_button_ctls);
        }

        #define add_man( man) add_man_( (man), (man))

        void add_man_( AbstractCtl* ctl, AbstractWidget* widget)
        {
            add_ctl( ctl);
            add_widget( widget);
        }

        void add_ctl( AbstractCtl* ctl)
        {
            vctls_.push_back( ctl);
        }

        void add_widget( AbstractWidget* widget)
        {
            vwidgets_.push_back( widget);
        }

        void draw();
        void on_action();

    private:
        sf::RenderWindow* window_; 
        std::vector<AbstractWidget*> vwidgets_;
        std::vector<AbstractCtl*> vctls_;
    };
}

#endif

