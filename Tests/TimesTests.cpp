#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"

CppOverride::Overrider OverrideObj;

int main(int argc, char** argv)
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    ssTEST_COMMON_SETUP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Return With Zero Time Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT(OverrideObj, NoArgsFunc).Times(0).Returns<int>(1);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
    };
    
    ssTEST("Return With One Time Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT (OverrideObj, NoArgsFunc)
                                .Times(1)
                                .Returns<int>(1)
                                .AssignsResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
    };
    
    ssTEST("Return With Two Times Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT(OverrideObj, NoArgsFunc).Times(2).Returns<int>(1).AssignsResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
    };
    
    ssTEST("Return With No Time Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT(OverrideObj, NoArgsFunc).Returns<int>(1).AssignsResult(result);
        );
        
        for(int i = 0; i < 10; i++)
        {
            ssTEST_OUTPUT_ASSERT(   "Try " + std::to_string(i), 
                                    CppOverrideTest::NonConst::NoArgsFunc() == 1);
            
            ssTEST_OUTPUT_ASSERT(   "Try " + std::to_string(i),
                                    result->LastStatusSucceed());
        }
    };
    
    ssTEST("Return Exceeding Times Set Should Set OverrideStatus To MATCHING_OVERRIDE_TIMES_FAILED")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT(OverrideObj, NoArgsFunc).Times(2).Returns<int>(1).AssignsResult(result);
        );

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED);
    };
    
    ssTEST("SetArgs With Zero Time Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT (OverrideObj, ArgsToSetFunc)
                        .Times(0)
                        .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test");
            
            float testFloat = 0.f;
            std::string testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 0.f);
        ssTEST_OUTPUT_ASSERT(testString.empty() == true);
    };
    
    ssTEST("SetArgs With One Time Set Should Override")
    {

        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT (OverrideObj, ArgsToSetFunc)
                        .Times(1)
                        .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                        .AssignsResult(result);
            
            float testFloat = 0.f;
            std::string testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());

        ssTEST_OUTPUT_SETUP
        (
            testFloat = 0.f;
            testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 0.f && testString.empty() == true);
    };
    
    ssTEST("SetArgs With Two Times Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT (OverrideObj, ArgsToSetFunc)
                        .Times(2)
                        .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                        .AssignsResult(result);
            
            float testFloat = 0.f;
            std::string testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());


        ssTEST_OUTPUT_SETUP
        (
            testFloat = 0.f;
            testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        
        ssTEST_OUTPUT_SETUP
        (
            testFloat = 0.f;
            testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 0.f && testString.empty() == true);
    };
    
    ssTEST("SetArgs With No Time Set Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT (OverrideObj, ArgsToSetFunc)
                        .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                        .AssignsResult(result);
            
            float testFloat = 0.f;
            std::string testString = "";
        );

        for(int i = 0; i < 10; i++)
        {
            ssTEST_OUTPUT_SETUP
            (
                testFloat = 0.f;
                testString = "";
            );
            ssTEST_OUTPUT_EXECUTION
            (
                CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
            );
            ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
            ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        }
    };
    
    ssTEST("SetArgs Exceeding Times Set Should Set OverrideStatus To MATCHING_OVERRIDE_TIMES_FAILED")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_INSTRUCT (OverrideObj, ArgsToSetFunc)
                        .Times(2)
                        .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 2.f, "Test")
                        .AssignsResult(result);
            
            float testFloat = 0.f;
            std::string testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());


        ssTEST_OUTPUT_SETUP
        (
            testFloat = 0.f;
            testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 2.f && testString == "Test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        
        ssTEST_OUTPUT_SETUP
        (
            testFloat = 0.f;
            testString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(0, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 0.f && testString.empty() == true);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED);
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
