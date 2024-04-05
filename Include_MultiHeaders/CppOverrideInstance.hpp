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
            //Overriding Returns
            //------------------------------------------------------------------------------
            #define CO_LOG_OverrideReturns 0

            //TODO(NOW): rename this
            inline OverrideInfoSetter Internal_OverrideReturns(std::string functionName)
            {
                if(CO_LOG_OverrideReturns)
                {
                    std::cout << "OverrideReturns\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                }

                OverrideDatas[functionName].push_back(Internal_OverrideData());
                return OverrideInfoSetter(functionName, *this);
            }
            
            //TODO(NOW): Common function between return and args
            //TODO(NOW): Rename this
            inline void Internal_ClearOverrideReturns(std::string functionName)
            {
                if(OverrideDatas.find(functionName) != OverrideDatas.end())
                    OverrideDatas.erase(functionName);
            }
            
            //TODO(NOW): Common function between return and args
            //TODO(NOW): Rename this
            inline void ClearAllOverrideReturns()
            {
                OverrideDatas.clear();
            }

            #define CO_LOG_CheckOverrideAndReturn 0

            template<typename T, typename... Args>
            inline bool Internal_CheckOverrideAndReturn(T& returnRef, 
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << "CheckOverrideAndReturn\n";
                    std::cout << "functionName: "<<functionName << "\n";
                    std::cout << "functionName.size(): " << functionName.size() << "\n";
                }
                
                if(OverrideDatas.find(functionName) == OverrideDatas.end())
                    return false;
            
                OverrideStatus retrieveStatus = OverrideStatus::NO_OVERRIDE;
                int correctDataIndex = GetCorrectReturnDataInfo(returnRef, 
                                                                functionName, 
                                                                retrieveStatus, 
                                                                args...);
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentDataList.size(); i++)
                    {
                        if(currentDataList.at(i).Status != nullptr)
                            *currentDataList.at(i).Status = retrieveStatus;
                    }
                    
                    return false;
                }
                
                //Called correctly action
                if(correctDataIndex == -1)
                    return false;
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(correctDataIndex);
                
                correctData.ConditionInfo.CalledTimes++;
                
                if(correctData.ResultActionInfo.CorrectActionSet)
                    correctData.ResultActionInfo.CorrectAction(argumentsList);
                
                if(correctData.Status != nullptr)
                    *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;
                
                if(correctData.ReturnDataInfo.DataSet)
                    returnRef = *reinterpret_cast<T*>(correctData.ReturnDataInfo.Data);
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);

                return true;
            }

            //------------------------------------------------------------------------------
            //Overriding Arguments
            //------------------------------------------------------------------------------
            #define CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline bool Internal_CheckOverrideAndSetArgs(std::string functionName, Args&... args)
            {
                if(CO_LOG_CheckOverrideAndSetArgs)
                {
                    std::cout << "CheckOverrideAndSetArgs\n";
                    std::cout << "functionName: "<<functionName << "\n";
                }
                
                if(OverrideDatas.find(functionName) == OverrideDatas.end())
                    return false;
            
                OverrideStatus retrieveStatus = OverrideStatus::NO_OVERRIDE;
                int correctDataIndex = GetCorrectArgumentsDataInfo( functionName, 
                                                                    retrieveStatus, 
                                                                    args...);
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                
                if(retrieveStatus != OverrideStatus::NO_OVERRIDE)
                {
                    for(int i = 0; i < currentDataList.size(); i++)
                    {
                        if(currentDataList.at(i).Status != nullptr)
                            *currentDataList.at(i).Status = retrieveStatus;
                    }
                    
                    return false;
                }
                
                //Called correctly action
                if(correctDataIndex == -1)
                    return false;
                
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(correctDataIndex);
                
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
                    
                return true;
            }
    };
}

#endif