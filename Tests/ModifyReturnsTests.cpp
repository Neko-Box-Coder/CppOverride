#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_COMMON_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };

    ssTEST("Return Primitive Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                .Returns<int>(32)
                                .AssignResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 32);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return String Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, ReturnStringFunc)
                                .Returns<std::string>("test")
                                .AssignResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ReturnStringFunc(1) == "test");
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Void Early Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, AssignArgInternallyFunc)
                                .ReturnsVoid()
                                .AssignResult(result);
            
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
                                .AssignResult(result);
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, ReturnReferenceFunc)
                                .Returns<int&>(testNum)
                                .AssignResult(result);
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, ReturnPointerFunc)
                                .Returns<int*>(&testNum)
                                .AssignResult(result);
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN)
                                .AssignResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Type Not Matching Should Not Override Return Value")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                .Returns<float>(2.f)
                                .AssignResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(result->GetStatusCount() == 0);
    };
    
    ssTEST("Return Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass assertObject(1, 2.0, "test");
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, ReturnObjectFunc)
                                .Returns<CppOverrideTest::TestClass>(assertObject)
                                .AssignResult(result);
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, TemplateReturnFunc)
                                .Returns<CppOverrideTest::TestClass>(assertObject)
                                .AssignResult(result);
        );
        using namespace CppOverrideTest::NonConst::Template;
        ssTEST_OUTPUT_ASSERT(TemplateReturnFunc<CppOverrideTest::TestClass>(testObject) == assertObject);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                                .ReturnsByAction<int>
                                (
                                    [](void*, const std::vector<void *>&, void* out)
                                    {
                                        (*(int*)(out)) = 10;
                                    }
                                )
                                .AssignResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 10);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
