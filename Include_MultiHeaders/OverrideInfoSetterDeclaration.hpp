#ifndef CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP
#define CO_OVERRIDE_INFO_SETTER_DECLARATION_HPP

#include "../External/MacroPowerToys/MacroPowerToy.h"
#include "./OverrideStatus.hpp"
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
            OverrideInfoSetter& Returns(ReturnType returnData);
            
            template<typename... Args>
            OverrideInfoSetter& SetArgs(Args... args);
            
            #ifndef CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL
            #define CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(...) \
                template<__VA_ARGS__>\
                OverrideInfoSetter& \
                SetArgsByAction(std::function<void(std::vector<void*>& args)> setArgsAction)
            #endif
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_1(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_2(Arg, 
                                                                                Type)));

            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_3(Arg, 
                                                                                Type)));

            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_4(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_5(Arg, 
                                                                                Type)));

            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_6(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_7(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_8(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_9(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_10(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_11(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_12(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_13(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_14(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_15(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_16(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_17(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_18(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_19(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_20(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_21(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_22(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_23(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_24(Arg, 
                                                                                Type)));
            
            CO_INTERNAL_INFO_SET_ARGS_BY_ACTION_DECL(MPT_PREPEND_APPEND_ARGS(   typename, 
                                                                                /* no append */, 
                                                                                MPT_COUNT_TO_25(Arg, 
                                                                                Type)));
            
            
            
            
    };


}

#endif