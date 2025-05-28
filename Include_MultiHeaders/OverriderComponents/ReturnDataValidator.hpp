#ifndef CO_OVERRIDER_COMPONENTS_RETURN_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_RETURN_DATA_VALIDATOR_HPP

#include "./ArgsValuesAppender.hpp"
#include "../OverrideData.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    struct ReturnDataValidator
    {
        ArgsValuesAppender& CurrentArgsValuesAppender;
    
        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_IsCorrectReturnDataInfo 1
        #else
            #define INTERNAL_CO_LOG_IsCorrectReturnDataInfo 0
        #endif

        template<typename ReturnType, typename... Args>
        inline bool IsCorrectReturnDataInfo(OverrideData& overrideDataToCheck,
                                            Args&... args)
        {
            if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                std::cout << std::endl << __func__ << " called" << std::endl;

            std::vector<void*> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            
            if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                std::cout << "Checking return data" << std::endl;

            //Check override return data exist
            if(overrideDataToCheck.CurrentReturnDataInfo.DataSet)
            {
                //Check return type match
                if( overrideDataToCheck.CurrentReturnDataInfo.DataType != 
                    typeid(ReturnType).hash_code())
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Failed at return type" << std::endl;
                    
                    return false;
                }
                
                //If we need to return a reference, 
                //  we check for pointer type as we can't store references
                if( std::is_reference<ReturnType>() && 
                    !overrideDataToCheck.CurrentReturnDataInfo.ReturnReference)
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Failed at return reference" << std::endl;
                    
                    return false;
                }
            }
            else if(overrideDataToCheck.CurrentReturnDataActionInfo.DataActionSet)
            {
                //Check return type match
                if( overrideDataToCheck.CurrentReturnDataActionInfo.DataType != 
                    typeid(ReturnType).hash_code())
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Failed at return type" << std::endl;
                    
                    return false;
                }
                
                //If we need to return a reference, 
                //  we check for pointer type as we can't store references
                if( std::is_reference<ReturnType>() && 
                    !overrideDataToCheck.CurrentReturnDataActionInfo.ReturnReference)
                {
                    if(INTERNAL_CO_LOG_IsCorrectReturnDataInfo)
                        std::cout << "Failed at return action reference" << std::endl;
                    
                    return false;
                }
            }
            else if(overrideDataToCheck.CurrentReturnDataInfo.ReturnAny)
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
        
        inline ReturnDataValidator(ArgsValuesAppender& argsValuesAppender) :
            CurrentArgsValuesAppender(argsValuesAppender)
        {}
    };
}

#endif
