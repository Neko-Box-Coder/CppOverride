#include "CppOverride.hpp"
#include "ssTest.hpp"

#include "./Components/FreeFunctions.hpp"
#include "./Components/MockFreeFunctions.hpp"

// CppOverride::Overrider OverrideObj;
CO_DECLARE_INSTANCE(OverrideObj);

int main(int argc, char** argv)
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    ssTEST_COMMON_SETUP
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
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest, MockFreeFunctionA)
                            .Returns<int>(10)
                            .Expected();
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest, MockFreeFunctionB)
                            .Returns<int>(10)
                            .Expected();
        );
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionA(1) == 10);
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::FreeFunctionB(1, 2) == 10);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
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
