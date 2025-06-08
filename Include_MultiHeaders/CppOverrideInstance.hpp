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
                                        CurrentConditionArgsValuesChecker)
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
                                                            CurrentConditionArgsValuesChecker)
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
                std::vector<void*> argumentsList;
                CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                correctData.CurrentResultActionInfo.CorrectAction(instance, argumentsList);
            }
            
            correctData.CurrentConditionInfo.CalledTimes++;
            if(correctData.Result != nullptr)
                correctData.Result->AddStatus(OverrideStatus::OVERRIDE_SUCCESS);
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
            Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
            return ReturnType();
        }

        template
        <
            typename ReturnType, 
            typename std::enable_if<!std::is_same<ReturnType, void>::value, bool>::type = true,
            typename std::enable_if<!std::is_reference<ReturnType>::value, bool>::type = true,
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
            std::vector<void*> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            
            OverrideData& correctData = currentDataList.at(dataIndex);
            Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
            
            if(correctData.CurrentReturnDataInfo.DataSet)
                return *static_cast<ReturnType*>(correctData.CurrentReturnDataInfo.Data.get());
            else if(correctData.CurrentReturnDataActionInfo.DataActionSet)
            {
                ReturnType returnRef;
                correctData.CurrentReturnDataActionInfo.DataAction( instance, 
                                                                    argumentsList, 
                                                                    &returnRef);
                return returnRef;
            }
            
            return ReturnType();
        }
        
        template
        <
            typename ReturnType, 
            typename std::enable_if<!std::is_same<ReturnType, void>::value, bool>::type = true,
            typename std::enable_if<std::is_reference<ReturnType>::value, bool>::type = true,
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
            std::vector<void*> argumentsList;
            CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
            
            OverrideData& correctData = currentDataList.at(dataIndex);
            Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);

            if(correctData.CurrentReturnDataInfo.DataSet)
            {
                return *reinterpret_cast<INTERNAL_CO_UNREF(ReturnType)*>
                (
                    correctData.CurrentReturnDataInfo.Data.get()
                );
            }
            else if(correctData.CurrentReturnDataActionInfo.DataActionSet)
            {
                INTERNAL_CO_UNREF(ReturnType)* returnRef;
                correctData.CurrentReturnDataActionInfo.DataAction( instance, 
                                                                    argumentsList, 
                                                                    &returnRef);
                return *returnRef;
            }
            
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
        inline void Internal_OverrideArgs(  int dataIndex,
                                            std::string functionName, 
                                            bool performResultAction,
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
            std::vector<void*> argumentsList;
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
            
            if(performResultAction && overrideStatus == OverrideStatus::OVERRIDE_SUCCESS)
                Internal_CallOverrideExpectedAction(functionName, dataIndex, instance, args...);
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
        
        inline void Internal_ClearAllOverrideInfo()
        {
            CurrentOverrideDatas.clear();
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
