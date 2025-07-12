#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

#include "./OverrideInfoSetterDeclaration.hpp"
#include "./Any.hpp"
#include "./OverriderComponents/ReturnDataSetter.hpp"
#include "./OverriderComponents/ArgsDataSetter.hpp"
#include "./OverriderComponents/RequirementSetter.hpp"
#include "./OverriderComponents/ArgsValuesAppender.hpp"
#include "./OverriderComponents/ArgsTypeInfoAppender.hpp"
#include "./OverriderComponents/ConditionArgsTypesChecker.hpp"
#include "./OverriderComponents/ConditionArgsValuesChecker.hpp"
#include "./OverriderComponents/ArgsModifier.hpp"

#include "./OverriderComponents/ReturnDataValidator.hpp"
#include "./OverriderComponents/ArgsDataValidator.hpp"
#include "./OverriderComponents/RequirementValidator.hpp"

#include "./OverrideData.hpp"
#include "./OverrideStatus.hpp"
#include "./EarlyReturn.hpp"
#include "./DataInfo.hpp"
#include "./TypedDataInfo.hpp"
#include "./TypedInfo.hpp"

#include <string>
#include <unordered_map>

namespace CppOverride
{
    inline std::string ProcessFunctionName(const std::string& functionName)
    {
        std::string processedName;
        
        for(int i = 0; i < functionName.size(); ++i)
        {
            if(functionName[i] == '<')
                break;
            else if(functionName[i] != ' ')
                processedName += functionName[i];
        }
        
        return processedName;
    }
    
    struct Overrider
    {
        OverrideDatas CurrentOverrideDatas;
        
        ReturnDataSetter CurrentReturnDataSetter;
        ArgsDataSetter CurrentArgsDataSetter;
        RequirementSetter CurrentRequirementSetter;
        ArgsValuesAppender CurrentArgsValuesAppender;
        ArgsTypeInfoAppender CurrentArgsTypeInfoAppender;
        ConditionArgsTypesChecker CurrentConditionArgsTypesChecker;
        ConditionArgsValuesChecker CurrentConditionArgsValuesChecker;
        ArgsModifier CurrentArgsModifier;
        ReturnDataValidator CurrentReturnDataValidator;
        ArgsDataValidator CurrentArgsDataValidator;
        RequirementValidator CurrentRequirementValidator;
        
        OverrideData PassthroughData;
        std::vector<std::string> UnexpectedPassthroughFunctions;

        //==============================================================================
        //Public facing methods for overriding returns or arguments
        //==============================================================================
        inline Overrider(const Overrider& other) :
            CurrentOverrideDatas(),
            CurrentReturnDataSetter(CurrentOverrideDatas),
            CurrentArgsDataSetter(CurrentOverrideDatas),
            CurrentRequirementSetter(CurrentOverrideDatas),
            CurrentArgsValuesAppender(),
            CurrentArgsTypeInfoAppender(),
            CurrentConditionArgsTypesChecker(),
            CurrentConditionArgsValuesChecker(),
            CurrentArgsModifier(),
            CurrentReturnDataValidator(CurrentArgsValuesAppender),
            CurrentArgsDataValidator(CurrentArgsValuesAppender, CurrentArgsTypeInfoAppender),
            CurrentRequirementValidator(CurrentArgsValuesAppender, 
                                        CurrentConditionArgsTypesChecker, 
                                        CurrentConditionArgsValuesChecker),
            PassthroughData(other.PassthroughData),
            UnexpectedPassthroughFunctions(other.UnexpectedPassthroughFunctions)
        {
            *this = other;
        }
        
        inline Overrider& operator=(const Overrider& other)
        {
            if(this == &other)
                return *this;
        
            CurrentOverrideDatas = other.CurrentOverrideDatas;
            return *this;
        }
            
        inline Overrider() :    CurrentOverrideDatas(),
                                CurrentReturnDataSetter(CurrentOverrideDatas),
                                CurrentArgsDataSetter(CurrentOverrideDatas),
                                CurrentRequirementSetter(CurrentOverrideDatas),
                                CurrentArgsValuesAppender(),
                                CurrentArgsTypeInfoAppender(),
                                CurrentConditionArgsTypesChecker(),
                                CurrentConditionArgsValuesChecker(),
                                CurrentArgsModifier(),
                                CurrentReturnDataValidator(CurrentArgsValuesAppender),
                                CurrentArgsDataValidator(   CurrentArgsValuesAppender, 
                                                            CurrentArgsTypeInfoAppender),
                                CurrentRequirementValidator(CurrentArgsValuesAppender, 
                                                            CurrentConditionArgsTypesChecker,
                                                            CurrentConditionArgsValuesChecker),
                                PassthroughData(OverrideData()),
                                UnexpectedPassthroughFunctions()
        {}
        
