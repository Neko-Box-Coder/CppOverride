#ifndef CO_ARGS_DATA_ACTION_INFO_HPP
#define CO_ARGS_DATA_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct ArgsDataActionInfo
    {
        std::function<void(void* instance, std::vector<void*>& args)> DataAction;
        std::vector<std::size_t> DataTypes;
        std::vector<bool> DataTypesSet;
        bool DataActionSet = false;
    };
}


#endif
