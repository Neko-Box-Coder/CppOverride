#ifndef CO_INTERNAL_RETURN_DATA_ACTION_INFO_HPP
#define CO_INTERNAL_RETURN_DATA_ACTION_INFO_HPP

#include "./Internal_DataInfo.hpp"

namespace CppOverride
{
    struct Internal_ReturnDataActionInfo
    {
        std::function<void(const std::vector<void*>& args, void* out)> DataAction;
        bool DataActionSet = false;
    };
}


#endif