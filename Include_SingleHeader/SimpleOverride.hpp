#ifndef SO_FUNCTION_OVERRIDES_HPP
#define SO_FUNCTION_OVERRIDES_HPP

#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <typeinfo>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <type_traits>
#include <set>

//==============================================================================
//Main Class
//==============================================================================
class SimpleOverride
{
    public:
        //==============================================================================
        //Public data structures
        //==============================================================================
        enum class ProxyType
        {
            COMMON,
            RETURN,
            ARGS
        };

        struct ArgInfo
        {
            void* ArgData = nullptr;
            std::function<void*(void*)> CopyConstructor;
            std::function<void(void*)> Destructor;
            size_t ArgSize = 0;
            size_t ArgTypeHash = 0;
            bool ArgSet = false;
        };

        struct Any
        {
            inline bool operator== (Any& other)
            {
                return true;
            }
            
            inline bool operator!= (Any& other)
            {
                return false;
            }

            friend std::ostream& operator<<(std::ostream& os, const Any& other)
            {
                os << "Any";
                return os;
            }
        };

        template<typename T>
        struct NonCopyable
        {
            T* ReferenceVar = nullptr;

            NonCopyable(){}
            NonCopyable(T& referenceVar) { ReferenceVar = &referenceVar; }
            
            inline bool operator== (NonCopyable<T>& other)
            {
                return *ReferenceVar == (*other.ReferenceVar);
            }
            
            inline bool operator!= (NonCopyable& other)
            {
                return !operator==(other);
            }

            friend std::ostream& operator<<(std::ostream& os, const NonCopyable& other)
            {
                os << "NonCopyable";
                return os;
            }
        };

        template<typename T>
        struct NonComparable
        {
            T* ReferenceVar = nullptr;

            NonComparable(){}
            NonComparable(T& referenceVar) { ReferenceVar = &referenceVar; }
            
            inline bool operator== (NonComparable<T>& other)
            {
                return true;
            }
            
            inline bool operator!= (NonComparable& other)
            {
                return false;
            }

            friend std::ostream& operator<<(std::ostream& os, const NonComparable& other)
            {
                os << "NonComparable";
                return os;
            }
        };

        template<typename T>
        struct NonComparableCopyable
        {
            T* ReferenceVar = nullptr;

            NonComparableCopyable(){}
            NonComparableCopyable(T& referenceVar) { ReferenceVar = &referenceVar; }
            
            inline bool operator== (NonComparableCopyable<T>& other)
            {
                return true;
            }
            
            inline bool operator!= (NonComparableCopyable& other)
            {
                return false;
            }

            friend std::ostream& operator<<(std::ostream& os, const NonComparableCopyable& other)
            {
                os << "NonComparableCopyable";
                return os;
            }
        };

        //==============================================================================
        //Method Chaining Classes
        //==============================================================================
        //Common proxy class for method chaining
        template<typename DeriveType>
        class CommonProxy
        {
            friend class SimpleOverride;

            protected:
                std::string FunctionSignatureName;
                SimpleOverride& SimpleOverrideObj;
                const ProxyType FunctionProxyType;

            public:
                CommonProxy(std::string functionSignatureName, SimpleOverride& SimpleOverrideObj, ProxyType functionProxyType) :  
                    FunctionSignatureName(functionSignatureName),
                    SimpleOverrideObj(SimpleOverrideObj),
                    FunctionProxyType(functionProxyType)
                {}

                DeriveType& Times(int times);
                
                template<typename... Args>
                DeriveType& WhenCalledWith(Args... args);
                
                DeriveType& If(std::function<bool(std::vector<void*>& args)> condition);

                DeriveType& Otherwise_Do(std::function<void(std::vector<void*>& args)> action);

                DeriveType& WhenCalledExpectedly_Do(std::function<void(std::vector<void*>& args)> action);
        };

        //Override return proxy class for method chaining
        class ReturnProxy : public CommonProxy<ReturnProxy>
        {
            public:
                ReturnProxy(std::string functionSignatureName, SimpleOverride& SimpleOverrideObj, ProxyType functionProxyType) : 
                    CommonProxy(functionSignatureName, SimpleOverrideObj, functionProxyType) 
                {}
                
                template<typename T>
                ReturnProxy& ReturnsByAction(std::function<void(std::vector<void*>& args, void* out)> returnAction);
                
                template<typename T>
                ReturnProxy& Returns(T returnData);
        };

        //Override arguments proxy class for method chaining
        class ArgumentsProxy : public CommonProxy<ArgumentsProxy>
        {
            public:
                ArgumentsProxy(std::string functionSignatureName, SimpleOverride& SimpleOverrideObj, ProxyType functionProxyType) : 
                    CommonProxy(functionSignatureName, SimpleOverrideObj, functionProxyType) 
                {}
                
                template<typename T>
                ArgumentsProxy& SetArgByAction(std::function<void(std::vector<void*>& args, void* out)> setArgsAction);
                
                template<typename... Args>
                ArgumentsProxy& SetArgs(Args... args);
        };

    //==============================================================================
    //Data Structures for storing requirements and datas to be returned or set
    //==============================================================================
    private:
        struct DataInfo
        {
            std::size_t DataType = 0;
            void* Data = nullptr;
            std::function<void*(void*)> CopyConstructor;
            std::function<void(void*)> Destructor;
            std::function<void(std::vector<void*>& args, void* out)> DataAction;
            bool DataSet = false;
            bool DataActionSet = false;
        };

        struct ConditionInfo
        {
            std::function<bool(std::vector<void*>& args)> DataCondition;
            std::vector<ArgInfo> ArgsCondition = {};
            int Times = -1;
            int CalledTimes = 0;
            bool DataConditionSet = false;
        };

        struct ActionInfo
        {
            std::function<void(std::vector<void*>& args)> OtherwiseAction;
            std::function<void(std::vector<void*>&)> CorrectAction;
            bool OtherwiseActionSet = false;
            bool CorrectActionSet = false;
        };
        
        struct ReturnData
        {
            ConditionInfo ReturnConditionInfo;
            DataInfo ReturnDataInfo;
            ActionInfo ReturnActionInfo;
        };

        struct OverrideReturnDataInfo
        {
            std::vector<ReturnData> ReturnDatas = {};
        };
        
        struct ArgumentsData
        {
            ConditionInfo ArgumentsConditionInfo;
            std::vector<DataInfo> ArgumentsDataInfo;
            ActionInfo ArgumentsActionInfo;
        };

        struct OverrideArgumentInfo
        {
            std::vector<ArgumentsData> ArgumentsDatas = {};
        };

        std::unordered_map<std::string, OverrideReturnDataInfo> OverrideReturnInfos;
        std::unordered_map<std::string, OverrideArgumentInfo> OverrideArgumentsInfos;
    
    //==============================================================================
    //Methods for storing requirements and datas to be returned or set
    //==============================================================================
    private:
        #define INTERNAL_SO_UNCONST(targetType) typename std::remove_const<targetType>::type
        #define INTERNAL_SO_NON_CONST_T INTERNAL_SO_UNCONST(T)
    
