#ifndef CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP
#define CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP

#include "../External/MacroPowerToys/MacroPowerToy.h"
#include "./OverrideStatus.hpp"
#include "./TemplateTypeSpecifier.hpp"

#include <functional>
#include <string>
#include <vector>

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
            
            OverrideInfoSetter& If(std::function<bool(const std::vector<void*>& args)> condition);

            OverrideInfoSetter& 
            Otherwise_Do(std::function<void(const std::vector<void*>& args)> action);

            OverrideInfoSetter& 
            WhenCalledExpectedly_Do(std::function<void(const std::vector<void*>& args)> action);
            
            OverrideInfoSetter& AssignStatus(OverrideStatus& status);
            
            
            template<typename ReturnType>
            OverrideInfoSetter& ReturnsByAction(std::function<void( const std::vector<void*>& args, 
                                                                    void* out)> returnAction);
    
            template<typename ReturnType>
            OverrideInfoSetter& Returns(typename TypeSpecifier<ReturnType>::Type returnData);
            
            OverrideInfoSetter& ReturnsVoid();
            
            #ifndef INTERNAL_CO_SET_ARGS_DECL
                #define INTERNAL_CO_SET_ARGS_DECL(...) \
                    template<MPT_PREFIX_SUFFIX_ARGS(typename Arg, Type, __VA_ARGS__)> \
                    OverrideInfoSetter& SetArgs \
                    ( \
                        MPT_APPEND_LISTS_ITEMS \
                        ( \
                            MPT_PREFIX_SUFFIX_ARGS \
                            ( \
                                typename TypeUnwrapper<Arg, \
                                Type>::Type, \
                                __VA_ARGS__ \
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
                    )
                
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_1(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_2(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_3(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_4(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_5(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_6(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_7(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_8(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_9(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_10(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_11(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_12(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_13(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_14(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_15(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_16(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_17(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_18(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_19(/* no prefix */, /* no suffix */));
                INTERNAL_CO_SET_ARGS_DECL(MPT_COUNT_TO_20(/* no prefix */, /* no suffix */));
            #endif
            
            #undef INTERNAL_CO_SET_ARGS_DECL
            
            template<typename... Args>
            OverrideInfoSetter& 
            SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction);
    };


}

#endif