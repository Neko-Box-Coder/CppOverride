#ifndef CO_OVERRIDER_COMPONENTS_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_ARGS_TYPE_INFO_APPENDER_HPP

#include "../Any.hpp"
#include "../DataInfo.hpp"

#include <iostream>
#include <vector>
#include <type_traits>

namespace CppOverride
{
    struct ArgsTypeInfoAppender
    {
        public:
            #if CO_SHOW_OVERRIDE_LOG
                #define INTERNAL_CO_LOG_AppendArgsTypeInfo 1
            #else
                #define INTERNAL_CO_LOG_AppendArgsTypeInfo 0
            #endif
            
            inline void AppendArgsTypeInfo(std::vector<DataInfo>&) {}
            
            template<typename T, typename... Args>
            inline void AppendArgsTypeInfo( std::vector<DataInfo>& argumentsList, 
                                            T&, 
                                            Args&... args)
            {
                DataInfo curArgInfo;
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