        //------------------------------------------------------------------------------
        //Methods for setting return data
        //------------------------------------------------------------------------------
        template<typename T>
        inline ReturnProxy& ReturnsByAction(ReturnProxy& proxy, 
                                                            std::function<void(std::vector<void*>& args, void* out)> returnAction)
        {
            ReturnData& lastData = OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();

            lastData.ReturnDataInfo.DataAction = returnAction;
            lastData.ReturnDataInfo.DataActionSet = true;
            lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
            return proxy;
        }
    
        template<typename T>
        inline ReturnProxy& Returns(ReturnProxy& proxy, T returnData)
        {
            ReturnData& lastData = OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();
            lastData.ReturnDataInfo.Data = new T(returnData);
            lastData.ReturnDataInfo.CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
            lastData.ReturnDataInfo.Destructor = [](void* data) { delete static_cast<T*>(data); }; 
            lastData.ReturnDataInfo.DataSet = true;
            lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
            return proxy;
        }
        
        //------------------------------------------------------------------------------
        //Methods for setting arguments data
        //------------------------------------------------------------------------------
        template<typename T>
        inline ArgumentsProxy& SetArgByAction( ArgumentsProxy& proxy,
                                                                std::function<void(std::vector<void*>& args, void* out)> setArgsAction)
        {
            ArgumentsData& lastData = OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();
            
            lastData.ArgumentsDataInfo.push_back(DataInfo());
            
            lastData.ArgumentsDataInfo.back().DataAction = setArgsAction;
            lastData.ArgumentsDataInfo.back().DataActionSet = true;
            lastData.ArgumentsDataInfo.back().DataType = typeid(T).hash_code();
            return proxy;
        }
        
        inline ArgumentsProxy& SetArgs(ArgumentsProxy& proxy)
        {
            return proxy;
        }
        
        #define SO_LOG_SetArgs 0
        
        #if 0 | SO_LOG_SetArgs
            #define PRINT_BYTES(val)\
            do\
            {\
                for(int byteIdx = 0; byteIdx < sizeof(val); byteIdx++)\
                {\
                    std::cout<<(int)((uint8_t*)&val)[byteIdx] <<", ";\
                }\
                std::cout << std::endl;\
            } while(0)
        #endif
        
