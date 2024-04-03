#ifndef CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP
#define CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP

#include "./Internal_ConditionInfo.hpp"
#include "./Internal_ReturnDataActionInfo.hpp"
#include "./Internal_ResultActionInfo.hpp"
#include "./OverrideStatus.hpp"

namespace CppOverride
{
    struct Internal_OverrideReturnData
    {
        Internal_ConditionInfo ReturnConditionInfo;
        Internal_ReturnDataActionInfo ReturnDataInfo;
        Internal_ResultActionInfo ReturnActionInfo;
        OverrideStatus* Status = nullptr;
    };
}

#endif