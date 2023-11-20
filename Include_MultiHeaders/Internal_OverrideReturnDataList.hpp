#ifndef CO_INTERNAL_OVERRIDE_RETURN_DATA_LIST_HPP
#define CO_INTERNAL_OVERRIDE_RETURN_DATA_LIST_HPP

#include <vector>
#include "./Internal_OverrideReturnData.hpp"

namespace CppOverride
{
    struct Internal_OverrideReturnDataList
    {
        std::vector<Internal_OverrideReturnData> ReturnDatas = {};
    };
}

#endif