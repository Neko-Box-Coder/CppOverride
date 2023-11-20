#ifndef SO_INTERNAL_ACTION_INFO_HPP
#define SO_INTERNAL_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace SimpleOverride
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