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

    ssTEST("Return Primitive Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                                                .Returns<int>(32)
                                                                .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 32);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return String Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, ReturnStringFunc)
                                                                .Returns<std::string>("test")
                                                                .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ReturnStringFunc(1) == "test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Void Early Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, AssignArgInternallyFunc)
                                                                .ReturnsVoid()
                                                                .ReturnsResult();
            std::string testString = "test";
            std::string testString2 = "test2";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("ReturnsVoid Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
            CO_CLEAR_ALL_OVERRIDE_SETUP(OverrideObj);
            CO_SETUP_OVERRIDE   (OverrideObj, AssignArgInternallyFunc)
                                .Returns<void>()
                                .AssignsResult(result);
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("Returns<void> Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Reference Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, ReturnReferenceFunc)
                                                                .Returns<int&>(testNum)
                                                                .ReturnsResult();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int& testNum2 = CppOverrideTest::NonConst::ReturnReferenceFunc(1);
        );
        ssTEST_OUTPUT_ASSERT(testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Pointer Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, ReturnPointerFunc)
                                                                .Returns<int*>(&testNum)
                                                                .ReturnsResult();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int* testNum2 = CppOverrideTest::NonConst::ReturnPointerFunc(1);
        );
        ssTEST_OUTPUT_ASSERT(&testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Nothing Should Not Override Return Value")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                    .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN)
                                    .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Type Not Matching Should Not Override Return Value")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                                                .Returns<float>(2.f)
                                                                .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(result->GetStatusCount() == 0);
    };
    
    ssTEST("Return Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass assertObject(1, 2.0, "test");
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   (OverrideObj, ReturnObjectFunc)
                                    .Returns<CppOverrideTest::TestClass>(assertObject)
                                    .ReturnsResult();
        );
        using namespace CppOverrideTest::NonConst::Object;
        ssTEST_OUTPUT_ASSERT(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Template Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass assertObject(1, 2.f, "test");
            CppOverrideTest::TestClass testObject(2, 3.f, "test 2");
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   (OverrideObj, TemplateReturnFunc)
                                    .Returns<CppOverrideTest::TestClass>(assertObject)
                                    .ReturnsResult();
        );
        using namespace CppOverrideTest::NonConst::Template;
        ssTEST_OUTPUT_ASSERT(TemplateReturnFunc<CppOverrideTest::TestClass>(testObject) == assertObject);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                    .ReturnsByAction<int>
                                    (
                                        [](void*, const std::vector<void *>&, void* out)
                                        {
                                            (*(int*)(out)) = 10;
                                        }
                                    )
                                    .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 10);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
