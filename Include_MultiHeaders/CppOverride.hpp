#ifndef CO_CPP_OVERRIDE_HPP
#define CO_CPP_OVERRIDE_HPP


#include "./CppOverrideInstance.hpp"
#include "./OverrideInfoSetterImplementation.hpp"
#include "./Macros.hpp"
#include "./AliasTypes.hpp"

namespace CppOverride
{
    struct Overridable
    {
        CO_DECLARE_MEMBER_INSTANCE(CurrentOverrideInstance);
        CO_DECLARE_OVERRIDE_METHODS(CurrentOverrideInstance);
    };
}

#endif
