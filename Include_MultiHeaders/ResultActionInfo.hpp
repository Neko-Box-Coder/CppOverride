#ifndef CO_RESULT_ACTION_INFO_HPP
#define CO_RESULT_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct ResultActionInfo
    {
        std::function<void(void* instance, const std::vector<void*>& args)> OtherwiseAction;
        std::function<void(void* instance, const std::vector<void*>& args)> CorrectAction;
        bool OtherwiseActionSet = false;
        bool CorrectActionSet = false;
    };
}

#endif
