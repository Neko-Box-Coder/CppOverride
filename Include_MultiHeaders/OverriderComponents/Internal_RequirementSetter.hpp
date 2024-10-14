#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP

#include "../OverrideInfoSetterDeclaration.hpp"
#include "../Internal_OverrideData.hpp"
#include "../Internal_DataInfo.hpp"
#include "../StaticAssertFalse.hpp"
#include "../Any.hpp"
#include "../PureType.hpp"

#include <cassert>
#include <unordered_map>
#include <iostream>
#include <type_traits>
#include <memory>

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
            
            template<   typename T, 
                        typename... Args, 
                        typename = typename std::enable_if<std::is_same<INTERNAL_CO_PURE_TYPE(T), 
                                                                        void>::value>::type,
                        typename PureType = INTERNAL_CO_PURE_TYPE(T)>
            inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                        T arg, 
                                                        Args... args)
            {
                Internal_DataInfo argData;
                //T is void*
                argData.Data = std::shared_ptr<void>(   new void*((void*)arg), 
                                                        [](void* p){ delete static_cast<char*>(p); });
                argData.DataType = typeid(void*).hash_code();
                argData.DataSet = true;

                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] .back()
                                                                            .ConditionInfo
                                                                            .ArgsCondition
                                                                            .push_back(argData);

                return WhenCalledWith(infoSetter, args...);
            }
            
            template<   typename T, 
                        typename... Args, 
                        typename = typename std::enable_if<!std::is_same<INTERNAL_CO_PURE_TYPE(T), 
                                                                        void>::value>::type>
            inline OverrideInfoSetter& WhenCalledWith(  OverrideInfoSetter& infoSetter,
                                                        T arg, 
                                                        Args... args)
            {
                Internal_DataInfo argData;
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
                                                                            .ConditionInfo
                                                                            .ArgsCondition
                                                                            .push_back(argData);

                return WhenCalledWith(infoSetter, args...);
            }
            
            inline OverrideInfoSetter& 
            If( OverrideInfoSetter& infoSetter, 
                std::function<bool(void* instance, const std::vector<void*>& args)> condition)
            {
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .ConditionInfo
                                    .LambdaCondition = condition;
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .ConditionInfo
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
                                    .ResultActionInfo
                                    .OtherwiseAction = action;
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .ResultActionInfo
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
                                    .ResultActionInfo
                                    .CorrectAction = action;
                CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()] 
                                    .back()
                                    .ResultActionInfo
                                    .CorrectActionSet = true;
                return infoSetter;
            }
            
            inline OverrideInfoSetter& AssignResult(OverrideInfoSetter& infoSetter, 
                                                    std::shared_ptr<OverrideResult> result)
            {
                Internal_OverrideData& currentData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                currentData.Result = result;
                return infoSetter;
            }
        
            inline OverrideInfoSetter& OverrideObject(  OverrideInfoSetter& infoSetter, 
                                                        void* instance)
            {
                Internal_OverrideData& currentData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                
                currentData.Instance = instance;
                return infoSetter;
            }
        
        public:
            Internal_RequirementSetter(OverrideDatas& overrideDataLists) :
                CurrentOverrideDatas(overrideDataLists)
            {}
    };
}

#endif
