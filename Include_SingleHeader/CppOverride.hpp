//=================================================================
//../Include_MultiHeaders/CppOverride.hpp
//=================================================================
#ifndef CO_CPP_OVERRIDE_HPP
#define CO_CPP_OVERRIDE_HPP


//=================================================================
//../Include_MultiHeaders/./CppOverrideInstance.hpp
//=================================================================
#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

//=================================================================
//../Include_MultiHeaders/././Internal_OverrideReturnDataList.hpp
//=================================================================
#ifndef CO_INTERNAL_OVERRIDE_RETURN_DATA_LIST_HPP
#define CO_INTERNAL_OVERRIDE_RETURN_DATA_LIST_HPP

#include <vector>
//=================================================================
//../Include_MultiHeaders/./././Internal_OverrideReturnData.hpp
//=================================================================
#ifndef CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP
#define CO_INTERNAL_OVERRIDE_RETURN_DATA_HPP

//=================================================================
//../Include_MultiHeaders/././././Internal_ConditionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_CONDITION_INFO_HPP
#define CO_INTERNAL_CONDITION_INFO_HPP

//=================================================================
//../Include_MultiHeaders/./././././ArgsInfo.hpp
//=================================================================
#ifndef CO_ARGS_INFO_HPP
#define CO_ARGS_INFO_HPP

#include <cstddef>
#include <functional>

namespace CppOverride
{
    struct ArgInfo
    {
        void* ArgDataPointer = nullptr;
        std::function<void*(void* data)> CopyConstructor;
        std::function<void(void* data)> Destructor;
        size_t ArgSize = 0;
        size_t ArgTypeHash = 0;
        bool ArgSet = false;
    };
}

#endif


#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ConditionInfo
    {
        std::function<bool(const std::vector<void*>& args)> DataCondition;
        std::vector<ArgInfo> ArgsCondition = {};
        int Times = -1;
        int CalledTimes = 0;
        bool DataConditionSet = false;
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././././Internal_ReturnDataInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_RETURN_DATA_INFO_HPP
#define CO_INTERNAL_RETURN_DATA_INFO_HPP

//=================================================================
//../Include_MultiHeaders/./././././Internal_DataInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_DATA_INFO_HPP
#define CO_INTERNAL_DATA_INFO_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_DataInfo
    {
        std::size_t DataType = 0;
        void* Data = nullptr;
        std::function<void*(void*)> CopyConstructor;
        std::function<void(void*)> Destructor;
        bool DataSet = false;
    };
}

#endif


namespace CppOverride
{
    struct Internal_ReturnDataInfo : public Internal_DataInfo
    {
        std::function<void(const std::vector<void*>& args, void* out)> DataAction;
        bool DataActionSet = false;
    };
}


#endif

//=================================================================
//../Include_MultiHeaders/././././Internal_ActionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_ACTION_INFO_HPP
#define CO_INTERNAL_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ActionInfo
    {
        std::function<void(const std::vector<void*>& args)> OtherwiseAction;
        std::function<void(const std::vector<void*>& args)> CorrectAction;
        bool OtherwiseActionSet = false;
        bool CorrectActionSet = false;
    };
}

#endif


namespace CppOverride
{
    struct Internal_OverrideReturnData
    {
        Internal_ConditionInfo ReturnConditionInfo;
        Internal_ReturnDataInfo ReturnDataInfo;
        Internal_ActionInfo ReturnActionInfo;
    };
}

#endif


namespace CppOverride
{
    struct Internal_OverrideReturnDataList
    {
        std::vector<Internal_OverrideReturnData> ReturnDatas = {};
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_OverrideArgsData.hpp
//=================================================================
#ifndef CO_INTERNAL_OVERRIDE_ARGS_DATA_HPP
#define CO_INTERNAL_OVERRIDE_ARGS_DATA_HPP

//=================================================================
//../Include_MultiHeaders/./././Internal_ArgsDataActionInfo.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP
#define CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ArgsDataActionInfo
    {
        std::function<void(std::vector<void*>& args)> DataAction;
        std::vector<std::size_t> DataTypes;
        bool DataActionSet = false;
    };
}


#endif



namespace CppOverride
{
    struct Internal_OverrideArgsData
    {
        Internal_ConditionInfo ArgumentsConditionInfo;
        std::vector<Internal_DataInfo> ArgumentsDataInfo;
        Internal_ArgsDataActionInfo  ArgumentsDataActionInfo;
        Internal_ActionInfo ArgumentsActionInfo;
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././ProxiesDeclarations.hpp
//=================================================================
#ifndef CO_PROXIES_DECLARATIONS_HPP
#define CO_PROXIES_DECLARATIONS_HPP

//=================================================================
//../Include_MultiHeaders/./././ProxyType.hpp
//=================================================================
#ifndef CO_PROXY_TYPE_HPP
#define CO_PROXY_TYPE_HPP

namespace CppOverride
{
    enum class ProxyType
    {
        COMMON,
        RETURN,
        ARGS
    };
}

#endif


#include <functional>
#include <string>
#include <vector>

namespace CppOverride
{
    class Overrider;
    
    //Common proxy class for method chaining
    template<typename DeriveType>
    class CommonProxy
    {
        friend class Overrider;
        friend class Internal_ReturnDataSetter;
        friend class Internal_ArgsDataSetter;
        friend class Internal_RequirementSetter;
        
        protected:
            std::string FunctionSignatureName;
            Overrider& CppOverrideObj;
            const ProxyType FunctionProxyType;

        public:
            CommonProxy(std::string functionSignatureName, 
                        Overrider& SimpleOverrideObj, 
                        ProxyType functionProxyType) :  FunctionSignatureName(functionSignatureName),
                                                        CppOverrideObj(SimpleOverrideObj),
                                                        FunctionProxyType(functionProxyType)
            {}

            DeriveType& Times(int times);
            
            template<typename... Args>
            DeriveType& WhenCalledWith(Args... args);
            
            DeriveType& If(std::function<bool(const std::vector<void*>& args)> condition);

            DeriveType& Otherwise_Do(std::function<void(const std::vector<void*>& args)> action);

            DeriveType& WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action);
    };

    //Override return proxy class for method chaining
    class ReturnProxy : public CommonProxy<ReturnProxy>
    {
        public:
            ReturnProxy(std::string functionSignatureName, 
                        Overrider& SimpleOverrideObj, 
                        ProxyType functionProxyType) : CommonProxy( functionSignatureName, 
                                                                    SimpleOverrideObj, 
                                                                    functionProxyType) 
            {}
            
            template<typename ReturnType>
            ReturnProxy& ReturnsByAction(std::function<void(const std::vector<void*>& args, 
                                                            void* out)> returnAction);
            
            template<typename ReturnType>
            ReturnProxy& Returns(ReturnType returnData);
            
