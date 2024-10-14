#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_MODIFIER_HPP

#include "../Internal_DataInfo.hpp"
#include "../Any.hpp"
#include "../Internal_ArgsDataActionInfo.hpp"
#include "../OverrideStatus.hpp"
#include "../PureType.hpp"

#include <cassert>
#include <cstdint>
#include <vector>
#include <iostream>

namespace CppOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #if CO_SHOW_OVERRIDE_LOG
                #define INTERNAL_CO_LOG_ModifyArgs 1
            #else
                #define INTERNAL_CO_LOG_ModifyArgs 0
            #endif
        
            inline void ModifyArgs( std::vector<Internal_DataInfo>&, 
                                    int,
                                    OverrideStatus*) {}

            template<   typename T, 
                        typename RawType = INTERNAL_CO_RAW_TYPE(T),
                        typename = typename std::enable_if<!std::is_copy_assignable<RawType>::value>::type,
                        typename... Args>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T&, 
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
                        typename RawType = INTERNAL_CO_RAW_TYPE(T),
                        typename = typename std::enable_if<std::is_copy_assignable<RawType>::value>::type,
                        typename... Args,
                        typename = void()>
            inline void ModifyArgs( std::vector<Internal_DataInfo>& argsData, 
                                    int index, 
                                    OverrideStatus* status,
                                    T& arg, 
                                    Args&... args)
            {
                if(argsData.at(index).DataSet)
                {
                    RawType& pureArg = (RawType&)(arg); 
                    pureArg = *static_cast<RawType*>(argsData.at(index).Data.get());
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
                        
                        std::cout << "modified index: " << index << std::endl;
                        std::cout << "typeid(RawType).name(): " << typeid(RawType).name() << std::endl;
                        std::cout <<    "typeid(RawType).hash_code(): " << 
                                        typeid(RawType).hash_code() <<
                                        std::endl;
                        
                        std::cout <<    "argsData.at(index).DataType: " << 
                                        argsData.at(index).DataType <<
                                        std::endl;
                        
                        //std::cout << "arg value: "<< arg << std::endl;
                        //std::cout <<    "modified value: "<< 
                        //                (*static_cast<T*>(argsData[index].Data)) << 
                        //                std::endl << 
                        //                std::endl;

                        std::cout << "modified value bytes:" << std::endl;
                        
                        PRINT_BYTES(*static_cast<RawType*>(argsData.at(index).Data.get()));
                        std::cout << std::endl;
                    }
                }

                ModifyArgs(argsData, ++index, status, args...);
            }
            
            //If the argument is a pointer type, we can just dereference that and 
            //pass it as reference to a value
            template<   typename T, 
                        typename RawType = INTERNAL_CO_RAW_TYPE(T),
                        typename = typename std::enable_if<!std::is_same<RawType, void>::value>::type, 
                        typename... Args,
                        typename = void(),
                        typename = void()>
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
                    std::cout << "argsData.att(index).DataSet: " << argsData.at(index).DataSet << std::endl;
                    std::cout << std::endl;
                }
                
                if(argsData.at(index).DataSet)
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
                                    const Any&, 
                                    Args&... args)
            {
                if(INTERNAL_CO_LOG_ModifyArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
                }
                
                ModifyArgs(argsData, ++index, status, args...);
            }
            
            inline void ModifyArgs( void* instance,
                                    std::vector<void*>& argumentsList, 
                                    Internal_ArgsDataActionInfo& argsDataAction)
            {
                if(argsDataAction.DataActionSet)
                    argsDataAction.DataAction(instance, argumentsList);
            }
    };
}

#endif
