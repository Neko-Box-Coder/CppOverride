#ifndef CO_STATIC_ASSERT_FALSE
#define CO_STATIC_ASSERT_FALSE

#include <type_traits>

namespace CppOverride
{
    template<typename T>
    struct CO_ASSERT_FALSE : std::false_type { };
}

#endif