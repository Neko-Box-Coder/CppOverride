#ifndef CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP
#define CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP

#include "../External/MacroPowerToys/MacroPowerToys.h"
#include "./OverrideStatus.hpp"
#include "./TemplateTypeSpecifier.hpp"
#include "./OverrideResult.hpp"
#include "./TypedDataInfo.hpp"
#include "./TypedInfo.hpp"

#include <functional>
#include <string>
#include <vector>
#include <memory>

namespace CppOverride
{
    struct Overrider;

    struct OverrideInfoSetter
    {
        std::string FunctionSignatureName;
        Overrider& CppOverrideObj;
        
        inline OverrideInfoSetter(  std::string functionSignatureName, 
                                    Overrider& SimpleOverrideObj) : 
            FunctionSignatureName(functionSignatureName),
            CppOverrideObj(SimpleOverrideObj)
        {}
        
        inline std::string GetFunctionSignatureName() const
        {
            return FunctionSignatureName;
        }
        
        OverrideInfoSetter& Times(int times);
        
        template<typename... Args>
        OverrideInfoSetter& WhenCalledWith(Args... args);
        
        //TODO: Enforce type for arguments
        OverrideInfoSetter& If(std::function<bool(  void* instance, 
                                                    const std::vector<TypedDataInfo>& args)> condition);

        OverrideInfoSetter& 
        Otherwise_Do(std::function<void(void* instance,
                                        std::vector<TypedDataInfo>& args)> action);

        OverrideInfoSetter& 
        WhenCalledExpectedly_Do(std::function<void( void* instance,
                                                    std::vector<TypedDataInfo>& args)> action);
        
        OverrideInfoSetter& AssignsResult(ResultPtr& outResult);
        
        OverrideInfoSetter& MatchesObject(const void* instance);
        
        OverrideInfoSetter& MatchesAny();
        
        template<typename ReturnType>
        OverrideInfoSetter& ReturnsByAction(std::function
                                            <
                                                TypedDataInfo(  void* instance, 
                                                                const std::vector<TypedDataInfo>& args,
                                                                const TypedInfo& returnInfo)
                                            > returnAction);

        template<typename ReturnType>
        OverrideInfoSetter& Returns(typename TypeSpecifier<ReturnType>::Type returnData);
        
        template<typename ReturnType>
        OverrideInfoSetter& Returns();
        
        OverrideInfoSetter& ReturnsVoid();
        
        template<typename... Args>
        OverrideInfoSetter& 
        SetArgs(typename TypeUnwrapper<Args>::Type... args);
        
        template<typename... Args>
        OverrideInfoSetter& 
        SetArgsByAction(std::function<void( void* instance, 
                                            std::vector<TypedDataInfo>& args)> setArgsAction);
    
        OverrideInfoSetter& Expected();
        
        OverrideInfoSetter& ExpectedNotSatisfy();
    };

    //NOTE: Subset of OverrideInfoSetter
    struct OverridePassthroughInfoSetter
    {
        Overrider& CppOverrideObj;
        
        inline OverridePassthroughInfoSetter(Overrider& SimpleOverrideObj) : 
            CppOverrideObj(SimpleOverrideObj)
        {}
        
        OverridePassthroughInfoSetter& Times(int times);
    
        OverridePassthroughInfoSetter& Expected();
        
        OverridePassthroughInfoSetter& ExpectedNotSatisfy();
    };
}

#endif
