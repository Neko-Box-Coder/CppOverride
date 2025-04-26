#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main(int argc, char** argv)
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    
    ssTEST_COMMON_SETUP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Override Both Args And Return In One Statement Should Override Once")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
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
                                .AssignResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_EXECUTION
        (
            executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg2, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg2 == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 2);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Multiple Matching Overrides Should Apply The First One")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            std::shared_ptr<CppOverride::OverrideResult> result2 = CppOverride::CreateOverrideResult();
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
                                .AssignResult(result);
            
            CO_SETUP_OVERRIDE  (OverrideObj, AddNumFromNumPointerFunc)
                                .SetArgs<int*, CO_ANY_TYPE>(10, CO_DONT_SET)
                                .WhenCalledExpectedly_Do
                                (
                                    [&calledCounter](...)
                                    {
                                        ++calledCounter;
                                    }
                                )
                                .AssignResult(result2);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int executeResult = CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 5);
        ssTEST_OUTPUT_ASSERT(executeResult == 32);
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        ssTEST_OUTPUT_ASSERT(result2->GetStatusCount() == 0);
    };
    
    ssTEST("Modify None With Action Result Should Perform Action")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
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
                                .AssignResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        );
        
        ssTEST_OUTPUT_ASSERT(calledCounter == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
