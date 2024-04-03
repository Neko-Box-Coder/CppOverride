#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_REQUIREMENT_SETTER_HPP

#include "./ProxiesDeclarations.hpp"
#include "./Internal_OverrideArgsDataList.hpp"
#include "./Internal_OverrideReturnDataList.hpp"
#include "./StaticAssertFalse.hpp"
#include "./Any.hpp"
#include "./PureType.hpp"

#include <cassert>
#include <unordered_map>
#include <iostream>
#include <type_traits>

namespace CppOverride
{
    class Internal_RequirementSetter
    {
        friend class CommonProxy<ReturnProxy>;
        friend class CommonProxy<ArgumentsProxy>;

        protected:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;
            using ArgumentInfosType = std::unordered_map<std::string, Internal_OverrideDataList>;
            
            ArgumentInfosType& OverrideArgumentsInfos;
            ReturnInfosType& OverrideReturnInfos;
        
            #define CO_INTERNAL_CHECK_IS_DERIVED_TYPE(checkType) \
                typename std::enable_if<std::is_same<checkType, ReturnProxy>::value ||\
                                        std::is_same<checkType, ArgumentsProxy>::value>::type\
            
            //------------------------------------------------------------------------------
            //Methods for setting requirements
            //------------------------------------------------------------------------------
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& Times(CommonProxy<DeriveType>& proxy, int times)
            {
                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back()
                                                                    .ReturnConditionInfo
                                                                    .Times = times;
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas.back()
                                                                        .ArgumentsConditionInfo
                                                                        .Times = times;
                }
                
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy)
            {
                return *static_cast<DeriveType*>(&proxy);
            }

            template<   typename DeriveType, 
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType),
                        typename T, 
                        typename... Args>
            inline DeriveType& WhenCalledWith(  CommonProxy<DeriveType>& proxy, 
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

                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnConditionInfo
                                                                    .ArgsCondition
                                                                    .push_back(curArg);
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsConditionInfo
                                                                        .ArgsCondition
                                                                        .push_back(curArg);
                }

                return WhenCalledWith(proxy, args...);
            }
            
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& If(  CommonProxy<DeriveType>& proxy, 
                                    std::function<bool(const std::vector<void*>& args)> condition)
            {
                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnConditionInfo
                                                                    .DataCondition = condition;
                        
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnConditionInfo
                                                                    .DataConditionSet = true;
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsConditionInfo
                                                                        .DataCondition = condition;
                        
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsConditionInfo
                                                                        .DataConditionSet = true;
                }

                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& Otherwise_Do(CommonProxy<DeriveType>& proxy, 
                                            std::function<void(const std::vector<void*>& args)> action)
            {
                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnActionInfo
                                                                    .OtherwiseAction = action;
                    
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnActionInfo
                                                                    .OtherwiseActionSet = true;
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsActionInfo
                                                                        .OtherwiseAction = action;
                        
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsActionInfo
                                                                        .OtherwiseActionSet = true;
                }

                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& 
                WhenCalledExpectedly_Do(CommonProxy<DeriveType>& proxy, 
                                        std::function<void(const std::vector<void*>& args)> action)
            {
                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnActionInfo
                                                                    .CorrectAction = action;
                    
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .ReturnActionInfo
                                                                    .CorrectActionSet = true;
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsActionInfo
                                                                        .CorrectAction = action;
                    
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .ArgumentsActionInfo
                                                                        .CorrectActionSet = true;
                }

                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<   typename DeriveType,
                        typename = CO_INTERNAL_CHECK_IS_DERIVED_TYPE(DeriveType)>
            inline DeriveType& AssignStatus(CommonProxy<DeriveType>& proxy, 
                                            OverrideStatus& status)
            {
                if(std::is_same<DeriveType, ReturnProxy>::value)
                {
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas
                                                                    .back()
                                                                    .Status = &status;
                }
                else if(std::is_same<DeriveType, ArgumentsProxy>::value)
                {
                    OverrideArgumentsInfos[proxy.FunctionSignatureName] .ArgumentsDatas
                                                                        .back()
                                                                        .Status = &status;
                }

                return *static_cast<DeriveType*>(&proxy);
            }
            
        
        public:
            Internal_RequirementSetter( ArgumentInfosType& overrideArgumentsInfos, 
                                        ReturnInfosType& overrideReturnInfos) : 
                                            OverrideArgumentsInfos(overrideArgumentsInfos),
                                            OverrideReturnInfos(overrideReturnInfos)
            {}
    };
}

#endif