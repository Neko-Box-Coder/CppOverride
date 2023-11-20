#ifndef SO_INTERNAL_DATA_INFO_HPP
#define SO_INTERNAL_DATA_INFO_HPP

#include <cstddef>
#include <functional>
#include <vector>

namespace SimpleOverride
{
    struct Internal_DataInfo
    {
        std::size_t DataType = 0;
        void* Data = nullptr;
        std::function<void*(void*)> CopyConstructor;
        std::function<void(void*)> Destructor;
        bool DataSet = false;
    };
}

#endif