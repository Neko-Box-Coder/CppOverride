#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP

#include "../PureType.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ConditionArgsTypesChecker.hpp"
#include "./Internal_ConditionArgsValuesChecker.hpp"
#include "../TypeCheck.hpp"
#include "../OverrideStatus.hpp"
#include "../Internal_OverrideData.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataRetriever
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ConditionArgsTypesChecker& ArgsTypesChecker;
            Internal_ConditionArgsValuesChecker& ArgsValuesChecker;
        
            #define INTERNAL_CO_LOG_GetCorrectReturnDataInfo 0

            template<   typename ReturnType, 
                        typename... Args>
            inline int GetCorrectReturnDataInfo(std::string functionName, 
                                                OverrideStatus& status,
                                                Args&... args)
            {
                if(CurrentOverrideDatas.find(functionName) == CurrentOverrideDatas.end())
                {
                    //NOTE: This should be checked before calling this
                    status = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_OverrideData>& curOverrideData = 
                    CurrentOverrideDatas[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curOverrideData.size(); i++)
                {
                    if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Checking return data["<<i<<"]\n";

                    //Check override return data exist
                    if(curOverrideData[i].ReturnDataInfo.DataSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataInfo.DataType != 
                            typeid(ReturnType).hash_code())
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type\n";
                            
                            continue;
                        }
                        
                        //If we need to return a reference, 
                        //  we check for pointer type as we can't store references
                        if( std::is_reference<ReturnType>() && 
                            !curOverrideData[i].ReturnDataInfo.ReturnReference)
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return reference\n";
                            
                            continue;
                        }
                    }
                    else if(curOverrideData[i].ReturnDataActionInfo.DataActionSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataActionInfo.DataType != 
                            typeid(ReturnType).hash_code())
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type\n";
                            
                            continue;
                        }
                        
                        //If we need to return a reference, 
                        //  we check for pointer type as we can't store references
                        if( std::is_reference<ReturnType>() && 
                            !curOverrideData[i].ReturnDataActionInfo.ReturnReference)
                        {
                            if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return action reference\n";
                            
                            continue;
                        }
                    }
                    else
                        continue;
                    
                    //Check parameter condition types/count match
                    if( !curOverrideData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curOverrideData[i]  .ConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check parameter\n";
                        
                        continue;
                    }
                    
                    //Check parameter values
                    if( !curOverrideData[i].ConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curOverrideData[i]  .ConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                status,
                                                                args...))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check parameter\n";
                        
                        if(curOverrideData.at(i).Status != nullptr)
                        {
                            *curOverrideData.at(i).Status = 
                                OverrideStatus::MATCHING_CONDITION_VALUE_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    
                    //Check condition lambda
                    if( curOverrideData[i].ConditionInfo.DataConditionSet && 
                        !curOverrideData[i].ConditionInfo.LambdaCondition(argumentsList))
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check condition\n";
                        
                        if(curOverrideData[i].Status != nullptr)
                        {
                            *curOverrideData[i].Status = 
                                OverrideStatus::MATCHING_CONDITION_ACTION_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curOverrideData[i].ConditionInfo.Times >= 0 && 
                        curOverrideData[i].ConditionInfo.CalledTimes >= 
                        curOverrideData[i].ConditionInfo.Times)
                    {
                        if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                            std::cout << "Failed at Check times\n";
                        
                        if(curOverrideData[i].Status != nullptr)
                        {
                            *curOverrideData[i].Status = 
                                OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED;
                        }
                        
                        if(curOverrideData[i].ResultActionInfo.OtherwiseActionSet)
                            curOverrideData[i].ResultActionInfo.OtherwiseAction(argumentsList);

                        continue;
                    }
                    
                    if(INTERNAL_CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Return data found: "<<i<<"\n";
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        public:
            inline Internal_ReturnDataRetriever(OverrideDatas& overrideDataLists,
                                                Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ConditionArgsTypesChecker& argsTypesChecker,
                                                Internal_ConditionArgsValuesChecker& argsValuesChecker) : 
                CurrentOverrideDatas(overrideDataLists),
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif