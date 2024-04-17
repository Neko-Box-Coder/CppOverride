#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };

    ssTEST("Return Primitive Type Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                            .Returns<int>(32)
                            .AssignStatus(status);

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 32);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return String Type Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnStringFunc)
                            .Returns<std::string>("test")
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ReturnStringFunc(1) == "test");
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Void Early Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, AssignArgInternallyFunc)
                            .ReturnsVoid()
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_SETUP
        (
            std::string testString = "test";
            std::string testString2 = "test2";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("ReturnsVoid Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        
        ssTEST_CALL_SET_UP();
        
        
        ssTEST_OUTPUT_SETUP
        (
            status = CppOverride::DEFAULT_STATUS;
        );
        CO_SETUP_OVERRIDE   (OverrideObj, AssignArgInternallyFunc)
                            .Returns<void>()
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("Returns<void> Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Reference Should Succeed")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
        );
        
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnReferenceFunc)
                            .Returns<int&>(testNum)
                            .AssignStatus(status);

        ssTEST_OUTPUT_EXECUTION
        (
            int& testNum2 = CppOverrideTest::NonConst::ReturnReferenceFunc(1);
        );
        ssTEST_OUTPUT_ASSERT(testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Pointer Should Succeed")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
        );
        
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnPointerFunc)
                            .Returns<int*>(&testNum)
                            .AssignStatus(status);

        ssTEST_OUTPUT_EXECUTION
        (
            int* testNum2 = CppOverrideTest::NonConst::ReturnPointerFunc(1);
        );

        ssTEST_OUTPUT_ASSERT(&testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Nothing Should Not Override Return Value")
    {
        //TODO(NOW): Right now it is not possible to override to return nothing because
        //              - If it doesn't override, you can't perform any actions such as 
        //                  WhenCalledExpectedly_Do or Otherwise_Do.
        //              - But if it does override for the actions, it will need to return SOMETHING
        
        CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
        CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                            .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN)
                            .AssignStatus(status);

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Type Not Matching Should Not Override Return Value")
    {
        CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
        CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                            .Returns<float>(2.f)
                            .AssignStatus(status);

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::NO_OVERRIDE);
    };
    
    ssTEST("Return Object Should Succeed")
    {
        ssTEST_OUTPUT_SETUP
        (
            TestClass assertObject(1, 2.0, "test");
        );
        
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnObjectFunc)
                            .Returns<TestClass>(assertObject)
                            .AssignStatus(status);
        
        using namespace CppOverrideTest::NonConst::Object;
        ssTEST_OUTPUT_ASSERT(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return Template Object Should Succeed")
    {
        ssTEST_OUTPUT_SETUP
        (
            TestClass assertObject(1, 2.f, "test");
            TestClass testObject(2, 3.f, "test 2");
        );
        
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, TemplateReturnFunc)
                            .Returns<TestClass>(assertObject)
                            .AssignStatus(status);
        
        using namespace CppOverrideTest::NonConst::Template;
        ssTEST_OUTPUT_ASSERT(TemplateReturnFunc<TestClass>(testObject) == assertObject);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Return By Action Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, NoArgsFunc)
                            .ReturnsByAction<int>
                            (
                                [](const std::vector<void *>& args, void* out)
                                {
                                    (*(int*)(out)) = 10;
                                }
                            )
                            .AssignStatus(status);

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 10);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    
    
    ssTEST_END();
    
    return 0;
}
