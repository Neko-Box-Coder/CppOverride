#ifndef CO_CPP_OVERRIDE_INSTANCE_HPP
#define CO_CPP_OVERRIDE_INSTANCE_HPP

#include "./OverrideInfoSetterDeclaration.hpp"
#include "./Any.hpp"
#include "./OverriderComponents/Internal_ReturnDataSetter.hpp"
#include "./OverriderComponents/Internal_ArgsDataSetter.hpp"
#include "./OverriderComponents/Internal_RequirementSetter.hpp"
#include "./OverriderComponents/Internal_ArgsValuesAppender.hpp"
#include "./OverriderComponents/Internal_ArgsTypeInfoAppender.hpp"
#include "./OverriderComponents/Internal_ConditionArgsTypesChecker.hpp"
#include "./OverriderComponents/Internal_ConditionArgsValuesChecker.hpp"
#include "./OverriderComponents/Internal_ArgsModifier.hpp"

#include "./OverriderComponents/Internal_ReturnDataValidator.hpp"
#include "./OverriderComponents/Internal_ArgsDataValidator.hpp"
#include "./OverriderComponents/Internal_RequirementValidator.hpp"

#include "./Internal_OverrideData.hpp"
#include "./OverrideStatus.hpp"
#include "./EarlyReturn.hpp"
#include "./Internal_DataInfo.hpp"

#include <string>
#include <unordered_map>

namespace CppOverride
{
    class Overrider :   public Internal_ReturnDataSetter, 
                        public Internal_ArgsDataSetter,
                        public Internal_RequirementSetter,
                        public Internal_ArgsValuesAppender,
                        public Internal_ArgsTypeInfoAppender,
                        public Internal_ConditionArgsTypesChecker,
                        public Internal_ConditionArgsValuesChecker,
                        public Internal_ArgsModifier,
                        public Internal_ReturnDataValidator,
                        public Internal_ArgsDataValidator,
                        public Internal_RequirementValidator
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
                Internal_RequirementSetter(OverrideDatas),
                Internal_ReturnDataValidator(static_cast<Internal_ArgsValuesAppender*>(this)),
                Internal_ArgsDataValidator(*this, *this),
                Internal_RequirementValidator(*this, *this, *this)
            {
                *this = other;
            }
            
            inline Overrider& operator=(const Overrider& other)
            {
                if(this == &other)
                    return *this;
            
                OverrideDatas = other.OverrideDatas;
                return *this;
            }
                
            inline Overrider() :    Internal_ReturnDataSetter(OverrideDatas),
                                    Internal_ArgsDataSetter(OverrideDatas),
                                    Internal_RequirementSetter(OverrideDatas),
                                    Internal_ReturnDataValidator(*this),
                                    Internal_ArgsDataValidator(*this, *this),
                                    Internal_RequirementValidator(*this, *this, *this)
            {}
            
            inline ~Overrider()
            {}

            //------------------------------------------------------------------------------
            //Check overrides available
            //------------------------------------------------------------------------------
            #define INTERNAL_CO_LOG_CheckOverride 0
            
            template<typename ReturnType, typename... Args>
            inline bool Internal_CheckOverride( std::string functionName, 
                                                int& outOverrideIndex,
                                                bool& outOverrideReturn,
                                                bool& outOverrideArgs,
                                                bool& outDontReturn,
                                                Args&... args)
            {
                outOverrideIndex = -1;
                
                if(INTERNAL_CO_LOG_CheckOverride)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: "<< functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                if(OverrideDatas.find(functionName) == OverrideDatas.end())
                {
                    if(INTERNAL_CO_LOG_CheckOverride)
                        std::cout << functionName << " not found\n";
                    
                    return false;
                }
            
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                
                outOverrideArgs = false;
                outOverrideReturn = false;
                outDontReturn = false;
                for(int i = 0; i < currentDataList.size(); ++i)
                {
                    if( !currentDataList.at(i).ArgumentsDataInfo.empty() ||
                        currentDataList.at(i).ArgumentsDataActionInfo.DataActionSet)
                    {
                        if(!IsCorrectArgumentsDataInfo( currentDataList.at(i), 
                                                        args...))
                        {
                            if(INTERNAL_CO_LOG_CheckOverride)
                                std::cout << "Arguments not correct at index: " << i << std::endl;
                            
                            continue;
                        }
                        
                        outOverrideArgs = true;
                    }

                    if( currentDataList.at(i).ReturnDataInfo.DataSet ||
                        currentDataList.at(i).ReturnDataInfo.ReturnAny ||
                        currentDataList.at(i).ReturnDataActionInfo.DataActionSet)
                    {
                        if(!IsCorrectReturnDataInfo<ReturnType>(currentDataList.at(i), args...))
                        {
                            if(INTERNAL_CO_LOG_CheckOverride)
                                std::cout << "Return not correct at index: " << i << std::endl;
                            
                            continue;
                        }
                        
                        outOverrideReturn = true;
                        
                        if(currentDataList.at(i).ReturnDataInfo.ReturnAny)
                            outDontReturn = true;
                        else
                            outDontReturn = false;
                    }

                    OverrideStatus internalStatus = OverrideStatus::NO_OVERRIDE;
                    if(!IsMeetingRequirementForDataInfo<ReturnType>(currentDataList.at(i), 
                                                                    internalStatus, 
                                                                    args...))
                    {
                        //If something is wrong internally, notify everything
                        if(internalStatus != OverrideStatus::NO_OVERRIDE)
                        {
                            for(int i = 0; i < currentDataList.size(); i++)
                            {
                                if(currentDataList.at(i).Status != nullptr)
                                    *currentDataList.at(i).Status = internalStatus;
                            }
                        }
                        
                        if(INTERNAL_CO_LOG_CheckOverride)
                            std::cout << "Requirement not correct at index: " << i << std::endl;
                        
                        outOverrideArgs = false;
                        outOverrideReturn = false;
                        outDontReturn = false;
                        continue;
                    }

                    outOverrideIndex = i;
                    break;
                }
                
                
                if(INTERNAL_CO_LOG_CheckOverride)
                    std::cout << "outOverrideIndex: " << outOverrideIndex << std::endl;
                
                return outOverrideIndex != -1;
            }

