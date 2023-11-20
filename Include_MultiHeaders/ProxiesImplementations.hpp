#ifndef SO_PROXIES_IMPLEMENTATIONS_HPP
#define SO_PROXIES_IMPLEMENTATIONS_HPP

#include "./SimpleOverrideInstance.hpp"
#include "./ProxiesDeclarations.hpp"

namespace SimpleOverride
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
        return SimpleOverrideObj.Times(*this, times);
    }

    template<typename DeriveType>
    template<typename... Args>
    inline DeriveType& CommonProxy<DeriveType>::WhenCalledWith(Args... args)
    {
        return SimpleOverrideObj.WhenCalledWith(*this, args...);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::If(std::function<bool(const std::vector<void*>& args)> condition)
    {
        return SimpleOverrideObj.If(*this, condition);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::Otherwise_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return SimpleOverrideObj.Otherwise_Do(*this, action);
    }

    template<typename DeriveType>
    inline DeriveType& 
        CommonProxy<DeriveType>::WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return SimpleOverrideObj.WhenCalledExpectedly_Do(*this, action);
    }

    template<typename ReturnType>
    inline ReturnProxy& ReturnProxy::ReturnsByAction(std::function<void(const std::vector<void*>& args, 
                                                                        void* out)> returnAction)
    {
        return SimpleOverrideObj.ReturnsByAction<ReturnType>(*this, returnAction);
    }

    template<typename ReturnType>
    inline ReturnProxy& ReturnProxy::Returns(ReturnType returnData)
    {
        return SimpleOverrideObj.Returns(*this, returnData);
    }
    
    template<typename ReturnType>
    ReturnProxy& ReturnProxy::ReturnsReference(ReturnType& returnData)
    {
        return SimpleOverrideObj.ReturnsReference(*this, returnData);
    }

    template<typename... Args>
    inline ArgumentsProxy& ArgumentsProxy::SetArgs(Args... args)
    {
        return SimpleOverrideObj.SetArgs(*this, args...);
    }
    
    #ifndef SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL
    #define SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(...) \
        template<__VA_ARGS__>\
        inline ArgumentsProxy&\
        ArgumentsProxy::SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)\
        {\
            return SimpleOverrideObj.SetArgsByAction<
    #endif
    
    #ifndef SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2
    #define SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(...) \
            __VA_ARGS__>(*this, setArgsAction);\
        }
    #endif

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type)
    
    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(typename Arg1Type, typename Arg2Type, typename Arg3Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type)
    
    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type)
    
    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)
    
    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type, 
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type,
                                                typename Arg7Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type, typename Arg15Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type, Arg15Type)

    SO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(  typename Arg1Type, typename Arg2Type, typename Arg3Type,
                                                typename Arg4Type, typename Arg5Type, typename Arg6Type, 
                                                typename Arg7Type, typename Arg8Type, typename Arg9Type,
                                                typename Arg10Type, typename Arg11Type, typename Arg12Type,
                                                typename Arg13Type, typename Arg14Type, typename Arg15Type,
                                                typename Arg16Type)
    SO_INTERNA_PROXYL_SET_ARGS_BY_ACTION_IMPL_2(Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type, 
                                                Arg6Type, Arg7Type, Arg8Type, Arg9Type, Arg10Type,
                                                Arg11Type, Arg12Type, Arg13Type, Arg14Type, Arg15Type,
                                                Arg16Type)
}

#endif