#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_RETRIEVER_HPP

//#include "./Internal_OverrideReturnDataList.hpp"
#include "./PureType.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ArgsTypesChecker.hpp"
#include "./Internal_ArgsValuesChecker.hpp"
#include "./TypeCheck.hpp"
#include "./OverrideStatus.hpp"
#include "./Internal_OverrideData.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataRetriever
    {
        protected:
            using OverrideDataLists = std::unordered_map<std::string, Internal_OverrideDataList>;
            OverrideDataLists& CurrentOverrideDataLists;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
        
            #define CO_LOG_GetCorrectReturnDataInfo 0

            template<   typename T, 
                        typename... Args>
            inline int GetCorrectReturnDataInfo(T& returnRef, 
                                                std::string functionName, 
                                                OverrideStatus& status,
                                                Args&... args)
            {
                if(CurrentOverrideDataLists.find(functionName) == CurrentOverrideDataLists.end())
                {
                    //NOTE: This should be checked before calling this
                    status = OverrideStatus::INTERNAL_MISSING_CHECK_ERROR;
                    return -1;
                }
                
                if(CO_LOG_GetCorrectReturnDataInfo)
                    std::cout <<"GetCorrectReturnDataInfo called\n";

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_OverrideData>& curOverrideData = 
                    CurrentOverrideDataLists[functionName];
                
                int returnIndex = -1;
                for(int i = 0; i < curOverrideData.size(); i++)
                {
                    if(CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Checking return data["<<i<<"]\n";

                    //Check override return data exist
                    if( curOverrideData[i].ReturnDataInfo.DataSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataInfo.DataType != 
                            typeid(INTERNAL_CO_NON_CONST_T).hash_code())
                        {
                            if(CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type\n";
                            
                            continue;
                        }
                    }
                    else if(curOverrideData[i].ReturnDataActionInfo.DataActionSet)
                    {
                        //Check return type match
                        if( curOverrideData[i].ReturnDataActionInfo.DataType != 
                            typeid(INTERNAL_CO_NON_CONST_T).hash_code())
                        {
                            if(CO_LOG_GetCorrectReturnDataInfo)
                                std::cout << "Failed at return type\n";
                            
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
                        if(CO_LOG_GetCorrectReturnDataInfo)
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
                        if(CO_LOG_GetCorrectReturnDataInfo)
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
                        !curOverrideData[i].ConditionInfo.DataCondition(argumentsList))
                    {
                        if(CO_LOG_GetCorrectReturnDataInfo)
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
                        if(CO_LOG_GetCorrectReturnDataInfo)
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
                    
                    if(CO_LOG_GetCorrectReturnDataInfo)
                        std::cout << "Return data found: "<<i<<"\n";
                    
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        public:
            inline Internal_ReturnDataRetriever(OverrideDataLists& overrideDataLists,
                                                Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ArgsTypesChecker& argsTypesChecker,
                                                Internal_ArgsValuesChecker& argsValuesChecker) : 
                CurrentOverrideDataLists(overrideDataLists),
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif