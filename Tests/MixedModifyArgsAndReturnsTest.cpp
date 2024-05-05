#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //TODO(NOW): Modify both and Modify Args and Returns should apply on the first one
    
    //TODO(NOW): Modify Args and Returns separately should only apply 1 and the first one
    
    //TODO(NOW): Modify None but expect result actions to be performed
    
    ssTEST("Override Both Args And Return In One Statement Should Override Once")
    {
        CppOverride::OverrideResult result;
        
        int testArg = 1;
        int calledCounter = 0;
        
        CO_SETUP_OVERRIDE   (OverrideObj, AddNumFromNumPointerFunc)
                            .SetArgs<int*, CO_ANY_TYPE>(5, CO_DONT_SET)
                            .Returns<int>(32)
                            .WhenCalledExpectedly_Do
                            (
                                [&calledCounter](...)
                                {
                                    ++calledCounter;
                                }
                            )
                            .AssignOverrideResult(result);
        
        int testArg2 = 1;
        
        int executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg2, 2);
        
        ssTEST_OUTPUT_ASSERT(testArg2 == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        
        ssTEST_OUTPUT_ASSERT(testArg2 == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 2);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        
        
    };
    
    ssTEST_END();
    
    return 0;
}