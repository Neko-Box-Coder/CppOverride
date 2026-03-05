#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Override Both Args And Return In One Statement Should Override Once
    {
        setup();
        int testArg = 1;
        int testArg2 = 1;
        int calledCounter = 0;
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromNumPointerFunc)
                        .SetArgs<int*, CO_ANY_TYPE>(5, CO_DONT_SET)
                        .Returns<int>(32)
                        .WhenCalledExpectedly_Do
                        (
                            [&calledCounter](...)
                            {
                                ++calledCounter;
                            }
                        )
                        .Expected();
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2), 32);
        
        DS_ASSERT_EQ(testArg, 5);
        DS_ASSERT_EQ(calledCounter, 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg2, 2), 32);
        DS_ASSERT_EQ(testArg2, 5);
        DS_ASSERT_EQ(calledCounter, 2);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Multiple Matching Overrides Should Apply The First One
    {
        setup();
        int testArg = 1;
        int calledCounter = 0;
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromNumPointerFunc)
                        .SetArgs<int*, CO_ANY_TYPE>(5, CO_DONT_SET)
                        .Returns<int>(32)
                        .WhenCalledExpectedly_Do
                        (
                            [&calledCounter](...)
                            {
                                ++calledCounter;
                            }
                        )
                        .Expected();
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromNumPointerFunc)
                        .SetArgs<int*, CO_ANY_TYPE>(10, CO_DONT_SET)
                        .WhenCalledExpectedly_Do
                        (
                            [&calledCounter](...)
                            {
                                ++calledCounter;
                            }
                        )
                        .ExpectedNotSatisfied();
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2), 32);
        DS_ASSERT_EQ(testArg, 5);
        DS_ASSERT_EQ(calledCounter, 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    };
    
    //Modify None With Action Result Should Perform Action
    {
        setup();
        int testArg = 1;
        int calledCounter = 0;
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromNumPointerFunc)
                        .WhenCalledExpectedly_Do
                        (
                            [&calledCounter](...)
                            {
                                ++calledCounter;
                            }
                        )
                        .Times(1)
                        .Expected();
        
        CppOverrideTest::NonConst::AddNumFromNumPointerFunc(&testArg, 2);
        
        DS_ASSERT_EQ(calledCounter, 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
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
