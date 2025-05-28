#ifndef CO_CONDITION_INFO_HPP
#define CO_CONDITION_INFO_HPP

#include "./DataInfo.hpp"

#include <functional>
#include <vector>

namespace CppOverride
{
    struct ConditionInfo
    {
        std::function<bool(void* instance, const std::vector<void*>& args)> LambdaCondition;
        std::vector<DataInfo> ArgsCondition = {};
        int Times = -1;
        int CalledTimes = 0;
        bool DataConditionSet = false;
    };
}

#endif
