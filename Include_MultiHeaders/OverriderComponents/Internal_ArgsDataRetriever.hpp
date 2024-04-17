#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP

#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ConditionArgsTypesChecker.hpp"
#include "./Internal_ConditionArgsValuesChecker.hpp"
#include "./OverrideStatus.hpp"
#include "./Internal_OverrideData.hpp"
#include "../AliasTypes.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataRetriever
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
            
            #define INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline int GetCorrectArgumentsDataInfo( std::string functionName, 
                                                    OverrideStatus& status,
                                                    Args&... args)
            {
                if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
                {
                    //NOTE: This should be checked before calling this
                    status = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> argumentsTypesList;
                ArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
                std::vector<Internal_OverrideData>& curData = CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curData.size(); i++)
                {
                    if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        std::cout << "Checking arg data[" << i << "]\n";
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curData[i].ArgumentsDataActionInfo.DataActionSet && 
                        !argumentsTypesList.empty() &&
                        curData[i].ArgumentsDataActionInfo.DataTypes.size() == 
                            argumentsTypesList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curData[i].ArgumentsDataActionInfo.DataTypes;
                        
                        std::vector<bool>& argsTypesSet = 
                            curData[i].ArgumentsDataActionInfo.DataTypesSet;
                        
                        for(int j = 0; j < argTypeHashes.size(); j++)
                        {
                            if( argsTypesSet[j] &&
                                argTypeHashes[j] != argumentsTypesList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout <<    "argTypeHashes[" << j << "]: " << 
                                                    argTypeHashes[j] << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    argumentsTypesList[j].ArgTypeHash << std::endl;
                                }
                                
                                break;
                            }
                        }
                    }
                    //Check set argument data counts match
                    else if(curData[i].ArgumentsDataInfo.size() == argumentsTypesList.size() &&
                            !argumentsTypesList.empty())
                    {
                        for(int j = 0; j < curData[i].ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curData[i].ArgumentsDataInfo[j].DataSet;

                            if( overrideArg && 
                                curData[i].ArgumentsDataInfo[j].DataType != 
                                    argumentsTypesList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout << "Failed at checking argument data type" << std::endl;
                                    std::cout <<    "curData[i].ArgumentsDataInfo[" << j << "]: " << 
                                                    curData[i].ArgumentsDataInfo[j].DataType << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    argumentsTypesList[j].ArgTypeHash << std::endl;
                                }
                                
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check set argument data exist" << std::endl;
                        
                        continue;
                    }
                    
                    if(argumentTypeFailedIndex >= 0)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        {
                            std::cout <<    "Failed at Check set argument data types at index " <<
                                            argumentTypeFailedIndex << std::endl;
                        }
                        
                        continue;
                    }
                    
                    //Check parameter condition types/count match
                    if( !curData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curData[i]  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter type" << std::endl;
                        
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curData[i]  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                status,
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter value" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                        {
                            *curData[i].Status = 
                                OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curData[i].ConditionInfo.DataConditionSet && 
                        !curData[i].ConditionInfo.LambdaCondition(argumentsList))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check condition" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                        {
                            *curData[i].Status = 
                                OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curData[i].ConditionInfo.Times >= 0 && 
                        curData[i].ConditionInfo.CalledTimes >= 
                            curData[i].ConditionInfo.Times)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check times" << std::endl;
                        
                        if(curData[i].Status != nullptr)
                        {
                            *curData[i].Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        continue;
                    }
                    
                    if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        std::cout << "Argument data found: " << i << std::endl;
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        
        public:
            Internal_ArgsDataRetriever( OverrideDatas& overrideArgumentsInfos,
                                        Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender,
                                        Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                        Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                                                CurrentOverrideDatas(overrideArgumentsInfos),
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif