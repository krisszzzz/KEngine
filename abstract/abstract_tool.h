#ifndef ABSTRACT_TOOL_H_
#define ABSTRACT_TOOL_H_

namespace kengine 
{
    class AbstractTool 
    {
    public:
        virtual void on_choose() = 0;
        virtual ~AbstractTool() = default;
    };
}

#endif

