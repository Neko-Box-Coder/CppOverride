#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_RETRIEVER_HPP

#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ArgsTypesChecker.hpp"
#include "./Internal_ArgsValuesChecker.hpp"
#include "./OverrideStatus.hpp"
#include "./Internal_OverrideData.hpp"

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
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
            
            #define CO_LOG_GetCorrectArgumentsDataInfo 0

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
                
                #if CO_LOG_GetCorrectArgumentsDataInfo
                    std::cout <<"GetCorrectArgumentsDataInfo called\n";
                #endif
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> deRefArgumentsList;
                ArgsTypeInfoAppender.AppendArgsPureTypeInfo(deRefArgumentsList, args...);
                
                std::vector<Internal_OverrideData>& curData = CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curData.size(); i++)
                {
                    #if CO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Checking arg data["<<i<<"]\n";
                    #endif
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curData[i].ArgumentsDataActionInfo.DataActionSet && 
                        curData[i].ArgumentsDataActionInfo.DataTypes.size() == 
                            deRefArgumentsList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curData[i].ArgumentsDataActionInfo.DataTypes;
                        
                        for(int j = 0; j < argTypeHashes.size(); j++)
                        {
                            if(argTypeHashes.at(j) != deRefArgumentsList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                
                                #if CO_LOG_GetCorrectArgumentsDataInfo
                                    std::cout <<    "argTypeHashes.at(" << j << "): " << 
                                                    argTypeHashes.at(j) << std::endl;
                                    std::cout <<    "deRefArgumentsList[" << j << "].ArgTypeHash: " <<
                                                    deRefArgumentsList[j].ArgTypeHash << std::endl;
                                #endif
                                
                                break;
                            }
                        }
                    }
                    //Check set argument data counts match
                    else if(curData[i].ArgumentsDataInfo.size() == deRefArgumentsList.size())
                    {
                        for(int j = 0; j < curData[i].ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curData[i].ArgumentsDataInfo[j].DataSet;

                            if( overrideArg && 
                                curData[i].ArgumentsDataInfo[j].DataType != 
                                    deRefArgumentsList[j].ArgTypeHash)
                            {
                                argumentTypeFailedIndex = j;
                                break;
                            }
                        }
                    }
                    else
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check set argument data exist\n";
                        #endif
                        continue;
                    }
                    
                    if(argumentTypeFailedIndex >= 0)
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout <<    "Failed at Check set argument data types at index " <<
                                            argumentTypeFailedIndex << std::endl;
                        #endif
                        continue;
                    }
                    
                    //Check parameter condition types/count match
                    if( !curData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curData[i]  .ConditionInfo
                                                                            .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check parameter type\n";
                        #endif
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
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check parameter value\n";
                        #endif
                        
                        if(curData.at(i).Status != nullptr)
                        {
                            *curData.at(i).Status = 
                                OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curData[i].ConditionInfo.DataConditionSet && 
                        !curData[i].ConditionInfo.DataCondition(argumentsList))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check condition\n";
                        #endif
                        
                        if(curData.at(i).Status != nullptr)
                        {
                            *curData.at(i).Status = 
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
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check times\n";
                        #endif
                        
                        if(curData.at(i).Status != nullptr)
                        {
                            *curData.at(i).Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curData[i].ResultActionInfo.OtherwiseActionSet)
                            curData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        continue;
                    }
                    
                    #if CO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Argument data found: "<<i<<"\n";
                    #endif
                    
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
                                        Internal_ArgsTypesChecker& argsTypesChecker,
                                        Internal_ArgsValuesChecker& argsValuesChecker) : 
                                                CurrentOverrideDatas(overrideArgumentsInfos),
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif