
#ifndef RECT_BUTTON_CTL_H_
#define RECT_BUTTON_CTL_H_

#include "abstract/abstract_ctl.h"
#include "button/rect_button.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>


#define BETWEEN(coord) mouse_pos.coord < button.get_right().coord &&   \
                       mouse_pos.coord > button.get_left().coord


namespace kengine
{
    // Control
    class RectButtonCtl : public AbstractCtl
    {
    public:
      int
      is_action( RectButton& button)
      {
          sf::Vector2i mouse_pos = sf::Mouse::getPosition();
          return (BETWEEN(x) && BETWEEN(y));
      }

      virtual ~RectButtonCtl() = default;
    };
} // namespace kengine

#endif