            template<typename ReturnType>
            ReturnProxy& ReturnsReference(ReturnType& returnData);
    };

    //Override arguments proxy class for method chaining
    class ArgumentsProxy : public CommonProxy<ArgumentsProxy>
    {
        public:
            ArgumentsProxy( std::string functionSignatureName, 
                            Overrider& SimpleOverrideObj, 
                            ProxyType functionProxyType) :  CommonProxy(functionSignatureName, 
                                                            SimpleOverrideObj, 
                                                            functionProxyType) 
            {}
            
            template<typename... Args>
            ArgumentsProxy& SetArgs(Args... args);
            
            #ifndef CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL
            #define CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(...) \
                template<__VA_ARGS__>\
                ArgumentsProxy& SetArgsByAction(std::function<void( std::vector<void*>& args)> setArgsAction);
            #endif

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(typename Arg1Type)
            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(typename Arg1Type, typename Arg2Type)
            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type)
            
            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type,
                                                        typename Arg15Type)

            CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type,
                                                        typename Arg15Type, typename Arg16Type)
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Any.hpp
//=================================================================
#ifndef CO_ANY_HPP
#define CO_ANY_HPP

#include <ostream>

namespace CppOverride
{
    struct Any
    {
        inline bool operator== (Any& other)
        {
            return true;
        }
        
        inline bool operator!= (Any& other)
        {
            return false;
        }

        friend std::ostream& operator<<(std::ostream& os, const Any& other)
        {
            os << "Any";
            return os;
        }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ReturnDataSetter.hpp
//=================================================================
#ifndef CO_INTERNAL_RETURN_DATA_SETTER_HPP
#define CO_INTERNAL_RETURN_DATA_SETTER_HPP

//=================================================================
//../Include_MultiHeaders/./././StaticAssertFalse.hpp
//=================================================================
#ifndef CO_STATIC_ASSERT_FALSE
#define CO_STATIC_ASSERT_FALSE

#include <type_traits>

namespace CppOverride
{
    template<typename T>
    struct CO_ASSERT_FALSE : std::false_type { };
}

#endif


#include <iostream>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ReturnDataSetter
    {
        friend class ReturnProxy;
    
        public:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;
        
        protected:
            ReturnInfosType& OverrideReturnInfos;
            
            //------------------------------------------------------------------------------
            //Methods for setting return data
            //------------------------------------------------------------------------------
            template<typename T>
            inline ReturnProxy& ReturnsByAction(ReturnProxy& proxy, 
                                                std::function<void( const std::vector<void*>& args, 
                                                                    void* out)> returnAction)
            {
                static_assert(  !std::is_same<T, Any>(), "You can't return nothing in return action");

                Internal_OverrideReturnData& lastData = 
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();

                lastData.ReturnDataInfo.DataAction = returnAction;
                lastData.ReturnDataInfo.DataActionSet = true;
                lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
                return proxy;
            }
            
            template<typename T>
            inline ReturnProxy& Returns(ReturnProxy& proxy, T returnData)
            {
                if(!std::is_same<T, Any>())
                {
                    Internal_OverrideReturnData& lastData = 
                        OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();
                    
                    lastData.ReturnDataInfo.Data = new T(returnData);
                    lastData.ReturnDataInfo.CopyConstructor = 
                        [](void* data) { return new T(*static_cast<T*>(data)); };
                    
                    lastData.ReturnDataInfo.Destructor = 
                        [](void* data) { delete static_cast<T*>(data); }; 
                    
                    lastData.ReturnDataInfo.DataSet = true;
                    lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
                }
                
                return proxy;
            }
            
            template<typename T>
            inline ReturnProxy& ReturnsReference(ReturnProxy& proxy, T& returnData)
            {
                return Returns(proxy, &returnData);
            }
            
        public:
            inline Internal_ReturnDataSetter(ReturnInfosType& overrideReturnInfos) : 
                OverrideReturnInfos(overrideReturnInfos)
            {}
    };
}


#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsDataSetter.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGUMENT_DATA_SETTER_HPP
#define CO_INTERNAL_ARGUMENT_DATA_SETTER_HPP

//=================================================================
//../Include_MultiHeaders/./././Internal_OverrideArgsDataList.hpp
//=================================================================
#ifndef CO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP
#define CO_INTERNAL_OVERRIDE_ARGS_DATA_LIST_HPP

#include <vector>

namespace CppOverride
{
    struct Internal_OverrideArgsDataList
    {
        std::vector<Internal_OverrideArgsData> ArgumentsDatas = {};
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/./././PureType.hpp
//=================================================================
#ifndef CO_PURE_TYPE_HPP
#define CO_PURE_TYPE_HPP

#include <type_traits>

namespace CppOverride
{
    #define INTERNAL_CO_UNCONST(targetType) typename std::remove_const<targetType>::type
    #define INTERNAL_CO_NON_CONST_T INTERNAL_CO_UNCONST(T)
    
    #define INTERNAL_CO_UNREF(targetType) typename std::remove_reference<targetType>::type
    
    #define INTERNAL_CO_UNPOINTER(targetType) typename std::remove_pointer<targetType>::type
    
    #define INTERNAL_CO_PURE_TYPE(targetType)\
        INTERNAL_CO_UNCONST(INTERNAL_CO_UNREF(INTERNAL_CO_UNPOINTER(targetType)))
}

#endif


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

//=================================================================
//../Include_MultiHeaders/././Internal_RequirementSetter.hpp
//=================================================================
#ifndef CO_INTERNAL_REQUIREMENT_SETTER_HPP
#define CO_INTERNAL_REQUIREMENT_SETTER_HPP


#include <cassert>
#include <unordered_map>
#include <iostream>


namespace CppOverride
{
    class Internal_RequirementSetter
    {
        friend class CommonProxy<ReturnProxy>;
        friend class CommonProxy<ArgumentsProxy>;

        protected:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;
            using ArgumentInfosType = std::unordered_map<std::string, Internal_OverrideArgsDataList>;
            
            ArgumentInfosType& OverrideArgumentsInfos;
            ReturnInfosType& OverrideReturnInfos;
        
            //------------------------------------------------------------------------------
            //Methods for setting requirements
            //------------------------------------------------------------------------------
            template<typename DeriveType>
            inline DeriveType& Times(CommonProxy<DeriveType>& proxy, int times)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas.back()
                            .ReturnConditionInfo
                            .Times = times;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas.back()
                            .ArgumentsConditionInfo
                            .Times = times;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy)
            {
                return *static_cast<DeriveType*>(&proxy);
            }

