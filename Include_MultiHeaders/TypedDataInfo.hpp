#ifndef CO_TYPED_DATA_INFO_HPP
#define CO_TYPED_DATA_INFO_HPP

#include "PureType.hpp"

#include <typeinfo>
#include <cstddef>
#include <memory>

namespace CppOverride
{
    struct TypedDataInfo
    {
        std::shared_ptr<void> ManagedData = nullptr;
        void* UnmanagedData = nullptr;
        std::size_t TypeHash = 0;
        bool IsSet = false;
        bool Managed = false;
        
        template<typename T>
        inline TypedDataInfo& CreateReference(INTERNAL_CO_UNREF(T)* dataPtr)
        {
            UnmanagedData = dataPtr;
            TypeHash = typeid(T).hash_code();
            IsSet = dataPtr != nullptr;
            Managed = false;
            return *this;
        }
        
        template<typename T>
        inline TypedDataInfo& CreateValue(T data)
        {
            ManagedData = std::shared_ptr<void>(new INTERNAL_CO_UNREF(T)(data));
            TypeHash = typeid(T).hash_code();
            IsSet = true;
            Managed = true;
            return *this;
        }
        
        template<typename T>
        inline INTERNAL_CO_UNREF(T)* GetTypedDataPtr() const
        {
            return static_cast<INTERNAL_CO_UNREF(T)*>(Managed ? ManagedData.get() : UnmanagedData);
        }
        
        template<typename T>
        inline bool IsType() const
        {
            return IsSet && (TypeHash == typeid(T).hash_code());
        }
    };
}

#endif 
