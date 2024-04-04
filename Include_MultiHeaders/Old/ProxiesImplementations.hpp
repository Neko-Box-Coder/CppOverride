#ifndef CO_PROXIES_IMPLEMENTATIONS_HPP
#define CO_PROXIES_IMPLEMENTATIONS_HPP

#include "./CppOverrideInstance.hpp"
#include "./ProxiesDeclarations.hpp"

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

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::AssignStatus(OverrideStatus& status)
    {
        return CppOverrideObj.AssignStatus(*this, status);
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