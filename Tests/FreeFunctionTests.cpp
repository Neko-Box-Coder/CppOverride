#include "CppOverride.hpp"
#include "ssTest.hpp"

#include "./Components/FreeFunctions.hpp"
#include "./Components/MockFreeFunctions.hpp"

// CppOverride::Overrider OverrideObj;
CO_DECLARE_INSTANCE(OverrideObj);

int main()
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_COMMON_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Free Functions Should Work")
    {
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionA(1) == 1);
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionB(1, 2) == 3);
    };
    
    //#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
        #define FreeFunctionA MockFreeFunctionA
        #define FreeFunctionB MockFreeFunctionB
    //#endif
    
    ssTEST("Mock Free Functions Should Work")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, MockFreeFunctionA)
                                .Returns<int>(10)
                                .AssignResult(result);
            
            CO_SETUP_OVERRIDE   (OverrideObj, MockFreeFunctionB)
                                .Returns<int>(10)
                                .AssignResult(result);
        );
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionA(1) == 10);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionB(1, 2) == 10);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    #ifdef FreeFunctionA
        #undef FreeFunctionA
    #endif
    
    #ifdef FreeFunctionB
        #undef FreeFunctionB
    #endif
    
    ssTEST("Free Functions Should Work When After Mocking")
    {
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionA(1) == 1);
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionB(1, 2) == 3);
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
