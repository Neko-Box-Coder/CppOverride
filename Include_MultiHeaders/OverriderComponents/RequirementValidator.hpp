#ifndef CO_OVERRIDER_COMPONENTS_REQUIREMENT_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_REQUIREMENT_VALIDATOR_HPP

#include "../PureType.hpp"
#include "./ArgsValuesAppender.hpp"
#include "./ConditionArgsTypesChecker.hpp"
#include "./ConditionArgsValuesChecker.hpp"
#include "../TypeCheck.hpp"
#include "../OverrideStatus.hpp"
#include "../OverrideData.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    struct RequirementValidator
    {
        public:
            ArgsValuesAppender& CurrentArgsValuesAppender;
            ConditionArgsTypesChecker& CurrentArgsTypesChecker;
            ConditionArgsValuesChecker& CurrentArgsValuesChecker;
        
            #if CO_SHOW_OVERRIDE_LOG
                #define INTERNAL_CO_LOG_IsCorrectDataInfo 1
            #else
                #define INTERNAL_CO_LOG_IsCorrectDataInfo 0
            #endif

            template<typename ReturnType, typename... Args>
            inline bool IsMeetingRequirementForDataInfo(OverrideData& overrideDataToCheck,
                                                        OverrideStatus& outInternalStatus,
                                                        void* instance,
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Checking override data" << std::endl;

                //Check parameter condition types/count match
                if( !overrideDataToCheck.CurrentConditionInfo.ArgsCondition.empty() && 
                    !CurrentArgsTypesChecker.CheckArgumentsTypes
                    (
                        overrideDataToCheck.CurrentConditionInfo.ArgsCondition, 
                        0, 
                        args...
                    ))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    return false;
                }
                
                //Check parameter values
                if( !overrideDataToCheck.CurrentConditionInfo.ArgsCondition.empty() && 
                    !CurrentArgsValuesChecker.CheckArgumentsValues
                    (
                        overrideDataToCheck.CurrentConditionInfo.ArgsCondition, 
                        0, 
                        outInternalStatus,
                        args...
                    ))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    if(overrideDataToCheck.Result != nullptr)
                    {
                        overrideDataToCheck.Result->AddStatus
                            (OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
                    }
                    
                    if(overrideDataToCheck.CurrentResultActionInfo.OtherwiseActionSet)
                    {
                        overrideDataToCheck .CurrentResultActionInfo
                                            .OtherwiseAction(instance, argumentsList);
                    }
                    return false;
                }
                
                //Check condition lambda
                //TODO: Enforce type for arguments
                if( overrideDataToCheck.CurrentConditionInfo.DataConditionSet && 
                    !overrideDataToCheck.CurrentConditionInfo.LambdaCondition(  instance,
                                                                                argumentsList))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check condition" << std::endl;
                    
                    if(overrideDataToCheck.Result != nullptr)
                    {
                        overrideDataToCheck.Result->AddStatus
                            (OverrideStatus::MATCHING_CONDITION_ACTION_FAILED);
                    }
                    
                    if(overrideDataToCheck.CurrentResultActionInfo.OtherwiseActionSet)
                    {
                        overrideDataToCheck .CurrentResultActionInfo
                                            .OtherwiseAction(   instance, 
                                                                argumentsList);
                    }
                    
                    return false;
                }
                
                //Check times
                if( overrideDataToCheck.CurrentConditionInfo.Times >= 0 && 
                    overrideDataToCheck.CurrentConditionInfo.CalledTimes >= 
                    overrideDataToCheck.CurrentConditionInfo.Times)
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check times" << std::endl;
                    
                    if(overrideDataToCheck.Result != nullptr)
                    {
                        overrideDataToCheck.Result->AddStatus
                            (OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED);
                    }
                    
                    if(overrideDataToCheck.CurrentResultActionInfo.OtherwiseActionSet)
                    {
                        overrideDataToCheck .CurrentResultActionInfo
                                            .OtherwiseAction(instance, argumentsList);
                    }

                    return false;
                }
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Override data found" << std::endl;
                
                return true;
            }
            
            inline RequirementValidator(ArgsValuesAppender& argsValuesAppender,
                                        ConditionArgsTypesChecker& argsTypesChecker,
                                        ConditionArgsValuesChecker& argsValuesChecker) : 
                CurrentArgsValuesAppender(argsValuesAppender),
                CurrentArgsTypesChecker(argsTypesChecker),
                CurrentArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif
