#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../Internal_OverrideData.hpp"

#include "../StaticAssertFalse.hpp"
#include "../Any.hpp"
#include "../PureType.hpp"

#include <cassert>
#include <unordered_map>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    class Internal_RequirementSetter
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
            friend class OverrideInfoSetter;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
        
            //------------------------------------------------------------------------------
            //Methods for setting requirements
            //------------------------------------------------------------------------------
            inline OverrideInfoSetter& Times(OverrideInfoSetter& infoSetter, int times)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .Times = times;
                
                return infoSetter;
            }
            
            inline OverrideInfoSetter& WhenCalledWith(OverrideInfoSetter& infoSetter)
            {
                return infoSetter;
            }

            template<typename T, typename... Args>
            inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                        T arg, 
                                                        Args... args)
            {
                ArgInfo curArg;
                if(!std::is_same<T, Any>())
                {
                    curArg.ArgDataPointer = new T(arg);
                    curArg.CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
                    curArg.Destructor = [](void* data){ delete static_cast<T*>(data); };
                    curArg.ArgSize = sizeof(T);
                    curArg.ArgTypeHash = typeid(T).hash_code();
                    curArg.ArgSet = true;
                    
                    #if 0
                        std::cout << "typeid(T).name(): "<<typeid(T).name() <<"\n";
                        std::cout << "sizeof(T): " << sizeof(T) << "\n";
                        std::cout << "typeid(T).hash_code(): " << typeid(T).hash_code() << "\n";
                    #endif
                }

                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .ArgsCondition
                                                                            .push_back(curArg);

                return WhenCalledWith(infoSetter, args...);
            }
            
            inline OverrideInfoSetter& 
            If( OverrideInfoSetter& infoSetter, 
                std::function<bool(const std::vector<void*>& args)> condition)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .LambdaCondition = condition;
                        
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .DataConditionSet = true;

                return infoSetter;
            }
            
            inline OverrideInfoSetter& 
            Otherwise_Do(   OverrideInfoSetter& infoSetter, 
                            std::function<void(const std::vector<void*>& args)> action)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .OtherwiseAction = action;
                    
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .OtherwiseActionSet = true;
                
                return infoSetter;
            }
            
            inline OverrideInfoSetter& 
            WhenCalledExpectedly_Do(OverrideInfoSetter& infoSetter, 
                                    std::function<void(const std::vector<void*>& args)> action)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .CorrectAction = action;
                
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ResultActionInfo
                                                                            .CorrectActionSet = true;

                return infoSetter;
            }
            
            inline OverrideInfoSetter& AssignOverrideResult(OverrideInfoSetter& infoSetter, 
                                                            OverrideResult& result)
            {
                Internal_OverrideData& currentData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                currentData.ReturnStatus = &result.ReturnStatus;
                currentData.SetArgsStatus = &result.SetArgsStatus;
                return infoSetter;
            }
            
        
        public:
            Internal_RequirementSetter(OverrideDatas& overrideDataLists) :
                CurrentOverrideDatas(overrideDataLists)
            {}
    };
}

#endif