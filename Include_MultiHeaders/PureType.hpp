#ifndef CO_PURE_TYPE_HPP
#define CO_PURE_TYPE_HPP

#include <type_traits>

namespace CppOverride
{
    #define INTERNAL_CO_UNCONST(targetType) typename std::remove_const<targetType>::type
    
    #define INTERNAL_CO_UNREF(targetType) typename std::remove_reference<targetType>::type
    
    #define INTERNAL_CO_UNPOINTER(targetType) typename std::remove_pointer<targetType>::type
    
    #define INTERNAL_CO_RAW_TYPE(targetType) \
        typename std::decay<INTERNAL_CO_UNCONST(targetType)>::type
    
    #define INTERNAL_CO_PURE_TYPE(targetType) \
        typename std::decay<INTERNAL_CO_UNCONST(INTERNAL_CO_UNPOINTER(targetType))>::type
}

#endif
