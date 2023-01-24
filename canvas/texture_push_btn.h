#ifndef TEXTURE_PUSH_BTN_H
#define TEXTURE_PUSH_BTN_H

#include "std/plugin.h"

namespace kengine
{
    typedef unsigned int uint32_t;

class TexturedPushButton : public IPushButton
{
public:
    void draw( uint32_t* screen, int width, int height) override;
};

}

#endif