        template<typename T, typename... Args>
        inline ArgumentsProxy& SetArgs( ArgumentsProxy& proxy,
                                                        T arg, Args... args)
        {
            ArgumentsData& lastData = OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();
            lastData.ArgumentsDataInfo.push_back(DataInfo());
            
            if(!std::is_same<T, Any>())
            {
                lastData.ArgumentsDataInfo.back().Data = new T(arg);
                lastData.ArgumentsDataInfo.back().CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
                lastData.ArgumentsDataInfo.back().Destructor = [](void* data) { delete static_cast<T*>(data); };
                lastData.ArgumentsDataInfo.back().DataSet = true;
                lastData.ArgumentsDataInfo.back().DataType = typeid(T).hash_code();

                #if SO_LOG_SetArgs
                    std::cout << "Set args index: "<<lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                    std::cout << "arg pointer: "<<&arg<<std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    std::cout << "Set args value: "<< (*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)) << std::endl << std::endl;
                    std::cout << "Original Data: "<<std::endl;
                    PRINT_BYTES(arg);
                    
                    std::cout << "Copied Data: "<<std::endl;
                    PRINT_BYTES((*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)));
                    std::cout << std::endl;
                #endif
            }
            
            return SetArgs(proxy, args...);
        }
        
        template<typename T, typename... Args>
        inline ArgumentsProxy& SetArgs( ArgumentsProxy& proxy,
                                                        NonComparable<T> arg, Args... args)
        {
            ArgumentsData& lastData = OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back();
            lastData.ArgumentsDataInfo.push_back(DataInfo());
            
            if(!std::is_same<T, Any>())
            {
                lastData.ArgumentsDataInfo.back().Data = new T(*arg.ReferenceVar);
                lastData.ArgumentsDataInfo.back().CopyConstructor = [](void* data) { return new T(*static_cast<T*>(data)); };
                lastData.ArgumentsDataInfo.back().Destructor = [](void* data) { delete static_cast<T*>(data); };
                lastData.ArgumentsDataInfo.back().DataSet = true;
                lastData.ArgumentsDataInfo.back().DataType = typeid(T).hash_code();

                #if SO_LOG_SetArgs
                    std::cout << "Set args index: "<<lastData.ArgumentsDataInfo.size() - 1 << std::endl;
                    std::cout << "arg pointer: "<<&arg<<std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    std::cout << "Set args value: "<< (*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)) << std::endl << std::endl;
                    std::cout << "Original Data: "<<std::endl;
                    PRINT_BYTES(arg);
                    
                    std::cout << "Copied Data: "<<std::endl;
                    PRINT_BYTES((*static_cast<T*>(lastData.ArgumentsDataInfo.back().Data)));
                    std::cout << std::endl;
                #endif
            }
            
            return SetArgs(proxy, args...);
        }
        
        template<typename T>
        struct SO_ASSERT_FALSE : std::false_type { };
        
        template<typename T, typename... Args>
        inline ArgumentsProxy& SetArgs( ArgumentsProxy& proxy,
                                                        NonCopyable<T> arg, Args... args)
        {
            static_assert(SO_ASSERT_FALSE<T>::value, "You can't pass non copyable argument to be set");
            return SetArgs(proxy, args...);
        }
        
        template<typename T, typename... Args>
        inline ArgumentsProxy& SetArgs( ArgumentsProxy& proxy,
                                                        NonComparableCopyable<T> arg, Args... args)
        {
            static_assert(SO_ASSERT_FALSE<T>::value, "You can't pass non copyable argument to be set");
            return SetArgs(proxy, args...);
        }
        
        
        //------------------------------------------------------------------------------
        //Methods for setting requirements
        //------------------------------------------------------------------------------
        template<typename DeriveType>
        inline DeriveType& Times(CommonProxy<DeriveType>& proxy, int times)
        {
            switch(proxy.FunctionProxyType)
            {
                case ProxyType::RETURN:
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnConditionInfo.Times = times;
                    break;
                case ProxyType::ARGS:
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsConditionInfo.Times = times;
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
        inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy, NonComparable<T> arg, Args... args)
        {
            static_assert(SO_ASSERT_FALSE<T>::value, "You can't check non comparable variable");
            return *static_cast<DeriveType*>(&proxy);
        }
        
        template<typename DeriveType, typename T, typename... Args>
        inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy, NonComparableCopyable<T> arg, Args... args)
        {
            static_assert(SO_ASSERT_FALSE<T>::value, "You can't check non comparable variable");
            return *static_cast<DeriveType*>(&proxy);
        }

        template<typename DeriveType, typename T, typename... Args>
        inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy, T arg, Args... args)
        {
            ArgInfo curArg;
            if(!std::is_same<T, Any>())
            {
                curArg.ArgData = new T(arg);
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
        
        template<typename DeriveType, typename T, typename... Args>
        inline DeriveType& WhenCalledWith(CommonProxy<DeriveType>& proxy, NonCopyable<T> arg, Args... args)
        {
            ArgInfo curArg;
            curArg.ArgData = const_cast<INTERNAL_SO_NON_CONST_T*>(arg.ReferenceVar);
            curArg.CopyConstructor = [](void* data) { return data; };
            curArg.Destructor = [](void* data){ };
            curArg.ArgSize = sizeof(T);
            curArg.ArgTypeHash = typeid(T).hash_code();
            curArg.ArgSet = true;
            
            #if 0
                std::cout << "typeid(T).name(): "<<typeid(T).name() <<"\n";
                std::cout << "sizeof(T): " << sizeof(T) << "\n";
                std::cout << "typeid(T).hash_code(): " << typeid(T).hash_code() << "\n";
            #endif

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
        inline DeriveType& If(   CommonProxy<DeriveType>& proxy, 
                                std::function<bool(std::vector<void*>& args)> condition)
        {
            switch(proxy.FunctionProxyType)
            {
                case ProxyType::RETURN:
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnConditionInfo.DataCondition = condition;
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnConditionInfo.DataConditionSet = true;
                    break;
                case ProxyType::ARGS:
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsConditionInfo.DataCondition = condition;
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsConditionInfo.DataConditionSet = true;
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
        inline DeriveType& Otherwise_Do( CommonProxy<DeriveType>& proxy, 
                                        std::function<void(std::vector<void*>& args)> action)
        {
            switch(proxy.FunctionProxyType)
            {
                case ProxyType::RETURN:
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnActionInfo.OtherwiseAction = action;
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnActionInfo.OtherwiseActionSet = true;
                    break;
                case ProxyType::ARGS:
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsActionInfo.OtherwiseAction = action;
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsActionInfo.OtherwiseActionSet = true;
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
        inline DeriveType& WhenCalledExpectedly_Do(  CommonProxy<DeriveType>& proxy, 
                                                    std::function<void(std::vector<void*>& args)> action)
        {
            switch(proxy.FunctionProxyType)
            {
                case ProxyType::RETURN:
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnActionInfo.CorrectAction = action;
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back().ReturnActionInfo.CorrectActionSet = true;
                    break;
                case ProxyType::ARGS:
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsActionInfo.CorrectAction = action;
                    OverrideArgumentsInfos[proxy.FunctionSignatureName].ArgumentsDatas.back().ArgumentsActionInfo.CorrectActionSet = true;
                    break;
                case ProxyType::COMMON:
                    std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                    assert(false);
                    exit(1);
                    break;
            }

            return *static_cast<DeriveType*>(&proxy);
        }

    //==============================================================================
    //Implementation methods for querying (and setting) the correct return or arugment data
    //==============================================================================
    private:
        //Appending arguments from function calls
        inline void AppendArguments(std::vector<void*>& argumentsList){};

        template<typename T, typename... Args>
        inline void AppendArguments(std::vector<void*>& argumentsList, T& arg, Args&... args)
        {
            argumentsList.push_back((INTERNAL_SO_NON_CONST_T*)&arg);
            AppendArguments(argumentsList, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendArguments(std::vector<void*>& argumentsList, NonCopyable<T>& arg, Args&... args)
        {
            argumentsList.push_back((INTERNAL_SO_NON_CONST_T*)&arg);
            AppendArguments(argumentsList, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendArguments(std::vector<void*>& argumentsList, NonComparable<T>& arg, Args&... args)
        {
            argumentsList.push_back((INTERNAL_SO_NON_CONST_T*)&arg);
            AppendArguments(argumentsList, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendArguments(std::vector<void*>& argumentsList, NonComparableCopyable<T>& arg, Args&... args)
        {
            argumentsList.push_back((INTERNAL_SO_NON_CONST_T*)&arg);
            AppendArguments(argumentsList, args...);
        }
        
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList) {}

        template<typename T, typename... Args>
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList, T& arg, Args&... args)
        {
            ArgInfo curArgInfo;
            if(!std::is_same<T, Any>())
            {
                curArgInfo.ArgSize = sizeof(INTERNAL_SO_NON_CONST_T);
                curArgInfo.ArgTypeHash = typeid(INTERNAL_SO_NON_CONST_T).hash_code();
                curArgInfo.ArgSet = true;
            }

            argumentsList.push_back(curArgInfo);
            AppendDereferenceArgsInfo(argumentsList, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList, NonCopyable<T>& arg, Args&... args)
        {
            AppendDereferenceArgsInfo(argumentsList, (INTERNAL_SO_NON_CONST_T&)arg, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList, NonComparable<T>& arg, Args&... args)
        {
            AppendDereferenceArgsInfo(argumentsList, (INTERNAL_SO_NON_CONST_T&)arg, args...);
        }
        
        template<typename T, typename... Args>
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList, NonComparableCopyable<T>& arg, Args&... args)
        {
            AppendDereferenceArgsInfo(argumentsList, (INTERNAL_SO_NON_CONST_T&)arg, args...);
        }
        
        template<   typename T, 
                    typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                    typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                    typename... Args>
        inline void AppendDereferenceArgsInfo(std::vector<ArgInfo>& argumentsList, T* arg, Args&... args)
        {
            AppendDereferenceArgsInfo(argumentsList, *arg, args...);
        }

        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex){ return true; };

        #define SO_LOG_CheckArguments 0

        template<typename T, typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, T& arg, Args&... args)
        {
            #if SO_LOG_CheckArguments
                std::cout <<"CheckArguments index: "<<argIndex<<"\n";
            #endif
        
            if(argIndex >= argumentsListToCheck.size())
                return false;

            if(argumentsListToCheck[argIndex].ArgSet)
            {
                if(sizeof(INTERNAL_SO_NON_CONST_T) != argumentsListToCheck[argIndex].ArgSize)
                {
                    #if SO_LOG_CheckArguments
                        std::cout <<"sizeof(INTERNAL_SO_NON_CONST_T): "<<sizeof(INTERNAL_SO_NON_CONST_T)<<"\n";
                        std::cout <<"sizeof(T): "<<sizeof(T)<<"\n";
                        std::cout <<"argumentsListToCheck["<<argIndex<<"].ArgSize: "<<argumentsListToCheck[argIndex].ArgSize<<"\n";
                    #endif
                    return false;
                }

                if(typeid(INTERNAL_SO_NON_CONST_T).hash_code() != argumentsListToCheck[argIndex].ArgTypeHash)
                {
                    #if SO_LOG_CheckArguments
                        std::cout <<"typeid(INTERNAL_SO_NON_CONST_T).hash_code(): "<<typeid(INTERNAL_SO_NON_CONST_T).hash_code()<<"\n";
                        std::cout <<"argumentsListToCheck["<<argIndex<<"].ArgTypeHash: "<<argumentsListToCheck[argIndex].ArgTypeHash<<"\n";
                    #endif
                    return false;
                }

                if(arg != *reinterpret_cast<INTERNAL_SO_NON_CONST_T*>(argumentsListToCheck[argIndex].ArgData))
                {
                    #if SO_LOG_CheckArguments
                        std::cout <<"arg != *reinterpret_cast<INTERNAL_SO_NON_CONST_T*>(argumentsListToCheck[argIndex].ArgData\n";
                    #endif
                    return false;
                }
            }            
            
            #if SO_LOG_CheckArguments
                std::cout <<"CheckArguments index: "<<argIndex<<" passed\n";
            #endif
            
            return CheckArguments(argumentsListToCheck, ++argIndex, args...);
        }
        
        template<typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, Any& arg, Args&... args)
        {
            #if SO_LOG_CheckArguments
                std::cout <<"CheckArguments index: "<<argIndex<<"\n";
            #endif
        
            if(argIndex >= argumentsListToCheck.size())
                return false;

            if(argumentsListToCheck[argIndex].ArgSet)
                return false;
            
            #if SO_LOG_CheckArguments
                std::cout <<"CheckArguments index: "<<argIndex<<" passed\n";
            #endif
            
            return CheckArguments(argumentsListToCheck, ++argIndex, args...);
        }
        
        template<typename T, typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, NonCopyable<T>& arg, Args&... args)
        {
            return CheckArguments(argumentsListToCheck, argIndex, (T&)arg, args...);
        }
        
        template<typename T, typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, NonComparable<T>& arg, Args&... args)
        {
            if(argIndex >= argumentsListToCheck.size())
                return false;
        
            return !argumentsListToCheck[argIndex].ArgSet ? CheckArguments(argumentsListToCheck, ++argIndex, args...) : false;
        }
        
        template<typename T, typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, NonComparableCopyable<T>& arg, Args&... args)
        {
            if(argIndex >= argumentsListToCheck.size())
                return false;

            return !argumentsListToCheck[argIndex].ArgSet ? CheckArguments(argumentsListToCheck, ++argIndex, args...) : false;
        }
        
        template<   typename T, 
                    typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                    typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                    typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, T*& arg, Args&... args)
        {
            return CheckArguments(argumentsListToCheck, argIndex, *arg, args...);
        }
        
        template<typename T, typename... Args>
        inline bool CheckArguments(std::vector<ArgInfo>& argumentsListToCheck, int argIndex, const T& arg, Args&... args)
        {
            return CheckArguments(argumentsListToCheck, argIndex, const_cast<INTERNAL_SO_NON_CONST_T&>(arg), args...);
        }
        
        #define SO_LOG_GetCorrectReturnDataInfo 0

        template<typename T, typename... Args>
        inline int GetCorrectReturnDataInfo(T& returnRef, std::string functionName, Args&... args)
        {
            if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
            {
                std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                assert(false);
                exit(1);
            }
            
            #if SO_LOG_GetCorrectReturnDataInfo
                std::cout <<"GetCorrectReturnDataInfo called\n";
            #endif

            std::vector<void*> argumentsList;
            AppendArguments(argumentsList, args...);
            
            std::vector<ReturnData>& curReturnDatas = OverrideReturnInfos[functionName].ReturnDatas;
            int returnIndex = -1;
            for(int i = 0; i < curReturnDatas.size(); i++)
            {
                #if SO_LOG_GetCorrectReturnDataInfo
                    std::cout << "Checking return data["<<i<<"]\n";
                #endif

                //Check return data exist
                if(!curReturnDatas[i].ReturnDataInfo.DataSet && !curReturnDatas[i].ReturnDataInfo.DataActionSet)
                {
                    #if SO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Failed at return data exist\n";
                    #endif
                    if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                        curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                    continue;
                }
            
                //Check return type
                if(curReturnDatas[i].ReturnDataInfo.DataType != typeid(INTERNAL_SO_NON_CONST_T).hash_code())
                {
                    #if SO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Failed at return type\n";
                    #endif
                    if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                        curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                    
                    continue;
                }

                //Check condition
                if(curReturnDatas[i].ReturnConditionInfo.DataConditionSet && !curReturnDatas[i].ReturnConditionInfo.DataCondition(argumentsList))
                {
                    #if SO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Failed at Check condition\n";
                    #endif
                    if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                        curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                    
                    continue;
                }

                //Check parameter
                if( !curReturnDatas[i].ReturnConditionInfo.ArgsCondition.empty() && 
                    !CheckArguments(curReturnDatas[i].ReturnConditionInfo.ArgsCondition, 0, args...))
                {
                    #if SO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Failed at Check parameter\n";
                    #endif
                    if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                        curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);

                    continue;
                }
                    
                //Check times
                if( curReturnDatas[i].ReturnConditionInfo.Times >= 0 && 
                    curReturnDatas[i].ReturnConditionInfo.CalledTimes >= curReturnDatas[i].ReturnConditionInfo.Times)
                {
                    #if SO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Failed at Check times\n";
                    #endif
                    if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                        curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);

                    continue;
                }
                
                #if SO_LOG_GetCorrectReturnDataInfo
                    std::cout << "Return data found: "<<i<<"\n";
                #endif
                returnIndex = i;
                break;
            }
            
            //Deallocating argumentsList
            //for(int i = 0; i < argumentsList.size(); i++)
            //    argumentsList[i].Destructor(argumentsList[i].ArgData);
            
            return returnIndex;
        }
        
        #define SO_LOG_GetCorrectArgumentsDataInfo 0
        
        template<typename... Args>
        inline int GetCorrectArgumentsDataInfo(std::string functionName, Args&... args)
        {
            if(OverrideArgumentsInfos.find(functionName) == OverrideArgumentsInfos.end())
            {
                std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                assert(false);
                exit(1);
            }
            
            #if SO_LOG_GetCorrectArgumentsDataInfo
                std::cout <<"GetCorrectArgumentsDataInfo called\n";
            #endif
            
            std::vector<void*> argumentsList;
            AppendArguments(argumentsList, args...);
            
            std::vector<ArgInfo> deRefArgumentsList;
            AppendDereferenceArgsInfo(deRefArgumentsList, args...);
            
            std::vector<ArgumentsData>& curArgData = OverrideArgumentsInfos[functionName].ArgumentsDatas;
            int returnIndex = -1;
            for(int i = 0; i < curArgData.size(); i++)
            {
                #if SO_LOG_GetCorrectArgumentsDataInfo
                    std::cout << "Checking arg data["<<i<<"]\n";
                #endif
            
                //Check set argument data exist
                if(curArgData[i].ArgumentsDataInfo.size() != deRefArgumentsList.size())
                {
                    #if SO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Failed at Check set argument data exist\n";
                    #endif
                    if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                        curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                    
                    continue;
                }
            
                //Check arguments types
                bool argumentTypeFailed = false;
                for(int j = 0; j < curArgData[i].ArgumentsDataInfo.size(); j++)
                {
                    if( curArgData[i].ArgumentsDataInfo[j].DataSet &&
                        curArgData[i].ArgumentsDataInfo[j].DataType != deRefArgumentsList[j].ArgTypeHash)
                    {
                        #if SO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check arguments types\n";
                        #endif
                        argumentTypeFailed = true;
                        break;;
                    }
                }
                if(argumentTypeFailed)
                {
                    if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                        curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);

                    continue;
                }

                //Check condition
                if(curArgData[i].ArgumentsConditionInfo.DataConditionSet && !curArgData[i].ArgumentsConditionInfo.DataCondition(argumentsList))
                {
                    #if SO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Failed at Check condition\n";
                    #endif
                    continue;
                }

                //Check parameter
                if( !curArgData[i].ArgumentsConditionInfo.ArgsCondition.empty() && 
                    !CheckArguments(curArgData[i].ArgumentsConditionInfo.ArgsCondition, 0, args...))
                {
                    #if SO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Failed at Check parameter\n";
                    #endif
                    if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                        curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                    continue;
                }
                    
                //Check times
                if( curArgData[i].ArgumentsConditionInfo.Times >= 0 && 
                    curArgData[i].ArgumentsConditionInfo.CalledTimes >= curArgData[i].ArgumentsConditionInfo.Times)
                {
                    #if SO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Failed at Check times\n";
                    #endif
                    if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                        curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                    continue;
                }
                
                #if SO_LOG_GetCorrectArgumentsDataInfo
                    std::cout << "Argument data found: "<<i<<"\n";
                #endif
                
                returnIndex = i;
                break;
            }
            
            //Deallocating argumentsList
            //for(int i = 0; i < argumentsList.size(); i++)
            //    argumentsList[i].Destructor(argumentsList[i].ArgData);
            
            //Deallocating derefArgumentsList
            //for(int i = 0; i < derefArgumentsList.size(); i++)
            //    derefArgumentsList[i].Destructor(derefArgumentsList[i].ArgData);

            return returnIndex;
        }
        
        #define SO_LOG_ModifyArgs 0
        
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index) {}

        template<typename T, typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, T& arg, Args&... args)
        {
            if(!argsData[index].DataSet && !argsData[index].DataActionSet)
            {
                ModifyArgs(argumentsList, argsData, ++index, args...);
                return;
            }
        
            if(argsData[index].DataSet)
            {
                INTERNAL_SO_NON_CONST_T& pureArg = const_cast<INTERNAL_SO_NON_CONST_T&>(arg); 
                pureArg = *static_cast<INTERNAL_SO_NON_CONST_T*>(argsData[index].Data);
                #if SO_LOG_ModifyArgs
                    std::cout << "modified index: "<<index << std::endl;
                    std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                    std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                    std::cout << "argsData[index].DataType: " << argsData[index].DataType <<std::endl;
                    std::cout << "arg value: "<< arg << std::endl;
                    std::cout << "modified value: "<< (*static_cast<T*>(argsData[index].Data)) << std::endl << std::endl;
                    std::cout << "modified value bytes:" << std::endl;
                    
                    PRINT_BYTES((*static_cast<T*>(argsData[index].Data)));
                    std::cout << std::endl;
                #endif
            }
            else
                argsData[index].DataAction(argumentsList, &const_cast<INTERNAL_SO_NON_CONST_T&>(arg));

            ModifyArgs(argumentsList, argsData, ++index, args...);
        }
        
        template<typename T, typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, NonComparable<T>& arg, Args&... args)
        {
            if(!argsData[index].DataSet && !argsData[index].DataActionSet)
            {
                ModifyArgs(argumentsList, argsData, ++index, args...);
                return;
            }
        
            #if SO_LOG_ModifyArgs
                std::cout << "modified index: "<<index << std::endl;
                std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                std::cout << "arg value: "<< arg << std::endl;
                std::cout << std::endl;
            #endif

            if(argsData[index].DataSet)
            {
                INTERNAL_SO_NON_CONST_T& pureArg = (INTERNAL_SO_NON_CONST_T&)(arg); 
                pureArg = *static_cast<INTERNAL_SO_NON_CONST_T*>(argsData[index].Data);
                #if SO_LOG_ModifyArgs
                    std::cout << "argsData[index].DataType: " << argsData[index].DataType <<std::endl;
                    std::cout << "modified value: "<< (*static_cast<T*>(argsData[index].Data)) << std::endl << std::endl;
                    std::cout << "modified value bytes:" << std::endl;
                    
                    PRINT_BYTES((*static_cast<T*>(argsData[index].Data)));
                    std::cout << std::endl;
                #endif
            }
            else
                argsData[index].DataAction(argumentsList, &((INTERNAL_SO_NON_CONST_T&)(arg)));

            ModifyArgs(argumentsList, argsData, ++index, args...);
        }
        
        template<typename T, typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, NonCopyable<T>& arg, Args&... args)
        {
            #if SO_LOG_ModifyArgs
                std ::cout <<"Skipping ModifyArgs for index "<<index << " for NonCopyable\n";
            #endif
            ModifyArgs(argumentsList, argsData, ++index, args...);
        }
        
        template<typename T, typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, NonComparableCopyable<T>& arg, Args&... args)
        {
            #if SO_LOG_ModifyArgs
                std ::cout <<"Skipping ModifyArgs for index "<<index << " for NonCopyable\n";
            #endif
            ModifyArgs(argumentsList, argsData, ++index, args...);
        }
        
        template<   typename T, 
                    typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                    typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                    typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, T*& arg, Args&... args)
        {
            ModifyArgs(argumentsList, argsData, index, *arg, args...);
        }
        
        template<typename T, typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, const T& arg, Args&... args)
        {
            if(!argsData[index].DataSet && !argsData[index].DataActionSet)
            {
                ModifyArgs(argumentsList, argsData, ++index, args...);
                return;
            }
            
            #if SO_LOG_ModifyArgs
                std::cout << "modified index: "<<index << std::endl;
                std::cout << "typeid(arg).name(): " << typeid(arg).name() <<std::endl;
                std::cout << "typeid(arg).hash_code(): " << typeid(arg).hash_code() <<std::endl;
                std::cout << "arg value: "<< arg << std::endl;
                std::cout << std::endl;
            #endif
            
            if(argsData[index].DataSet)
            {
                std::cout << "[ERROR] Data cannot be set for const arguments" << std::endl;
                assert(false);
                exit(1);
            }
            else
            {
                std::cout << "[WARNING] DataAction is called on const argument, is this intentional?" << std::endl;
                argsData[index].DataAction(argumentsList, &((INTERNAL_SO_NON_CONST_T&)(arg)));
            }
            
            ModifyArgs(argumentsList, argsData, ++index, args...);
        }

        template<typename... Args>
        inline void ModifyArgs(std::vector<void*>& argumentsList, std::vector<DataInfo>& argsData, int index, const Any& arg, Args&... args)
        {
            #if SO_LOG_ModifyArgs
                std ::cout <<"Skipping ModifyArgs for index "<<index << " for Any\n";
            #endif
            ModifyArgs(argumentsList, argsData, ++index, args...);
        }

    //==============================================================================
    //Public facing methods for overriding returns or arguments
    //==============================================================================
    public:
        inline SimpleOverride(const SimpleOverride& other)
        {
            *this = other;
        }
    
        inline SimpleOverride& operator=(const SimpleOverride& other)
        {
            if(this == &other)
                return *this;
        
            OverrideReturnInfos = other.OverrideReturnInfos;
            OverrideArgumentsInfos = other.OverrideArgumentsInfos;
        
            for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
            {
                for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                {
                    DataInfo& curReturnDataInfo = it->second.ReturnDatas[i].ReturnDataInfo;
                    if(curReturnDataInfo.DataSet)
                        curReturnDataInfo.Data = curReturnDataInfo.CopyConstructor(curReturnDataInfo.Data);
                    
                    for(int j = 0; j < it->second.ReturnDatas[i].ReturnConditionInfo.ArgsCondition.size(); j++)
                    {
                        ArgInfo& curArgDataInfo = it->second.ReturnDatas[i].ReturnConditionInfo.ArgsCondition[j];
                        
                        if(curArgDataInfo.ArgSet)
                            curArgDataInfo.ArgData = curArgDataInfo.CopyConstructor(curArgDataInfo.ArgData);
                    }
                }
            }
            
            for(auto it = OverrideArgumentsInfos.begin(); it != OverrideArgumentsInfos.end(); it++)
            {
                for(int i = 0; i < it->second.ArgumentsDatas.size(); i++)
                {
                    for(int j = 0; j < it->second.ArgumentsDatas[i].ArgumentsDataInfo.size(); j++)
                    {
                        DataInfo& curArgDataInfo = it->second.ArgumentsDatas[i].ArgumentsDataInfo[j];
                        
                        if(curArgDataInfo.DataSet)
                            curArgDataInfo.Data = curArgDataInfo.CopyConstructor(curArgDataInfo.Data);
                    }
                    
                    for(int j = 0; j < it->second.ArgumentsDatas[i].ArgumentsConditionInfo.ArgsCondition.size(); j++)
                    {
                        ArgInfo& curArgDataInfo = it->second.ArgumentsDatas[i].ArgumentsConditionInfo.ArgsCondition[j];
                        
                        if(curArgDataInfo.ArgSet)
                            curArgDataInfo.ArgData = curArgDataInfo.CopyConstructor(curArgDataInfo.ArgData);
                    }
                }
            }
            
            return *this;
        }
        
        SimpleOverride() = default;
    
        inline ~SimpleOverride()
        {
            for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
            {
                for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                {
                    //Free return data
                    DataInfo& curDataInfo = it->second.ReturnDatas[i].ReturnDataInfo;
                    if(curDataInfo.DataSet)
                        curDataInfo.Destructor(curDataInfo.Data);
                    
                    //Free argument condition data
                    for(int j = 0; j < it->second.ReturnDatas[i].ReturnConditionInfo.ArgsCondition.size(); j++)
                    {
                        ArgInfo& curArgInfos = it->second.ReturnDatas[i].ReturnConditionInfo.ArgsCondition[j];
                        if(curArgInfos.ArgSet)
                            curArgInfos.Destructor(curArgInfos.ArgData);
                    }
                }
            }
            
            for(auto it = OverrideArgumentsInfos.begin(); it != OverrideArgumentsInfos.end(); it++)
            {
                for(int i = 0; i < it->second.ArgumentsDatas.size(); i++)
                {
                    //Free set arguments data
                    for(int j = 0; j < it->second.ArgumentsDatas[i].ArgumentsDataInfo.size(); j++)
                    {
                        DataInfo& curDataInfo = it->second.ArgumentsDatas[i].ArgumentsDataInfo[j];
                        if(curDataInfo.DataSet)
                            curDataInfo.Destructor(curDataInfo.Data);
                    }
                    
                    //Free argument condition data
                    for(int j = 0; j < it->second.ArgumentsDatas[i].ArgumentsConditionInfo.ArgsCondition.size(); j++)
                    {
                        ArgInfo& curArgInfo = it->second.ArgumentsDatas[i].ArgumentsConditionInfo.ArgsCondition[j];
                        if(curArgInfo.ArgSet)
                            curArgInfo.Destructor(curArgInfo.ArgData);
                    }
                }
            }
        }

        //------------------------------------------------------------------------------
        //Overrding Returns
        //------------------------------------------------------------------------------
        #define SO_LOG_OverrideReturns 0
        inline ReturnProxy Internal_OverrideReturns(std::string functionName)
        {
            #if SO_LOG_OverrideReturns
                std::cout << "OverrideReturns\n";
                std::cout << "functionName: "<<functionName << "\n";
                std::cout << "functionName.size(): " << functionName.size() << "\n";
            #endif

            OverrideReturnInfos[functionName].ReturnDatas.push_back(ReturnData());
            return ReturnProxy(functionName, *this, ProxyType::RETURN);
        }
        
        inline void Internal_ClearOverrideReturns(std::string functionName)
        {
            if(OverrideReturnInfos.find(functionName) != OverrideReturnInfos.end())
                OverrideReturnInfos.erase(functionName);
        }
        
        inline void ClearAllOverrideReturns()
        {
            OverrideReturnInfos.clear();
        }
        
        #define SO_LOG_CheckOverrideAndReturn 0
        
        template<typename T, typename... Args>
        inline bool Internal_CheckOverrideAndReturn(T& returnRef, std::string functionName, Args&... args)
        {
            #if SO_LOG_CheckOverrideAndReturn
                std::cout << "CheckOverrideAndReturn\n";
                std::cout << "functionName: "<<functionName << "\n";
                std::cout << "functionName.size(): " << functionName.size() << "\n";
            #endif
            if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
                return false;
        
            int correctDataIndex = GetCorrectReturnDataInfo(returnRef, functionName, args...);
            
            std::vector<void*> argumentsList;
            AppendArguments(argumentsList, args...);
            
            //Called correctly action
            bool returnResult = false;
            if(correctDataIndex != -1)
            {
                ReturnData& correctData = OverrideReturnInfos[functionName].ReturnDatas[correctDataIndex];
                correctData.ReturnConditionInfo.CalledTimes++;
                
                if(correctData.ReturnActionInfo.CorrectActionSet)
                    correctData.ReturnActionInfo.CorrectAction(argumentsList);
                
                if(correctData.ReturnDataInfo.DataSet)
                    returnRef = *reinterpret_cast<T*>(correctData.ReturnDataInfo.Data);
                else
                    correctData.ReturnDataInfo.DataAction(argumentsList, &returnRef);

                assert(correctData.ReturnDataInfo.DataSet || correctData.ReturnDataInfo.DataActionSet);
                returnResult = true;
            }
            
            //Deallocating argumentsList
            //for(int i = 0; i < argumentsList.size(); i++)
            //    argumentsList[i].Destructor(argumentsList[i].ArgData);

            return returnResult;
        }

        //------------------------------------------------------------------------------
        //Overrding Arguments
        //------------------------------------------------------------------------------
        #define SO_LOG_OverrideArgs 0

        inline ArgumentsProxy Internal_OverrideArgs(std::string functionName)
        {
            #if SO_LOG_OverrideArgs
                std::cout << "OverrideArgs\n";
                std::cout << "functionName: "<<functionName << "\n";
            #endif

            OverrideArgumentsInfos[functionName].ArgumentsDatas.push_back(ArgumentsData());
            return ArgumentsProxy(functionName, *this, ProxyType::ARGS);
        }
        
        inline void Internal_ClearOverrideArgs(std::string functionName)
        {
            if(OverrideArgumentsInfos.find(functionName) != OverrideArgumentsInfos.end())
                OverrideArgumentsInfos.erase(functionName);
        }
        
        inline void ClearAllOverrideArgs()
        {
            OverrideArgumentsInfos.clear();
        }

        #define SO_LOG_CheckOverrideAndSetArgs 0

        template<typename... Args>
        inline bool Internal_CheckOverrideAndSetArgs(std::string functionName, Args&... args)
        {
            #if SO_LOG_CheckOverrideAndSetArgs
                std::cout << "CheckOverrideAndSetArgs\n";
                std::cout << "functionName: "<<functionName << "\n";
            #endif
            if(OverrideArgumentsInfos.find(functionName) == OverrideArgumentsInfos.end())
                return false;
        
            int correctDataIndex = GetCorrectArgumentsDataInfo(functionName, args...);
            
            std::vector<void*> argumentsList;
            AppendArguments(argumentsList, args...);
            
            //Called correctly action
            bool returnResult = false;
            if(correctDataIndex != -1)
            {
                ArgumentsData& correctData = OverrideArgumentsInfos[functionName].ArgumentsDatas[correctDataIndex];
                correctData.ArgumentsConditionInfo.CalledTimes++;
                
                if(correctData.ArgumentsActionInfo.CorrectActionSet)
                    correctData.ArgumentsActionInfo.CorrectAction(argumentsList);

                ModifyArgs(argumentsList, correctData.ArgumentsDataInfo, 0, args...);
                returnResult = true;
            }

            //Deallocating argumentsList
            //for(int i = 0; i < argumentsList.size(); i++)
            //    argumentsList[i].Destructor(argumentsList[i].ArgData);

            return returnResult;
        }
};

