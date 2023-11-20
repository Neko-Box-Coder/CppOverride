#ifndef SO_INTERNAL_REQUIREMENT_SETTER_HPP
#define SO_INTERNAL_REQUIREMENT_SETTER_HPP

#include "./ProxiesDeclarations.hpp"
#include "./Internal_OverrideArgsDataList.hpp"
#include "./Internal_OverrideReturnDataList.hpp"
#include "./StaticAssertFalse.hpp"
#include "./Any.hpp"
#include "./PureType.hpp"

#include <cassert>
#include <unordered_map>
#include <iostream>


namespace SimpleOverride
{
    class Internal_RequirementSetter
    {
        friend class CommonProxy<ReturnProxy>;
        friend class CommonProxy<ArgumentsProxy>;

        protected:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;
            using ArgumentInfosType = std::unordered_map<std::string, Internal_OverrideArgsDataList>;
            
            ArgumentInfosType& OverrideArgumentsInfos;
            ReturnInfosType& OverrideReturnInfos;
        
            //------------------------------------------------------------------------------
            //Methods for setting requirements
            //------------------------------------------------------------------------------
            template<typename DeriveType>
            inline DeriveType& Times(CommonProxy<DeriveType>& proxy, int times)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas.back()
                            .ReturnConditionInfo
                            .Times = times;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas.back()
                            .ArgumentsConditionInfo
                            .Times = times;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy)
            {
                return *static_cast<DeriveType*>(&proxy);
            }

            template<typename DeriveType, typename T, typename... Args>
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

                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back()
                            .ReturnConditionInfo.ArgsCondition.push_back(curArg);
                        break;
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back()
                            .ArgumentsConditionInfo.ArgsCondition.push_back(curArg);
                        break;
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }

                return WhenCalledWith(proxy, args...);
            }
            
            template<typename DeriveType>
            inline DeriveType& If(  CommonProxy<DeriveType>& proxy, 
                                    std::function<bool(const std::vector<void*>& args)> condition)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnConditionInfo
                            .DataCondition = condition;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnConditionInfo
                            .DataConditionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsConditionInfo
                            .DataCondition = condition;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsConditionInfo
                            .DataConditionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
            
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& Otherwise_Do(CommonProxy<DeriveType>& proxy, 
                                            std::function<void(const std::vector<void*>& args)> action)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .OtherwiseAction = action;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .OtherwiseActionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .OtherwiseAction = action;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .OtherwiseActionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
                }
                
                return *static_cast<DeriveType*>(&proxy);
            }
            
            template<typename DeriveType>
            inline DeriveType& 
                WhenCalledExpectedly_Do(CommonProxy<DeriveType>& proxy, 
                                        std::function<void(const std::vector<void*>& args)> action)
            {
                switch(proxy.FunctionProxyType)
                {
                    case ProxyType::RETURN:
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .CorrectAction = action;
                        
                        OverrideReturnInfos[proxy.FunctionSignatureName]
                            .ReturnDatas
                            .back()
                            .ReturnActionInfo
                            .CorrectActionSet = true;
                        
                        break;
                    
                    case ProxyType::ARGS:
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .CorrectAction = action;
                        
                        OverrideArgumentsInfos[proxy.FunctionSignatureName]
                            .ArgumentsDatas
                            .back()
                            .ArgumentsActionInfo
                            .CorrectActionSet = true;
                        
                        break;
                    
                    case ProxyType::COMMON:
                        std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                        assert(false);
                        exit(1);
                        break;
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