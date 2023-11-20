#ifndef SO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP
#define SO_INTERNAL_ARGS_DATA_ACTION_INFO_HPP

#include <functional>
#include <vector>

namespace SimpleOverride
{
    struct Internal_ArgsDataActionInfo
    {
        std::function<void(std::vector<void*>& args)> DataAction;
        std::vector<std::size_t> DataTypes;
        bool DataActionSet = false;
    };
}


#endif