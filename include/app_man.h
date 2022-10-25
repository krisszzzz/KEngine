#ifndef APP_MAN_H_
#define APP_MAN_H_

#include "abstract_widget.h"
#include "abstract_button_ctl.h"
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
        vbutton_ctls_()
        {
            vwidgets_.reserve( n_widgets);
            vbutton_ctls_.reserve( n_button_ctls);
        }

        #define add_man( man) add_man_( (man), (man))

        void add_man_( AbstractButtonCtl* ctl, AbstractWidget* widget)
        {
            add_ctl( ctl);
            add_widget( widget);
        }

        void add_ctl( AbstractButtonCtl* ctl)
        {
            vbutton_ctls_.push_back( ctl);
        }

        void add_widget( AbstractWidget* widget)
        {
            vwidgets_.push_back( widget);
        }

        void draw();
        void on_push();

    private:
        sf::RenderWindow* window_; 
        std::vector<AbstractWidget*> vwidgets_;
        std::vector<AbstractButtonCtl*> vbutton_ctls_;
    };
}

#endif

