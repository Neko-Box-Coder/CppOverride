#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

#include "./OverrideInfoSetterDeclaration.hpp"
#include "./Any.hpp"
#include "./OverriderComponents/Internal_ReturnDataSetter.hpp"
#include "./OverriderComponents/Internal_ArgsDataSetter.hpp"
#include "./OverriderComponents/Internal_RequirementSetter.hpp"
#include "./OverriderComponents/Internal_ArgsValuesAppender.hpp"
#include "./OverriderComponents/Internal_ArgsTypeInfoAppender.hpp"
#include "./OverriderComponents/Internal_ArgsTypesChecker.hpp"
#include "./OverriderComponents/Internal_ArgsValuesChecker.hpp"
#include "./OverriderComponents/Internal_ArgsModifier.hpp"
#include "./OverriderComponents/Internal_ReturnDataRetriever.hpp"
#include "./OverriderComponents/Internal_ArgsDataRetriever.hpp"
#include "./Internal_OverrideData.hpp"
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
            std::unordered_map<std::string, Internal_OverrideDataList> OverrideDatas;


        //==============================================================================
        //Public facing methods for overriding returns or arguments
        //==============================================================================
        public:
            inline Overrider(const Overrider& other) :
                Internal_ReturnDataSetter(OverrideDatas),
                Internal_ArgsDataSetter(OverrideDatas),
                Internal_RequirementSetter( OverrideDatas),
                Internal_ReturnDataRetriever(OverrideDatas, *this, *this, *this),
                Internal_ArgsDataRetriever(OverrideDatas, *this, *this, *this, *this)
            {
                *this = other;
            }
            
            inline Overrider& operator=(const Overrider& other)
            {
                if(this == &other)
                    return *this;
            
                OverrideDatas = other.OverrideDatas;
            
                //For each function
                for(auto it = OverrideDatas.begin(); it != OverrideDatas.end(); it++)
                {
                    //For each override
                    for(int i = 0; i < it->second.size(); i++)
                    {
                        for(int j = 0; j < it->second[i].ConditionInfo.ArgsCondition.size(); j++)
                        {
                            ArgInfo& currentInfo = it->second[i].ConditionInfo.ArgsCondition[j];
                            
                            if(currentInfo.ArgSet)
                            {
                                currentInfo.ArgDataPointer = 
                                    currentInfo.CopyConstructor(currentInfo.ArgDataPointer);
                            }
                        }
                        
                        for(int j = 0; j < it->second[i].ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& currentInfo = it->second[i].ArgumentsDataInfo[j];
                            
                            if(currentInfo.DataSet)
                            {
                                currentInfo.Data = 
                                    currentInfo.CopyConstructor(currentInfo.Data);
                            }
                        }
                        
                        {
                            Internal_DataInfo& currentInfo = it->second[i].ReturnDataInfo;
                            
                            if(currentInfo.DataSet)
                            {
                                currentInfo.Data = 
                                    currentInfo.CopyConstructor(currentInfo.Data);
                            }
                        }
                    }
                }
                
                return *this;
            }
                
            inline Overrider() :    Internal_ReturnDataSetter(OverrideDatas),
                                    Internal_ArgsDataSetter(OverrideDatas),
                                    Internal_RequirementSetter(OverrideDatas),
                                    Internal_ReturnDataRetriever(   OverrideDatas, 
                                                                    *this, 
                                                                    *this,
                                                                    *this),
                                    Internal_ArgsDataRetriever( OverrideDatas, 
                                                                *this, 
                                                                *this, 
                                                                *this,
                                                                *this)
            {}
            
            inline ~Overrider()
            {
                for(auto it = OverrideDatas.begin(); it != OverrideDatas.end(); it++)
                {
                    for(int i = 0; i < it->second.size(); i++)
                    {
                        //Free argument condition data
                        for(int j = 0; j < it->second[i].ConditionInfo.ArgsCondition.size(); j++)
                        {
                            ArgInfo& curArgInfo = it->second[i].ConditionInfo.ArgsCondition[j];
                            
                            if(curArgInfo.ArgSet)
                                curArgInfo.Destructor(curArgInfo.ArgDataPointer);
                        }
                        
                        //Free arguments data
                        for(int j = 0; j < it->second[i].ArgumentsDataInfo.size(); j++)
                        {
                            Internal_DataInfo& curData = it->second[i].ArgumentsDataInfo[j];
                            
                            if(curData.DataSet)
                                curData.Destructor(curData.Data);
                        }
                        
                        //Free return data
                        {
                            Internal_DataInfo& curData = it->second[i].ReturnDataInfo;
                            
                            if(curData.DataSet)
                                curData.Destructor(curData.Data);
                        }
                    }
                }
            }

            //------------------------------------------------------------------------------
            //Check overrides available
            //------------------------------------------------------------------------------
            #define CO_LOG_Internal_CheckOverride 0
            
            template<typename ReturnType, typename... Args>
            inline bool Internal_CheckOverride( std::string functionName, 
                                                int& outReturnIndex,
                                                int& outArgsIndex,
                                                Args&... args)
            {
                outReturnIndex = -1;
                outArgsIndex = -1;
                
                if(CO_LOG_Internal_CheckOverride)
                {
                    std::cout << __func__ << "\n";
                    std::cout << "functionName: "<< functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                }
                
                if(OverrideDatas.find(functionName) == OverrideDatas.end())
                    return false;
            
                OverrideStatus retrieveStatus = OverrideStatus::NO_OVERRIDE;
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                
                //TODO: Merge GetCorrectReturnDataInfo and GetCorrectArgumentsDataInfo common part
                outReturnIndex = GetCorrectReturnDataInfo<ReturnType>(  functionName, 
                                                                        retrieveStatus, 
                                                                        args...);
                
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentDataList.size(); i++)
                    {
                        if(currentDataList.at(i).Status != nullptr)
                            *currentDataList.at(i).Status = retrieveStatus;
                    }
                }
                
                //Called correctly action
                if(outReturnIndex != -1)
                    return true;
                
                retrieveStatus = OverrideStatus::NO_OVERRIDE;
            
                outArgsIndex = GetCorrectArgumentsDataInfo( functionName, 
                                                            retrieveStatus, 
                                                            args...);
            
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentDataList.size(); i++)
                    {
                        if(currentDataList.at(i).Status != nullptr)
                            *currentDataList.at(i).Status = retrieveStatus;
                    }
                }
                
                //Called correctly action
                if(outArgsIndex != -1)
                    return true;
            
                return false;
            }


            //------------------------------------------------------------------------------
            //Overriding Returns
            //------------------------------------------------------------------------------

            #define CO_LOG_CheckOverrideAndReturn 0

            //TODO(NOW): Auto convert ref to pointer
            template<typename ReturnType, typename... Args>
            inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << "CheckOverrideAndReturn\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                
                correctData.ConditionInfo.CalledTimes++;
                
                if(correctData.ResultActionInfo.CorrectActionSet)
                    correctData.ResultActionInfo.CorrectAction(argumentsList);
                
                if(correctData.Status != nullptr)
                    *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;
                
                if(correctData.ReturnDataInfo.DataSet)
                    return *reinterpret_cast<ReturnType*>(correctData.ReturnDataInfo.Data);
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                {
                    ReturnType* returnRef;
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);
                    return *returnRef;
                }
            }

            //------------------------------------------------------------------------------
            //Overriding Arguments
            //------------------------------------------------------------------------------
            #define CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline void Internal_OverrideArgs(  int dataIndex,
                                                std::string functionName, 
                                                Args&... args)
            {
                if(CO_LOG_CheckOverrideAndSetArgs)
                {
                    std::cout << "CheckOverrideAndSetArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                
                correctData.ConditionInfo.CalledTimes++;
                
                if(correctData.ResultActionInfo.CorrectActionSet)
                    correctData.ResultActionInfo.CorrectAction(argumentsList);
                
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
            }
            
            //------------------------------------------------------------------------------
            //Creating override info
            //------------------------------------------------------------------------------
            
            #define CO_LOG_OverrideCreation 0

            inline OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName)
            {
                if(CO_LOG_OverrideCreation)
                {
                    std::cout << "OverrideReturns\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                }

                OverrideDatas[functionName].push_back(Internal_OverrideData());
                return OverrideInfoSetter(functionName, *this);
            }
            
            inline void Internal_RemoveOverrideInfo(std::string functionName)
            {
                if(OverrideDatas.find(functionName) != OverrideDatas.end())
                    OverrideDatas.erase(functionName);
            }
            
            inline void ClearAllOverrideInfo()
            {
                OverrideDatas.clear();
            }
    };
}

#endif