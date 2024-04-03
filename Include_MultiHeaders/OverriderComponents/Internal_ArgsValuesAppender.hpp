#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_ARGS_VALUES_APPENDER_HPP

#include "./PureType.hpp"
#include <vector>

namespace CppOverride
{
    class Internal_ArgsValuesAppender
    {
        friend class Internal_ReturnDataRetriever;
        friend class Internal_ArgsDataRetriever;
        
        protected:
            //Appending arguments from function calls
            inline void AppendArgsValues(std::vector<void*>& argumentsList){};

            template<typename T, typename... Args>
            inline void AppendArgsValues(std::vector<void*>& argumentsList, T& arg, Args&... args)
            {
                argumentsList.push_back((INTERNAL_CO_NON_CONST_T*)&arg);
                AppendArgsValues(argumentsList, args...);
            }
    };
}

#endif