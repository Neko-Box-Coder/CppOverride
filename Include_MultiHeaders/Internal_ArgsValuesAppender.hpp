#ifndef SO_INTERNAL_ARGS_VALUES_APPENDER_HPP
#define SO_INTERNAL_ARGS_VALUES_APPENDER_HPP

#include "./PureType.hpp"
#include <vector>

namespace SimpleOverride
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
                argumentsList.push_back((INTERNAL_SO_NON_CONST_T*)&arg);
                AppendArgsValues(argumentsList, args...);
            }
    };
}

#endif