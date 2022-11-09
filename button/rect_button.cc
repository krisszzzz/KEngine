#include "rect_button.h"

#define BETWEEN(coord) mouse_pos.coord < right_.coord &&   \
                       mouse_pos.coord > left_.coord

using kengine::RectButton;

int
RectButton::is_valid()
{
    if ( left_.x > right_.x || 
         left_.y < right_.y )
    {
        printf( "The left corner and right corner are switched."
                "The is_click() function working wrong in this case\n"
                "Info: addr = %p, left = (%d, %d), right = (%d, %d)\n", 
                this, left_.x, left_.y, right_.x, right_.y
                );

        return 0;
    }

    return 1;
}

