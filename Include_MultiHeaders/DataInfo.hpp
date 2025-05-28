#ifndef CO_DATA_INFO_HPP
#define CO_DATA_INFO_HPP

#include <cstddef>
#include <functional>
#include <vector>
#include <memory>

namespace CppOverride
{
    struct DataInfo
    {
        std::size_t DataType = 0;
        std::shared_ptr<void> Data = nullptr;
        bool DataSet = false;
    };
    
    struct ReturnDataInfo : public DataInfo
    {
        bool ReturnReference = false;
        bool ReturnAny = false;
    };
}

#endif
