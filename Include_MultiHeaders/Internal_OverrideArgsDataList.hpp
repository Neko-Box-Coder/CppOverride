#ifndef CO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP
#define CO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP

#include "./Internal_OverrideArgsData.hpp"
#include <vector>

namespace CppOverride
{
    struct Internal_OverrideArgsDataList
    {
        std::vector<Internal_OverrideArgsData> ArgumentsDatas = {};
    };
}

#endif