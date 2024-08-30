#ifndef CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP
#define CO_OVERRIDE_INFO_SETTER_IMPLEMENTATION_HPP

#include "./CppOverrideInstance.hpp"
#include "./OverrideInfoSetterDeclaration.hpp"
#include "../External/MacroPowerToys/MacroPowerToys.h"

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
    OverrideInfoSetter::If(std::function<bool(  void* instance, 
                                                const std::vector<void*>& args)> condition)
    {
        return CppOverrideObj.If(*this, condition);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::Otherwise_Do(std::function<void(void* instance,
                                                        const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.Otherwise_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::
    WhenCalledExpectedly_Do(std::function<void( void* instance,
                                                const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.WhenCalledExpectedly_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::AssignResult(std::shared_ptr<OverrideResult> result)
    {
        return CppOverrideObj.AssignResult(*this, result);
    }

    inline OverrideInfoSetter& OverrideInfoSetter::OverrideObject(const void* instance)
    {
        return CppOverrideObj.OverrideObject(*this, (void*)instance);
    }

    inline OverrideInfoSetter& OverrideInfoSetter::OverrideAny()
    {
        return CppOverrideObj.OverrideObject(*this, nullptr);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter& 
    OverrideInfoSetter::ReturnsByAction(std::function<void( void* instance,
                                                            const std::vector<void*>& args, 
                                                            void* out)> returnAction)
    {
        return CppOverrideObj.ReturnsByAction<ReturnType>(*this, returnAction);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns(typename TypeSpecifier<ReturnType>::Type returnData)
    {
        static_assert(std::is_same<ReturnType, decltype(returnData)>::value, "");
        return CppOverrideObj.Returns<ReturnType>(*this, returnData);
    }
    
    template<>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns<void>()
    {
        return CppOverrideObj.ReturnsVoid(*this);
    }
    
    inline OverrideInfoSetter& OverrideInfoSetter::ReturnsVoid()
    {
        return CppOverrideObj.ReturnsVoid(*this);
    }
    
    template<typename... Args>
    inline OverrideInfoSetter& 
    OverrideInfoSetter::SetArgs(typename TypeUnwrapper<Args>::Type... args)
    {
        return CppOverrideObj.SetArgs<Args...>(*this, args...);
    }
    
    template<typename... Args>
    inline OverrideInfoSetter&
    OverrideInfoSetter::
    SetArgsByAction(std::function<void( void* instance, 
                                        std::vector<void*>& args)> setArgsAction)
    {
        return CppOverrideObj.SetArgsByAction<Args...>(*this, setArgsAction);
    }
}

#endif