            template<typename... Args>
            inline void Internal_CallReturnOverrideResultExpectedAction(    std::string functionName,
                                                                            int overrideIndex,
                                                                            Args&... args)
            {
                Internal_OverrideData& correctData = OverrideDatas.at(functionName).at(overrideIndex);
                if(correctData.ResultActionInfo.CorrectActionSet)
                {
                    std::vector<void*> argumentsList;
                    AppendArgsValues(argumentsList, args...);
                    correctData.ResultActionInfo.CorrectAction(argumentsList); 
                }
                
                correctData.ConditionInfo.CalledTimes++;
                
                if(correctData.Status != nullptr)
                    *correctData.Status = OverrideStatus::OVERRIDE_SUCCESS;
            }

            //------------------------------------------------------------------------------
            //Overriding Returns
            //------------------------------------------------------------------------------

            #define INTERNAL_CO_LOG_CheckOverrideAndReturn 0

            template<   typename ReturnType, 
                        typename = typename std::enable_if<std::is_same<ReturnType, void>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);
                return ReturnType();
            }

            template<   typename ReturnType, 
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<!std::is_reference<ReturnType>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn(  int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);
                
                if(correctData.ReturnDataInfo.DataSet)
                    return *static_cast<ReturnType*>(correctData.ReturnDataInfo.Data.get());
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                {
                    ReturnType returnRef;
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);
                    return returnRef;
                }
                
                return ReturnType();
            }
            
            template<   typename ReturnType, 
                        typename = typename std::enable_if<!std::is_same<ReturnType, void>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type,
                        typename = typename std::enable_if<std::is_reference<ReturnType>::value>::type,
                        typename... Args>
            inline ReturnType Internal_OverrideReturn( int dataIndex,
                                                        std::string functionName, 
                                                        Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndReturn)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                Internal_CallReturnOverrideResultExpectedAction(functionName, dataIndex, args...);

                if(correctData.ReturnDataInfo.DataSet)
                {
                    return *reinterpret_cast<INTERNAL_CO_UNREF(ReturnType)*>
                    (
                        correctData.ReturnDataInfo.Data.get()
                    );
                }
                else if(correctData.ReturnDataActionInfo.DataActionSet)
                {
                    INTERNAL_CO_UNREF(ReturnType)* returnRef;
                    correctData.ReturnDataActionInfo.DataAction(argumentsList, &returnRef);
                    return *returnRef;
                }
                
                return EarlyReturn<ReturnType>();
            }

            //------------------------------------------------------------------------------
            //Overriding Arguments
            //------------------------------------------------------------------------------
            #define INTERNAL_CO_LOG_CheckOverrideAndSetArgs 0

            template<typename... Args>
            inline void Internal_OverrideArgs(  int dataIndex,
                                                std::string functionName, 
                                                bool performResultAction,
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckOverrideAndSetArgs)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: "<<functionName << std::endl;
                }
                
                Internal_OverrideDataList& currentDataList = OverrideDatas.at(functionName);
                std::vector<void*> argumentsList;
                AppendArgsValues(argumentsList, args...);
                
                Internal_OverrideData& correctData = currentDataList.at(dataIndex);
                OverrideStatus overrideStatus = OverrideStatus::OVERRIDE_SUCCESS;
                
                if(correctData.ArgumentsDataActionInfo.DataActionSet)
                    ModifyArgs(argumentsList, correctData.ArgumentsDataActionInfo);
                else
                {
                    ModifyArgs( correctData.ArgumentsDataInfo, 
                                0, 
                                &overrideStatus, 
                                args...);
                }
                
                if(correctData.Status != nullptr)
                    *correctData.Status = overrideStatus;
                
                if( performResultAction && 
                    overrideStatus == OverrideStatus::OVERRIDE_SUCCESS)
                {
                    Internal_CallReturnOverrideResultExpectedAction(functionName, 
                                                                    dataIndex, 
                                                                    args...);
                }
            }
            
            //------------------------------------------------------------------------------
            //Creating override info
            //------------------------------------------------------------------------------
            
            #define INTERNAL_CO_LOG_OverrideCreation 0

            inline OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName)
            {
                if(INTERNAL_CO_LOG_OverrideCreation)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "functionName: " << functionName << std::endl;
                    std::cout << "functionName.size(): " << functionName.size() << std::endl;
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
