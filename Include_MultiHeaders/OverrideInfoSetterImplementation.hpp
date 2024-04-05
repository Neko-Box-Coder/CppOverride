#ifndef CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP
#define CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP

#include "./CppOverrideInstance.hpp"
#include "./OverrideInfoSetterDeclaration.hpp"
#include "../External/MacroPowerToys/MacroPowerToy.h"

namespace CppOverride 
{
    //==============================================================================
    //Implementation of OverrideInfoSetter classes for method chaining
    //==============================================================================

    inline OverrideInfoSetter& OverrideInfoSetter::Times(int times)
    {
        return CppOverrideObj.Times(*this, times);
    }

    template<typename... Args>
    inline OverrideInfoSetter& OverrideInfoSetter::WhenCalledWith(Args... args)
    {
        return CppOverrideObj.WhenCalledWith(*this, args...);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::If(std::function<bool(const std::vector<void*>& args)> condition)
    {
        return CppOverrideObj.If(*this, condition);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::Otherwise_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.Otherwise_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.WhenCalledExpectedly_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::AssignStatus(OverrideStatus& status)
    {
        return CppOverrideObj.AssignStatus(*this, status);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter& 
    OverrideInfoSetter::ReturnsByAction(std::function<void( const std::vector<void*>& args, 
                                                            void* out)> returnAction)
    {
        return CppOverrideObj.ReturnsByAction<ReturnType>(*this, returnAction);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter& OverrideInfoSetter::Returns(ReturnType returnData)
    {
        return CppOverrideObj.Returns(*this, returnData);
    }
    
    template<typename ReturnType>
    OverrideInfoSetter& OverrideInfoSetter::ReturnsReference(ReturnType& returnData)
    {
        return CppOverrideObj.ReturnsReference(*this, returnData);
    }

    template<typename... Args>
    inline OverrideInfoSetter& OverrideInfoSetter::SetArgs(Args... args)
    {
        return CppOverrideObj.SetArgs(*this, args...);
    }
    
    #ifndef CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL
    #define CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(...) \
        template<MPT_PREPEND_APPEND_ARGS(typename, /* no append */, __VA_ARGS__)>\
        inline OverrideInfoSetter&\
        OverrideInfoSetter::SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)\
        {\
            return CppOverrideObj.SetArgsByAction<__VA_ARGS__>(*this, setArgsAction);\
        }
    #endif

    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_1(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_2(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_3(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_4(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_5(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_6(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_7(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_8(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_9(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_10(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_11(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_12(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_13(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_14(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_15(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_16(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_17(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_18(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_19(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_20(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_21(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_22(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_23(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_24(Arg, Type));
    CO_INTERNAL_PROXY_SET_ARGS_BY_ACTION_IMPL(MPT_COUNT_TO_25(Arg, Type));
    
}

#endif