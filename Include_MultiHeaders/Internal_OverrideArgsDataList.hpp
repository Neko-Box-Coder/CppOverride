#ifndef SO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP
#define SO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP

#include "./Internal_OverrideArgsData.hpp"
#include <vector>

namespace SimpleOverride
{
    struct Internal_OverrideArgsDataList
    {
        std::vector<Internal_OverrideArgsData> ArgumentsDatas = {};
    };
}

#endif