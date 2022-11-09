#include "button/color_button.h"
#include "button/rect_button_ctl.h"
#include "abstract/abstract_widget.h"
#include <vector>

namespace kengine
{
    class ColorButtonMan : public RectButtonCtl, public AbstractWidget
    {
    public:
        ColorButtonMan( std::size_t size) :
            RectButtonCtl(),
            AbstractWidget(size),
            vbuttons_()
        {
            vbuttons_.reserve( size);
        }
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

        void 
        add_button( const ColorButton& button)
        {
            vbuttons_.push_back( button);
        }
        
        std::size_t 
        get_n_objects() const
        {
            return vbuttons_.size();
        }

        void on_action( sf::Event::EventType event_type) override;
        void draw( sf::RenderWindow* win) override;

    private:
        std::vector<ColorButton> vbuttons_;
    };

}

