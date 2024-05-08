#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_VALIDATOR_HPP

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
    class Internal_ReturnDataValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_IsCorrectReturnDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline bool IsCorrectReturnDataInfo(Internal_OverrideData& overrideDataToCheck,
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << "Checking return data" << std::endl;

                //Check override return data exist
                if(overrideDataToCheck.ReturnDataInfo.DataSet)
                {
                    //Check return type match
                    if(overrideDataToCheck.ReturnDataInfo.DataType != typeid(ReturnType).hash_code())
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return type" << std::endl;
                        
                        return false;
                    }
                    
                    //If we need to return a reference, 
                    //  we check for pointer type as we can't store references
                    if( std::is_reference<ReturnType>() && 
                        !overrideDataToCheck.ReturnDataInfo.ReturnReference)
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return reference" << std::endl;
                        
                        return false;
                    }
                }
                else if(overrideDataToCheck.ReturnDataActionInfo.DataActionSet)
                {
                    //Check return type match
                    if( overrideDataToCheck.ReturnDataActionInfo.DataType != 
                        typeid(ReturnType).hash_code())
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return type" << std::endl;
                        
                        return false;
                    }
                    
                    //If we need to return a reference, 
                    //  we check for pointer type as we can't store references
                    if( std::is_reference<ReturnType>() && 
                        !overrideDataToCheck.ReturnDataActionInfo.ReturnReference)
                    {
                        if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                            std::cout << "Failed at return action reference" << std::endl;
                        
                        return false;
                    }
                }
                else if(overrideDataToCheck.ReturnDataInfo.ReturnAny)
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Any return type entry encountered" << std::endl;
                }
                else
                    return false;
                
                if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                    std::cout << "Return data found" << std::endl;
                
                return true;
            }
        public:
            inline Internal_ReturnDataValidator(Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif