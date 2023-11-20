#ifndef SO_INTERNAL_ARGS_MODIFIER_HPP
#define SO_INTERNAL_ARGS_MODIFIER_HPP

#include "./Internal_DataInfo.hpp"
#include "./PureType.hpp"
#include "./Any.hpp"
#include "./Internal_ArgsDataActionInfo.hpp"

#include <cassert>
#include <vector>
#include <iostream>

namespace SimpleOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #define SO_LOG_ModifyArgs 0
        
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index) {}

            template<typename T, typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    INTERNAL_SO_NON_CONST_T& pureArg = const_cast<INTERNAL_SO_NON_CONST_T&>(arg); 
                    pureArg = *static_cast<INTERNAL_SO_NON_CONST_T*>(argsData[index].Data);
                    #if SO_LOG_ModifyArgs
                        std::cout << "modified index: "<<index << std::endl;
                        std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                        std::cout <<    "typeid(arg).hash_code(): " << 
                                        typeid(arg).hash_code() <<
                                        std::endl;
                        
                        std::cout <<    "argsData[index].DataType: " << 
                                        argsData[index].DataType <<
                                        std::endl;
                        
                        std::cout << "arg value: "<< arg << std::endl;
                        std::cout <<    "modified value: "<< 
                                        (*static_cast<T*>(argsData[index].Data)) << 
                                        std::endl << 
                                        std::endl;

                        std::cout << "modified value bytes:" << std::endl;
                        
                        PRINT_BYTES((*static_cast<T*>(argsData[index].Data)));
                        std::cout << std::endl;
                    #endif
                }

                ModifyArgs(argumentsList, argsData, ++index, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    T*& arg, 
                                    Args&... args)
            {
                ModifyArgs(argumentsList, argsData, index, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    const T& arg, 
                                    Args&... args)
            {
                #if SO_LOG_ModifyArgs
                    std::cout << "modified index: "<<index << std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    std::cout << "arg value: "<< arg << std::endl;
                    std::cout << std::endl;
                #endif
                
                if(argsData[index].DataSet)
                {
                    std::cout << "[ERROR] Data cannot be set for const arguments" << std::endl;
                    assert(false);
                    exit(1);
                }

                ModifyArgs(argumentsList, argsData, ++index, args...);
            }

            template<typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    const Any& arg, 
                                    Args&... args)
            {
                #if SO_LOG_ModifyArgs
                    std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
                #endif
                ModifyArgs(argumentsList, argsData, ++index, args...);
            }
            
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    Internal_ArgsDataActionInfo& argsDataAction)
            {
                if(argsDataAction.DataActionSet)
                    argsDataAction.DataAction(argumentsList);
            }
    };
}

#endif