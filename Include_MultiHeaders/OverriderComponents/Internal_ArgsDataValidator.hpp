#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_DATA_VALIDATOR_HPP

#include "./Internal_ArgsTypeInfoAppender.hpp"
#include "./Internal_ArgsValuesAppender.hpp"
#include "../Internal_OverrideData.hpp"
#include "../AliasTypes.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    class Internal_ArgsDataValidator
    {
        protected:
            Internal_ArgsValuesAppender& ArgsValuesAppender;
            Internal_ArgsTypeInfoAppender& ArgsTypeInfoAppender;
            
            #define INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo 0

            template<typename... Args>
            inline bool IsCorrectArgumentsDataInfo( Internal_OverrideData& overrideDataToCheck,
                                                    Args&... args)
            {
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                ArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<ArgInfo> argumentsTypesList;
                ArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << "Checking arg data\n";
                
                //Check override argument data types match
                int argumentTypeFailedIndex = -1;
                
                if( overrideDataToCheck.ArgumentsDataActionInfo.DataActionSet && 
                    !argumentsTypesList.empty() &&
                    overrideDataToCheck.ArgumentsDataActionInfo.DataTypes.size() == 
                        argumentsTypesList.size())
                {
                    std::vector<std::size_t>& argTypeHashes = 
                        overrideDataToCheck.ArgumentsDataActionInfo.DataTypes;
                    
                    std::vector<bool>& argsTypesSet = 
                        overrideDataToCheck.ArgumentsDataActionInfo.DataTypesSet;
                    
                    for(int i = 0; i < argTypeHashes.size(); i++)
                    {
                        if( argsTypesSet[i] &&
                            argTypeHashes[i] != argumentsTypesList[i].ArgTypeHash)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout <<    "argTypeHashes[" << i << "]: " << 
                                                argTypeHashes[i] << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList[i].ArgTypeHash << std::endl;
                            }
                            
                            break;
                        }
                    }
                }
                //Check set argument data counts match
                else if(overrideDataToCheck.ArgumentsDataInfo.size() == argumentsTypesList.size() &&
                        !argumentsTypesList.empty())
                {
                    for(int i = 0; i < overrideDataToCheck.ArgumentsDataInfo.size(); i++)
                    {
                        bool overrideArg =  overrideDataToCheck.ArgumentsDataInfo[i].DataSet;

                        if( overrideArg && 
                            overrideDataToCheck.ArgumentsDataInfo[i].DataType != 
                                argumentsTypesList[i].ArgTypeHash)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout << "Failed at checking argument data type" << std::endl;
                                std::cout <<    "overrideDataToCheck.ArgumentsDataInfo[" << i << "]: " << 
                                                overrideDataToCheck.ArgumentsDataInfo[i].DataType << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList[i].ArgTypeHash << std::endl;
                            }
                            
                            break;
                        }
                    }
                }
                else
                {
                    if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                        std::cout << "Failed at Check set argument data exist" << std::endl;
                    
                    return false;
                }
                
                if(argumentTypeFailedIndex >= 0)
                {
                    if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    {
                        std::cout <<    "Failed at Check set argument data types at index " <<
                                        argumentTypeFailedIndex << std::endl;
                    }
                    
                    return false;
                }
                
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << "Argument data found " <<  std::endl;
                
                return true;
            }
        
        public:
            Internal_ArgsDataValidator( Internal_ArgsValuesAppender& argsValuesAppender,
                                        Internal_ArgsTypeInfoAppender& argsTypeInfoAppender) :
                                                ArgsValuesAppender(argsValuesAppender),
                                                ArgsTypeInfoAppender(argsTypeInfoAppender)
            {}
    };

}

#endif
