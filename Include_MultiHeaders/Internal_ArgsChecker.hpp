#ifndef CO_INTERNAL_ARGS_CHECKER_HPP
#define CO_INTERNAL_ARGS_CHECKER_HPP

#include "./Any.hpp"
#include "./ArgsInfo.hpp"
#include "./PureType.hpp"
#include <vector>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArguments( std::vector<ArgInfo>& validArgumentsList, 
                                        int argIndex) { return true; };

            #define INTERNAL_CO_LOG_CheckArguments 0

            template<typename T, typename... Args>
            inline bool CheckArguments( std::vector<ArgInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T& arg, 
                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout <<"CheckArguments index: "<<argIndex<<"\n";
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if(sizeof(INTERNAL_CO_UNCONST(T)) != validArgumentsList[argIndex].ArgSize)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "sizeof(INTERNAL_CO_UNCONST(T)): " <<
                                            sizeof(INTERNAL_CO_UNCONST(T)) <<
                                            std::endl;
                            
                            std::cout << "sizeof(T): " << sizeof(T) << std::endl;
                            std::cout <<    "validArgumentsList[" << 
                                            argIndex << 
                                            "].ArgSize: " << 
                                            validArgumentsList[argIndex].ArgSize <<
                                            std::endl;
                        }
                        
                        return false;
                    }

                    if(typeid(INTERNAL_CO_UNCONST(T)).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "typeid(INTERNAL_CO_UNCONST(T)).hash_code(): " <<
                                            typeid(INTERNAL_CO_UNCONST(T)).hash_code() << 
                                            std::endl;
                            
                            std::cout <<    "validArgumentsList["
                                            <<argIndex << 
                                            "].ArgTypeHash: " <<
                                            validArgumentsList[argIndex].ArgTypeHash <<
                                            std::endl;
                        }
                        
                        return false;
                    }

                    if(arg != *reinterpret_cast<INTERNAL_CO_UNCONST(T)*>
                                (validArgumentsList[argIndex].ArgDataPointer))
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout << 
                            "arg != *reinterpret_cast<INTERNAL_CO_UNCONST(T)*>\
                            (validArgumentsList[argIndex].ArgData\n";
                        }
                        
                        return false;
                    }
                }            
                
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout << "CheckArguments index: " << argIndex << " passed" << std::endl;
                
                return CheckArguments(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename... Args>
            inline bool CheckArguments( std::vector<ArgInfo>& validArgumentsList, 
                                        int argIndex, 
                                        Any& arg, 
                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout << "CheckArguments index: " << argIndex << std::endl;
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                    return false;
                
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout << "CheckArguments index: " << argIndex << " passed" << std::endl;
                
                return CheckArguments(validArgumentsList, ++argIndex, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline bool CheckArguments( std::vector<ArgInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T*& arg, 
                                        Args&... args)
            {
                return CheckArguments(validArgumentsList, argIndex, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArguments( std::vector<ArgInfo>& validArgumentsList, 
                                        int argIndex, 
                                        const T& arg, 
                                        Args&... args)
            {
                return CheckArguments(  validArgumentsList, 
                                        argIndex, 
                                        const_cast<INTERNAL_CO_UNCONST(T)&>(arg), 
                                        args...);
            }
    };
}

#endif