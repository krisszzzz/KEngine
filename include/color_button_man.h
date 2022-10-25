#include "color_button.h"
#include "abstract_button_ctl.h"
#include "abstract_widget.h"
#include <vector>

namespace kengine 
{
    class ColorButtonMan : public AbstractButtonCtl, public AbstractWidget
    {
    public:
        ColorButtonMan( std::size_t size) :
            AbstractButtonCtl( size),
            AbstractWidget( size),
            vbuttons_()
        {
            vbuttons_.reserve( size);
        }

        void on_push( sf::Event::EventType event_type) override;
        void draw( sf::RenderWindow* win) override;

        ColorButton& 
        operator[]( std::size_t indx)
        {
            return vbuttons_.at( indx);
        }

        const ColorButton& 
        operator[]( std::size_t indx) const
        {
            return  vbuttons_.at( indx);
        }

        void add_button( const ColorButton& button)
        {
            vbuttons_.push_back( button);
        }

    private:
        std::vector<ColorButton> vbuttons_;
    };

}

