#ifndef CO_TYPE_CHECK_HPP
#define CO_TYPE_CHECK_HPP

#include <type_traits>
namespace CppOverride
{
    template<typename T, typename = void>
    struct InequalExists : std::false_type {};
    
    template<typename T>
    struct InequalExists
    <
        T, decltype(std::declval<T>() != std::declval<T>(), void())
    > : std::true_type {};
}

#endif
