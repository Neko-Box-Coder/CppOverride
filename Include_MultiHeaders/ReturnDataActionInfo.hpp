#ifndef CO_RETURN_DATA_ACTION_INFO_HPP
#define CO_RETURN_DATA_ACTION_INFO_HPP

#include <functional>

namespace CppOverride
{
    struct ReturnDataActionInfo
    {
        std::function<void(void* instance, const std::vector<void*>& args, void* out)> DataAction;
        std::size_t DataType = 0;
        bool DataActionSet = false;
        bool ReturnReference = false;
    };
}


#endif
