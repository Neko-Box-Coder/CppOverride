#ifndef CO_OVERRIDE_DATA_HPP
#define CO_OVERRIDE_DATA_HPP

#include "./ReturnDataActionInfo.hpp"
#include "./ConditionInfo.hpp"
#include "./ResultActionInfo.hpp"
#include "./DataInfo.hpp"
#include "./ArgsDataActionInfo.hpp"
#include "./OverrideStatus.hpp"

#include <memory>

namespace CppOverride
{
    struct OverrideData
    {
        //The object instance we are overriding if specified, 
        //  nullptr for non specified or free function
        void* Instance = nullptr;
        
        //Condition for override
        ConditionInfo CurrentConditionInfo;
        
        //Arguments and return data
        std::vector<DataInfo> ArgumentsDataInfo;
        ReturnDataInfo CurrentReturnDataInfo;
        
        ReturnDataActionInfo CurrentReturnDataActionInfo;
        ArgsDataActionInfo ArgumentsDataActionInfo;
        
        //Result of the override
        ResultActionInfo CurrentResultActionInfo;
        std::shared_ptr<OverrideResult> Result = nullptr;
    };
}

#endif
