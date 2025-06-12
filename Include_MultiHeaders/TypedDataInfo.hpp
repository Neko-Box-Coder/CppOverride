#ifndef CO_TYPED_DATA_INFO_HPP
#define CO_TYPED_DATA_INFO_HPP

#include <typeinfo>
#include <cstddef>

namespace CppOverride
{
    struct TypedDataInfo
    {
        void* Data = nullptr;
        std::size_t TypeHash = 0;
        bool IsSet = false;
        
        TypedDataInfo() = default;
        
        template<typename T>
        TypedDataInfo(T* dataPtr) : Data(dataPtr), 
                                    TypeHash(typeid(T).hash_code()), 
                                    IsSet(dataPtr != nullptr)
        {}
        
        template<typename T>
        T* GetTypedDataPtr() const
        {
            return static_cast<T*>(Data);
        }
        
        template<typename T>
        bool IsType() const
        {
            return IsSet && (TypeHash == typeid(T).hash_code());
        }
    };
}

#endif 
