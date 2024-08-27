#ifndef CO_INTERNAL_DATA_INFO_HPP
#define CO_INTERNAL_DATA_INFO_HPP

#include <cstddef>
#include <functional>
#include <vector>
#include <memory>

namespace CppOverride
{
    struct Internal_DataInfo
    {
        std::size_t DataType = 0;
        std::shared_ptr<void> Data = nullptr;
        bool DataSet = false;
    };
    
    struct Internal_ReturnDataInfo : public Internal_DataInfo
    {
        bool ReturnReference = false;
        bool ReturnAny = false;
    };
}

#endif
