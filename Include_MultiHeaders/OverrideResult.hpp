#ifndef CO_OVERRIDE_RESULT_HPP
#define CO_OVERRIDE_RESULT_HPP

#include "./OverrideStatus.hpp"

namespace CppOverride
{
    struct OverrideResult
    {
        OverrideStatus ReturnStatus = OverrideStatus::NO_OVERRIDE;
        OverrideStatus SetArgsStatus = OverrideStatus::NO_OVERRIDE;
    };
}

#endif