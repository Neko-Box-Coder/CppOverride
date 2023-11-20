#ifndef CO_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_INTERNAL_ARGUMENT_DATA_SETTER_HPP

#include "./Internal_OverrideArgsDataList.hpp"
#include "./ProxiesDeclarations.hpp"
#include "./Any.hpp"
#include "./StaticAssertFalse.hpp"
#include "./PureType.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ArgsDataSetter
    {
        friend class ArgumentsProxy;
        
        public:
            using ArgumentInfosType = std::unordered_map<std::string, Internal_OverrideArgsDataList>;
        
        protected:
            ArgumentInfosType& OverrideArgumentsInfos;
            
            inline ArgumentsProxy& SetArgs(ArgumentsProxy& proxy)
            {
                return proxy;
            }
            
            #define CO_LOG_SetArgs 0
            
            #if 0 | CO_LOG_SetArgs
                #define PRINT_BYTES(val)\
                do\
                {\
                    for(int byteIdx = 0; byteIdx < sizeof(val); byteIdx++)\
                    {\
                        std::cout<<(int)((uint8_t*)&val)[byteIdx] <<", ";\
                    }\
                    std::cout << std::endl;\
                } while(0)
            #endif
            
            template<typename T, typename... Args>
            inline ArgumentsProxy& SetArgs( ArgumentsProxy& proxy,
                                            T arg, Args... args)
            {
                Internal_OverrideArgsData& lastData = 
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();
                
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

                    #if CO_LOG_SetArgs
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
                    #endif
                }
                
                return SetArgs(proxy, args...);
            }
            
            template<typename Arg1Type>
            inline ArgumentsProxy& 
                SetArgsByAction(ArgumentsProxy& proxy,
                                std::function<void(std::vector<void*>& args)> setArgsAction)
            {
                Internal_OverrideArgsData& lastData = 
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();
                
                lastData.ArgumentsDataActionInfo.DataAction = setArgsAction;
                lastData.ArgumentsDataActionInfo.DataActionSet = true;
                lastData.ArgumentsDataActionInfo.DataTypes
                        .push_back(typeid(INTERNAL_CO_PURE_TYPE(Arg1Type)).hash_code());
                
                return proxy;
            }
            
            #ifndef CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL
            #define CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(...)\
                template<__VA_ARGS__>\
                inline ArgumentsProxy& \
                    SetArgsByAction(ArgumentsProxy& proxy,\
                                    std::function<void(std::vector<void*>& args)> setArgsAction)\
                {\
                    SetArgsByAction<
            #endif
            
            #ifndef CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1
            #define CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(...)\
                                    __VA_ARGS__>(proxy, setArgsAction);\
                Internal_OverrideArgsData& lastData = \
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();\
                lastData.ArgumentsDataActionInfo\
                        .DataTypes\
                        .push_back(typeid(
            #endif
            
            #ifndef CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2
            #define CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(_1)\
                                            INTERNAL_CO_PURE_TYPE(_1)).hash_code());\
                return proxy;\
            }
            #endif
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(Arg1Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg2Type)
        
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(Arg1Type, Arg2Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg3Type)
        
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(Arg1Type, Arg2Type, Arg3Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg4Type)
        
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(Arg1Type, Arg2Type, Arg3Type, Arg4Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg5Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg6Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg7Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type, typename Arg8Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type, Arg7Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg8Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type, Arg7Type, Arg8Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg9Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type, Arg7Type, Arg8Type, Arg9Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg10Type)
            
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg11Type)

            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_1(  Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                    Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                    Arg11Type)
            CO_INTERNAL_SET_ARGS_BY_ACTION_IMPL_2(Arg12Type)

        public:
            inline Internal_ArgsDataSetter(ArgumentInfosType& overrideArgumentsInfos) : 
                OverrideArgumentsInfos(overrideArgumentsInfos)
            {}
    };
}


#endif