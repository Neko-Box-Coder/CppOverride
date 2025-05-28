#ifndef CO_OVERRIDER_COMPONENTS_ARGS_DATA_VALIDATOR_HPP
#define CO_OVERRIDER_COMPONENTS_ARGS_DATA_VALIDATOR_HPP

#include "./ArgsTypeInfoAppender.hpp"
#include "./ArgsValuesAppender.hpp"
#include "../OverrideData.hpp"
#include "../AliasTypes.hpp"
#include "../DataInfo.hpp"

#include <cassert>
#include <string>
#include <unordered_map>
#include <iostream>

namespace CppOverride
{
    struct ArgsDataValidator
    {
        public:
            ArgsValuesAppender& CurrentArgsValuesAppender;
            ArgsTypeInfoAppender& CurrentArgsTypeInfoAppender;
            
            #if CO_SHOW_OVERRIDE_LOG
                #define INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo 1
            #else
                #define INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo 0
            #endif

            template<typename... Args>
            inline bool IsCorrectArgumentsDataInfo( OverrideData& overrideDataToCheck,
                                                    Args&... args)
            {
                
                if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                    std::cout << std::endl << __func__ << " called" << std::endl;
                
                std::vector<void*> argumentsList;
                CurrentArgsValuesAppender.AppendArgsValues(argumentsList, args...);
                
                std::vector<DataInfo> argumentsTypesList;
                CurrentArgsTypeInfoAppender.AppendArgsTypeInfo(argumentsTypesList, args...);
                
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
                        if( argsTypesSet.at(i) &&
                            argTypeHashes.at(i) != argumentsTypesList.at(i).DataType)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout <<    "argTypeHashes[" << i << "]: " << 
                                                argTypeHashes.at(i) << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList.at(i).DataType << std::endl;
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
                        bool overrideArg =  overrideDataToCheck.ArgumentsDataInfo.at(i).DataSet;

                        if( overrideArg && 
                            overrideDataToCheck.ArgumentsDataInfo.at(i).DataType != 
                                argumentsTypesList.at(i).DataType)
                        {
                            argumentTypeFailedIndex = i;
                            
                            if(INTERNAL_CO_LOG_IsCorrectArgumentsDataInfo)
                            {
                                std::cout << "Failed at checking argument data type" << std::endl;
                                std::cout <<    "overrideDataToCheck.ArgumentsDataInfo[" << i << "]: " << 
                                                overrideDataToCheck.ArgumentsDataInfo.at(i).DataType << std::endl;
                                std::cout <<    "deRefArgumentsList[" << i << "].ArgTypeHash: " <<
                                                argumentsTypesList.at(i).DataType << std::endl;
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
        
            ArgsDataValidator(  ArgsValuesAppender& argsValuesAppender,
                                ArgsTypeInfoAppender& argsTypeInfoAppender) :
                CurrentArgsValuesAppender(argsValuesAppender),
                CurrentArgsTypeInfoAppender(argsTypeInfoAppender)
            {}
    };

}

#endif
