#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP

#include "./Internal_DataInfo.hpp"
#include "./PureType.hpp"
#include "./Any.hpp"
#include "./Internal_ArgsDataActionInfo.hpp"
#include "./OverrideStatus.hpp"

#include <cassert>
#include <cstdint>
#include <vector>
#include <iostream>
#include <type_traits>

namespace CppOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #define INTERNAL_CO_LOG_ModifyArgs 0
        
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index,
                                    OverrideStatus* status) {}

            template<   typename T, 
                        typename = typename std::enable_if<!std::is_copy_assignable<T>::value>::type,
                        typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
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
                
                ModifyArgs(argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<std::is_copy_assignable<T>::value>::type,
                        typename... Args,
                        typename = void()>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData[index].DataSet)
                {
                    INTERNAL_CO_UNCONST(T)& pureArg = const_cast<INTERNAL_CO_UNCONST(T)&>(arg); 
                    pureArg = *static_cast<INTERNAL_CO_UNCONST(T)*>(argsData[index].Data);
                    if(INTERNAL_CO_LOG_ModifyArgs)
                    {
                        std::cout << std::endl << __func__ << " called" << std::endl;
                        std::cout << "&arg: " << &arg << std::endl;
                        
                        #ifndef PRINT_BYTES
                            #define PRINT_BYTES(val) \
                                do \
                                { \
                                    for(int byteIdx = 0; byteIdx < sizeof(val); byteIdx++) \
                                    { \
                                        std::cout<<(int)((uint8_t*)&val)[byteIdx] <<", "; \
                                    } \
                                    std::cout << std::endl; \
                                } while(0)
                        #endif
                        
                        std::cout << "modified index: "<<index << std::endl;
                        std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                        std::cout <<    "typeid(arg).hash_code(): " << 
                                        typeid(arg).hash_code() <<
                                        std::endl;
                        
                        std::cout <<    "argsData[index].DataType: " << 
                                        argsData[index].DataType <<
                                        std::endl;
                        
                        //std::cout << "arg value: "<< arg << std::endl;
                        //std::cout <<    "modified value: "<< 
                        //                (*static_cast<T*>(argsData[index].Data)) << 
                        //                std::endl << 
                        //                std::endl;

                        std::cout << "modified value bytes:" << std::endl;
                        
                        PRINT_BYTES((*static_cast<T*>(argsData[index].Data)));
                        std::cout << std::endl;
                    }
                }

                ModifyArgs(argsData, ++index, status, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T*& arg, 
                                    Args&... args)
            {
                ModifyArgs(argsData, index, status, *arg, args...);
            }
            
            template<typename T, typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const T& arg, 
                                    Args&... args)
            {
                if(INTERNAL_CO_LOG_ModifyArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "modified index: "<<index << std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    //std::cout << "arg value: "<< arg << std::endl;
                    std::cout << "argsData[index].DataSet: " << argsData[index].DataSet << std::endl;
                    std::cout << std::endl;
                }
                
                if(argsData[index].DataSet)
                {
                    //NOTE: Data cannot be set for const arguments
                    if(status != nullptr)
                        *status = OverrideStatus::MODIFY_CONST_ARG_ERROR;
                    
                    return;
                }

                ModifyArgs(argsData, ++index, status, args...);
            }

            template<typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    const Any& arg, 
                                    Args&... args)
            {
                if(INTERNAL_CO_LOG_ModifyArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
                }
                
                ModifyArgs(argsData, ++index, status, args...);
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