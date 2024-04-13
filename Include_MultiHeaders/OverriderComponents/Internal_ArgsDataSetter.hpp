#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP

//#include "./ProxiesDeclarations.hpp"
#include "./OverrideInfoSetterDeclaration.hpp"
#include "./Any.hpp"
#include "./StaticAssertFalse.hpp"
#include "./PureType.hpp"
#include "./Internal_OverrideData.hpp"
#include "../../External/MacroPowerToys/MacroPowerToy.h"
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
        
        #define INTERNAL_CO_UNCONST_UNREF_T INTERNAL_CO_UNREF(INTERNAL_CO_UNCONST(T))
        #define INTERNAL_CO_UNCONST_UNREF(arg) INTERNAL_CO_UNREF(INTERNAL_CO_UNCONST(arg))
        
        private:
            template<   typename T,
                        typename std::enable_if
                        <
                            std::is_same<INTERNAL_CO_UNCONST(T), void*>::value ||
                            !std::is_pointer<T>::value, bool
                        >::type = true>
            inline void InternalPushArgTypes(Internal_OverrideData& lastData)
            {
                lastData.ArgumentsDataActionInfo.DataTypes
                        .push_back(typeid(INTERNAL_CO_UNCONST_UNREF_T).hash_code());
                
                if(!std::is_same<T, CO_ANY_TYPE>::value)
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(true);
                else
                    lastData.ArgumentsDataActionInfo.DataTypesSet.push_back(false);
            }
            
            //Unwrap pointer
            template<   typename T,
                        typename std::enable_if
                        <
                            std::is_pointer<T>::value &&
                            !std::is_same<INTERNAL_CO_UNCONST(T), void*>::value, bool
                        >::type = true>
            inline void InternalPushArgTypes(Internal_OverrideData& lastData)
            {
                InternalPushArgTypes<INTERNAL_CO_UNPOINTER(T)>(lastData);
            }
            
            template<typename T, typename... Args>
            inline void PushArgTypes(Internal_OverrideData& lastData)
            {
                InternalPushArgTypes<T>(lastData);
                PushArgTypes<Args...>(lastData);
            }
            
            template<typename... Args>
            inline typename std::enable_if<sizeof...(Args) == 0>::type 
            PushArgTypes(Internal_OverrideData& lastData)
            {
            }
        
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            inline OverrideInfoSetter& SetArgs(OverrideInfoSetter& infoSetter)
            {
                return infoSetter;
            }
            
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
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_copy_assignable<INTERNAL_CO_UNCONST_UNREF_T>::value>::type,
                        typename... Args>
            inline OverrideInfoSetter& SetArgs( OverrideInfoSetter& infoSetter,
                                                INTERNAL_CO_UNCONST_UNREF_T arg, Args&... args)
            {
                static_assert(  CO_ASSERT_FALSE<T>::value, 
                                "Cannot modify a non copy assignable object. "
                                "Please use SetArgsByAction instead.");

                return SetArgs(infoSetter, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<std::is_copy_assignable<INTERNAL_CO_UNCONST_UNREF_T>::value>::type,
                        typename... Args>
            inline OverrideInfoSetter& SetArgs( OverrideInfoSetter& infoSetter,
                                                T arg, 
                                                Args... args)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataInfo.push_back(Internal_DataInfo());
                
                if(!std::is_same<T, Any>())
                {
                    lastData.ArgumentsDataInfo.back().Data = new INTERNAL_CO_UNCONST_UNREF_T(arg);
                    lastData.ArgumentsDataInfo.back().CopyConstructor = 
                        [](void* data) 
                        { 
                            return new INTERNAL_CO_UNCONST_UNREF_T
                            (
                                *static_cast<INTERNAL_CO_UNCONST_UNREF_T*>(data)
                            ); 
                        };
                    
                    lastData.ArgumentsDataInfo.back().Destructor = 
                        [](void* data) { delete static_cast<INTERNAL_CO_UNCONST_UNREF_T*>(data); };

                    lastData.ArgumentsDataInfo.back().DataSet = true;
                    lastData.ArgumentsDataInfo.back().DataType = 
                        typeid(INTERNAL_CO_UNCONST_UNREF_T).hash_code();

                    if(INTERNAL_CO_LOG_SetArgs)
                    {
                        std::cout << "Set args index: "<< 
                            lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                        
                        std::cout << "arg pointer: "<<&arg<<std::endl;
                        std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                        std::cout <<    "typeid(arg).hash_code(): " << 
                                        typeid(arg).hash_code() << 
                                        std::endl;
                        
                        //std::cout <<    "Set args value: "<< 
                        //                (*static_cast<INTERNAL_CO_UNCONST_UNREF_T*>
                        //                (
                        //                    lastData.ArgumentsDataInfo.back().Data
                        //                )) << 
                        //                std::endl << 
                        //                std::endl;
                        
                        std::cout << "Original Data: "<<std::endl;
                        PRINT_BYTES(arg);
                        
                        std::cout << "Copied Data: "<<std::endl;
                        PRINT_BYTES((*static_cast<INTERNAL_CO_UNCONST_UNREF_T*>
                        (
                            lastData.ArgumentsDataInfo.back().Data
                        )));
                        
                        std::cout << std::endl;
                    }
                }
                
                return SetArgs(infoSetter, args...);
            }
            
            //Unwrap pointers
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<INTERNAL_CO_UNCONST_UNREF_T, void*>::value>::type,
                        typename... Args>
            inline OverrideInfoSetter& SetArgs( OverrideInfoSetter& infoSetter,
                                                T* arg, 
                                                Args... args)
            {
                return SetArgs(infoSetter, *arg, args...);
            }
            
            template<typename... Args>
            inline OverrideInfoSetter& 
            SetArgsByAction(OverrideInfoSetter& infoSetter,
                            std::function<void(std::vector<void*>& args)> setArgsAction)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataActionInfo.DataAction = setArgsAction;
                lastData.ArgumentsDataActionInfo.DataActionSet = true;
                
                PushArgTypes<Args...>(lastData);
                
                if(INTERNAL_CO_LOG_SetArgs)
                {
                    std::cout << __func__ << " called" << std::endl;
                    std::cout <<    "Target function: " <<
                                    infoSetter.GetFunctionSignatureName() << std::endl;
                    
                    for(int i = 0; i < lastData.ArgumentsDataActionInfo.DataTypes.size(); i++)
                    {
                        std::cout << "Data Type[" << i << "]: " << 
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