//==============================================================================
//Implementation of proxy classes for method chaining
//==============================================================================

//NOTE: Can't do using as this will evaluate the DeriveType which contains SimpleOverrideCommonProxy which has functions not defined yet.
//      See https://stackoverflow.com/questions/35428422/crtp-accessing-incomplete-type-members
//template<typename DeriveType>
//using CommonProxy = SimpleOverrideCommonProxy<DeriveType>;

template<typename T>
inline SimpleOverride::ReturnProxy& SimpleOverride::ReturnProxy::ReturnsByAction(std::function<void(std::vector<void*>& args, void* out)> returnAction)
{
    return SimpleOverrideObj.ReturnsByAction<T>(*this, returnAction);
}

template<typename T>
inline SimpleOverride::ReturnProxy& SimpleOverride::ReturnProxy::Returns(T returnData)
{
    return SimpleOverrideObj.Returns(*this, returnData);
}

template<typename T>
inline SimpleOverride::ArgumentsProxy& SimpleOverride::ArgumentsProxy::SetArgByAction(std::function<void(std::vector<void*>& args, void* out)> setArgsAction)
{
    return SimpleOverrideObj.SetArgByAction<T>(*this, setArgsAction);
}
        
template<typename... Args>
inline SimpleOverride::ArgumentsProxy& SimpleOverride::ArgumentsProxy::SetArgs(Args... args)
{
    return SimpleOverrideObj.SetArgs(*this, args...);
}

