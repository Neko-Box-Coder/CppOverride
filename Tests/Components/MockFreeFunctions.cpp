#include "./MockFreeFunctions.hpp"
#include "CppOverride.hpp"

extern CO_DECLARE_INSTANCE(OverrideObj);

namespace CppOverrideTest
{
    int MockFreeFunctionA(int arg)
    {
        CO_INSERT_IMPL(OverrideObj, int, (arg));
        return arg;
    }
    
    int MockFreeFunctionB(int arg, int arg2)
    {
        CO_INSERT_IMPL(OverrideObj, int, (arg, arg2));
        return arg + arg2;
    }
}