            template<typename DeriveType, typename T, typename... Args>
            inline DeriveType& WhenCalledWith(  CommonProxy<DeriveType>& proxy, 
                                                T arg, 
                                                Args... args)
            {
                ArgInfo curArg;
                if(!std::is_same<T, Any>())
                {
                    curArg.ArgDataPointer = new T(arg);
                    curArg.CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
                    curArg.Destructor = [](void* data){ delete static_cast<T*>(data); };
                    curArg.ArgSize = sizeof(T);
                    curArg.ArgTypeHash = typeid(T).hash_code();
                    curArg.ArgSet = true;
                    
                    #if 0
                        std::cout << "typeid(T).name(): "<<typeid(T).name() <<"\n";
                        std::cout << "sizeof(T): " << sizeof(T) << "\n";
                        std::cout << "typeid(T).hash_code(): " << typeid(T).hash_code() << "\n";
                    #endif
                }

                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back()
                            .ReturnConditionInfo.ArgsCondition.push_back(curArg);
                        break;
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back()
                            .ArgumentsConditionInfo.ArgsCondition.push_back(curArg);
                        break;
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }

                return WhenCalledWith(proxy, args...);
            }
            
            template<typename DeriveType>
            inline DeriveType& If(  CommonProxy<DeriveType>& proxy, 
                                    std::function<bool(const std::vector<void*>& args)> condition)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnConditionInfo
                            .DataCondition = condition;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnConditionInfo
                            .DataConditionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsConditionInfo
                            .DataCondition = condition;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsConditionInfo
                            .DataConditionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
            
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& Otherwise_Do(CommonProxy<DeriveType>& proxy, 
                                            std::function<void(const std::vector<void*>& args)> action)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .OtherwiseAction = action;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .OtherwiseActionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .OtherwiseAction = action;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .OtherwiseActionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
                
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& 
                WhenCalledExpectedly_Do(CommonProxy<DeriveType>& proxy, 
                                        std::function<void(const std::vector<void*>& args)> action)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .CorrectAction = action;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .CorrectActionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .CorrectAction = action;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .CorrectActionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }

                return *static_cast<DeriveType*>(&proxy);
            }
        
        public:
            Internal_RequirementSetter( ArgumentInfosType& overrideArgumentsInfos, 
                                        ReturnInfosType& overrideReturnInfos) : 
                                            OverrideArgumentsInfos(overrideArgumentsInfos),
                                            OverrideReturnInfos(overrideReturnInfos)
            {}
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsValuesAppender.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_VALUES_APPENDER_HPP
#define CO_INTERNAL_ARGS_VALUES_APPENDER_HPP

#include <vector>

namespace CppOverride
{
    class Internal_ArgsValuesAppender
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            //Appending arguments from function calls
            inline void AppendArgsValues(std::vector<void*>& argumentsList){};

            template<typename T, typename... Args>
            inline void AppendArgsValues(std::vector<void*>& argumentsList, T& arg, Args&... args)
            {
                argumentsList.push_back((INTERNAL_CO_NON_CONST_T*)&arg);
                AppendArgsValues(argumentsList, args...);
            }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsTypeInfoAppender.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP

#include <vector>
namespace CppOverride
{
    class Internal_ArgsTypeInfoAppender
    {
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline void AppendArgsPureTypeInfo(std::vector<ArgInfo>& argumentsList) {}

            template<typename T, typename... Args>
            inline void AppendArgsPureTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                                T& arg, 
                                                Args&... args)
            {
                ArgInfo curArgInfo;
                if(!std::is_same<T, Any>())
                {
                    curArgInfo.ArgSize = sizeof(INTERNAL_CO_NON_CONST_T);
                    curArgInfo.ArgTypeHash = typeid(INTERNAL_CO_NON_CONST_T).hash_code();
                    curArgInfo.ArgSet = true;
                }

                argumentsList.push_back(curArgInfo);
                AppendArgsPureTypeInfo(argumentsList, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void AppendArgsPureTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                                T* arg, 
                                                Args&... args)
            {
                AppendArgsPureTypeInfo(argumentsList, *arg, args...);
            }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsTypesChecker.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_TYPES_CHECKER_HPP
#define CO_INTERNAL_ARGS_TYPES_CHECKER_HPP

#include <vector>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsTypesChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex) { return true; };

            #define CO_LOG_CheckArguments 0

            //Check Value or reference
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T& arg, 
                                            Args&... args)
            {
                #if CO_LOG_CheckArguments
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize)
                    {
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        return false;
                    }
                }
                
                #if CO_LOG_CheckArguments
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            //Check Pointer or value
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        //typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            T*& arg, 
                                            Args&... args)
            {
                #if CO_LOG_CheckArguments
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) != validArgumentsList[argIndex].ArgSize &&
                        sizeof(INTERNAL_CO_NON_CONST_T) != validArgumentsList[argIndex].ArgSize)
                    {
                        #if CO_LOG_CheckArguments
                            std::cout <<    "sizeof(INTERNAL_CO_NON_CONST_T): " <<
                                            sizeof(INTERNAL_CO_NON_CONST_T) <<
                                            "\n";
                            
                            std::cout << "sizeof(T): "<<sizeof(T)<<"\n";
                            std::cout <<    "validArgumentsList[" << 
                                            argIndex << 
                                            "].ArgSize: " << 
                                            validArgumentsList[argIndex].ArgSize <<
                                            "\n";
                        #endif
                        return false;
                    }

                    if( typeid(INTERNAL_CO_NON_CONST_T*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash &&
                        typeid(INTERNAL_CO_NON_CONST_T).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        #if CO_LOG_CheckArguments
                            std::cout <<    "typeid(INTERNAL_CO_NON_CONST_T).hash_code(): " <<
                                            typeid(INTERNAL_CO_NON_CONST_T).hash_code() << 
                                            "\n";
                            
                            std::cout <<    "validArgumentsList["
                                            <<argIndex << 
                                            "].ArgTypeHash: " <<
                                            validArgumentsList[argIndex].ArgTypeHash <<
                                            "\n";
                        #endif
                        return false;
                    }
                }
                
                #if CO_LOG_CheckArguments
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsTypes index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsTypes(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsTypes(std::vector<ArgInfo>& validArgumentsList, 
                                            int argIndex, 
                                            const T& arg, 
                                            Args&... args)
            {
                return CheckArgumentsTypes( validArgumentsList, 
                                            argIndex, 
                                            const_cast<INTERNAL_CO_NON_CONST_T&>(arg), 
                                            args...);
            }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsValuesChecker.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_VALUES_CHECKER_HPP
#define CO_INTERNAL_ARGS_VALUES_CHECKER_HPP

#include <vector>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsValuesChecker
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex) { return true; };

