#ifndef CO_IS_SIMPLE_STL_CONTAINER_HPP
#define CO_IS_SIMPLE_STL_CONTAINER_HPP

#include <type_traits>

namespace CppOverride
{
    template<typename... Ts>
    struct make_void { typedef void type; };
     
    template<typename... Ts>
    using void_t = typename make_void<Ts...>::type;
    
    template<typename T, typename = void>
    struct IsSimpleSTLContainer : std::false_type {};
    
    template<typename T>
    struct IsSimpleSTLContainer<T, void_t<typename T::value_type>> : std::true_type {};
}

#endif
