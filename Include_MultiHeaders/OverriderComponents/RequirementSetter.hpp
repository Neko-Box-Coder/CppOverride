#ifndef CO_OVERRIDER_COMPONENTS_REQUIREMENT_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_REQUIREMENT_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../OverrideData.hpp"
#include "../DataInfo.hpp"
#include "../Any.hpp"
#include "../PureType.hpp"

#include <cassert>
#include <unordered_map>
#include <iostream>
#include <type_traits>
#include <memory>

namespace CppOverride
{
    struct RequirementSetter
    {
        using OverrideDatas = std::unordered_map<std::string, std::vector<OverrideData>>;
        OverrideDatas& CurrentOverrideDatas;
    
        //------------------------------------------------------------------------------
        //Methods for setting requirements
        //------------------------------------------------------------------------------
        inline OverrideInfoSetter& Times(OverrideInfoSetter& infoSetter, int times)
        {
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                        .CurrentConditionInfo
                                                                        .Times = times;
            return infoSetter;
        }
        
        inline OverrideInfoSetter& WhenCalledWith(OverrideInfoSetter& infoSetter)
        {
            return infoSetter;
        }
        
        template
        <
            typename T, 
            typename... Args, 
            typename std::enable_if<std::is_same<   INTERNAL_CO_PURE_TYPE(T), void>::value, 
                                                    bool>::type = true,
            typename PureType = INTERNAL_CO_PURE_TYPE(T)
        >
        inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                    T arg, 
                                                    Args... args)
        {
            DataInfo argData;
            //T is void*
            argData.Data = std::shared_ptr<void>(   new void*((void*)arg), 
                                                    [](void* p){ delete static_cast<char*>(p); });
            argData.DataType = typeid(void*).hash_code();
            argData.DataSet = true;

            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                        .CurrentConditionInfo
                                                                        .ArgsCondition
                                                                        .push_back(argData);

            return WhenCalledWith(infoSetter, args...);
        }
        
        template
        <
            typename T, 
            typename... Args, 
            typename std::enable_if<!std::is_same<  INTERNAL_CO_PURE_TYPE(T), 
                                                    void>::value, bool>::type = true
        >
        inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                    T arg, 
                                                    Args... args)
        {
            DataInfo argData;
            //Other types that are not Any
            if(!std::is_same<INTERNAL_CO_RAW_TYPE(T), Any>())
            {
                argData.Data = std::shared_ptr<void>(   new T(arg), 
                                                        [](void* p){ delete static_cast<T*>(p); });
                argData.DataType = typeid(INTERNAL_CO_RAW_TYPE(T)).hash_code();
                argData.DataSet = true;
                
                #if 0
                    std::cout << "typeid(T).name(): " << typeid(T).name() <<"\n";
                    std::cout << "typeid(T).hash_code(): " << typeid(T).hash_code() << "\n";
                #endif
            }

            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                        .CurrentConditionInfo
                                                                        .ArgsCondition
                                                                        .push_back(argData);

            return WhenCalledWith(infoSetter, args...);
        }
        
        //TODO: Enforce type for arguments
        inline OverrideInfoSetter& 
        If( OverrideInfoSetter& infoSetter, 
            std::function<bool(void* instance, const std::vector<void*>& args)> condition)
        {
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentConditionInfo
                                .LambdaCondition = condition;
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentConditionInfo
                                .DataConditionSet = true;
            return infoSetter;
        }
        
        inline OverrideInfoSetter& 
        Otherwise_Do(   OverrideInfoSetter& infoSetter, 
                        std::function<void( void* instance, 
                                            const std::vector<void*>& args)> action)
        {
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentResultActionInfo
                                .OtherwiseAction = action;
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentResultActionInfo
                                .OtherwiseActionSet = true;
            return infoSetter;
        }
        
        inline OverrideInfoSetter& 
        WhenCalledExpectedly_Do(OverrideInfoSetter& infoSetter, 
                                std::function<void( void* instance, 
                                                    const std::vector<void*>& args)> action)
        {
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentResultActionInfo
                                .CorrectAction = action;
            CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                .back()
                                .CurrentResultActionInfo
                                .CorrectActionSet = true;
            return infoSetter;
        }
        
        inline OverrideInfoSetter& AssignResult(OverrideInfoSetter& infoSetter, 
                                                std::shared_ptr<OverrideResult> result)
        {
            OverrideData& currentData = 
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
            
            currentData.Result = result;
            return infoSetter;
        }
    
        inline OverrideInfoSetter& OverrideObject(  OverrideInfoSetter& infoSetter, 
                                                    void* instance)
        {
            OverrideData& currentData = 
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
            
            currentData.Instance = instance;
            return infoSetter;
        }
    
        RequirementSetter(OverrideDatas& overrideDataLists) :
            CurrentOverrideDatas(overrideDataLists)
        {}
    };
}

#endif
