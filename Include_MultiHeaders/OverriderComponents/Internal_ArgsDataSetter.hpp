#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGUMENT_DATA_SETTER_HPP

//#include "./ProxiesDeclarations.hpp"
#include "./OverrideInfoSetterDeclaration.hpp"
#include "./Any.hpp"
#include "./StaticAssertFalse.hpp"
#include "./PureType.hpp"
#include "./Internal_OverrideData.hpp"
#include "../../External/MacroPowerToys/MacroPowerToy.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ArgsDataSetter
    {
        friend class OverrideInfoSetter;
        
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            inline OverrideInfoSetter& SetArgs(OverrideInfoSetter& infoSetter)
            {
                return infoSetter;
            }
            
            #define CO_LOG_SetArgs 0
            
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
                        typename =  typename std::enable_if<!std::is_copy_assignable<T>::value>::type,
                        typename... Args>
            inline OverrideInfoSetter& SetArgs( OverrideInfoSetter& infoSetter,
                                                T arg, Args&... args)
            {
                static_assert(  CO_ASSERT_FALSE<T>::value, 
                                "Cannot modify a non copy assignable object. "
                                "Please use SetArgsByAction instead.");

                return SetArgs(infoSetter, args...);
            }
            
            template<   typename T, 
                        typename =  typename std::enable_if<std::is_copy_assignable<T>::value>::type,
                        typename... Args>
            inline OverrideInfoSetter& SetArgs( OverrideInfoSetter& infoSetter,
                                                T arg, Args... args)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataInfo.push_back(Internal_DataInfo());
                
                if(!std::is_same<T, Any>())
                {
                    lastData.ArgumentsDataInfo.back().Data = new T(arg);
                    lastData.ArgumentsDataInfo.back().CopyConstructor = 
                        [](void* data) { return new T(*static_cast<T*>(data)); };
                    
                    lastData.ArgumentsDataInfo.back().Destructor = 
                        [](void* data) { delete static_cast<T*>(data); };

                    lastData.ArgumentsDataInfo.back().DataSet = true;
                    lastData.ArgumentsDataInfo.back().DataType = typeid(T).hash_code();

                    if(CO_LOG_SetArgs)
                    {
                        std::cout << "Set args index: "<< 
                            lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                        
                        std::cout << "arg pointer: "<<&arg<<std::endl;
                        std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                        std::cout <<    "typeid(arg).hash_code(): " << 
                                        typeid(arg).hash_code() << 
                                        std::endl;
                        
                        std::cout <<    "Set args value: "<< 
                                        (*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)) << 
                                        std::endl << 
                                        std::endl;
                        
                        std::cout << "Original Data: "<<std::endl;
                        PRINT_BYTES(arg);
                        
                        std::cout << "Copied Data: "<<std::endl;
                        PRINT_BYTES((*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)));
                        std::cout << std::endl;
                    }
                }
                
                return SetArgs(infoSetter, args...);
            }
            
            template<typename Arg1Type>
            inline OverrideInfoSetter& 
            SetArgsByAction(OverrideInfoSetter& infoSetter,
                            std::function<void(std::vector<void*>& args)> setArgsAction)
            {
                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                lastData.ArgumentsDataActionInfo.DataAction = setArgsAction;
                lastData.ArgumentsDataActionInfo.DataActionSet = true;
                lastData.ArgumentsDataActionInfo.DataTypes
                        .push_back(typeid(INTERNAL_CO_PURE_TYPE(Arg1Type)).hash_code());
                
                return infoSetter;
            }
            
            
            #define INTERNAL_CO_COUNT_TO(...) \
                MPT_COMPOSE( MPT_CONCAT, (MPT_COUNT_TO_, MPT_ARGS_COUNT(__VA_ARGS__)) )
            
            #define INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(...) \
                template<MPT_PREPEND_APPEND_ARGS(   typename, \
                                                    /* no append */, \
                                                    INTERNAL_CO_COUNT_TO(__VA_ARGS__) (Arg, Type))> \
                inline OverrideInfoSetter& \
                SetArgsByAction(OverrideInfoSetter& infoSetter, \
                                std::function<void(std::vector<void*>& args)> setArgsAction) \
                { \
                    SetArgsByAction<MPT_COMPOSE \
                                    ( \
                                        MPT_CONCAT, \
                                        ( \
                                            INTERNAL_CO_COUNT_TO(__VA_ARGS__), \
                                            _MINUS_1 \
                                        ) \
                                    ) (Arg, Type)>(infoSetter, setArgsAction); \
                    \
                    Internal_OverrideData& lastData = \
                        CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back(); \
                    \
                    lastData.ArgumentsDataActionInfo \
                            .DataTypes \
                            .push_back( typeid \
                                        ( \
                                            INTERNAL_CO_PURE_TYPE \
                                            ( \
                                                MPT_PREFIX_SUFFIX_ARGS \
                                                ( \
                                                    Arg, \
                                                    Type,\
                                                    MPT_ARGS_COUNT(__VA_ARGS__) \
                                                ) \
                                            ) \
                                        ).hash_code()); \
                    \
                    return infoSetter; \
                }
            
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_2(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_3(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_4(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_5(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_6(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_7(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_8(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_9(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_10(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_11(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_12(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_13(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_14(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_15(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_16(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_17(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_18(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_19(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_20(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_21(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_22(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_23(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_24(_, _));
            INTERNAL_CO_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_25(_, _));
            
        public:
            inline Internal_ArgsDataSetter(OverrideDatas& overrideArgumentsInfos) : 
                CurrentOverrideDatas(overrideArgumentsInfos)
            {}
    };
}


#endif