#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

//#include "./Internal_OverrideReturnDataList.hpp"
//#include "./Internal_OverrideArgsData.hpp"
#include "./ProxiesDeclarations.hpp"
#include "./Any.hpp"
#include "./Internal_ReturnDataSetter.hpp"
#include "./Internal_ArgsDataSetter.hpp"
#include "./Internal_RequirementSetter.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsTypesChecker.hpp"
#include "./Internal_ArgsValuesChecker.hpp"
#include "./Internal_ArgsModifier.hpp"
#include "./Internal_ReturnDataRetriever.hpp"
#include "./Internal_ArgsDataRetriever.hpp"
#include "./OverrideStatus.hpp"

#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Overrider :   public Internal_ReturnDataSetter, 
                        public Internal_ArgsDataSetter,
                        public Internal_RequirementSetter,
                        public Internal_ArgsValuesAppender,
                        public Internal_ArgsTypeInfoAppender,
                        public Internal_ArgsTypesChecker,
                        public Internal_ArgsValuesChecker,
                        public Internal_ArgsModifier,
                        public Internal_ReturnDataRetriever,
                        public Internal_ArgsDataRetriever
    {
        private:
            std::unordered_map<std::string, Internal_OverrideReturnDataList> OverrideReturnInfos;
            std::unordered_map<std::string, Internal_OverrideArgsDataList> OverrideArgumentsInfos;

        //==============================================================================
        //Public facing methods for overriding returns or arguments
        //==============================================================================
        public:
            inline Overrider(const Overrider& other) :
                Internal_ReturnDataSetter(OverrideReturnInfos),
                Internal_ArgsDataSetter(OverrideArgumentsInfos),
                Internal_RequirementSetter( OverrideArgumentsInfos,
                                            OverrideReturnInfos),
                Internal_ReturnDataRetriever(OverrideReturnInfos, *this, *this, *this),
                Internal_ArgsDataRetriever(OverrideArgumentsInfos, *this, *this, *this, *this)
            {
                *this = other;
            }
            
            inline Overrider& operator=(const Overrider& other)
            {
                if(this == &other)
                    return *this;
            
                OverrideReturnInfos = other.OverrideReturnInfos;
                OverrideArgumentsInfos = other.OverrideArgumentsInfos;
            
                for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                    {
                        Internal_DataInfo& curReturnDataInfo = 
                            it->second.ReturnDatas[i].ReturnDataInfo;
                        
                        if(curReturnDataInfo.DataSet)
                        {
                            curReturnDataInfo.Data = 
                                curReturnDataInfo.CopyConstructor(curReturnDataInfo.Data);
                        }
                        
                        for(int j = 0; j < it   ->second
                                                .ReturnDatas[i]
                                                .ReturnConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgDataInfo = it->second
                                                        .ReturnDatas[i]
                                                        .ReturnConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgDataInfo.ArgSet)
                            {
                                curArgDataInfo.ArgDataPointer = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.ArgDataPointer);
                            }
                        }
                    }
                }
                
                for(auto it = OverrideArgumentsInfos.begin(); it != OverrideArgumentsInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ArgumentsDatas.size(); i++)
                    {
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& curArgDataInfo = it  ->second
                                                                    .ArgumentsDatas[i]
                                                                    .ArgumentsDataInfo[j];
                            
                            if(curArgDataInfo.DataSet)
                            {
                                curArgDataInfo.Data = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.Data);
                            }
                        }
                        
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgDataInfo = it->second
                                                        .ArgumentsDatas[i]
                                                        .ArgumentsConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgDataInfo.ArgSet)
                            {
                                curArgDataInfo.ArgDataPointer = 
                                    curArgDataInfo.CopyConstructor(curArgDataInfo.ArgDataPointer);
                            }
                        }
                    }
                }
                
                return *this;
            }
                
            inline Overrider() :    Internal_ReturnDataSetter(OverrideReturnInfos),
                                    Internal_ArgsDataSetter(OverrideArgumentsInfos),
                                    Internal_RequirementSetter( OverrideArgumentsInfos,
                                                                OverrideReturnInfos),
                                    Internal_ReturnDataRetriever(   OverrideReturnInfos, 
                                                                    *this, 
                                                                    *this,
                                                                    *this),
                                    Internal_ArgsDataRetriever( OverrideArgumentsInfos, 
                                                                *this, 
                                                                *this, 
                                                                *this,
                                                                *this)
            {}
            
            inline ~Overrider()
            {
                for(auto it = OverrideReturnInfos.begin(); it != OverrideReturnInfos.end(); it++)
                {
                    for(int i = 0; i < it->second.ReturnDatas.size(); i++)
                    {
                        //Free return data
                        Internal_DataInfo& curDataInfo = it->second.ReturnDatas[i].ReturnDataInfo;
                        if(curDataInfo.DataSet)
                            curDataInfo.Destructor(curDataInfo.Data);
                        
                        //Free argument condition data
                        for(int j = 0; j < it->second
                                            .ReturnDatas[i]
                                            .ReturnConditionInfo
                                            .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfos = it   ->second
                                                        .ReturnDatas[i]
                                                        .ReturnConditionInfo
                                                        .ArgsCondition[j];
                            
                            if(curArgInfos.ArgSet)
                                curArgInfos.Destructor(curArgInfos.ArgDataPointer);
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
                            Internal_DataInfo& curDataInfo = it ->second
                                                                .ArgumentsDatas[i]
                                                                .ArgumentsDataInfo[j];
                            
                            if(curDataInfo.DataSet)
                                curDataInfo.Destructor(curDataInfo.Data);
                        }
                        
                        //Free argument condition data
                        for(int j = 0; j < it   ->second
                                                .ArgumentsDatas[i]
                                                .ArgumentsConditionInfo
                                                .ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfo = it->second
                                                    .ArgumentsDatas[i]
                                                    .ArgumentsConditionInfo
                                                    .ArgsCondition[j];
                            
                            if(curArgInfo.ArgSet)
                                curArgInfo.Destructor(curArgInfo.ArgDataPointer);
                        }
                    }
                }
            }

            //------------------------------------------------------------------------------
            //Overrding Returns
            //------------------------------------------------------------------------------
            #define CO_LOG_OverrideReturns 0

            inline ReturnProxy Internal_OverrideReturns(std::string functionName)
            {
                #if CO_LOG_OverrideReturns
                    std::cout << "OverrideReturns\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                #endif

                OverrideReturnInfos[functionName].ReturnDatas.push_back(Internal_OverrideReturnData());
                return ReturnProxy(functionName, *this);
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

            #define CO_LOG_CheckOverrideAndReturn 0

            template<typename T, typename... Args>
            inline bool Internal_CheckOverrideAndReturn(T& returnRef, 
                                                        std::string functionName, 
                                                        Args&... args)
            {
                #if CO_LOG_CheckOverrideAndReturn
                    std::cout << "CheckOverrideAndReturn\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                #endif
                if(OverrideReturnInfos.find(functionName) == OverrideReturnInfos.end())
                    return false;
            
                OverrideStatus retrieveStatus = OverrideStatus::NO_OVERRIDE;
                int correctDataIndex = GetCorrectReturnDataInfo(returnRef, 
                                                                functionName, 
                                                                retrieveStatus, 
                                                                args...);
                
                auto& currentReturnDatas = OverrideReturnInfos.at(functionName).ReturnDatas;
                
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentReturnDatas.size(); i++)
                    {
                        if(currentReturnDatas.at(i).Status != nullptr)
                            *currentReturnDatas.at(i).Status = retrieveStatus;
                    }
                    
                    return false;
                }
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                //Called correctly action
                bool returnResult = false;
                if(correctDataIndex != -1)
                {
                    Internal_OverrideReturnData& correctData = 
                        currentReturnDatas.at(correctDataIndex);
                    
                    correctData.ReturnConditionInfo.CalledTimes++;
                    
                    if(correctData.ReturnActionInfo.CorrectActionSet)
                        correctData.ReturnActionInfo.CorrectAction(argumentsList);
                    
                    if(correctData.Status != nullptr)
                        *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;
                    
                    if(correctData.ReturnDataInfo.DataSet)
                        returnRef = *reinterpret_cast<T*>(correctData.ReturnDataInfo.Data);
                    else if(correctData.ReturnDataInfo.DataActionSet)
                        correctData.ReturnDataInfo.DataAction(argumentsList, &returnRef);

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
            #define CO_LOG_OverrideArgs 0

            inline ArgumentsProxy Internal_OverrideArgs(std::string functionName)
            {
                #if CO_LOG_OverrideArgs
                    std::cout << "OverrideArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                #endif

                OverrideArgumentsInfos[functionName].ArgumentsDatas
                                                    .push_back(Internal_OverrideArgsData());
                
                return ArgumentsProxy(functionName, *this);
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

            #define CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline bool Internal_CheckOverrideAndSetArgs(std::string functionName, Args&... args)
            {
                #if CO_LOG_CheckOverrideAndSetArgs
                    std::cout << "CheckOverrideAndSetArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                #endif
                if(OverrideArgumentsInfos.find(functionName) == OverrideArgumentsInfos.end())
                    return false;
            
                OverrideStatus retrieveStatus = OverrideStatus::NO_OVERRIDE;
                int correctDataIndex = GetCorrectArgumentsDataInfo( functionName, 
                                                                    retrieveStatus, 
                                                                    args...);
                
                auto& currentArgsDatas = OverrideArgumentsInfos.at(functionName).ArgumentsDatas;
                
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentArgsDatas.size(); i++)
                    {
                        if(currentArgsDatas.at(i).Status != nullptr)
                            *currentArgsDatas.at(i).Status = retrieveStatus;
                    }
                    
                    return false;
                }
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                //Called correctly action
                bool returnResult = false;
                if(correctDataIndex != -1)
                {
                    Internal_OverrideArgsData& correctData = 
                        OverrideArgumentsInfos[functionName].ArgumentsDatas[correctDataIndex];
                    
                    correctData.ArgumentsConditionInfo.CalledTimes++;
                    
                    if(correctData.ArgumentsActionInfo.CorrectActionSet)
                        correctData.ArgumentsActionInfo.CorrectAction(argumentsList);

                    if(correctData.Status != nullptr)
                        *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;

                    if(correctData.ArgumentsDataActionInfo.DataActionSet)
                        ModifyArgs(argumentsList, correctData.ArgumentsDataActionInfo);
                    else
                    {
                        ModifyArgs( argumentsList, 
                                    correctData.ArgumentsDataInfo, 
                                    0, 
                                    correctData.Status, 
                                    args...);
                    }
                        
                    returnResult = true;
                }
                
                //Deallocating argumentsList
                //for(int i = 0; i < argumentsList.size(); i++)
                //    argumentsList[i].Destructor(argumentsList[i].ArgData);

                return returnResult;
            }
    };
}

#endif