#ifndef CO_OVERRIDE_RESULT_HPP
#define CO_OVERRIDE_RESULT_HPP

#include "./OverrideStatus.hpp"

namespace CppOverride
{
    struct OverrideResult
    {
        OverrideStatus Status = OverrideStatus::NO_OVERRIDE;
    };
}

#endif