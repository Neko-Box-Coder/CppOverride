#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Return With Zero Time Set Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Times(0)
                        .Returns<int>(1);
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
    }
    
    //Return With One Time Set Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Times(1)
                        .Returns<int>(1)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
    }
    
    //Return With Two Times Set Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Times(2)
                        .Returns<int>(1)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
    }
    
    //Return With No Time Set Should Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Returns<int>(1)
                        .Expected();
        
        for(int i = 0; i < 10; i++)
        {
            DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
            DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        }
    }
    
    //Return Exceeding Times Set Should Set OverrideStatus To MATCHING_OVERRIDE_TIMES_FAILED
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                        .Times(2)
                        .Returns<int>(1)
                        .AssignsResult(result);

        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), 1);
        DS_ASSERT_TRUE(result->LastStatusSucceed());

        DS_ASSERT_EQ(CppOverrideTest::NonConst::NoArgsFunc(), -1);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED);
    }
    
    //SetArgs With Zero Time Set Should Override
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .Times(0)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test");
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 0.f);
        DS_ASSERT_TRUE(testString.empty());
    }
    
    //SetArgs With One Time Set Should Override
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .Times(1)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Expected();
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 2.f);
        DS_ASSERT_EQ(testString, "Test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());

        testFloat = 0.f;
        testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 0.f);
        DS_ASSERT_TRUE(testString.empty());
    }
    
    //SetArgs With Two Times Set Should Override
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .Times(2)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Expected();
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 2.f);
        DS_ASSERT_EQ(testString, "Test");

        testFloat = 0.f;
        testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 2.f);
        DS_ASSERT_EQ(testString, "Test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        
        testFloat = 0.f;
        testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 0.f);
        DS_ASSERT_TRUE(testString.empty());
    }
    
    //SetArgs With No Time Set Should Override
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Expected();
        float testFloat = 0.f;
        std::string testString = "";

        for(int i = 0; i < 10; i++)
        {
            testFloat = 0.f;
            testString = "";
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
            DS_ASSERT_EQ(testFloat, 2.f);
            DS_ASSERT_EQ(testString, "Test");
            DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        }
    }
    
    //SetArgs Exceeding Times Set Should Set OverrideStatus To MATCHING_OVERRIDE_TIMES_FAILED
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .Times(2)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .AssignsResult(result);
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 2.f);
        DS_ASSERT_EQ(testString, "Test");
        DS_ASSERT_TRUE(result->LastStatusSucceed());

        testFloat = 0.f;
        testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 2.f);
        DS_ASSERT_EQ(testString, "Test");
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        testFloat = 0.f;
        testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 0.f);
        DS_ASSERT_TRUE(testString.empty());
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED);
    }
    
    //0 Time Expected Should Be Met When No Calls Are Made
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Times(0)
                            .Expected();

        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //0 Time Expected Should Not Be Met When Calls Are Made
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Times(0)
                            .Expected();
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);

        DS_ASSERT_EQ(CO_GET_FAILED_FUNCTIONS(OverrideObj).size(), 1);
    }
    
    //0 Time Not Expected Should Be Met When Calls Are Made
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Times(0)
                            .ExpectedNotSatisfied();
        float testFloat = 0.f;
        std::string testString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);

        DS_ASSERT_EQ(CO_GET_FAILED_FUNCTIONS(OverrideObj).size(), 0);
    }
    
    //0 Time Not Expected Should Not Be Met When Calls Are Not Made
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                            .Times(0)
                            .ExpectedNotSatisfied();

        DS_ASSERT_EQ(CO_GET_FAILED_FUNCTIONS(OverrideObj).size(), 1);
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
