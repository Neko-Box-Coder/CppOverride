#include "CppOverride.hpp"

#include "./Components/FreeFunctions.hpp"
#include "./Components/MockFreeFunctions.hpp"

#include "DSResult/DSResult.hpp"
#include <iostream>

// CppOverride::Overrider OverrideObj;
CO_DECLARE_INSTANCE(OverrideObj);

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Free Functions Should Work
    {
        setup();
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionA(1), 1);
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionB(1, 2), 3);
    }
    
    //#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
        #define FreeFunctionA MockFreeFunctionA
        #define FreeFunctionB MockFreeFunctionB
    //#endif
    
    //Mock Free Functions Should Work
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest, MockFreeFunctionA)
                        .Returns<int>(10)
                        .Expected();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest, MockFreeFunctionB)
                        .Returns<int>(10)
                        .Expected();
        
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionA(1), 10);
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionB(1, 2), 10);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    #ifdef FreeFunctionA
        #undef FreeFunctionA
    #endif
    
    #ifdef FreeFunctionB
        #undef FreeFunctionB
    #endif
    
    //Free Functions Should Work When After Mocking
    {
        setup();
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionA(1), 1);
        DS_ASSERT_EQ(CppOverrideTest::FreeFunctionB(1, 2), 3);
    };
    
    return {};
}

int main(int, char**)
{
    try
    {
        TestMain().DS_TRY_ACT(std::cout << DS_TMP_ERROR.ToString() << std::endl; return 1);
        return 0;
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    return 1;
}
