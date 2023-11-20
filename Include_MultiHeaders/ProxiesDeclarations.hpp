#ifndef SO_PROXIES_DECLARATIONS_HPP
#define SO_PROXIES_DECLARATIONS_HPP

#include "./ProxyType.hpp"

#include <functional>
#include <string>
#include <vector>

namespace SimpleOverride
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
            Overrider& SimpleOverrideObj;
            const ProxyType FunctionProxyType;

        public:
            CommonProxy(std::string functionSignatureName, 
                        Overrider& SimpleOverrideObj, 
                        ProxyType functionProxyType) :  FunctionSignatureName(functionSignatureName),
                                                        SimpleOverrideObj(SimpleOverrideObj),
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
            
            #ifndef SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL
            #define SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(...) \
                template<__VA_ARGS__>\
                ArgumentsProxy& SetArgsByAction(std::function<void( std::vector<void*>& args)> setArgsAction);
            #endif

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(typename Arg1Type)
            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(typename Arg1Type, typename Arg2Type)
            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type)
            
            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type)

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type);

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type,
                                                        typename Arg15Type);

            SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_DECL(  typename Arg1Type, typename Arg2Type, 
                                                        typename Arg3Type, typename Arg4Type,
                                                        typename Arg5Type, typename Arg6Type,
                                                        typename Arg7Type, typename Arg8Type,
                                                        typename Arg9Type, typename Arg10Type,
                                                        typename Arg11Type, typename Arg12Type,
                                                        typename Arg13Type, typename Arg14Type,
                                                        typename Arg15Type, typename Arg16Type);
    };
}

#endif