        inline ~Overrider()
        {}

        inline Overrider& Internal_GetOverrideObject()
        {
            return *this;
        }
        
        //------------------------------------------------------------------------------
        //Check overrides available
        //------------------------------------------------------------------------------
        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_CheckOverride 1
        #else
            #define INTERNAL_CO_LOG_CheckOverride 0
        #endif
        
        template<typename ReturnType, typename... Args>
        inline bool Internal_CheckOverride( std::string functionName, 
                                            int& outOverrideIndex,
                                            bool& outOverrideReturn,
                                            bool& outOverrideArgs,
                                            bool& outDontReturn,
                                            void* instance,
                                            Args&... args)
        {
            outOverrideIndex = -1;
            
            functionName = ProcessFunctionName(functionName);
            
            if(INTERNAL_CO_LOG_CheckOverride)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "functionName: "<< functionName << std::endl;
                std::cout << "functionName.size(): " << functionName.size() << std::endl;
            }
            
            if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
            {
                if(INTERNAL_CO_LOG_CheckOverride)
                    std::cout << functionName << " not found\n";
                
                return false;
            }
        
            std::vector<OverrideData>& currentDataList = CurrentOverrideDatas.at(functionName);
            
            outOverrideArgs = false;
            outOverrideReturn = false;
            outDontReturn = false;
            for(int i = 0; i < (int)currentDataList.size(); ++i)
            {
                //Match the correct instance if any
                if( currentDataList.at(i).Instance != nullptr && 
                    currentDataList.at(i).Instance != instance)
                {
                    continue;
                }
                
                if( !currentDataList.at(i).ArgumentsDataInfo.empty() ||
                    currentDataList.at(i).ArgumentsDataActionInfo.DataActionSet)
                {
                    if(!CurrentArgsDataValidator.IsCorrectArgumentsDataInfo(currentDataList.at(i), 
                                                                            args...))
                    {
                        if(INTERNAL_CO_LOG_CheckOverride)
                            std::cout << "Arguments not correct at index: " << i << std::endl;
                        
                        continue;
                    }
                    
                    outOverrideArgs = true;
                }

                if( currentDataList.at(i).CurrentReturnDataInfo.DataSet ||
                    currentDataList.at(i).CurrentReturnDataInfo.ReturnAny ||
                    currentDataList.at(i).CurrentReturnDataActionInfo.DataActionSet)
                {
                    if( !CurrentReturnDataValidator.IsCorrectReturnDataInfo<ReturnType>
                        (
                            currentDataList.at(i), 
                            args...
                        ))
                    {
                        if(INTERNAL_CO_LOG_CheckOverride)
                            std::cout << "Return not correct at index: " << i << std::endl;
                        
                        continue;
                    }
                    
                    outOverrideReturn = true;
                    
                    if(currentDataList.at(i).CurrentReturnDataInfo.ReturnAny)
                        outDontReturn = true;
                    else
                        outDontReturn = false;
                }

                OverrideStatus internalStatus = OverrideStatus::NO_OVERRIDE;
                if( !CurrentRequirementValidator.IsMeetingRequirementForDataInfo<ReturnType>
                    (
                        currentDataList.at(i), 
                        internalStatus, 
                        instance,
                        args...
                    ))
                {
                    //If something is wrong internally, notify everything
                    if(internalStatus != OverrideStatus::NO_OVERRIDE)
                    {
                        for(int j = 0; j < (int)currentDataList.size(); j++)
                        {
                            if(currentDataList.at(j).Result != nullptr)
                                currentDataList.at(j).Result->AddStatus(internalStatus);
                        }
                    }
                    
                    if(INTERNAL_CO_LOG_CheckOverride)
                        std::cout << "Requirement not correct at index: " << i << std::endl;
                    
                    outOverrideArgs = false;
                    outOverrideReturn = false;
                    outDontReturn = false;
                    continue;
                }

                outOverrideIndex = i;
                break;
            }
            
            
            if(INTERNAL_CO_LOG_CheckOverride)
                std::cout << "outOverrideIndex: " << outOverrideIndex << std::endl;
            
            return outOverrideIndex != -1;
        }

