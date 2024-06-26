#ifndef CO_INTERNAL_OVERRIDE_ARGS_DATA_HPP
#define CO_INTERNAL_OVERRIDE_ARGS_DATA_HPP

#include "./Internal_ConditionInfo.hpp"
#include "./Internal_ResultActionInfo.hpp"
#include "./Internal_DataInfo.hpp"
#include "./Internal_ArgsDataActionInfo.hpp"
#include "./OverrideStatus.hpp"


namespace CppOverride
{
    struct Internal_OverrideArgsData
    {
        Internal_ConditionInfo ArgumentsConditionInfo;
        std::vector<Internal_DataInfo> ArgumentsDataInfo;
        Internal_ArgsDataActionInfo  ArgumentsDataActionInfo;
        Internal_ResultActionInfo ArgumentsActionInfo;
        OverrideStatus* Status = nullptr;
    };
}

#endif