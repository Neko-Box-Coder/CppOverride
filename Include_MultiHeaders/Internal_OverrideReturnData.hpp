#ifndef SO_INTERNAL_OVERRIDE_RETURN_DATA_HPP
#define SO_INTERNAL_OVERRIDE_RETURN_DATA_HPP

#include "./Internal_ConditionInfo.hpp"
#include "./Internal_ReturnDataInfo.hpp"
#include "./Internal_ActionInfo.hpp"

namespace SimpleOverride
{
    struct Internal_OverrideReturnData
    {
        Internal_ConditionInfo ReturnConditionInfo;
        Internal_ReturnDataInfo ReturnDataInfo;
        Internal_ActionInfo ReturnActionInfo;
    };
}

#endif