template<typename DeriveType>
inline DeriveType& SimpleOverride::CommonProxy<DeriveType>::Times(int times)
{
    return SimpleOverrideObj.Times(*this, times);
}

template<typename DeriveType>
template<typename... Args>
inline DeriveType& SimpleOverride::CommonProxy<DeriveType>::WhenCalledWith(Args... args)
{
    return SimpleOverrideObj.WhenCalledWith(*this, args...);
}

template<typename DeriveType>
inline DeriveType& SimpleOverride::CommonProxy<DeriveType>::If(std::function<bool(std::vector<void*>& args)> condition)
{
    return SimpleOverrideObj.If(*this, condition);
}

template<typename DeriveType>
inline DeriveType& SimpleOverride::CommonProxy<DeriveType>::Otherwise_Do(std::function<void(std::vector<void*>& args)> action)
{
    return SimpleOverrideObj.Otherwise_Do(*this, action);
}

template<typename DeriveType>
inline DeriveType& SimpleOverride::CommonProxy<DeriveType>::WhenCalledExpectedly_Do(std::function<void(std::vector<void*>& args)> action)
{
    return SimpleOverrideObj.WhenCalledExpectedly_Do(*this, action);
}

//==============================================================================
//Macros and functions for translating function signature to string
//==============================================================================
inline std::string ProcessFunctionSig(std::string functionSig)
{
    //Trimming
    int firstCharIndex = -1;
    for(int i = 0; i < functionSig.size(); i++)
    {
        if(functionSig[i] != ' ')
        {
            firstCharIndex = i;
            break;
        }
    }
    
    int lastCharIndex = -1;
    for(int i = functionSig.size() - 1; i >= 0; i--)
    {
        if(functionSig[i] != ' ')
        {
            lastCharIndex = i;
            break;
        }
    }
    
    functionSig = functionSig.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
    
    //Remove any consecutive spaces
    std::set<int> spacesToRemove;
    bool isLastSpace = false;
    for(int i = 0; i < functionSig.size(); i++)
    {
        if(isLastSpace)
        {
            if(functionSig[i] == ' ')
                spacesToRemove.insert(i);
            else
                isLastSpace = false;
        }
        else if(functionSig[i] == ' ')
            isLastSpace = true;
    }
    
    //Remove spaces around parentheses and commas
    for(int i = 0; i < functionSig.size(); i++)
    {
        switch(functionSig[i])
        {
            case '(':
            case ')':
            case ',':
            case '*':
            case '&':
            case ':':
            case '<':
            case '>':
                if(i > 0 && functionSig[i - 1] == ' ')
                    spacesToRemove.insert(i - 1);
                
                if(i < functionSig.size() - 1 && functionSig[i + 1] == ' ')
                    spacesToRemove.insert(i + 1);
                break;
            default:
                break;
        }
    }
    
    
    for(auto it = spacesToRemove.rbegin(); it != spacesToRemove.rend(); it++)
        functionSig.erase(functionSig.begin() + *it);

    return functionSig;
}