            #define CO_LOG_CheckArgumentsValues 0

            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                T& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Reference (Which is converted to pointer when checking)
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(&arg != *(INTERNAL_CO_NON_CONST_T**)(validArgumentsList[argIndex].ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else if(arg != *static_cast<INTERNAL_CO_NON_CONST_T*>(validArgumentsList[argIndex].ArgDataPointer))
                        return false;
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        //typename = typename std::enable_if<!std::is_same<T, const void>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                T*& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check Pointer
                    if( sizeof(INTERNAL_CO_NON_CONST_T*) == validArgumentsList[argIndex].ArgSize &&
                        typeid(INTERNAL_CO_NON_CONST_T*).hash_code() == 
                            validArgumentsList[argIndex].ArgTypeHash)
                    {
                        if(arg != *(INTERNAL_CO_NON_CONST_T**)(validArgumentsList[argIndex].ArgDataPointer))
                            return false;
                    }
                    //Check Value
                    else
                        return CheckArgumentsValues(validArgumentsList, argIndex, *arg, args...);
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                void*& arg, 
                                                Args&... args)
            {
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                #endif
                
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList[argIndex].ArgSet)
                {
                    //Check void Pointer
                    if( sizeof(void*) != validArgumentsList[argIndex].ArgSize ||
                        typeid(void*).hash_code() != 
                            validArgumentsList[argIndex].ArgTypeHash ||
                        arg != *(void**)(validArgumentsList[argIndex].ArgDataPointer))
                    {
                        return false;
                    }
                }
                
                #if CO_LOG_CheckArgumentsValues
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                #endif
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, args...);
            }
            
            template<typename T, typename... Args>
            inline bool CheckArgumentsValues(   std::vector<ArgInfo>& validArgumentsList, 
                                                int argIndex, 
                                                const T& arg, 
                                                Args&... args)
            {
                return CheckArgumentsValues(validArgumentsList, 
                                            argIndex, 
                                            const_cast<INTERNAL_CO_NON_CONST_T&>(arg), 
                                            args...);
            }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsModifier.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_MODIFIER_HPP
#define CO_INTERNAL_ARGS_MODIFIER_HPP


#include <cassert>
#include <vector>
#include <iostream>

namespace CppOverride 
{
    class Internal_ArgsModifier
    {
        protected:
            #define CO_LOG_ModifyArgs 0
        
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
                #if CO_LOG_ModifyArgs
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
                #if CO_LOG_ModifyArgs
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

//=================================================================
//../Include_MultiHeaders/././Internal_ReturnDataRetriever.hpp
//=================================================================
#ifndef CO_INTERNAL_RETURN_DATA_RETRIEVER_HPP
#define CO_INTERNAL_RETURN_DATA_RETRIEVER_HPP


#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataRetriever
    {
        public:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;

        protected:
            ReturnInfosType& OverrideReturnInfos;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
        
            #define CO_LOG_GetCorrectReturnDataInfo 0

            template<typename T, typename... Args>
            inline int GetCorrectReturnDataInfo(T& returnRef, std::string functionName, Args&... args)
            {
                if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
                {
                    std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                    assert(false);
                    exit(1);
                }
                
                #if CO_LOG_GetCorrectReturnDataInfo
                    std::cout <<"GetCorrectReturnDataInfo called\n";
                #endif

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_OverrideReturnData>& curReturnDatas = 
                    OverrideReturnInfos[functionName].ReturnDatas;
                
                int returnIndex = -1;
                for(int i = 0; i < curReturnDatas.size(); i++)
                {
                    #if CO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Checking return data["<<i<<"]\n";
                    #endif

                    //Check override return data exist
                    if( curReturnDatas[i].ReturnDataInfo.DataSet ||
                        curReturnDatas[i].ReturnDataInfo.DataActionSet)
                    {
                        //Check return type match
                        if(curReturnDatas[i].ReturnDataInfo.DataType != 
                            typeid(INTERNAL_CO_NON_CONST_T).hash_code())
                        {
                            #if CO_LOG_GetCorrectReturnDataInfo
                                std::cout << "Failed at return type\n";
                            #endif
                            
                            continue;
                        }
                    }
                    else
                        continue;
                    
                    //Check parameter condition types/count match
                    if( !curReturnDatas[i].ReturnConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curReturnDatas[i]   .ReturnConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check parameter\n";
                        #endif
                        continue;
                    }
                    
                    
                    //Check parameter values
                    if( !curReturnDatas[i].ReturnConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curReturnDatas[i]   .ReturnConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check parameter\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    
                    //Check condition lambda
                    if( curReturnDatas[i].ReturnConditionInfo.DataConditionSet && 
                        !curReturnDatas[i].ReturnConditionInfo.DataCondition(argumentsList))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check condition\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curReturnDatas[i].ReturnConditionInfo.Times >= 0 && 
                        curReturnDatas[i].ReturnConditionInfo.CalledTimes >= 
                            curReturnDatas[i].ReturnConditionInfo.Times)
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check times\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);

                        continue;
                    }
                    
                    #if CO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Return data found: "<<i<<"\n";
                    #endif
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        public:
            inline Internal_ReturnDataRetriever(ReturnInfosType& overrideReturnInfos,
                                                Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ArgsTypesChecker& argsTypesChecker,
                                                Internal_ArgsValuesChecker& argsValuesChecker) : 
                OverrideReturnInfos(overrideReturnInfos),
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/././Internal_ArgsDataRetriever.hpp
//=================================================================
#ifndef CO_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_INTERNAL_ARGS_DATA_RETRIEVER_HPP


#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataRetriever
    {
        public:
            using OverrideArgsDataType = std::unordered_map<std::string, Internal_OverrideArgsDataList>;
        
        protected:
            OverrideArgsDataType& OverrideArgsDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
            
            #define CO_LOG_GetCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline int GetCorrectArgumentsDataInfo(std::string functionName, Args&... args)
            {
                if(OverrideArgsDatas.find(functionName) == OverrideArgsDatas.end())
                {
                    std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                    assert(false);
                    exit(1);
                }
                
                #if CO_LOG_GetCorrectArgumentsDataInfo
                    std::cout <<"GetCorrectArgumentsDataInfo called\n";
                #endif
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> deRefArgumentsList;
                ArgsTypeInfoAppender.AppendArgsPureTypeInfo(deRefArgumentsList, args...);
                
                std::vector<Internal_OverrideArgsData>& curArgData = 
                    OverrideArgsDatas[functionName].ArgumentsDatas;
                
                int returnIndex = -1;
                for(int i = 0; i < curArgData.size(); i++)
                {
                    #if CO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Checking arg data["<<i<<"]\n";
                    #endif
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curArgData[i].ArgumentsDataActionInfo.DataActionSet && 
                        curArgData[i].ArgumentsDataActionInfo.DataTypes.size() == 
                            deRefArgumentsList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curArgData[i].ArgumentsDataActionInfo.DataTypes;
                        
                        for(int j = 0; j < argTypeHashes.size(); j++)
                        {
                            if(argTypeHashes.at(j) != deRefArgumentsList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                #if CO_LOG_GetCorrectArgumentsDataInfo
                                    std::cout <<    "argTypeHashes.at(" << j << "): " << 
                                                    argTypeHashes.at(j) << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    deRefArgumentsList[j].ArgTypeHash << std::endl;
                                #endif
                                
                                break;
                            }
                        }
                    }
                    //Check set argument data counts match
                    else if(curArgData[i].ArgumentsDataInfo.size() == deRefArgumentsList.size())
                    {
                        for(int j = 0; j < curArgData[i].ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curArgData[i].ArgumentsDataInfo[j].DataSet;

                            if( overrideArg && 
                                curArgData[i].ArgumentsDataInfo[j].DataType != 
                                    deRefArgumentsList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                break;
                            }
                        }
                    }
                    else
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check set argument data exist\n";
                        #endif
                        continue;
                    }
                    
                    if(argumentTypeFailedIndex >= 0)
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout <<    "Failed at Check set argument data types at index " <<
                                            argumentTypeFailedIndex << std::endl;
                        #endif
                        continue;
                    }
                    
                    //Check parameter condition types/count match
                    if( !curArgData[i].ArgumentsConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curArgData[i]   .ArgumentsConditionInfo
                                                                                .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check parameter type\n";
                        #endif
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curArgData[i].ArgumentsConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curArgData[i]   .ArgumentsConditionInfo
                                                                                .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check parameter value\n";
                        #endif
                        
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curArgData[i].ArgumentsConditionInfo.DataConditionSet && 
                        !curArgData[i].ArgumentsConditionInfo.DataCondition(argumentsList))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check condition\n";
                        #endif
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curArgData[i].ArgumentsConditionInfo.Times >= 0 && 
                        curArgData[i].ArgumentsConditionInfo.CalledTimes >= 
                            curArgData[i].ArgumentsConditionInfo.Times)
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check times\n";
                        #endif
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                        continue;
                    }
                    
