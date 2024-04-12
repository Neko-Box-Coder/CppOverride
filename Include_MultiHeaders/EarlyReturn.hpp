#ifndef CO_EARLY_RETURN_HPP
#define CO_EARLY_RETURN_HPP

#include <type_traits>

namespace CppOverride
{
    template<   typename T,
                typename = typename std::enable_if<!std::is_reference<T>::value>::type,
                typename = typename std::enable_if<!std::is_reference<T>::value>::type>
    T EarlyReturn()
    {
        return T();
    }
    
    template<   typename T,
                typename = typename std::enable_if<std::is_reference<T>::value>::type>
    T EarlyReturn()
    {
        typename std::remove_reference<T>::type* dummy = nullptr;
        return *dummy;
    }
    
}

#endif