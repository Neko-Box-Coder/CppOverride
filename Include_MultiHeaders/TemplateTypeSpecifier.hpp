#ifndef CO_TEMPLATE_TYPE_SPECIFIER_HPP
#define CO_TEMPLATE_TYPE_SPECIFIER_HPP

#include "./PureType.hpp"
#include <type_traits>

namespace CppOverride
{
    //NOTE: This is used to avoid auto type translation
    template<typename T>
    struct TypeSpecifier { using Type = T; };
    
    template<   typename T,
                typename VoidType = void>
    struct TypeUnwrapper
    { 
        static_assert(std::is_same<VoidType, void>::value, "");
        static_assert(std::is_same<T, void>::value, "");
    };
    
    template<typename T>
    struct TypeUnwrapper
    <
        T, typename std::enable_if<!std::is_same<INTERNAL_CO_UNCONST(T), void*>::value>::type
    >
    {
        using Type = INTERNAL_CO_PURE_TYPE(T);
    };
    
    template<typename T>
    struct TypeUnwrapper
    <
        T, typename std::enable_if<std::is_same<INTERNAL_CO_UNCONST(T), void*>::value>::type
    >
    {
        using Type = INTERNAL_CO_UNCONST(T);
    };
}

#endif
