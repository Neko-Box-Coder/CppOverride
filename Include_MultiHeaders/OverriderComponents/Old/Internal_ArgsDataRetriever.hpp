#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP

#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ConditionArgsTypesChecker.hpp"
#include "./Internal_ConditionArgsValuesChecker.hpp"
#include "../OverrideStatus.hpp"
#include "../Internal_OverrideData.hpp"
#include "../AliasTypes.hpp"
#include "../Internal_DataInfo.hpp"

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
                                                    OverrideStatus& outInternalStatus,
                                                    Args&... args)
            {
                if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
                {
                    //NOTE: This should be checked before calling this
                    outInternalStatus = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_DataInfo> argumentsTypesList;
                ArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
                std::vector<Internal_OverrideData>& curData = CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curData.size(); i++)
                {
                    if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                        std::cout << "Checking arg data[" << i << "]\n";
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curData.at(i).ArgumentsDataActionInfo.DataActionSet && 
                        !argumentsTypesList.empty() &&
                        curData.at(i).ArgumentsDataActionInfo.DataTypes.size() == 
                            argumentsTypesList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curData.at(i).ArgumentsDataActionInfo.DataTypes;
                        
                        std::vector<bool>& argsTypesSet = 
                            curData.at(i).ArgumentsDataActionInfo.DataTypesSet;
                        
                        for(int j = 0; j < argTypeHashes.size(); j++)
                        {
                            if( argsTypesSet.at(j) &&
                                argTypeHashes.at(j) != argumentsTypesList.at(j).DataType)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout <<    "argTypeHashes[" << j << "]: " << 
                                                    argTypeHashes.at(j) << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].DataType: " <<
                                                    argumentsTypesList.at(j).DataType << std::endl;
                                }
                                
                                break;
                            }
                        }
                    }
                    //Check set argument data counts match
                    else if(curData.at(i).ArgumentsDataInfo.size() == argumentsTypesList.size() &&
                            !argumentsTypesList.empty())
                    {
                        for(int j = 0; j < curData.at(i).ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curData.at(i).ArgumentsDataInfo.at(j).DataSet;

                            if( overrideArg && 
                                curData.at(i).ArgumentsDataInfo.at(j).DataType != 
                                    argumentsTypesList.at(j).DataType)
                            {
                                argumentTypeFailedIndex = j;
                                
                                if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                                {
                                    std::cout << "Failed at checking argument data type" << std::endl;
                                    std::cout <<    "curData.at(i).ArgumentsDataInfo[" << j << "]: " << 
                                                    curData.at(i).ArgumentsDataInfo.at(j).DataType << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].DataType: " <<
                                                    argumentsTypesList.at(j).DataType << std::endl;
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
                    if( !curData.at(i).ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curData.at(i)  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter type" << std::endl;
                        
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curData.at(i).ConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curData.at(i)  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                outInternalStatus,
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check parameter value" << std::endl;
                        
                        if(curData.at(i).Status != nullptr)
                            *curData.at(i).Status = OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        
                        if(curData.at(i).ResultActionInfo.OtherwiseActionSet)
                            curData.at(i).ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curData.at(i).ConditionInfo.DataConditionSet && 
                        !curData.at(i).ConditionInfo.LambdaCondition(argumentsList))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check condition" << std::endl;
                        
                        if(curData.at(i).Status != nullptr)
                            *curData.at(i).Status = OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                        
                        if(curData.at(i).ResultActionInfo.OtherwiseActionSet)
                            curData.at(i).ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curData.at(i).ConditionInfo.Times >= 0 && 
                        curData.at(i).ConditionInfo.CalledTimes >= 
                            curData.at(i).ConditionInfo.Times)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectArgumentsDataInfo)
                            std::cout << "Failed at Check times" << std::endl;
                        
                        if(curData.at(i).Status != nullptr)
                        {
                            *curData.at(i).Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curData.at(i).ResultActionInfo.OtherwiseActionSet)
                            curData.at(i).ResultActionInfo.OtherwiseAction(argumentsList);
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
