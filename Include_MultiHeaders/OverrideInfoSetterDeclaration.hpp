#ifndef CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP
#define CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP

#include "../External/MacroPowerToys/MacroPowerToys.h"
#include "./OverrideStatus.hpp"
#include "./TemplateTypeSpecifier.hpp"
#include "./OverrideResult.hpp"

#include <functional>
#include <string>
#include <vector>
#include <memory>

namespace CppOverride
{
    class Overrider;

    class OverrideInfoSetter
    {
        protected:
            std::string FunctionSignatureName;
            Overrider& CppOverrideObj;
        
        public:
            OverrideInfoSetter( std::string functionSignatureName, 
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
                                                        const std::vector<void*>& args)> condition);

            OverrideInfoSetter& 
            Otherwise_Do(std::function<void(void* instance,
                                            const std::vector<void*>& args)> action);

            OverrideInfoSetter& 
            WhenCalledExpectedly_Do(std::function<void( void* instance,
                                                        const std::vector<void*>& args)> action);
            
            OverrideInfoSetter& AssignResult(ResultPtr result);
            OverrideInfoSetter& AssignsResult(ResultPtr result);
            
            ResultPtr ReturnResult();
            ResultPtr ReturnsResult();
            
            OverrideInfoSetter& OverrideObject(const void* instance);
            OverrideInfoSetter& OverridesObject(const void* instance);
            
            OverrideInfoSetter& OverrideAny();
            
            template<typename ReturnType>
            OverrideInfoSetter& ReturnsByAction(std::function<void( void* instance,
                                                                    const std::vector<void*>& args, 
                                                                    void* out)> returnAction);
    
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
                                                std::vector<void*>& args)> setArgsAction);
    };


}

#endif
