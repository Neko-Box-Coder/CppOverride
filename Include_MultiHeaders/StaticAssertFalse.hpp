#ifndef CO_STATIC_ASSERT_FALSE_HPP
#define CO_STATIC_ASSERT_FALSE_HPP

#include <type_traits>

namespace CppOverride
{
    template<typename T>
    struct CoAssertFalseType : std::false_type { };
}

#endif
