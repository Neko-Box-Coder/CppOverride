#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP

#include "../Any.hpp"
#include "../ArgsInfo.hpp"
#include "../PureType.hpp"
#include <iostream>
#include <vector>
namespace CppOverride
{
    class Internal_ArgsTypeInfoAppender
    {
        friend class Internal_ArgsDataValidator;
        
        protected:
            #define INTERNAL_CO_LOG_AppendArgsTypeInfo 0
            
            inline void AppendArgsTypeInfo(std::vector<ArgInfo>& argumentsList) {}
            
            template<   typename T, 
                        typename... Args>
            inline void AppendArgsTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                            T& arg, 
                                            Args&... args)
            {
                ArgInfo curArgInfo;
                if(!std::is_same<T, Any>())
                {
                    curArgInfo.ArgSize = sizeof(T);
                    curArgInfo.ArgTypeHash = typeid(T).hash_code();
                    curArgInfo.ArgSet = true;
                }
                
                if(INTERNAL_CO_LOG_AppendArgsTypeInfo)
                {
                    std::cout << std::endl << __func__ << " called" << std::endl;
                    std::cout << "Type: " << typeid(T).name() << std::endl;
                    std::cout << "Hash: " << typeid(T).hash_code() << std::endl;
                }

                argumentsList.push_back(curArgInfo);
                AppendArgsTypeInfo(argumentsList, args...);
            }
    };
}

#endif