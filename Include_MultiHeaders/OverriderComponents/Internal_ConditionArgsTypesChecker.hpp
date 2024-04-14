#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_TYPES_CHECKER_HPP

#include "../Any.hpp"
#include "../ArgsInfo.hpp"
#include "../PureType.hpp"
#include <vector>
#include <iostream>

namespace CppOverride
{
    class Internal_ConditionArgsTypesChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex) { return true; };

            #define INTERNAL_CO_NON_CONST_T INTERNAL_CO_UNCONST(T)

            #define INTERNAL_CO_LOG_CheckArguments 0

            //Check Value or reference
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T& arg, 
                                            Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize)
                    {
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            //Check Pointer or value
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T*& arg, 
                                            Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "sizeof(INTERNAL_CO_NON_CONST_T): " <<
                                            sizeof(INTERNAL_CO_NON_CONST_T) <<
                                            "\n";
                            
                            std::cout << "sizeof(T): "<<sizeof(T)<<"\n";
                            std::cout <<    "validArgumentsList[" << 
                                            argIndex << 
                                            "].ArgSize: " << 
                                            validArgumentsList[argIndex].ArgSize <<
                                            "\n";
                        }
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "typeid(INTERNAL_CO_NON_CONST_T).hash_code(): " <<
                                            typeid(INTERNAL_CO_NON_CONST_T).hash_code() << 
                                            "\n";
                            
                            std::cout <<    "validArgumentsList["
                                            <<argIndex << 
                                            "].ArgTypeHash: " <<
                                            validArgumentsList[argIndex].ArgTypeHash <<
                                            "\n";
                        }
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            const T& arg, 
                                            Args&... args)
            {
                return CheckArgumentsTypes( validArgumentsList, 
                                            argIndex, 
                                            const_cast<INTERNAL_CO_NON_CONST_T&>(arg), 
                                            args...);
            }

        #undef INTERNAL_CO_NON_CONST_T
    };
}

#endif