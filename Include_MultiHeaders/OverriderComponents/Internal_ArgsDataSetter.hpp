#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../Any.hpp"
#include "../StaticAssertFalse.hpp"
#include "../PureType.hpp"
#include "../Internal_OverrideData.hpp"
#include "../../External/MacroPowerToys/MacroPowerToys.h"
#include "../AliasTypes.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ArgsDataSetter
    {
        friend class OverrideInfoSetter;
        
        #define INTERNAL_CO_UNWRAPPED(arg) typename TypeUnwrapper<arg>::Type
        
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            #define INTERNAL_CO_LOG_SetArgs 0
            
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
            
            template<typename T, typename... Args>
            inline typename std::enable_if
            <
                !std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value && 
                sizeof...(Args) != 0, 
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter,
                    INTERNAL_CO_UNWRAPPED(T) arg, 
                    INTERNAL_CO_UNWRAPPED(Args)... args)
            {
                static_assert(  CO_ASSERT_FALSE<T>::value, 
                                "Cannot modify a non copy assignable object. "
                                "Please use SetArgsByAction instead.");

                return SetArgs<INTERNAL_CO_UNWRAPPED(Args)...>(infoSetter, args...);
            }
            
            template<typename T>
            inline typename std::enable_if
            <
                std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value,
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter, INTERNAL_CO_UNWRAPPED(T) arg)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataInfo.push_back(Internal_DataInfo());
                
                if(!std::is_same<T, Any>())
                {
                    lastData.ArgumentsDataInfo.back().Data = new INTERNAL_CO_UNWRAPPED(T)(arg);
                    lastData.ArgumentsDataInfo.back().CopyConstructor = 
                        [](void* data) 
                        { 
                            return new INTERNAL_CO_UNWRAPPED(T)
                            (
                                *static_cast<INTERNAL_CO_UNWRAPPED(T)*>(data)
                            ); 
                        };
                    
                    lastData.ArgumentsDataInfo.back().Destructor = 
                        [](void* data) { delete static_cast<INTERNAL_CO_UNWRAPPED(T)*>(data); };

                    lastData.ArgumentsDataInfo.back().DataSet = true;
                    lastData.ArgumentsDataInfo.back().DataType = 
                        typeid(T).hash_code();

                    if(INTERNAL_CO_LOG_SetArgs)
                    {
                        std::cout << std::endl << __func__ << " called" << std::endl;
                        
                        std::cout <<    "Set args index: " << 
                                        lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                        
                        std::cout << "arg pointer: " << &arg << std::endl;
                        std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
                        std::cout <<    "typeid(T).hash_code(): " << 
                                        typeid(T).hash_code() << 
                                        std::endl;
                        
                        //std::cout <<    "Set args value: "<< 
                        //                (*static_cast<INTERNAL_CO_UNCONST_UNREF_T*>
                        //                (
                        //                    lastData.ArgumentsDataInfo.back().Data
                        //                )) << 
                        //                std::endl << 
                        //                std::endl;
                        
                        //std::cout << "Original Data: "<<std::endl;
                        //PRINT_BYTES(arg);
                        
                        //std::cout << "Copied Data: "<<std::endl;
                        //PRINT_BYTES((*static_cast<INTERNAL_CO_UNWRAPPED(T)*>
                        //(
                        //    lastData.ArgumentsDataInfo.back().Data
                        //)));
                        
                        std::cout << std::endl;
                    }
                }
                
                return infoSetter;
            }
            
            template<typename T, typename... Args>
            inline typename std::enable_if
            <
                std::is_copy_assignable<INTERNAL_CO_UNWRAPPED(T)>::value &&
                sizeof...(Args) != 0, 
                OverrideInfoSetter&
            >::type
            SetArgs(OverrideInfoSetter& infoSetter,
                    INTERNAL_CO_UNWRAPPED(T) arg, 
                    INTERNAL_CO_UNWRAPPED(Args)... args)
            {
                SetArgs<T>(infoSetter, arg);
                return SetArgs<Args...>(infoSetter, args...);
            }
            
        private:
            template<typename T>
            inline void InternalPushActionArgTypes(Internal_OverrideData& lastData)
            {
                lastData.ArgumentsDataActionInfo.DataTypes
                        .push_back(typeid(T).hash_code());
                
                if(INTERNAL_CO_LOG_SetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout <<    "Data Hash: " << typeid(T).hash_code() << std::endl;
                    std::cout <<    "Data Type: " << typeid(T).name() << std::endl;
                }
                
                if(!std::is_same<T, CO_ANY_TYPE>::value)
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(true);
                else
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(false);
            }
            
            template<typename T, typename... Args>
            inline void PushActionArgTypes(Internal_OverrideData& lastData)
            {
                InternalPushActionArgTypes<T>(lastData);
                PushActionArgTypes<Args...>(lastData);
            }
            
            template<typename... Args>
            inline typename std::enable_if<sizeof...(Args) == 0>::type 
            PushActionArgTypes(Internal_OverrideData& lastData)
            {
            }
        
        protected:
            template<typename... Args>
            inline OverrideInfoSetter& 
            SetArgsByAction(OverrideInfoSetter& infoSetter,
                            std::function<void(std::vector<void*>& args)> setArgsAction)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataActionInfo.DataAction = setArgsAction;
                lastData.ArgumentsDataActionInfo.DataActionSet = true;
                
                PushActionArgTypes<Args...>(lastData);
                
                if(INTERNAL_CO_LOG_SetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout <<    "Target function: " <<
                                    infoSetter.GetFunctionSignatureName() << std::endl;
                    
                    for(int i = 0; i < lastData.ArgumentsDataActionInfo.DataTypes.size(); i++)
                    {
                        std::cout <<    "Data Type[" << i << "]: " << 
                                        lastData.ArgumentsDataActionInfo.DataTypes[i] << std::endl;
                    }
                }
                
                return infoSetter;
            }
            
        #undef INTERNAL_CO_UNCONST_UNREF_T
        #undef INTERNAL_CO_UNCONST_UNREF
        
        public:
            inline Internal_ArgsDataSetter(OverrideDatas& overrideArgumentsInfos) : 
                CurrentOverrideDatas(overrideArgumentsInfos)
            {}
    };
}


#endif