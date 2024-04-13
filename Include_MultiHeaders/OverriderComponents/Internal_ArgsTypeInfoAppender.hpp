#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_TYPE_INFO_APPENDER_HPP

#include "./Any.hpp"
#include "./ArgsInfo.hpp"
#include "./PureType.hpp"
#include <vector>
namespace CppOverride
{
    class Internal_ArgsTypeInfoAppender
    {
        friend class Internal_ArgsDataRetriever;
        
        protected:
            inline void AppendArgsPureTypeInfo(std::vector<ArgInfo>& argumentsList) {}

            //NOTE: We need to transform pointers and references into the base type so that
            //      the we can assign the values that we have stored to the arguments
            template<   typename T, 
                        typename... Args>
            inline void AppendArgsPureTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                                T& arg, 
                                                Args&... args)
            {
                ArgInfo curArgInfo;
                if(!std::is_same<T, Any>())
                {
                    curArgInfo.ArgSize = sizeof(INTERNAL_CO_UNCONST(INTERNAL_CO_UNREF(T)));
                    curArgInfo.ArgTypeHash = typeid(INTERNAL_CO_UNCONST(INTERNAL_CO_UNREF(T))).hash_code();
                    curArgInfo.ArgSet = true;
                }

                argumentsList.push_back(curArgInfo);
                AppendArgsPureTypeInfo(argumentsList, args...);
            }
            
            //Unwrap pointers if it is not void*
            template<   typename T, 
                        typename = typename std::enable_if<!std::is_same<T, void>::value>::type, 
                        typename = typename std::enable_if<!std::is_same<T, const void>::value>::type, 
                        typename... Args>
            inline void AppendArgsPureTypeInfo( std::vector<ArgInfo>& argumentsList, 
                                                T* arg, 
                                                Args&... args)
            {
                AppendArgsPureTypeInfo(argumentsList, *arg, args...);
            }
    };
}

#endif