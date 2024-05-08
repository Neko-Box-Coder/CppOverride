#ifndef CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP
#define CO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace CppOverride
{
    struct Internal_ArgsDataActionInfo
    {
        std::function<void(std::vector<void*>& args)> DataAction;
        std::vector<std::size_t> DataTypes;
        std::vector<bool> DataTypesSet;
        bool DataActionSet = false;
    };
}


#endif