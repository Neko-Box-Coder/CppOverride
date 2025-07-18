#ifndef CO_RESULT_ACTION_INFO_HPP
#define CO_RESULT_ACTION_INFO_HPP

#include "./TypedDataInfo.hpp"
#include <functional>
#include <vector>

namespace CppOverride
{
    struct ResultActionInfo
    {
        std::function<void(void* instance, std::vector<TypedDataInfo>& args)> OtherwiseAction;
        std::function<void(void* instance, std::vector<TypedDataInfo>& args)> CorrectAction;
        bool OtherwiseActionSet = false;
        bool CorrectActionSet = false;
    };
}

#endif