//==============================================================================
//Macro argument expandsion
//==============================================================================

#define SO_INTERNAL_APPEND_ARGS_NOT_EMPTY(...) , __VA_ARGS__
#define SO_INTERNAL_APPEND_ARGS_EMPTY(...)

//NOTE: Up to 20 arguments
#define SO_INTERNAL_EXPAND_IF_EMPTY() ,,,,,,,,,,,,,,,,,,,,
#define SO_INTERNAL_ESCAPE_BRACKET(...) __VA_ARGS__ ()
#define SO_INTERNAL_TEST_EMPTY(...)   SO_INTERNAL_CAT_ALLOW_GARBAGE(SO_INTERNAL_EXPAND_IF_EMPTY, SO_INTERNAL_ESCAPE_BRACKET __VA_ARGS__ ())
#define SO_INTERNAL_SELECT_TAG(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _TAG, ...) _TAG
#define SO_INTERNAL_CAT_ALLOW_GARBAGE(a, b, ...) a b
#define SO_INTERNAL_CAT(a, b) a b
#define SO_INTERNAL_FUNC_CAT(a, b) a ## b

#define SO_INTERNAL_GET_TAG(...) SO_INTERNAL_CAT( SO_INTERNAL_SELECT_TAG, (SO_INTERNAL_TEST_EMPTY(__VA_ARGS__), _EMPTY, \
                                                        _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                                                        _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY) )

