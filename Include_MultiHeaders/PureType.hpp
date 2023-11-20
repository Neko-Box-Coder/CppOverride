#ifndef SO_PURE_TYPE_HPP
#define SO_PURE_TYPE_HPP

#include <type_traits>

namespace SimpleOverride
{
    #define INTERNAL_SO_UNCONST(targetType) typename std::remove_const<targetType>::type
    #define INTERNAL_SO_NON_CONST_T INTERNAL_SO_UNCONST(T)
    
    #define INTERNAL_SO_UNREF(targetType) typename std::remove_reference<targetType>::type
    
    #define INTERNAL_SO_UNPOINTER(targetType) typename std::remove_pointer<targetType>::type
    
    #define INTERNAL_SO_PURE_TYPE(targetType)\
        INTERNAL_SO_UNCONST(INTERNAL_SO_UNREF(INTERNAL_SO_UNPOINTER(targetType)))
}

#endif