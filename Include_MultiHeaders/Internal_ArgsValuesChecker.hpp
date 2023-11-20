#ifndef SO_INTERNAL_ARGS_VALUES_CHECKER_HPP
#define SO_INTERNAL_ARGS_VALUES_CHECKER_HPP

#include "./Any.hpp"
#include "./ArgsInfo.hpp"
#include "./PureType.hpp"
#include <vector>
#include <iostream>

namespace SimpleOverride
{
    class Internal_ArgsValuesChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex) { return true; };

            #define SO_LOG_CheckArgumentsValues 0

            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                T& arg, 
                                                Args&... args)
            {
                #if SO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Reference (Which is converted to pointer when checking)
                    if( sizeof(INTERNAL_SO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_SO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(&arg != *(INTERNAL_SO_NON_CONST_T**)(validArgumentsList[argIndex].ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else if(arg != *static_cast<INTERNAL_SO_NON_CONST_T*>(validArgumentsList[argIndex].ArgDataPointer))
                        return false;
                }
                
                #if SO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        //typename = typename std::enable_if<!std::is_same<T, const void>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                T*& arg, 
                                                Args&... args)
            {
                #if SO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Pointer
                    if( sizeof(INTERNAL_SO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_SO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(arg != *(INTERNAL_SO_NON_CONST_T**)(validArgumentsList[argIndex].ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else
                        return CheckArgumentsValues(validArgumentsList, argIndex, *arg, args...);
                }
                
                #if SO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                void*& arg, 
                                                Args&... args)
            {
                #if SO_LOG_CheckArgumentsValues
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
                
                #if SO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                const T& arg, 
                                                Args&... args)
            {
                return CheckArgumentsValues(validArgumentsList, 
                                            argIndex, 
                                            const_cast<INTERNAL_SO_NON_CONST_T&>(arg), 
                                            args...);
            }
    };
}

#endif