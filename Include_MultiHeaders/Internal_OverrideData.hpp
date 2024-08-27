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
        //Condition for override
        Internal_ConditionInfo ConditionInfo;
        
        //Arguments and return data
        std::vector<Internal_DataInfo> ArgumentsDataInfo;
        Internal_ReturnDataInfo ReturnDataInfo;
        
        Internal_ReturnDataActionInfo ReturnDataActionInfo;
        Internal_ArgsDataActionInfo  ArgumentsDataActionInfo;
        
        //Result of the override
        Internal_ResultActionInfo ResultActionInfo;
        std::shared_ptr<OverrideStatus> Status = nullptr;
    };
    
    using Internal_OverrideDataList = std::vector<Internal_OverrideData>;
}

#endif