                    #if CO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Argument data found: "<<i<<"\n";
                    #endif
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        
        public:
            Internal_ArgsDataRetriever( OverrideArgsDataType& overrideArgumentsInfos,
                                        Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender,
                                        Internal_ArgsTypesChecker& argsTypesChecker,
                                        Internal_ArgsValuesChecker& argsValuesChecker) : 
                                                OverrideArgsDatas(overrideArgumentsInfos),
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif


#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Overrider :   public Internal_ReturnDataSetter, 
                        public Internal_ArgsDataSetter,
                        public Internal_RequirementSetter,
                        public Internal_ArgsValuesAppender,
                        public Internal_ArgsTypeInfoAppender,
                        public Internal_ArgsTypesChecker,
                        public Internal_ArgsValuesChecker,
                        public Internal_ArgsModifier,
                        public Internal_ReturnDataRetriever,
                        public Internal_ArgsDataRetriever
    {
        private:
            std::unordered_map<std::string, Internal_OverrideReturnDataList> OverrideReturnInfos;
            std::unordered_map<std::string, Internal_OverrideArgsDataList> OverrideArgumentsInfos;

        //==============================================================================
        //Public facing methods for overriding returns or arguments
        //==============================================================================
        public:
            inline Overrider(const Overrider& other) :
                Internal_ReturnDataSetter(OverrideReturnInfos),
                Internal_ArgsDataSetter(OverrideArgumentsInfos),
                Internal_RequirementSetter( OverrideArgumentsInfos,
                                            OverrideReturnInfos),
                Internal_ReturnDataRetriever(OverrideReturnInfos, *this, *this, *this),
                Internal_ArgsDataRetriever(OverrideArgumentsInfos, *this, *this, *this, *this)
            {
                *this = other;
            }
            
            inline Overrider& operator=(const Overrider& other)
            {
                if(this == &other)
                    return *this;
            
                OverrideReturnInfos = other.OverrideReturnInfos;
                OverrideArgumentsInfos = other.OverrideArgumentsInfos;
            
                for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                    {
                        Internal_DataInfo& curReturnDataInfo = 
                            it->second.ReturnDatas[i].ReturnDataInfo;
                        
                        if(curReturnDataInfo.DataSet)
                        {
                            curReturnDataInfo.Data = 
                                curReturnDataInfo.CopyConstructor(curReturnDataInfo.Data);
                        }
                        
                        for(int j = 0; j < it   ->second
                                                .ReturnDatas[i]
                                                .ReturnConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgDataInfo = it->second
                                                        .ReturnDatas[i]
                                                        .ReturnConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgDataInfo.ArgSet)
                            {
                                curArgDataInfo.ArgDataPointer = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.ArgDataPointer);
                            }
                        }
                    }
                }
                
                for(auto it = OverrideArgumentsInfos.begin(); it != OverrideArgumentsInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ArgumentsDatas.size(); i++)
                    {
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& curArgDataInfo = it  ->second
                                                                    .ArgumentsDatas[i]
                                                                    .ArgumentsDataInfo[j];
                            
                            if(curArgDataInfo.DataSet)
                            {
                                curArgDataInfo.Data = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.Data);
                            }
                        }
                        
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgDataInfo = it->second
                                                        .ArgumentsDatas[i]
                                                        .ArgumentsConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgDataInfo.ArgSet)
                            {
                                curArgDataInfo.ArgDataPointer = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.ArgDataPointer);
                            }
                        }
                    }
                }
                
                return *this;
            }
                
            inline Overrider() :    Internal_ReturnDataSetter(OverrideReturnInfos),
                                    Internal_ArgsDataSetter(OverrideArgumentsInfos),
                                    Internal_RequirementSetter( OverrideArgumentsInfos,
                                                                OverrideReturnInfos),
                                    Internal_ReturnDataRetriever(   OverrideReturnInfos, 
                                                                    *this, 
                                                                    *this,
                                                                    *this),
                                    Internal_ArgsDataRetriever( OverrideArgumentsInfos, 
                                                                *this, 
                                                                *this, 
                                                                *this,
                                                                *this)
            {}
            
            inline ~Overrider()
            {
                for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                    {
                        //Free return data
                        Internal_DataInfo& curDataInfo = it->second.ReturnDatas[i].ReturnDataInfo;
                        if(curDataInfo.DataSet)
                            curDataInfo.Destructor(curDataInfo.Data);
                        
                        //Free argument condition data
                        for(int j = 0; j < it->second
                                            .ReturnDatas[i]
                                            .ReturnConditionInfo
                                            .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfos = it   ->second
                                                        .ReturnDatas[i]
                                                        .ReturnConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgInfos.ArgSet)
                                curArgInfos.Destructor(curArgInfos.ArgDataPointer);
                        }
                    }
                }
                
                for(auto it = OverrideArgumentsInfos.begin(); it != OverrideArgumentsInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ArgumentsDatas.size(); i++)
                    {
                        //Free set arguments data
                        for(int j = 0; j < it->second.ArgumentsDatas[i].ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& curDataInfo = it ->second
                                                                .ArgumentsDatas[i]
                                                                .ArgumentsDataInfo[j];
                            
                            if(curDataInfo.DataSet)
                                curDataInfo.Destructor(curDataInfo.Data);
                        }
                        
                        //Free argument condition data
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfo = it->second
                                                    .ArgumentsDatas[i]
                                                    .ArgumentsConditionInfo
                                                    .ArgsCondition[j];
                            
                            if(curArgInfo.ArgSet)
                                curArgInfo.Destructor(curArgInfo.ArgDataPointer);
                        }
                    }
                }
            }

            //------------------------------------------------------------------------------
            //Overrding Returns
            //------------------------------------------------------------------------------
            #define CO_LOG_OverrideReturns 0

            inline ReturnProxy Internal_OverrideReturns(std::string functionName)
            {
                #if CO_LOG_OverrideReturns
                    std::cout << "OverrideReturns\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                #endif

                OverrideReturnInfos[functionName].ReturnDatas.push_back(Internal_OverrideReturnData());
                return ReturnProxy(functionName, *this, ProxyType::RETURN);
            }
            
            inline void Internal_ClearOverrideReturns(std::string functionName)
            {
                if(OverrideReturnInfos.find(functionName) != OverrideReturnInfos.end())
                    OverrideReturnInfos.erase(functionName);
            }
            
            inline void ClearAllOverrideReturns()
            {
                OverrideReturnInfos.clear();
            }

            #define CO_LOG_CheckOverrideAndReturn 0

            template<typename T, typename... Args>
            inline bool Internal_CheckOverrideAndReturn(T& returnRef, 
                                                        std::string functionName, 
                                                        Args&... args)
            {
                #if CO_LOG_CheckOverrideAndReturn
                    std::cout << "CheckOverrideAndReturn\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                #endif
                if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
                    return false;
            
                int correctDataIndex = GetCorrectReturnDataInfo(returnRef, functionName, args...);
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                //Called correctly action
                bool returnResult = false;
                if(correctDataIndex != -1)
                {
                    Internal_OverrideReturnData& correctData = 
                        OverrideReturnInfos[functionName].ReturnDatas[correctDataIndex];
                    
                    correctData.ReturnConditionInfo.CalledTimes++;
                    
                    if(correctData.ReturnActionInfo.CorrectActionSet)
                        correctData.ReturnActionInfo.CorrectAction(argumentsList);
                    
                    if(correctData.ReturnDataInfo.DataSet)
                        returnRef = *reinterpret_cast<T*>(correctData.ReturnDataInfo.Data);
                    else if(correctData.ReturnDataInfo.DataActionSet)
                        correctData.ReturnDataInfo.DataAction(argumentsList, &returnRef);

                    returnResult = true;
                }
                
                //Deallocating argumentsList
                //for(int i = 0; i < argumentsList.size(); i++)
                //    argumentsList[i].Destructor(argumentsList[i].ArgData);

                return returnResult;
            }

            //------------------------------------------------------------------------------
            //Overrding Arguments
            //------------------------------------------------------------------------------
            #define CO_LOG_OverrideArgs 0

            inline ArgumentsProxy Internal_OverrideArgs(std::string functionName)
            {
                #if CO_LOG_OverrideArgs
                    std::cout << "OverrideArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                #endif

                OverrideArgumentsInfos[functionName].ArgumentsDatas
                                                    .push_back(Internal_OverrideArgsData());
                
                return ArgumentsProxy(functionName, *this, ProxyType::ARGS);
            }
            
            inline void Internal_ClearOverrideArgs(std::string functionName)
            {
                if(OverrideArgumentsInfos.find(functionName) != OverrideArgumentsInfos.end())
                    OverrideArgumentsInfos.erase(functionName);
            }
            
            inline void ClearAllOverrideArgs()
            {
                OverrideArgumentsInfos.clear();
            }

            #define CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline bool Internal_CheckOverrideAndSetArgs(std::string functionName, Args&... args)
            {
                #if CO_LOG_CheckOverrideAndSetArgs
                    std::cout << "CheckOverrideAndSetArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                #endif
                if(OverrideArgumentsInfos.find(functionName) == OverrideArgumentsInfos.end())
                    return false;
            
                int correctDataIndex = GetCorrectArgumentsDataInfo(functionName, args...);
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                //Called correctly action
                bool returnResult = false;
                if(correctDataIndex != -1)
                {
                    Internal_OverrideArgsData& correctData = 
                        OverrideArgumentsInfos[functionName].ArgumentsDatas[correctDataIndex];
                    
                    correctData.ArgumentsConditionInfo.CalledTimes++;
                    
                    if(correctData.ArgumentsActionInfo.CorrectActionSet)
                        correctData.ArgumentsActionInfo.CorrectAction(argumentsList);

                    if(correctData.ArgumentsDataActionInfo.DataActionSet)
                        ModifyArgs(argumentsList, correctData.ArgumentsDataActionInfo);
                    else
                        ModifyArgs(argumentsList, correctData.ArgumentsDataInfo, 0, args...);
                        
                    returnResult = true;
                }

                //Deallocating argumentsList
                //for(int i = 0; i < argumentsList.size(); i++)
                //    argumentsList[i].Destructor(argumentsList[i].ArgData);

                return returnResult;
            }
    };
}

