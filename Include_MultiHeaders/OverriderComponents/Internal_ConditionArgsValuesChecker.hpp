#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_VALUES_CHECKER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_CONDITION_ARGS_VALUES_CHECKER_HPP

#include "../Any.hpp"
#include "../Internal_DataInfo.hpp"
#include "../TypeCheck.hpp"
#include "../OverrideStatus.hpp"
#include "../PureType.hpp"

#include <cassert>
#include <type_traits>
#include <vector>
#include <iostream>


namespace CppOverride
{
    class Internal_ConditionArgsValuesChecker
    {
        friend class Internal_ReturnDataValidator;
        friend class Internal_ArgsDataValidator;
        friend class Internal_RequirementValidator;
        
        protected:
            inline bool CheckArgumentsValues(   std::vector<Internal_DataInfo>&, 
                                                int,
                                                OverrideStatus&) { return true; };

            #define INTERNAL_CO_LOG_CheckArgumentsValues 0

            //Check type support inequal operator
            template<   typename T, 
                        typename RawType = INTERNAL_CO_RAW_TYPE(T), 
                        typename = typename std::enable_if<!InequalExists<RawType>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<Internal_DataInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                {
                    const Internal_DataInfo& curArgInfo = validArgumentsList.at(argIndex);
                    
                    //Check Reference (Which is converted to pointer when checking)
                    if(typeid(RawType*).hash_code() == curArgInfo.DataType)
                    {
                        if((RawType*)&arg != *static_cast<RawType**>(curArgInfo.Data.get()))
                            return false;
                    }
                    else
                    {
                        //NOTE: Cannot check data that doesn't have inequal operator
                        status = OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR;
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            //Check value or reference
            template<   typename T, 
                        typename RawType = INTERNAL_CO_RAW_TYPE(T), 
                        typename = typename std::enable_if<InequalExists<RawType>::value>::type,
                        typename = typename std::enable_if<!std::is_pointer<RawType>::value>::type,
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<Internal_DataInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout << "CheckArgumentsValues index: " << argIndex << std::endl;
                }

                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                {
                    const Internal_DataInfo& curArgInfo = validArgumentsList.at(argIndex);
                    
                    //Check Reference (Which is converted to pointer when checking)
                    if(typeid(RawType*).hash_code() == curArgInfo.DataType)
                    {
                        if((RawType*)&arg != *static_cast<RawType**>(curArgInfo.Data.get()))
                            return false;
                    }
                    //Check Value
                    else if(*(RawType*)&arg != *static_cast<RawType*>(curArgInfo.Data.get()))
                        return false;
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<< argIndex << " passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            //Check pointer or value
            template<   typename T, 
                        typename RawType = INTERNAL_CO_RAW_TYPE(T), 
                        typename = typename std::enable_if<std::is_pointer<RawType>::value>::type,
                        typename = typename std::enable_if<!std::is_same<INTERNAL_CO_PURE_TYPE(RawType), void>::value>::type, 
                        typename PureType = INTERNAL_CO_PURE_TYPE(T),
                        typename... Args>
            inline bool CheckArgumentsValues(   std::vector<Internal_DataInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
            
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                {
                    const Internal_DataInfo& curArgInfo = validArgumentsList.at(argIndex);
                    
                    //Check Pointer
                    if(typeid(RawType).hash_code() == curArgInfo.DataType)
                    {
                        if((RawType)arg != *static_cast<RawType*>(curArgInfo.Data.get()))
                            return false;
                    }
                    //Check Value
                    else
                    {
                        return CheckArgumentsValues(validArgumentsList, 
                                                    argIndex, 
                                                    status, 
                                                    *(RawType)(arg), 
                                                    args...);
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
            
            //Check void*
            template<   typename T, 
                        typename PureType = INTERNAL_CO_PURE_TYPE(T),
                        typename = typename std::enable_if<std::is_same<PureType, void>::value>::type, 
                        typename... Args,
                        typename = void(),
                        typename = void(),
                        typename = void()>
            inline bool CheckArgumentsValues(   std::vector<Internal_DataInfo>& validArgumentsList, 
                                                int argIndex, 
                                                OverrideStatus& status,
                                                T& arg, 
                                                Args&... args)
            {
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<"\n";
                }
                
                if(argIndex >= validArgumentsList.size())
                    return false;

                if(validArgumentsList.at(argIndex).DataSet)
                {
                    //Check void Pointer
                    if( typeid(void*).hash_code() != validArgumentsList.at(argIndex).DataType ||
                        (void*)arg != *static_cast<void**>(validArgumentsList.at(argIndex).Data.get()))
                    {
                        return false;
                    }
                }
                
                if(INTERNAL_CO_LOG_CheckArgumentsValues)
                {
                    std::cout << "Line: " << __LINE__ << std::endl;
                    std::cout <<"CheckArgumentsValues index: "<<argIndex<<" passed\n";
                }
                
                return CheckArgumentsValues(validArgumentsList, ++argIndex, status, args...);
            }
    };
}

#endif
