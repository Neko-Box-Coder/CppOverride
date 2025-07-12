#ifndef CO_TYPED_INFO_HPP
#define CO_TYPED_INFO_HPP

#include <typeinfo>
#include <cstddef>

namespace CppOverride
{
    struct TypedInfo
    {
        std::size_t TypeHash = 0;
        bool IsSet = false;
        
        template<typename T>
        inline TypedInfo& Create()
        {
            TypeHash = typeid(T).hash_code();
            IsSet = true;
            return *this;
        }
        
        template<typename T>
        inline bool IsType() const
        {
            return IsSet && (TypeHash == typeid(T).hash_code());
        }
    };
}

#endif 
