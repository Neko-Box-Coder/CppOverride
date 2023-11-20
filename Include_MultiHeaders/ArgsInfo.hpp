#ifndef SO_ARGS_INFO_HPP
#define SO_ARGS_INFO_HPP

#include <cstddef>
#include <functional>

namespace SimpleOverride
{
    struct ArgInfo
    {
        void* ArgDataPointer = nullptr;
        std::function<void*(void* data)> CopyConstructor;
        std::function<void(void* data)> Destructor;
        size_t ArgSize = 0;
        size_t ArgTypeHash = 0;
        bool ArgSet = false;
    };
}

#endif