        template<typename... Args>
        inline void Internal_CallOverrideExpectedAction(std::string functionName,
                                                        int overrideIndex,
                                                        void* instance,
                                                        Args&... args)
        {
            functionName = ProcessFunctionName(functionName);
            
            OverrideData& correctData = CurrentOverrideDatas.at(functionName).at(overrideIndex);
            if(correctData.CurrentResultActionInfo.CorrectActionSet)
            {
                std::vector<TypedDataInfo> argumentsList;
                CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                correctData.CurrentResultActionInfo.CorrectAction(instance, argumentsList);
            }
            
            correctData.CurrentConditionInfo.CalledTimes++;
            if(correctData.Result != nullptr)
                correctData.Result->AddStatus(OverrideStatus::OVERRIDE_SUCCESS);
        }
        
        template<typename... Args>
        inline void Internal_CallOverrideUnexpectedAction(  std::string functionName,
                                                            int overrideIndex,
                                                            void* instance,
                                                            OverrideStatus unexpectedStatus,
                                                            Args&... args)
        {
            functionName = ProcessFunctionName(functionName);
            
            OverrideData& correctData = CurrentOverrideDatas.at(functionName).at(overrideIndex);
            if(correctData.CurrentResultActionInfo.OtherwiseActionSet)
            {
                std::vector<TypedDataInfo> argumentsList;
                CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                correctData.CurrentResultActionInfo.OtherwiseAction(instance, argumentsList);
            }
            
            correctData.CurrentConditionInfo.CalledTimes++;
            if(correctData.Result != nullptr)
                correctData.Result->AddStatus(unexpectedStatus);
        }
        
        inline void Internal_CallOverridePassthroughExpectedAction(const std::string& functionName)
        {
            PassthroughData.CurrentConditionInfo.CalledTimes++;
            if(PassthroughData.Expected == OverrideData::ExpectedType::TRIGGERED)
            {
                if( PassthroughData.CurrentConditionInfo.Times >= 0 && 
                    PassthroughData.CurrentConditionInfo.CalledTimes >
                    PassthroughData.CurrentConditionInfo.Times)
                {
                    UnexpectedPassthroughFunctions.emplace_back(functionName);
                }
            }
            else if(PassthroughData.Expected == OverrideData::ExpectedType::NOT_TRIGGERED)
            {
                if( PassthroughData.CurrentConditionInfo.Times == -1 && 
                    PassthroughData.CurrentConditionInfo.CalledTimes > 0)
                {
                    UnexpectedPassthroughFunctions.emplace_back(functionName);
                }
            }
        }

        //------------------------------------------------------------------------------
        //Overriding Returns
        //------------------------------------------------------------------------------

        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_CheckOverrideAndReturn 1
        #else
            #define INTERNAL_CO_LOG_CheckOverrideAndReturn 0
        #endif

