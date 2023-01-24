#ifndef SINGLETON_H
#define SINGLETON_H

#include "shared/non_copyable.h"

namespace kengine
{
    template<typename SingletonObj>
    class Singleton : public NonCopyable
    {
    public:
        static SingletonObj* get_instance() 
        {
            static SingletonObj singleton {};
            return &singleton;
        };

    };

}

#endif
