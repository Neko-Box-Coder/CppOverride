#ifndef CO_IS_SIMPLE_STL_CONTAINER_HPP
#define CO_IS_SIMPLE_STL_CONTAINER_HPP

#include <type_traits>

namespace CppOverride
{
    template<typename T, typename = void>
    struct IsSimpleSTLContainer : std::false_type {};
    
    template<typename T>
    struct IsSimpleSTLContainer<T, std::void_t<typename T::value_type>> : std::true_type {};
}

#endif
