#ifndef CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP
#define CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP

#include "./Internal_ConditionInfo.hpp"
#include "./Internal_ReturnDataInfo.hpp"
#include "./Internal_ActionInfo.hpp"
#include "./OverrideStatus.hpp"

namespace CppOverride
{
    struct Internal_OverrideReturnData
    {
        Internal_ConditionInfo ReturnConditionInfo;
        Internal_ReturnDataInfo ReturnDataInfo;
        Internal_ActionInfo ReturnActionInfo;
        OverrideStatus* Status = nullptr;
    };
}

#endif