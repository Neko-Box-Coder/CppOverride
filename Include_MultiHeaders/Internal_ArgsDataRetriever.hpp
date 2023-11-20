#ifndef CO_INTERNAL_ARGS_DATA_RETRIEVER_HPP
#define CO_INTERNAL_ARGS_DATA_RETRIEVER_HPP

#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_OverrideArgsDataList.hpp"
#include "./Internal_ArgsTypesChecker.hpp"
#include "./Internal_ArgsValuesChecker.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataRetriever
    {
        public:
            using OverrideArgsDataType = std::unordered_map<std::string, Internal_OverrideArgsDataList>;
        
        protected:
            OverrideArgsDataType& OverrideArgsDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
            
            #define CO_LOG_GetCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline int GetCorrectArgumentsDataInfo(std::string functionName, Args&... args)
            {
                if(OverrideArgsDatas.find(functionName) == OverrideArgsDatas.end())
                {
                    std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                    assert(false);
                    exit(1);
                }
                
                #if CO_LOG_GetCorrectArgumentsDataInfo
                    std::cout <<"GetCorrectArgumentsDataInfo called\n";
                #endif
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> deRefArgumentsList;
                ArgsTypeInfoAppender.AppendArgsPureTypeInfo(deRefArgumentsList, args...);
                
                std::vector<Internal_OverrideArgsData>& curArgData = 
                    OverrideArgsDatas[functionName].ArgumentsDatas;
                
                int returnIndex = -1;
                for(int i = 0; i < curArgData.size(); i++)
                {
                    #if CO_LOG_GetCorrectArgumentsDataInfo
                        std::cout << "Checking arg data["<<i<<"]\n";
                    #endif
                    
                    //Check override argument data types match
                    int argumentTypeFailedIndex = -1;
                    
                    if( curArgData[i].ArgumentsDataActionInfo.DataActionSet && 
                        curArgData[i].ArgumentsDataActionInfo.DataTypes.size() == 
                            deRefArgumentsList.size())
                    {
                        std::vector<std::size_t>& argTypeHashes = 
                            curArgData[i].ArgumentsDataActionInfo.DataTypes;
                        
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
                    else if(curArgData[i].ArgumentsDataInfo.size() == deRefArgumentsList.size())
                    {
                        for(int j = 0; j < curArgData[i].ArgumentsDataInfo.size(); j++)
                        {
                            bool overrideArg =  curArgData[i].ArgumentsDataInfo[j].DataSet;

                            if( overrideArg && 
                                curArgData[i].ArgumentsDataInfo[j].DataType != 
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
                    if( !curArgData[i].ArgumentsConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curArgData[i]   .ArgumentsConditionInfo
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
                    if( !curArgData[i].ArgumentsConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curArgData[i]   .ArgumentsConditionInfo
                                                                                .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check parameter value\n";
                        #endif
                        
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check condition lambda
                    if( curArgData[i].ArgumentsConditionInfo.DataConditionSet && 
                        !curArgData[i].ArgumentsConditionInfo.DataCondition(argumentsList))
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check condition\n";
                        #endif
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curArgData[i].ArgumentsConditionInfo.Times >= 0 && 
                        curArgData[i].ArgumentsConditionInfo.CalledTimes >= 
                            curArgData[i].ArgumentsConditionInfo.Times)
                    {
                        #if CO_LOG_GetCorrectArgumentsDataInfo
                            std::cout << "Failed at Check times\n";
                        #endif
                        if(curArgData[i].ArgumentsActionInfo.OtherwiseActionSet)
                            curArgData[i].ArgumentsActionInfo.OtherwiseAction(argumentsList);
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
            Internal_ArgsDataRetriever( OverrideArgsDataType& overrideArgumentsInfos,
                                        Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender,
                                        Internal_ArgsTypesChecker& argsTypesChecker,
                                        Internal_ArgsValuesChecker& argsValuesChecker) : 
                                                OverrideArgsDatas(overrideArgumentsInfos),
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender),
                                                ArgsTypesChecker(argsTypesChecker),
                                                ArgsValuesChecker(argsValuesChecker)
            {}
    };

}

#endif