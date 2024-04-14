#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./FileFunctions.hpp"
#include "./ClassFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Primitive Type Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgs)
                            .Returns<int>(1)
                            .WhenCalledWith(1, true, 2.f);
        
        ssTEST_OUTPUT_ASSERT(ArgsFunc(1, true, 2.f) == 1);
    };
    
    ssTEST("Object Value Test")
    {
        DummyClass testObject(1, 2.0, "test");
        DummyClass assignObject(2, 3.0, "test2");
        
        CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
                            .WhenCalledWith(10, 20.0, std::string("test10"), testObject)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        DummyClass&>(   CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        assignObject)
                            .Returns<bool>(true);

        SetObjectFunc(10, 20.0, "test10", testObject);
        
        ssTEST_OUTPUT_ASSERT(testObject == assignObject);
    };
    
    ssTEST("String Value Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, ConstStringRefArgFunc)
                            .WhenCalledWith(std::string("test"))
                            .Returns<int>(1);

        ssTEST_OUTPUT_ASSERT(ConstStringRefArgFunc("test") == 1);
    };
    
    ssTEST("Template Object Value Test")
    {
        TemplateTestClass<int> testDummy(1, 2, 3.f, "test");
        TemplateTestClass<int> testDummy2(2, 3, 4.f, "test2");
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnTemplateObjectFunc)
                            .WhenCalledWith(testDummy)
                            .Returns<TemplateTestClass<int>>(testDummy2);

        ssTEST_OUTPUT_ASSERT(TemplateReturnFunc(testDummy) == testDummy2);
    };
    
    ssTEST("No Comparison Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgs)
                            .WhenCalledWith(CO_ANY, CO_ANY, CO_ANY)
                            .Returns<int>(1);

        ssTEST_OUTPUT_ASSERT(ArgsFunc(1, false, 2.f) == 1);
    };
    
    ssTEST("Pointer Value Test")
    {
        float testFloat = 2.f;
        
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgsToSet)
                            .WhenCalledWith(1, testFloat, CO_ANY)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "test");

        float assignFloat = 2.f;
        std::string assignString = "";
        
        ArgsToSetFunc(1, &assignFloat, assignString);
        
        ssTEST_OUTPUT_ASSERT("Pointer", assignString == "test");
        
        CO_SETUP_OVERRIDE   (OverrideObj, ConstStringRefArgFunc)
                            .WhenCalledWith(std::string("test"))
                            .Returns<int>(1);

        ssTEST_OUTPUT_ASSERT("Reference", ConstStringRefArgFunc("test") == 1);
    };
    
    ssTEST("Member Function Test")
    {
        Rectangle rect(1.5, 1.5);
        
        CO_SETUP_OVERRIDE   (rect, GetWidth)
                            .WhenCalledWith(2.f)
                            .Returns<float>(5.f);
        
        ssTEST_OUTPUT_ASSERT(rect.GetWidth(2.f) == 5.f);
    };
    
    ssTEST("Pointer Condition Test")
    {
        float testFloat = 1.f;
        
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgsToSet)
                            .WhenCalledWith(1, &testFloat, std::string("test"))
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "pass");

        std::string assignString = "test";
        
        ArgsToSetFunc(1, &testFloat, assignString);
        
        ssTEST_OUTPUT_ASSERT(assignString == "pass");
    };
    
    ssTEST("Reference Condition Test")
    {
        std::string testString = "test";
        
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgsToSet)
                            .WhenCalledWith(1, 2.f, &testString)
                            .SetArgs<   CO_ANY_TYPE, 
                                        float*, 
                                        CO_ANY_TYPE>(   CO_DONT_SET, 
                                                        3.f, 
                                                        CO_DONT_SET);

        float assignFloat = 2.f;
        
        ArgsToSetFunc(1, &assignFloat, testString);
        
        ssTEST_OUTPUT_ASSERT(assignFloat == 3.f);
    };
    
    ssTEST("Const void* Test")
    {
        float testArg = 1;
        
        CO_SETUP_OVERRIDE   (OverrideObj, ConstVoidPointerFunc)
                            .WhenCalledWith(static_cast<void*>(&testArg), 2)
                            .Returns<int>(1);
        
        ssTEST_OUTPUT_ASSERT(ConstVoidPointerFunc(&testArg, 2));
        
    };
    
    ssTEST("Object Missing inequality operator Test")
    {
        NonComparableTestClass testDummy(2);
        NonComparableTestClass returnDummy(3);
        
        CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
        
        CO_SETUP_OVERRIDE   (OverrideObj, ReturnTemplateObjectFunc)
                            .WhenCalledWith(testDummy)
                            .Returns<NonComparableTestClass>(returnDummy)
                            .AssignStatus(status);
        
        NonComparableTestClass resultDummy = TemplateReturnFunc(testDummy);
        
        ssTEST_OUTPUT_ASSERT(status == 
            CppOverride::OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR);
        
        ssTEST_OUTPUT_ASSERT(resultDummy.GetTestData() == testDummy.GetTestData());
    };
    
    ssTEST_END();
    
    return 0;
}