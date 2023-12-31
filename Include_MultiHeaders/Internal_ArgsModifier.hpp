#ifndef CO_INTERNAL_ARGS_MODIFIER_HPP
#define CO_INTERNAL_ARGS_MODIFIER_HPP

#include "./Internal_DataInfo.hpp"
#include "./PureType.hpp"
#include "./Any.hpp"
#include "./Internal_ArgsDataActionInfo.hpp"
#include "./OverrideStatus.hpp"

#include <cassert>
#include <vector>
#include <iostream>
#include <type_traits>

namespace CppOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #define CO_LOG_ModifyArgs 0
        
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index,
                                    OverrideStatus* status) {}

            template<   typename T, 
                        typename = typename std::enable_if<!std::is_copy_assignable<T>::value>::type,
                        typename... Args
                        >
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    //NOTE: Cannot modify data that are not copy assignable
                    if(status != nullptr)
                        *status = OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR;
                    
                    return;
                }
                
                ModifyArgs(argumentsList, argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<std::is_copy_assignable<T>::value>::type,
                        typename... Args,
                        typename = void()>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    INTERNAL_CO_NON_CONST_T& pureArg = const_cast<INTERNAL_CO_NON_CONST_T&>(arg); 
                    pureArg = *static_cast<INTERNAL_CO_NON_CONST_T*>(argsData[index].Data);
                    #if CO_LOG_ModifyArgs
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

                ModifyArgs(argumentsList, argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T*& arg, 
                                    Args&... args)
            {
                ModifyArgs(argumentsList, argsData, index, status, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const T& arg, 
                                    Args&... args)
            {
                #if CO_LOG_ModifyArgs
                    std::cout << "modified index: "<<index << std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    std::cout << "arg value: "<< arg << std::endl;
                    std::cout << std::endl;
                #endif
                
                if(argsData[index].DataSet)
                {
                    //NOTE: Data cannot be set for const arguments
                    if(status != nullptr)
                        *status = OverrideStatus::MODIFY_CONST_ARG_ERROR;
                    
                    return;
                }

                ModifyArgs(argumentsList, argsData, ++index, status, args...);
            }

            template<typename... Args>
            inline void ModifyArgs( std::vector<void*>& argumentsList, 
                                    std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const Any& arg, 
                                    Args&... args)
            {
                #if CO_LOG_ModifyArgs
                    std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
                #endif
                ModifyArgs(argumentsList, argsData, ++index, status, args...);
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