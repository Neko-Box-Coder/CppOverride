#ifndef SO_INTERNAL_RETURN_DATA_INFO_HPP
#define SO_INTERNAL_RETURN_DATA_INFO_HPP

#include "./Internal_DataInfo.hpp"

namespace SimpleOverride
{
    struct Internal_ReturnDataInfo : public Internal_DataInfo
    {
        std::function<void(const std::vector<void*>& args, void* out)> DataAction;
        bool DataActionSet = false;
    };
}


#endif