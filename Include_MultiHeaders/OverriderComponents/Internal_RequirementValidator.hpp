#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_VALIDATOR_HPP

#include "../PureType.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ConditionArgsTypesChecker.hpp"
#include "./Internal_ConditionArgsValuesChecker.hpp"
#include "../TypeCheck.hpp"
#include "../OverrideStatus.hpp"
#include "../Internal_OverrideData.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_RequirementValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_IsCorrectDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline bool IsMeetingRequirementForDataInfo(Internal_OverrideData& overrideDataToCheck,
                                                        OverrideStatus& outInternalStatus,
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Checking override data" << std::endl;

                //Check parameter condition types/count match
                if( !overrideDataToCheck.ConditionInfo.ArgsCondition.empty() && 
                    !ArgsTypesChecker.CheckArgumentsTypes(  overrideDataToCheck .ConditionInfo
                                                                                .ArgsCondition, 
                                                            0, 
                                                            args...))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    return false;
                }
                
                //Check parameter values
                if( !overrideDataToCheck.ConditionInfo.ArgsCondition.empty() && 
                    !ArgsValuesChecker.CheckArgumentsValues(overrideDataToCheck .ConditionInfo
                                                                                .ArgsCondition, 
                                                            0, 
                                                            outInternalStatus,
                                                            args...))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check parameter" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);
                    
                    return false;
                }
                
                
                //Check condition lambda
                if( overrideDataToCheck.ConditionInfo.DataConditionSet && 
                    !overrideDataToCheck.ConditionInfo.LambdaCondition(argumentsList))
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check condition" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);
                    
                    return false;
                }
                
                //Check times
                if( overrideDataToCheck.ConditionInfo.Times >= 0 && 
                    overrideDataToCheck.ConditionInfo.CalledTimes >= 
                    overrideDataToCheck.ConditionInfo.Times)
                {
                    if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                        std::cout << "Failed at Check times" << std::endl;
                    
                    if(overrideDataToCheck.Status != nullptr)
                        *overrideDataToCheck.Status = OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                    
                    if(overrideDataToCheck.ResultActionInfo.OtherwiseActionSet)
                        overrideDataToCheck.ResultActionInfo.OtherwiseAction(argumentsList);

                    return false;
                }
                
                if(INTERNAL_CO_LOG_IsCorrectDataInfo)
                    std::cout << "Override data found" << std::endl;
                
                return true;
            }
        public:
            inline Internal_RequirementValidator(   Internal_ArgsValuesAppender& argsValuesAppender,
                                                    Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                    Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif