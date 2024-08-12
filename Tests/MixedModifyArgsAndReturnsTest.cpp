#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_COMMON_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Override Both Args And Return In One Statement Should Override Once")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            int testArg = 1;
            int testArg2 = 1;
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
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        ssTEST_OUTPUT_EXECUTION
        (
            executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg2, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg2 == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 2);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Multiple Matching Overrides Should Apply The First One")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CppOverride::OverrideResult result2;
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
            
            CO_SETUP_OVERRIDE  (OverrideObj, AddNumFromNumPointerFunc)
                                .SetArgs<int*, CO_ANY_TYPE>(10, CO_DONT_SET)
                                .WhenCalledExpectedly_Do
                                (
                                    [&calledCounter](...)
                                    {
                                        ++calledCounter;
                                    }
                                )
                                .AssignOverrideResult(result2);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        ssTEST_OUTPUT_ASSERT(result2.Status == CppOverride::OverrideStatus::NO_OVERRIDE);
    };
    
    ssTEST("Modify None With Action Result Should Perform Action")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            int testArg = 1;
            int calledCounter = 0;
            
            CO_SETUP_OVERRIDE   (OverrideObj, AddNumFromNumPointerFunc)
                                .WhenCalledExpectedly_Do
                                (
                                    [&calledCounter](...)
                                    {
                                        ++calledCounter;
                                    }
                                )
                                .AssignOverrideResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
