#ifndef CO_INTERNAL_OVERRIDE_DATA_HPP
#define CO_INTERNAL_OVERRIDE_DATA_HPP

#include "./Internal_ReturnDataActionInfo.hpp"
#include "./Internal_ConditionInfo.hpp"
#include "./Internal_ResultActionInfo.hpp"
#include "./Internal_DataInfo.hpp"
#include "./Internal_ArgsDataActionInfo.hpp"
#include "./OverrideStatus.hpp"


namespace CppOverride
{
    struct Internal_OverrideData
    {
        Internal_ConditionInfo ConditionInfo;
        std::vector<Internal_DataInfo> ArgumentsDataInfo;
        Internal_DataInfo ReturnDataInfo;
        
        Internal_ReturnDataActionInfo ReturnDataActionInfo;
        Internal_ArgsDataActionInfo  ArgumentsDataActionInfo;
        
        Internal_ResultActionInfo ResultActionInfo;
        OverrideStatus* Status = nullptr;
    };
    
    using Internal_OverrideDataList = std::vector<Internal_OverrideData>;
}

#endif