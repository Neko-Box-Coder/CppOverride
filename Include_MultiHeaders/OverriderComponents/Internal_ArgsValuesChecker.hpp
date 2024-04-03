#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_CHECKER_HPP

#include "./Any.hpp"
#include "./ArgsInfo.hpp"
#include "./PureType.hpp"
#include "./TypeCheck.hpp"
#include "./OverrideStatus.hpp"

#include <cassert>
#include <type_traits>
#include <vector>
#include <iostream>


namespace CppOverride
{
    class Internal_ArgsValuesChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex,
                                                OverrideStatus& status) { return true; };

            #define CO_LOG_CheckArgumentsValues 0

            template<   typename T, 
                        typename = typename std::enable_if<!InequalExists<T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //NOTE: Cannot check data that doesn't have inequal operator
                    status = OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR;
                    return false;
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<InequalExists<T>::value>::type,
                        typename... Args,
                        typename = void()>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Reference (Which is converted to pointer when checking)
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(&arg != *(INTERNAL_CO_NON_CONST_T**)(validArgumentsList[argIndex].ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else if(arg != *static_cast<INTERNAL_CO_NON_CONST_T*>(validArgumentsList[argIndex].ArgDataPointer))
                        return false;
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type,
                        typename = typename std::enable_if<InequalExists<T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T*& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Pointer
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(arg != *(INTERNAL_CO_NON_CONST_T**)
                                    (validArgumentsList[argIndex].ArgDataPointer))
                        {
                            return false;
                        }
                    }
                    //Check Value
                    else
                    {
                        return CheckArgumentsValues(validArgumentsList, 
                                                    argIndex, 
                                                    status, 
                                                    *arg, 
                                                    args...);
                    }
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                void*& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
                
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check void Pointer
                    if( sizeof(void*) != validArgumentsList[argIndex].ArgSize ||
                        typeid(void*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash ||
                        arg != *(void**)(validArgumentsList[argIndex].ArgDataPointer))
                    {
                        return false;
                    }
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                const T& arg, 
                                                Args&... args)
            {
                return CheckArgumentsValues(validArgumentsList, 
                                            argIndex, 
                                            status,
                                            const_cast<INTERNAL_CO_NON_CONST_T&>(arg), 
                                            args...);
            }
    };
}

#endif