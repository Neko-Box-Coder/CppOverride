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

    template<typename ReturnType, typename ReturnTypeOption>
    inline OverrideInfoSetter& OverrideInfoSetter::Returns(ReturnTypeOption returnData)
    {
        return CppOverrideObj.Returns<ReturnType>(*this, returnData);
    }
    
    inline OverrideInfoSetter& OverrideInfoSetter::ReturnsVoid()
    {
        return CppOverrideObj.ReturnsVoid(*this);
    }

    #ifndef INTERNAL_CO_SET_ARGS_IMPL
        #define INTERNAL_CO_SET_ARGS_IMPL(...) \
            template<MPT_PREFIX_SUFFIX_ARGS(typename Arg,Type,__VA_ARGS__)> \
            OverrideInfoSetter& OverrideInfoSetter::SetArgs \
            ( \
                MPT_APPEND_LISTS_ITEMS \
                ( \
                    MPT_PREFIX_SUFFIX_ARGS \
                    ( \
                        typename TypeSpecifier<Arg,Type>::Type, __VA_ARGS__ \
                    ), \
                    MPT_COMPOSE \
                    ( \
                        MPT_CONCAT, \
                        ( \
                            MPT_COUNT_TO_, \
                            MPT_ARGS_COUNT(__VA_ARGS__) \
                        ) \
                    )(_, /* no suffix */) \
                ) \
            ) \
            { \
                return CppOverrideObj.SetArgs(*this, MPT_PREFIX_SUFFIX_ARGS(_, \
                                                                            /* no suffix */, \
                                                                            __VA_ARGS__)); \
            }

        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_1(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_2(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_3(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_4(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_5(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_6(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_7(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_8(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_9(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_10(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_11(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_12(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_13(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_14(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_15(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_16(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_17(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_18(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_19(/* no prefix */, /* no suffix */))
        INTERNAL_CO_SET_ARGS_IMPL(MPT_COUNT_TO_20(/* no prefix */, /* no suffix */))
    #endif
    
    #undef INTERNAL_CO_SET_ARGS_IMPL
    
    
    //template<typename T, typename... Args>
    //OverrideInfoSetter& OverrideInfoSetter::SetArgs(typename TypeSpecifier<T>::Type arg, Args... args)
    //{
    //    return CppOverrideObj.SetArgs(*this, arg, args...);
    //    //static_assert(CO_ASSERT_FALSE<int>::value, "Please specify argument types");
    //    return *this;
    //}

    //template<typename... Args>
    //inline OverrideInfoSetter& OverrideInfoSetter::SetArgs(Args... args)
    //{
    //    return CppOverrideObj.SetArgs(*this, args...);
    //}
    
    template<typename... Args>
    inline OverrideInfoSetter&
    OverrideInfoSetter::SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)
    {
        return CppOverrideObj.SetArgsByAction<Args...>(*this, setArgsAction);
    }
}

#endif