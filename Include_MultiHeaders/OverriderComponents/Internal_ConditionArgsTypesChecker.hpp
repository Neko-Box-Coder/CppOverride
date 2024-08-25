#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP

#include "../Any.hpp"
#include "../Internal_DataInfo.hpp"
#include "../PureType.hpp"

#include <vector>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    class Internal_ConditionArgsTypesChecker
    {
        friend class Internal_ReturnDataValidator;
        friend class Internal_ArgsDataValidator;
        friend class Internal_RequirementValidator;
        
        protected:
            inline bool CheckArgumentsTypes(std::vector<Internal_DataInfo>&, int) { return true; };

            #define INTERNAL_CO_LOG_CheckArguments 0

            //Check void*
            template<   typename T, 
                        typename PURE_T = INTERNAL_CO_PURE_TYPE(T),
                        typename = typename std::enable_if<std::is_same<PURE_T, void>::value>::type, 
                        typename... Args,
                        typename = void()>
            inline bool CheckArgumentsTypes(std::vector<Internal_DataInfo>& validArgumentsList, 
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
            
            //Check Value or reference
            template<   typename T, 
                        typename RAW_T = INTERNAL_CO_RAW_TYPE(T), 
                        typename = typename std::enable_if<!std::is_pointer<RAW_T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsTypes(std::vector<Internal_DataInfo>& validArgumentsList, 
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
                    if( typeid(RAW_T).hash_code() != 
                            validArgumentsList.at(argIndex).DataType &&
                        typeid(RAW_T&).hash_code() != 
                            validArgumentsList.at(argIndex).DataType &&
                        //NOTE: Reference can be compared as pointer later down the line
                        typeid(RAW_T*).hash_code() != 
                            validArgumentsList.at(argIndex).DataType)
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
            template<   typename T, 
                        typename RAW_T = INTERNAL_CO_RAW_TYPE(T), 
                        typename = typename std::enable_if<std::is_pointer<RAW_T>::value>::type,
                        typename = typename std::enable_if<!std::is_same<INTERNAL_CO_PURE_TYPE(RAW_T), void>::value>::type, 
                        typename PURE_T = INTERNAL_CO_PURE_TYPE(T),
                        typename... Args>
            inline bool CheckArgumentsTypes(std::vector<Internal_DataInfo>& validArgumentsList, 
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
                    if( typeid(RAW_T).hash_code() != validArgumentsList.at(argIndex).DataType &&
                        //Check value type
                        typeid(PURE_T).hash_code() != validArgumentsList.at(argIndex).DataType)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "typeid(RAW_T).hash_code(): " <<
                                            typeid(RAW_T).hash_code() << 
                                            std::endl;
                            std::cout <<    "typeid(PURE_T).hash_code(): " <<
                                            typeid(PURE_T).hash_code() << 
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
