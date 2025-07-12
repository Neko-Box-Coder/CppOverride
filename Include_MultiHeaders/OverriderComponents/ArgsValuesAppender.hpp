#ifndef CO_OVERRIDER_COMPONENTS_ARGS_VALUES_APPENDER_HPP
#define CO_OVERRIDER_COMPONENTS_ARGS_VALUES_APPENDER_HPP

#include "../PureType.hpp"
#include "../TypedDataInfo.hpp"
#include <vector>

namespace CppOverride
{
    struct ArgsValuesAppender
    {
        //Appending arguments as TypedDataInfo from function calls
        inline void AppendArgsValues(std::vector<TypedDataInfo>&) {};

        template<typename T, typename RawType = INTERNAL_CO_RAW_TYPE(T), typename... Args>
        inline void AppendArgsValues(std::vector<TypedDataInfo>& argumentsList, T& arg, Args&... args)
        {
            argumentsList.push_back(TypedDataInfo().CreateReference<RawType>((RawType*)&arg));
            AppendArgsValues(argumentsList, args...);
        }
    };
}

#endif
