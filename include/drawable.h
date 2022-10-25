#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include <SFML/Graphics/RenderWindow.hpp>
namespace kengine
{
    class Drawable
    {
    public:
        virtual ~Drawable() = default;
        virtual void draw( sf::RenderWindow* win) = 0;
    };
}

#endif