        template
        <
            typename ReturnType, 
            typename std::enable_if<std::is_same<ReturnType, void>::value, bool>::type = true,
            typename... Args
        >
        inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                    std::string functionName, 
                                                    void* instance,
                                                    Args&... args)
        {
            functionName = ProcessFunctionName(functionName);
            std::vector<OverrideData>& currentDataList = CurrentOverrideDatas.at(functionName);
            std::vector<TypedDataInfo> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            OverrideData& correctData = currentDataList.at(dataIndex);
            if(correctData.CurrentReturnDataActionInfo.DataActionSet)
            {
                TypedInfo returnTypeInfo = TypedInfo().Create<ReturnType>();
                correctData.CurrentReturnDataActionInfo.DataAction( instance, 
                                                                    argumentsList, 
                                                                    returnTypeInfo);
            }
            Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
            return ReturnType();
        }

        template
        <
            typename ReturnType, 
            typename std::enable_if<!std::is_same<ReturnType, void>::value, bool>::type = true,
            typename... Args
        >
        inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                    std::string functionName, 
                                                    void* instance, 
                                                    Args&... args)
        {
            functionName = ProcessFunctionName(functionName);
            
            if(INTERNAL_CO_LOG_CheckOverrideAndReturn)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "functionName: " << functionName << std::endl;
                std::cout << "functionName.size(): " << functionName.size() << std::endl;
            }
            
            std::vector<OverrideData>& currentDataList = CurrentOverrideDatas.at(functionName);
            std::vector<TypedDataInfo> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            OverrideData& correctData = currentDataList.at(dataIndex);
            
            if(correctData.CurrentReturnDataInfo.DataSet)
            {
                Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
                return  *static_cast<INTERNAL_CO_UNREF(ReturnType)*>
                        (
                            correctData.CurrentReturnDataInfo.Data.get()
                        );
            }
            else if(correctData.CurrentReturnDataActionInfo.DataActionSet)
            {
                TypedInfo returnTypeInfo = TypedInfo().Create<ReturnType>();
                TypedDataInfo returnDataInfo = 
                    correctData.CurrentReturnDataActionInfo.DataAction( instance, 
                                                                        argumentsList, 
                                                                        returnTypeInfo);
                if(returnDataInfo.IsType<ReturnType>())
                {
                    Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
                    return *returnDataInfo.GetTypedDataPtr<ReturnType>();
                }
                else
                {
                    Internal_CallOverrideUnexpectedAction(  functionName, 
                                                            dataIndex, 
                                                            instance, 
                                                            OverrideStatus::RETURN_ACTION_TYPE_MISMATCH,
                                                            args...);
                }
            }
            
            //return ReturnType();
            return EarlyReturn<ReturnType>();
        }

        //------------------------------------------------------------------------------
        //Overriding Arguments
        //------------------------------------------------------------------------------
        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_CheckOverrideAndSetArgs 1
        #else
            #define INTERNAL_CO_LOG_CheckOverrideAndSetArgs 0
        #endif

        template<typename... Args>
        inline bool Internal_OverrideArgs(  int dataIndex,
                                            std::string functionName, 
                                            bool noOverrideAfterThis,
                                            void* instance,
                                            Args&... args)
        {
            functionName = ProcessFunctionName(functionName);
            
            if(INTERNAL_CO_LOG_CheckOverrideAndSetArgs)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "functionName: "<<functionName << std::endl;
            }
            
            std::vector<OverrideData>& currentDataList = CurrentOverrideDatas.at(functionName);
            std::vector<TypedDataInfo> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            
            OverrideData& correctData = currentDataList.at(dataIndex);
            OverrideStatus overrideStatus = OverrideStatus::OVERRIDE_SUCCESS;
            
            if(correctData.ArgumentsDataActionInfo.DataActionSet)
            {
                CurrentArgsModifier.ModifyArgs( instance, 
                                                argumentsList, 
                                                correctData.ArgumentsDataActionInfo);
            }
            else
            {
                CurrentArgsModifier.ModifyArgs( correctData.ArgumentsDataInfo, 
                                                0, 
                                                &overrideStatus, 
                                                args...);
            }
            
            if(correctData.Result != nullptr)
                correctData.Result->AddStatus(overrideStatus);
            
            if(noOverrideAfterThis && overrideStatus == OverrideStatus::OVERRIDE_SUCCESS)
            {
                Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
                return true;
            }
            
            //If this override fails, notify caller to not perform any more overrides
            if(overrideStatus != OverrideStatus::OVERRIDE_SUCCESS)
            {
                Internal_CallOverrideUnexpectedAction(  functionName, 
                                                        dataIndex, 
                                                        instance, 
                                                        overrideStatus,
                                                        args...);
                return false;
            }
            return true;
        }
        
        //------------------------------------------------------------------------------
        //Modify override info
        //------------------------------------------------------------------------------
        
        #if CO_SHOW_OVERRIDE_LOG
            #define INTERNAL_CO_LOG_OverrideCreation 1
        #else
            #define INTERNAL_CO_LOG_OverrideCreation 0
        #endif

        inline OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName)
        {
            functionName = ProcessFunctionName(functionName);
            
            if(INTERNAL_CO_LOG_OverrideCreation)
            {
                std::cout << std::endl << __func__ << " called" << std::endl;
                std::cout << "functionName: " << functionName << std::endl;
                std::cout << "functionName.size(): " << functionName.size() << std::endl;
            }

            CurrentOverrideDatas[functionName].push_back(OverrideData());
            return OverrideInfoSetter(functionName, *this);
        }
        
        inline void Internal_RemoveOverrideInfo(std::string functionName)
        {
            functionName = ProcessFunctionName(functionName);
            if(CurrentOverrideDatas.find(functionName) != CurrentOverrideDatas.end())
                CurrentOverrideDatas.erase(functionName);
        }
        
        inline OverridePassthroughInfoSetter Internal_CreateOverridePassthroughInfo()
        {
            return OverridePassthroughInfoSetter(*this);
        }
        
        inline void Internal_ResetPassthroughOverrideData()
        {
            PassthroughData = OverrideData();
            UnexpectedPassthroughFunctions.clear();
        }
        
        inline void Internal_ClearAllOverrideInfo()
        {
            CurrentOverrideDatas.clear();
            Internal_ResetPassthroughOverrideData();
        }
        
        inline std::vector<FunctionName> Internal_GetFailedExpects()
        {
            std::vector<FunctionName> failedFunctions;
            for(auto it = CurrentOverrideDatas.begin(); it != CurrentOverrideDatas.end(); ++it)
            {
                for(int i = 0; i < it->second.size(); ++i)
                {
                    if( it->second[i].Expected == OverrideData::ExpectedType::TRIGGERED && 
                        it->second[i].Result)
                    {
                        if( it->second[i].CurrentConditionInfo.Times >= 0 && 
                            it->second[i].CurrentConditionInfo.CalledTimes != 
                            it->second[i].CurrentConditionInfo.Times)
                        {
                            failedFunctions.push_back(it->first);
                            break;
                        }
                        
                        if( it->second[i].CurrentConditionInfo.Times == -1 && 
                            it->second[i].CurrentConditionInfo.CalledTimes == 0)
                        {
                            failedFunctions.push_back(it->first);
                            break;
                        }
                    }
                    else if(it->second[i].Expected == OverrideData::ExpectedType::NOT_TRIGGERED && 
                            it->second[i].Result)
                    {
                        if( it->second[i].CurrentConditionInfo.Times >= 0 && 
                            it->second[i].CurrentConditionInfo.CalledTimes == 
                            it->second[i].CurrentConditionInfo.Times)
                        {
                            failedFunctions.push_back(it->first);
                            break;
                        }
                        
                        if( it->second[i].CurrentConditionInfo.Times == -1 && 
                            it->second[i].CurrentConditionInfo.CalledTimes > 0)
                        {
                            failedFunctions.push_back(it->first);
                            break;
                        }
                    }
                }
            }
            
            if(PassthroughData.Expected == OverrideData::ExpectedType::TRIGGERED)
            {
                if( PassthroughData.CurrentConditionInfo.Times >= 0 && 
                    PassthroughData.CurrentConditionInfo.CalledTimes != 
                    PassthroughData.CurrentConditionInfo.Times)
                {
                    #if 0
                    const std::string msg = 
                        std::string("Passthrough failed to reach times as instructed, ") +
                        "Instructed Times: " + std::to_string(PassthroughData   .CurrentConditionInfo
                                                                                .Times) + ", " +
                        "Called Times: " + std::to_string(PassthroughData   .CurrentConditionInfo
                                                                            .CalledTimes);
                    failedFunctions.emplace_back(msg);
                    #endif
                    failedFunctions.emplace_back("Passthrough");
                }
                else if(PassthroughData.CurrentConditionInfo.Times == -1 && 
                        PassthroughData.CurrentConditionInfo.CalledTimes == 0)
                {
                    #if 0
                    failedFunctions.emplace_back(   "Passthrough function expected to be called at "
                                                    "least once");
                    #endif
                    failedFunctions.emplace_back("Passthrough");
                }
            }
            else if(PassthroughData.Expected == OverrideData::ExpectedType::NOT_TRIGGERED)
            {
                if( PassthroughData.CurrentConditionInfo.Times >= 0 && 
                    PassthroughData.CurrentConditionInfo.CalledTimes == 
                    PassthroughData.CurrentConditionInfo.Times)
                {
                    #if 0
                    const std::string msg = 
                        std::string("Passthrough failed to not reach times as instructed, ") +
                        "Instructed Times: " + std::to_string(PassthroughData   .CurrentConditionInfo
                                                                                .Times) + ", " +
                        "Called Times: " + std::to_string(PassthroughData   .CurrentConditionInfo
                                                                            .CalledTimes);
                    failedFunctions.emplace_back(msg);
                    #endif
                    failedFunctions.emplace_back("Passthrough");
                }
                else if(PassthroughData.CurrentConditionInfo.Times == -1 && 
                        PassthroughData.CurrentConditionInfo.CalledTimes > 0)
                {
                    #if 0
                    failedFunctions.emplace_back("Passthrough function expected not to be called");
                    #endif
                }
            }
            
            for(int i = 0; i < UnexpectedPassthroughFunctions.size(); ++i)
                failedFunctions.emplace_back(UnexpectedPassthroughFunctions[i] + " (Passthrough)");
            
            return failedFunctions;
        }
        
        inline std::vector<ResultPtr> 
        Internal_GetOverrideResults(const std::string& functionName)
        {
            std::vector<ResultPtr> results;
            if(CurrentOverrideDatas.find(functionName) != CurrentOverrideDatas.end())
            {
                const std::vector<OverrideData>& overrideData = CurrentOverrideDatas.at(functionName);
                for(int i = 0; i < overrideData.size(); ++i)
                    results.push_back(overrideData[i].Result);
            }
            
            return results;
        }
    };
}

#endif
