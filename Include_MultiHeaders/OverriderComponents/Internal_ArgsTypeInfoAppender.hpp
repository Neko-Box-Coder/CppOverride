#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP

#include "../Any.hpp"
#include "../Internal_DataInfo.hpp"

#include <iostream>
#include <vector>
#include <type_traits>

namespace CppOverride
{
    class Internal_ArgsTypeInfoAppender
    {
        friend class Internal_ArgsDataValidator;
        
        protected:
            #if CO_SHOW_OVERRIDE_LOG
                #define INTERNAL_CO_LOG_AppendArgsTypeInfo 1
            #else
                #define INTERNAL_CO_LOG_AppendArgsTypeInfo 0
            #endif
            
            inline void AppendArgsTypeInfo(std::vector<Internal_DataInfo>&) {}
            
            template<typename T, typename... Args>
            inline void AppendArgsTypeInfo( std::vector<Internal_DataInfo>& argumentsList, 
                                            T&, 
                                            Args&... args)
            {
                Internal_DataInfo curArgInfo;
                if(!std::is_same<T, Any>())
                {
                    curArgInfo.DataType = typeid(T).hash_code();
                    curArgInfo.DataSet = true;
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
