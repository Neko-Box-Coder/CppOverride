#ifndef CO_INTERNAL_ARGS_CHECKER_HPP
#define CO_INTERNAL_ARGS_CHECKER_HPP

#include "./Any.hpp"
#include "./Internal_DataInfo.hpp"
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
            inline bool CheckArguments( std::vector<Internal_DataInfo>& validArgumentsList, 
                                        int argIndex) { return true; };

            #define INTERNAL_CO_LOG_CheckArguments 0

            template<typename T, typename... Args>
            inline bool CheckArguments( std::vector<Internal_DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T& arg, 
                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "CheckArguments index: " << argIndex << std::endl;
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                {
                    if(typeid(INTERNAL_CO_UNCONST(T)).hash_code() != 
                            validArgumentsList.at(argIndex).DataType)
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout <<    "typeid(INTERNAL_CO_UNCONST(T)).hash_code(): " <<
                                            typeid(INTERNAL_CO_UNCONST(T)).hash_code() << 
                                            std::endl;
                            
                            std::cout <<    "validArgumentsList["
                                            << argIndex << 
                                            "].ArgTypeHash: " <<
                                            validArgumentsList.at(argIndex).DataType <<
                                            std::endl;
                        }
                        
                        return false;
                    }

                    if(arg != *reinterpret_cast<INTERNAL_CO_UNCONST(T)*>
                                (validArgumentsList.at(argIndex).Data))
                    {
                        if(INTERNAL_CO_LOG_CheckArguments)
                        {
                            std::cout << 
                            "arg != *reinterpret_cast<INTERNAL_CO_UNCONST(T)*>\
                            (validArgumentsList.at(argIndex).Data" << std::endl;
                        }
                        
                        return false;
                    }
                }            
                
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout << "CheckArguments index: " << argIndex << " passed" << std::endl;
                
                return CheckArguments(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename... Args>
            inline bool CheckArguments( std::vector<Internal_DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        Any& arg, 
                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArguments)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "CheckArguments index: " << argIndex << std::endl;
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                    return false;
                
                if(INTERNAL_CO_LOG_CheckArguments)
                    std::cout << "CheckArguments index: " << argIndex << " passed" << std::endl;
                
                return CheckArguments(validArgumentsList, ++argIndex, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline bool CheckArguments( std::vector<Internal_DataInfo>& validArgumentsList, 
                                        int argIndex, 
                                        T*& arg, 
                                        Args&... args)
            {
                return CheckArguments(validArgumentsList, argIndex, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArguments( std::vector<Internal_DataInfo>& validArgumentsList, 
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
