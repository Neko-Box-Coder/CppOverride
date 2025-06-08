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
        return CppOverrideObj.CurrentRequirementSetter.Times(*this, times);
    }

    template<typename... Args>
    inline OverrideInfoSetter& OverrideInfoSetter::WhenCalledWith(Args... args)
    {
        return CppOverrideObj.CurrentRequirementSetter.WhenCalledWith(*this, args...);
    }

    //TODO: Enforce type for arguments
    inline OverrideInfoSetter& 
    OverrideInfoSetter::If(std::function<bool(  void* instance, 
                                                const std::vector<void*>& args)> condition)
    {
        return CppOverrideObj.CurrentRequirementSetter.If(*this, condition);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::Otherwise_Do(std::function<void(void* instance,
                                                        const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.CurrentRequirementSetter.Otherwise_Do(*this, action);
    }

    inline OverrideInfoSetter& 
    OverrideInfoSetter::
    WhenCalledExpectedly_Do(std::function<void( void* instance,
                                                const std::vector<void*>& args)> action)
    {
        return CppOverrideObj.CurrentRequirementSetter.WhenCalledExpectedly_Do(*this, action);
    }

    inline OverrideInfoSetter& OverrideInfoSetter::AssignsResult(ResultPtr& outResult)
    {
        return CppOverrideObj.CurrentRequirementSetter.AssignsResult(*this, outResult);
    }

    inline OverrideInfoSetter& OverrideInfoSetter::MatchesObject(const void* instance)
    {
        return CppOverrideObj.CurrentRequirementSetter.MatchesObject(*this, (void*)instance);
    }
    
    inline OverrideInfoSetter& OverrideInfoSetter::MatchesAny()
    {
        return CppOverrideObj.CurrentRequirementSetter.MatchesObject(*this, nullptr);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter&
    OverrideInfoSetter::ReturnsByAction(std::function<void( void* instance,
                                                            const std::vector<void*>& args, 
                                                            void* out)> returnAction)
    {
        return CppOverrideObj.CurrentReturnDataSetter.ReturnsByAction<ReturnType>(  *this, 
                                                                                    returnAction);
    }

    template<typename ReturnType>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns(typename TypeSpecifier<ReturnType>::Type returnData)
    {
        static_assert(std::is_same<ReturnType, decltype(returnData)>::value, "");
        return CppOverrideObj.CurrentReturnDataSetter.Returns<ReturnType>(*this, returnData);
    }
    
    template<>
    inline OverrideInfoSetter&
    OverrideInfoSetter::Returns<void>()
    {
        return CppOverrideObj.CurrentReturnDataSetter.ReturnsVoid(*this);
    }
    
    inline OverrideInfoSetter& OverrideInfoSetter::ReturnsVoid()
    {
        return CppOverrideObj.CurrentReturnDataSetter.ReturnsVoid(*this);
    }
    
    template<typename... Args>
    inline OverrideInfoSetter&
    OverrideInfoSetter::SetArgs(typename TypeUnwrapper<Args>::Type... args)
    {
        return CppOverrideObj.CurrentArgsDataSetter.SetArgs<Args...>(*this, args...);
    }
    
    template<typename... Args>
    inline OverrideInfoSetter&
    OverrideInfoSetter::SetArgsByAction(std::function<void( void* instance, 
                                        std::vector<void*>& args)> setArgsAction)
    {
        return CppOverrideObj.CurrentArgsDataSetter.SetArgsByAction<Args...>(*this, setArgsAction);
    }
}

#endif
