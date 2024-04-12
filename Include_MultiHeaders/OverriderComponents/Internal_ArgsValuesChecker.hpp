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

            #define INTERNAL_CO_LOG_CheckArgumentsValues 0

            template<   typename T, 
                        typename = typename std::enable_if<!InequalExists<T>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //NOTE: Cannot check data that doesn't have inequal operator
                    status = OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR;
                    return false;
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
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
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout << "CheckArgumentsValues index: " << argIndex << std::endl;
                }

                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    const ArgInfo& curArgInfo = validArgumentsList[argIndex];
                    
                    //Check Reference (Which is converted to pointer when checking)
                    if( sizeof(INTERNAL_CO_UNCONST(T)*) == curArgInfo.ArgSize &&
                        typeid(INTERNAL_CO_UNCONST(T)*).hash_code() == curArgInfo.ArgTypeHash)
                    {
                        if( &arg != *(INTERNAL_CO_UNCONST(T)**)(curArgInfo.ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else if(arg != *static_cast<INTERNAL_CO_UNCONST(T)*>(curArgInfo.ArgDataPointer))
                        return false;
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
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
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    const ArgInfo& curArgInfo = validArgumentsList[argIndex];
                    
                    //Check Pointer
                    if( sizeof(INTERNAL_CO_UNCONST(T)*) == curArgInfo.ArgSize &&
                        typeid(INTERNAL_CO_UNCONST(T)*).hash_code() == curArgInfo.ArgTypeHash)
                    {
                        if(arg != *(INTERNAL_CO_UNCONST(T)**)(curArgInfo.ArgDataPointer))
                            return false;
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
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            template<typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                void*& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
                
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
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
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
                                            const_cast<INTERNAL_CO_UNCONST(T)&>(arg), 
                                            args...);
            }
    };
}

#endif