//Debug
//#define SO_INTERNAL_GET_TAG(...) SO_INTERNAL_CAT( SO_INTERNAL_SELECT_TAG, ( SO_INTERNAL_EXPAND_IF_EMPTY __VA_ARGS__ (), _0,
//                                                    _20, _19, _18, _17, _16, _15, _14, _13, _12, _11,
//                                                    _10, _9, _8, _7, _6, _5, _4, _3, _2, _1) )

//MSVC workaround: https://stackoverflow.com/questions/48710758/how-to-fix-variadic-macro-related-issues-with-macro-overloading-in-msvc-mic

#ifndef _MSC_VER
    #define SO_INTERNAL_APPEND_ARGS(...) SO_INTERNAL_CAT( SO_INTERNAL_FUNC_CAT, (SO_INTERNAL_APPEND_ARGS, SO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) )
#else
    #define SO_INTERNAL_VA_ARGS_FIX( macro, args ) macro args
    #define SO_INTERNAL_APPEND_ARGS(...) SO_INTERNAL_VA_ARGS_FIX( SO_INTERNAL_CAT, ( SO_INTERNAL_FUNC_CAT, (SO_INTERNAL_APPEND_ARGS, SO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) ) )
#endif

#define SO_INTERNAL_STR(x) #x

//==============================================================================
//Public Macros
//==============================================================================


