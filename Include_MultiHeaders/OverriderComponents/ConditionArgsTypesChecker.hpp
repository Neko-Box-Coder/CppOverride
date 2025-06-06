#ifndef CO_OVERRIDER_COMPONENTS_CONDITION_ARGS_TYPES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_CONDITION_ARGS_TYPES_CHECKER_HPP

#include "../Any.hpp"
#include "../DataInfo.hpp"
#include "../PureType.hpp"

#include <vector>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    struct ConditionArgsTypesChecker
    {
        inline bool CheckArgumentsTypes(std::vector<DataInfo>&, int) { return true; };

        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_CheckArguments 1
        #else
            #define INTERNAL_CO_LOG_CheckArguments 0
        #endif

        //Check void*
        template
        <
            typename T, 
            typename PureType = INTERNAL_CO_PURE_TYPE(T),
            typename std::enable_if<std::is_same<PureType, void>::value, bool>::type = true, 
            typename... Args
        >
        inline bool CheckArgumentsTypes(std::vector<DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T&, 
                                        Args&... args)
        {
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << std::endl;
            }
        
            if(argIndex >= validArgumentsList.size())
                return false;

            if(validArgumentsList.at(argIndex).DataSet)
            {
                if(typeid(void*).hash_code() != validArgumentsList.at(argIndex).DataType)
                    return false;
            }
            
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << " passed" << std::endl;
            }
            
            return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
        }
        
        //Check reference
        template
        <
            typename T, 
            typename RawType = INTERNAL_CO_RAW_TYPE(T), 
            typename std::enable_if<!std::is_pointer<RawType>::value, bool>::type = true,
            typename... Args
        >
        inline bool CheckArgumentsTypes(std::vector<DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T&, 
                                        Args&... args)
        {
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << std::endl;
            }
        
            if(argIndex >= validArgumentsList.size())
                return false;

            if(validArgumentsList.at(argIndex).DataSet)
            {
                if( typeid(RawType).hash_code() != validArgumentsList.at(argIndex).DataType &&
                    typeid(RawType&).hash_code() != validArgumentsList.at(argIndex).DataType &&
                    //NOTE: Reference can be compared as pointer later down the line
                    typeid(RawType*).hash_code() != validArgumentsList.at(argIndex).DataType)
                {
                    return false;
                }
            }
            
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << " passed" << std::endl;
            }
            
            return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
        }
        
        //Check Pointer or value
        template
        <
            typename T, 
            typename RawType = INTERNAL_CO_RAW_TYPE(T), 
            typename std::enable_if<std::is_pointer<RawType>::value, bool>::type = true,
            typename std::enable_if<!std::is_same<  INTERNAL_CO_PURE_TYPE(RawType), 
                                                    void>::value, bool>::type = true, 
            typename PureType = INTERNAL_CO_PURE_TYPE(T),
            typename... Args
        >
        inline bool CheckArgumentsTypes(std::vector<DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T&, 
                                        Args&... args)
        {
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << std::endl;
            }
        
            if(argIndex >= validArgumentsList.size())
                return false;

            if(validArgumentsList.at(argIndex).DataSet)
            {
                    //Check pointer type
                if( typeid(RawType).hash_code() != validArgumentsList.at(argIndex).DataType &&
                    //Check value type
                    typeid(PureType).hash_code() != validArgumentsList.at(argIndex).DataType)
                {
                    if(INTERNAL_CO_LOG_CheckArguments)
                    {
                        std::cout <<    "typeid(RawType).hash_code(): " <<
                                        typeid(RawType).hash_code() << 
                                        std::endl;
                        std::cout <<    "typeid(PureType).hash_code(): " <<
                                        typeid(PureType).hash_code() << 
                                        std::endl;
                        std::cout <<    "validArgumentsList[" << 
                                        argIndex << 
                                        "].ArgTypeHash: " <<
                                        validArgumentsList.at(argIndex).DataType <<
                                        std::endl;
                    }
                    return false;
                }
            }
            
            if(INTERNAL_CO_LOG_CheckArguments)
            {
                std::cout << "Line: " << __LINE__ << std::endl;
                std::cout << "CheckArgumentsTypes index: " << argIndex << " passed" << std::endl;
            }
            
            return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
        }
    };
}

#endif
