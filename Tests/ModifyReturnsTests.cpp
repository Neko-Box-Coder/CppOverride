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
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc) 
                            .Returns<int>(32)
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 32);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return String Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnStringFunc)  
                            .Returns<std::string>("test")
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ReturnStringFunc(1) == "test");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Void Early Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                            .ReturnsVoid()
                            .Expected();
            std::string testString = "test";
            std::string testString2 = "test2";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("ReturnsVoid Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
        
        
        ssTEST_OUTPUT_SETUP
        (
            CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                            .Returns<void>()
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc(testString, testString2);
        );
        ssTEST_OUTPUT_ASSERT("Returns<void> Function", testString2 == "test2");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Reference Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnReferenceFunc)
                            .Returns<int&>(testNum)
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int& testNum2 = CppOverrideTest::NonConst::ReturnReferenceFunc(1);
        );
        ssTEST_OUTPUT_ASSERT(testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Pointer Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            int testNum = 1;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ReturnPointerFunc)
                            .Returns<int*>(&testNum)
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int* testNum2 = CppOverrideTest::NonConst::ReturnPointerFunc(1);
        );
        ssTEST_OUTPUT_ASSERT(&testNum == testNum2);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Nothing Should Not Override Return Value")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                            .Returns<CO_ANY_TYPE>(CO_DONT_OVERRIDE_RETURN)
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Type Not Matching Should Not Override Return Value")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                            .Returns<float>(2.f)
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == -1);
        ssTEST_OUTPUT_ASSERT("", CO_GET_FAILED_EXPECTS(OverrideObj).size(), 1);
    };
    
    ssTEST("Return Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass assertObject(1, 2.0, "test");
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst::Object, ReturnObjectFunc)
                            .Returns<CppOverrideTest::TestClass>(assertObject)
                            .Expected();
        );
        using namespace CppOverrideTest::NonConst::Object;
        ssTEST_OUTPUT_ASSERT(ReturnObjectFunc(1, 3.0, "test 2") == assertObject);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return Template Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass assertObject(1, 2.f, "test");
            CppOverrideTest::TestClass testObject(2, 3.f, "test 2");
            CO_INSTRUCT_REF 
            (
                OverrideObj, 
                CppOverrideTest::NonConst::Template, 
                TemplateReturnFunc<CppOverrideTest::TestClass>
            )
            .Returns<CppOverrideTest::TestClass>(assertObject)
            .Expected();
        );
        using namespace CppOverrideTest::NonConst::Template;
        ssTEST_OUTPUT_ASSERT(TemplateReturnFunc<CppOverrideTest::TestClass>(testObject) == assertObject);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Return By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, NoArgsFunc)
                            .ReturnsByAction<int>
                            (
                                [](void*, const std::vector<void *>&, void* out)
                                {
                                    (*(int*)(out)) = 10;
                                }
                            )
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::NoArgsFunc() == 10);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
