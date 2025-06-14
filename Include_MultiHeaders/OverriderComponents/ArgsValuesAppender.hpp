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
            TypedDataInfo info;
            info.Data = (RawType*)&arg;
            info.TypeHash = typeid(RawType).hash_code();
            info.IsSet = true;
            argumentsList.push_back(info);
            AppendArgsValues(argumentsList, args...);
        }
    };
}

#endif