#endif

//=================================================================
//../Include_MultiHeaders/./ProxiesImplementations.hpp
//=================================================================
#ifndef CO_PROXIES_IMPLEMENTATIONS_HPP
#define CO_PROXIES_IMPLEMENTATIONS_HPP


namespace CppOverride
{
    //==============================================================================
    //Implementation of proxy classes for method chaining
    //==============================================================================

    //NOTE: Can't do using as this will evaluate the DeriveType which contains 
    //      SimpleOverrideCommonProxy which has functions not defined yet.
    //      See https://stackoverflow.com/questions/35428422/crtp-accessing-incomplete-type-members
    //template<typename DeriveType>
    //using CommonProxy = SimpleOverrideCommonProxy<DeriveType>;

    template<typename DeriveType>
    inline DeriveType& CommonProxy<DeriveType>::Times(int times)
    {
        return CppOverrideObj.Times(*this, times);
    }

    template<typename DeriveType>
    template<typename... Args>
    inline DeriveType& CommonProxy<DeriveType>::WhenCalledWith(Args... args)
    {
        return CppOverrideObj.WhenCalledWith(*this, args...);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::If(std::function<bool(const std::vector<void*>& args)> condition)
    {
        return CppOverrideObj.If(*this, condition);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::Otherwise_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.Otherwise_Do(*this, action);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.WhenCalledExpectedly_Do(*this, action);
    }

    template<typename ReturnType>
    inline ReturnProxy& ReturnProxy::ReturnsByAction(std::function<void(const std::vector<void*>& args, 
                                                                        void* out)> returnAction)
    {
        return CppOverrideObj.ReturnsByAction<ReturnType>(*this, returnAction);
    }

    template<typename ReturnType>
    inline ReturnProxy& ReturnProxy::Returns(ReturnType returnData)
    {
        return CppOverrideObj.Returns(*this, returnData);
    }
    
    template<typename ReturnType>
    ReturnProxy& ReturnProxy::ReturnsReference(ReturnType& returnData)
    {
        return CppOverrideObj.ReturnsReference(*this, returnData);
    }

    template<typename... Args>
    inline ArgumentsProxy& ArgumentsProxy::SetArgs(Args... args)
    {
        return CppOverrideObj.SetArgs(*this, args...);
    }
    
    #ifndef CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL
    #define CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(...) \
        template<__VA_ARGS__>\
        inline ArgumentsProxy&\
        ArgumentsProxy::SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)\
        {\
            return CppOverrideObj.SetArgsByAction<
    #endif
    
    #ifndef CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2
    #define CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(...) \
            __VA_ARGS__>(*this, setArgsAction);\
        }
    #endif

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type)
    
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type)
    
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type)
    
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)
    
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type, typename Arg15Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type, Arg15Type)

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type, typename Arg15Type,
                                                typename Arg16Type)
    CO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type, Arg15Type,
                                                Arg16Type)
}

