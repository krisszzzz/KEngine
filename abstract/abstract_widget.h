#ifndef ABSTRACT_WIDGET_
#define ABSTRACT_WIDGET_

#include "drawable.h"
#include <assert.h>
#undef N_DEBUG

namespace kengine
{
    class AbstractWidget
    {
    public:
        AbstractWidget( std::size_t n_draws) :
            n_draws_(n_draws) 
        {};

        AbstractWidget() : 
            n_draws_(0) 
        {}; 

        virtual void draw( sf::RenderWindow* window) = 0;

        virtual ~AbstractWidget() = default; 

        std::size_t get_n_draws() const { return n_draws_; }
        void set_n_draws( std::size_t n_draws) { n_draws_ = n_draws; }

    private:
        std::size_t n_draws_;
    };
}

#endif


