#ifndef CO_RETURN_DATA_ACTION_INFO_HPP
#define CO_RETURN_DATA_ACTION_INFO_HPP

#include "./TypedDataInfo.hpp"
#include "./TypedInfo.hpp"
#include <functional>
#include <vector>

namespace CppOverride
{
    struct ReturnDataActionInfo
    {
        std::function<TypedDataInfo(void* instance, 
                                    const std::vector<TypedDataInfo>& args,
                                    const TypedInfo& returnInfo)> DataAction;
        std::size_t DataType = 0;
        bool DataActionSet = false;
        bool ReturnReference = false;
    };
}


#endif