#endif

//=================================================================
//../Include_MultiHeaders/./Macros.hpp
//=================================================================
#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP

#include <set>
#include <string>
namespace CppOverride
{
    inline std::string Internal_RemoveNewlines(std::string functionSig)
    {
        std::set<int> newlinesToRemove;
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '\n':
                case '\r':
                    newlinesToRemove.insert(i);
                    break;
                default:
                    break;
            }
        }

        for(auto it = newlinesToRemove.rbegin(); it != newlinesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_RemoveSpaces(std::string functionSig)
    {
        //Remove any consecutive spaces
        std::set<int> spacesToRemove;
        bool isLastSpace = false;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(isLastSpace)
            {
                if(functionSig[i] == ' ')
                    spacesToRemove.insert(i);
                else
                    isLastSpace = false;
            }
            else if(functionSig[i] == ' ')
                isLastSpace = true;
        }
        
        //Remove spaces around parentheses and commas
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '(':
                case ')':
                case ',':
                case '*':
                case '&':
                case ':':
                case '<':
                case '>':
                    if(i > 0 && functionSig[i - 1] == ' ')
                        spacesToRemove.insert(i - 1);
                    
                    if(i < functionSig.size() - 1 && functionSig[i + 1] == ' ')
                        spacesToRemove.insert(i + 1);
                    break;
                default:
                    break;
            }
        }
        
        for(auto it = spacesToRemove.rbegin(); it != spacesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_Trim(std::string functionSig)
    {
        //Trimming
        int firstCharIndex = -1;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(functionSig[i] != ' ')
            {
                firstCharIndex = i;
                break;
            }
        }
        
        int lastCharIndex = -1;
        for(int i = functionSig.size() - 1; i >= 0; i--)
        {
            if(functionSig[i] != ' ')
            {
                lastCharIndex = i;
                break;
            }
        }
        
        return functionSig.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
    }
    
    //==============================================================================
    //Macros and functions for translating function signature to string
    //==============================================================================
    inline std::string Internal_ProcessFunctionSig(std::string functionSig)
    {
        functionSig = Internal_RemoveNewlines(functionSig);
        functionSig = Internal_Trim(functionSig);
        functionSig = Internal_RemoveSpaces(functionSig);
        return functionSig;
    }

    //==============================================================================
    //Macro argument expandsion
    //==============================================================================

    #define CO_INTERNAL_APPEND_ARGS_NOT_EMPTY(...) , __VA_ARGS__
    #define CO_INTERNAL_APPEND_ARGS_EMPTY(...)

    //NOTE: Up to 20 arguments
    #define CO_INTERNAL_EXPAND_IF_EMPTY() ,,,,,,,,,,,,,,,,,,,,
    #define CO_INTERNAL_ESCAPE_BRACKET(...) __VA_ARGS__ ()
    #define CO_INTERNAL_TEST_EMPTY(...)\
        CO_INTERNAL_CAT_ALLOW_GARBAGE(  CO_INTERNAL_EXPAND_IF_EMPTY, \
                                        CO_INTERNAL_ESCAPE_BRACKET __VA_ARGS__ ())
    
    #define CO_INTERNAL_SELECT_TAG( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                                    _15, _16, _17, _18, _19, _20, _21, _TAG, ...) _TAG
    
    #define CO_INTERNAL_CAT_ALLOW_GARBAGE(a, b, ...) a b
    #define CO_INTERNAL_CAT(a, b) a b
    #define CO_INTERNAL_FUNC_CAT(a, b) a ## b

    #define CO_INTERNAL_GET_TAG(...)\
        CO_INTERNAL_CAT(    CO_INTERNAL_SELECT_TAG, \
                            (CO_INTERNAL_TEST_EMPTY(__VA_ARGS__), \
                            _EMPTY, \
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY) )

    //Debug
    //#define CO_INTERNAL_GET_TAG(...) CO_INTERNAL_CAT( CO_INTERNAL_SELECT_TAG, ( CO_INTERNAL_EXPAND_IF_EMPTY __VA_ARGS__ (), _0,
    //                                                    _20, _19, _18, _17, _16, _15, _14, _13, _12, _11,
    //                                                    _10, _9, _8, _7, _6, _5, _4, _3, _2, _1) )

    //MSVC workaround: https://stackoverflow.com/questions/48710758/how-to-fix-variadic-macro-related-issues-with-macro-overloading-in-msvc-mic

    #ifndef _MSC_VER
        #define CO_INTERNAL_APPEND_ARGS(...)\
            CO_INTERNAL_CAT( CO_INTERNAL_FUNC_CAT,\
                            (CO_INTERNAL_APPEND_ARGS, CO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) )
    #else
        #define CO_INTERNAL_VA_ARGS_FIX( macro, args ) macro args
        #define CO_INTERNAL_APPEND_ARGS(...)\
            CO_INTERNAL_VA_ARGS_FIX(    CO_INTERNAL_CAT, \
                                        ( CO_INTERNAL_FUNC_CAT, (CO_INTERNAL_APPEND_ARGS,\
                                        CO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) ) )
    #endif

    #define CO_INTERNAL_STR(x) #x

    #define CO_INTERNAL_FUNC_SIG(functionSig) \
        CppOverride::Internal_ProcessFunctionSig(CO_INTERNAL_STR(functionSig))

    //==============================================================================
    //Public Macros
    //==============================================================================


    //-------------------------------------------------------
    //Return Modifying Macros for implementations
    //-------------------------------------------------------
    #define CO_RETURN_IF_FOUND(overrideObjName, functionSig, returnType, ...)\
    do\
    {\
        returnType returnVal;\
        if(CO_CHECK_RETURN_OVERRIDE(overrideObjName, returnVal, functionSig, __VA_ARGS__))\
            return returnVal;\
    } while(0)

    #define CO_RETURN_REF_IF_FOUND(overrideObjName, functionSig, returnType, ...)\
    do\
    {\
        INTERNAL_CO_PURE_TYPE(returnType)* returnVal;\
        if(CO_CHECK_RETURN_OVERRIDE(overrideObjName, returnVal, functionSig, __VA_ARGS__))\
            return *returnVal;\
    } while(0)

    #define CO_CHECK_RETURN_OVERRIDE(overrideObjName, returnRef, functionSig, ...)\
        overrideObjName.Internal_CheckOverrideAndReturn(returnRef, \
            CO_INTERNAL_FUNC_SIG(functionSig)\
            CO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )

    //-------------------------------------------------------
    //Returns Overriding Macros
    //-------------------------------------------------------

    #define CO_OVERRIDE_RETURNS(overrideObjName, functionSig) \
        overrideObjName.Internal_OverrideReturns(CO_INTERNAL_FUNC_SIG(functionSig))
    
    #define CO_CLEAR_OVERRIDE_RETURNS(overrideObjName, functionSig)\
        overrideObjName.Internal_ClearOverrideReturns(CO_INTERNAL_FUNC_SIG(functionSig))

    #define CO_CLEAR_ALL_OVERRIDE_RETURNS(overrideObjName) \
        overrideObjName.ClearAllOverrideReturns()

    //-------------------------------------------------------
    //Argument Modifying Macros for implementations
    //-------------------------------------------------------

    #define CO_MODIFY_ARGS_IF_FOUND(overrideObjName, functionSig, ...)\
        CO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, __VA_ARGS__)
            
    #define CO_MODIFY_ARGS_AND_RETURN_IF_FOUND(overrideObjName, returnValue, functionSig, ...)\
    do\
    {\
        if(CO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, __VA_ARGS__))\
            return returnValue;\
    } while(0)

    #define CO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, ...)\
            overrideObjName.Internal_CheckOverrideAndSetArgs(   CO_INTERNAL_FUNC_SIG(functionSig)\
                                                                CO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )


    //-------------------------------------------------------
    //Argumetns Overriding Macros
    //-------------------------------------------------------

    #define CO_OVERRIDE_ARGS(overrideObjName, functionSig)\
        overrideObjName.Internal_OverrideArgs(CO_INTERNAL_FUNC_SIG(functionSig))

    #define CO_CLEAR_OVERRIDE_ARGS(overrideObjName, functionSig)\
        overrideObjName.Internal_ClearOverrideArgs(CO_INTERNAL_FUNC_SIG(functionSig))

    #define CO_CLEAR_ALL_OVERRIDE_ARGS(overrideObjName)\
        overrideObjName.ClearAllOverrideArgs()

    //-------------------------------------------------------
    //Delacration Macros
    //-------------------------------------------------------
    #define CO_DECLARE_MEMBER_INSTNACE(OverrideObjName) mutable CppOverride::Overrider OverrideObjName
    #define CO_DECLARE_INSTNACE(OverrideObjName) CppOverride::Overrider OverrideObjName
            
    #define CO_DECLARE_OVERRIDE_METHODS(OverrideObjName)\
    inline CppOverride::ArgumentsProxy Internal_OverrideArgs(std::string functionName)\
    {\
        return OverrideObjName.Internal_OverrideArgs(functionName);\
    }\
    inline void Internal_ClearOverrideArgs(std::string functionName)\
    {\
        OverrideObjName.Internal_ClearOverrideArgs(functionName);\
    }\
    inline void ClearAllOverrideArgs()\
    {\
        OverrideObjName.ClearAllOverrideArgs();\
    }\
    inline CppOverride::ReturnProxy Internal_OverrideReturns(std::string functionName)\
    {\
        return OverrideObjName.Internal_OverrideReturns(functionName);\
    }\
    inline void Internal_ClearOverrideReturns(std::string functionName)\
    {\
        OverrideObjName.Internal_ClearOverrideReturns(functionName);\
    }\
    inline void ClearAllOverrideReturns()\
    {\
        OverrideObjName.ClearAllOverrideReturns();\
    }\
    inline CppOverride::Overrider* GetOverrideObject()\
    {\
        return &OverrideObjName;\
    }
    
    //#if 1
    #ifdef CO_NO_OVERRIDE
        #undef CO_RETURN_IF_FOUND
        #undef CO_CHECK_RETURN_OVERRIDE
        #undef CO_OVERRIDE_RETURNS
        #undef CO_CLEAR_OVERRIDE_RETURNS
        #undef CO_MODIFY_ARGS_IF_FOUND
        #undef CO_MODIFY_ARGS_AND_RETURN_IF_FOUND
        #undef CO_CHECK_ARGS_OVERRIDE
        #undef CO_OVERRIDE_ARGS
        #undef CO_CLEAR_OVERRIDE_ARGS
        #undef CO_DECLARE_INSTNACE
        #undef CO_DECLARE_OVERRIDE_METHODS
    
        #define CO_RETURN_IF_FOUND(...)
        #define CO_CHECK_RETURN_OVERRIDE(...) CO_CHECK_RETURN_OVERRIDE
        #define CO_OVERRIDE_RETURNS(...)
        #define CO_CLEAR_OVERRIDE_RETURNS(...)
        #define CO_MODIFY_ARGS_IF_FOUND(...)
        #define CO_MODIFY_ARGS_AND_RETURN_IF_FOUND(...)
        #define CO_CHECK_ARGS_OVERRIDE(...) false
        #define CO_OVERRIDE_ARGS(...)
        #define CO_CLEAR_OVERRIDE_ARGS(...)
        #define CO_DECLARE_INSTNACE(...)
        #define CO_DECLARE_OVERRIDE_METHODS(...)
    #endif
}

#endif

//=================================================================
//../Include_MultiHeaders/./AliasTypes.hpp
//=================================================================
#ifndef CO_ALIAS_TYPES_HPP
#define CO_ALIAS_TYPES_HPP


const CppOverride::Any CO_ANY;
const CppOverride::Any CO_DONT_SET;
const CppOverride::Any CO_DONT_OVERRIDE_RETURN;

#endif


#endif
