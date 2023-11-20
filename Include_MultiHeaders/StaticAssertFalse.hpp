#ifndef SO_STATIC_ASSERT_FALSE
#define SO_STATIC_ASSERT_FALSE

#include <type_traits>

namespace SimpleOverride
{
    template<typename T>
    struct SO_ASSERT_FALSE : std::false_type { };
}

#endif