#ifndef CO_EARLY_RETURN_HPP
#define CO_EARLY_RETURN_HPP

#include <type_traits>
//#include <stdexcept>

namespace CppOverride
{
    template<   typename T,
                typename std::enable_if<!std::is_reference<T>::value, bool>::type = true>
    inline T EarlyReturn()
    {
        return T();
    }
    
    template
    <
        typename T,
        typename std::enable_if
        <
            std::is_reference<T>::value &&
            std::is_default_constructible<typename std::remove_reference<T>::type>::value, 
            bool
        >::type = true
    >
    inline T EarlyReturn()
    {
        using NonRefT = typename std::remove_reference<T>::type;
        NonRefT temp;
        return temp;
    }
    
    template
    <
        typename T,
        typename std::enable_if
        <
            std::is_reference<T>::value &&
            !std::is_default_constructible<typename std::remove_reference<T>::type>::value, 
            bool
        >::type = true
    >
    inline T EarlyReturn()
    {
        typename std::remove_reference<T>::type* dummy = nullptr;
        //throw std::runtime_error(   "Trying to return a reference for an fully overridden method but "
        //                            "no override return is found or setup.");
        return *dummy;
    }
}

#endif