//-------------------------------------------------------
//Return Macros
//-------------------------------------------------------
#define SO_RETURN_IF_FOUND(overrideObjName, functionSig, returnType, ...)\
do\
{\
    returnType returnVal;\
    if(SO_CHECK_OVERRIDE_AND_RETURN(overrideObjName, returnVal, functionSig, __VA_ARGS__))\
        return returnVal;\
} while(0)

#define SO_CHECK_OVERRIDE_AND_RETURN(overrideObjName, returnRef, functionSig, ...)\
    overrideObjName.Internal_CheckOverrideAndReturn(returnRef, ProcessFunctionSig(SO_INTERNAL_STR(functionSig)) SO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )

#define SO_OVERRIDE_RETURNS(overrideObjName, functionSig) overrideObjName.Internal_OverrideReturns(ProcessFunctionSig(SO_INTERNAL_STR(functionSig)))
#define SO_CLEAR_OVERRIDE_RETURNS(overrideObjName, functionSig) overrideObjName.Internal_ClearOverrideReturns(ProcessFunctionSig(SO_INTERNAL_STR(functionSig)))



//-------------------------------------------------------
//Argument Macros
//-------------------------------------------------------

#define SO_MODIFY_ARGS_IF_FOUND(overrideObjName, functionSig, ...)\
    SO_CHECK_OVERRIDE_AND_SET_ARGS(overrideObjName, functionSig, __VA_ARGS__)
        
#define SO_MODIFY_ARGS_AND_RETURN_IF_FOUND(overrideObjName, returnValue, functionSig, ...)\
do\
{\
    if(SO_CHECK_OVERRIDE_AND_SET_ARGS(overrideObjName, functionSig, __VA_ARGS__))\
        return returnValue;\
} while(0)

#define SO_CHECK_OVERRIDE_AND_SET_ARGS(overrideObjName, functionSig, ...)\
        overrideObjName.Internal_CheckOverrideAndSetArgs(ProcessFunctionSig(SO_INTERNAL_STR(functionSig)) SO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )


#define SO_OVERRIDE_ARGS(overrideObjName, functionSig) overrideObjName.Internal_OverrideArgs(ProcessFunctionSig(SO_INTERNAL_STR(functionSig)))

#define SO_CLEAR_OVERRIDE_ARGS(overrideObjName, functionSig) overrideObjName.Internal_ClearOverrideArgs(ProcessFunctionSig(SO_INTERNAL_STR(functionSig)))


//-------------------------------------------------------
//Delacration Macros
//-------------------------------------------------------
#define SO_DECLARE_INSTNACE(OverrideObjName) mutable SimpleOverride OverrideObjName
        
#define SO_DECLARE_OVERRIDE_METHODS(OverrideObjName)\
inline SimpleOverride::ArgumentsProxy Internal_OverrideArgs(std::string functionName)\
{\
    return OverrideObjName.Internal_OverrideArgs(functionName);\
}\
inline void Internal_ClearOverrideArgs(std::string functionName)\
{\
    OverrideObjName.Internal_ClearOverrideArgs(functionName);\
}\
inline void ClearAllOverrideArgs()\
{\
    OverrideObjName.ClearAllOverrideArgs();\
}\
inline SimpleOverride::ReturnProxy Internal_OverrideReturns(std::string functionName)\
{\
    return OverrideObjName.Internal_OverrideReturns(functionName);\
}\
inline void Internal_ClearOverrideReturns(std::string functionName)\
{\
    OverrideObjName.Internal_ClearOverrideReturns(functionName);\
}\
inline void ClearAllOverrideReturns()\
{\
    OverrideObjName.ClearAllOverrideReturns();\
}

const SimpleOverride::Any SO_ANY;
const SimpleOverride::Any SO_DONT_SET;

template<typename T>
using SO_NonCopyable = SimpleOverride::NonCopyable<T>;
    
template<typename T>
using SO_NonComparable = SimpleOverride::NonComparable<T>;

template<typename T>
using SO_NonComparableCopyable = SimpleOverride::NonComparableCopyable<T>;

#endif
