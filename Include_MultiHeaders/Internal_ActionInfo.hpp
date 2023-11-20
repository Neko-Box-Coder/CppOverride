#ifndef CO_INTERNAL_ACTION_INFO_HPP
#define CO_INTERNAL_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ActionInfo
    {
        std::function<void(const std::vector<void*>& args)> OtherwiseAction;
        std::function<void(const std::vector<void*>& args)> CorrectAction;
        bool OtherwiseActionSet = false;
        bool CorrectActionSet = false;
    };
}

#endif