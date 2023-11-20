#ifndef CO_INTERNAL_RETURN_DATA_RETRIEVER_HPP
#define CO_INTERNAL_RETURN_DATA_RETRIEVER_HPP

#include "./Internal_OverrideReturnDataList.hpp"
#include "./PureType.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ArgsTypesChecker.hpp"
#include "./Internal_ArgsValuesChecker.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ReturnDataRetriever
    {
        public:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;

        protected:
            ReturnInfosType& OverrideReturnInfos;
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypesChecker& ArgsTypesChecker;
            Internal_ArgsValuesChecker& ArgsValuesChecker;
        
            #define CO_LOG_GetCorrectReturnDataInfo 0

            template<typename T, typename... Args>
            inline int GetCorrectReturnDataInfo(T& returnRef, std::string functionName, Args&... args)
            {
                if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
                {
                    std::cout << "[ERROR] This should be checked before calling this" << std::endl;
                    assert(false);
                    exit(1);
                }
                
                #if CO_LOG_GetCorrectReturnDataInfo
                    std::cout <<"GetCorrectReturnDataInfo called\n";
                #endif

                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<Internal_OverrideReturnData>& curReturnDatas = 
                    OverrideReturnInfos[functionName].ReturnDatas;
                
                int returnIndex = -1;
                for(int i = 0; i < curReturnDatas.size(); i++)
                {
                    #if CO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Checking return data["<<i<<"]\n";
                    #endif

                    //Check override return data exist
                    if( curReturnDatas[i].ReturnDataInfo.DataSet ||
                        curReturnDatas[i].ReturnDataInfo.DataActionSet)
                    {
                        //Check return type match
                        if(curReturnDatas[i].ReturnDataInfo.DataType != 
                            typeid(INTERNAL_CO_NON_CONST_T).hash_code())
                        {
                            #if CO_LOG_GetCorrectReturnDataInfo
                                std::cout << "Failed at return type\n";
                            #endif
                            
                            continue;
                        }
                    }
                    else
                        continue;
                    
                    //Check parameter condition types/count match
                    if( !curReturnDatas[i].ReturnConditionInfo.ArgsCondition.empty() && 
                        !ArgsTypesChecker.CheckArgumentsTypes(  curReturnDatas[i]   .ReturnConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check parameter\n";
                        #endif
                        continue;
                    }
                    
                    
                    //Check parameter values
                    if( !curReturnDatas[i].ReturnConditionInfo.ArgsCondition.empty() && 
                        !ArgsValuesChecker.CheckArgumentsValues(curReturnDatas[i]   .ReturnConditionInfo
                                                                                    .ArgsCondition, 
                                                                0, 
                                                                args...))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check parameter\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    
                    //Check condition lambda
                    if( curReturnDatas[i].ReturnConditionInfo.DataConditionSet && 
                        !curReturnDatas[i].ReturnConditionInfo.DataCondition(argumentsList))
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check condition\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);
                        
                        continue;
                    }
                    
                    //Check times
                    if( curReturnDatas[i].ReturnConditionInfo.Times >= 0 && 
                        curReturnDatas[i].ReturnConditionInfo.CalledTimes >= 
                            curReturnDatas[i].ReturnConditionInfo.Times)
                    {
                        #if CO_LOG_GetCorrectReturnDataInfo
                            std::cout << "Failed at Check times\n";
                        #endif
                        if(curReturnDatas[i].ReturnActionInfo.OtherwiseActionSet)
                            curReturnDatas[i].ReturnActionInfo.OtherwiseAction(argumentsList);

                        continue;
                    }
                    
                    #if CO_LOG_GetCorrectReturnDataInfo
                        std::cout << "Return data found: "<<i<<"\n";
                    #endif
                    returnIndex = i;
                    break;
                }
                
                //NOTE: We don't need to deallocate argumentsList and derefArgumentsList 
                //  because they are just pointers to arg values and type info from the caller
                return returnIndex;
            }
        public:
            inline Internal_ReturnDataRetriever(ReturnInfosType& overrideReturnInfos,
                                                Internal_ArgsValuesAppender& argsValuesAppender,
                                                Internal_ArgsTypesChecker& argsTypesChecker,
                                                Internal_ArgsValuesChecker& argsValuesChecker) : 
                OverrideReturnInfos(overrideReturnInfos),
                ArgsValuesAppender(argsValuesAppender),
                ArgsTypesChecker(argsTypesChecker),
                ArgsValuesChecker(argsValuesChecker)
            {}
    };
}

#endif