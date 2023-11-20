#ifndef SO_INTERNAL_CONDITION_INFO_HPP
#define SO_INTERNAL_CONDITION_INFO_HPP

#include "./ArgsInfo.hpp"

#include <functional>
#include <vector>

namespace SimpleOverride
{
    struct Internal_ConditionInfo
    {
        std::function<bool(const std::vector<void*>& args)> DataCondition;
        std::vector<ArgInfo> ArgsCondition = {};
        int Times = -1;
        int CalledTimes = 0;
        bool DataConditionSet = false;
    };
}

#endif