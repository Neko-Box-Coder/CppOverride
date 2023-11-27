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
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .Returns(1)
                            .WhenCalledWith(1, true, 2.f);
        
        ssTEST_OUTPUT_ASSERT(FuncWithArgs(1, true, 2.f) == 1);
    };
    
    ssTEST("Object Value Test")
    {
        DummyClass testObject(1, 2.0, "test");
        DummyClass assignObject(2, 3.0, "test2");
        
        CO_OVERRIDE_ARGS(OverrideObj, SetObjectFunc(int, double, std::string, DummyClass&))
                        .WhenCalledWith(10, 20.0, std::string("test10"), testObject)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, CO_DONT_SET, assignObject);

        SetObjectFunc(10, 20.0, "test10", testObject);
        
        ssTEST_OUTPUT_ASSERT(testObject == assignObject);
    };
    
    ssTEST("String Value Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, ConstStringRefArgFunc(const std::string&))
                            .WhenCalledWith(std::string("test"))
                            .Returns(1);

        ssTEST_OUTPUT_ASSERT(ConstStringRefArgFunc("test") == 1);
    };
    
    ssTEST("Template Object Value Test")
    {
        TemplateDummy<int> testDummy(1, 2, 3.f, "test");
        TemplateDummy<int> testDummy2(2, 3, 4.f, "test2");
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnTemplateObjectFunc(T))
                            .WhenCalledWith(testDummy)
                            .Returns(testDummy2);

        ssTEST_OUTPUT_ASSERT(ReturnTemplateObjectFunc(testDummy) == testDummy2);
    };
    
    ssTEST("No Comparison Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .WhenCalledWith(CO_ANY, CO_ANY, CO_ANY)
                            .Returns(1);

        ssTEST_OUTPUT_ASSERT(FuncWithArgs(1, false, 2.f) == 1);
    };
    
    ssTEST("Pointer Value Test")
    {
        float testFloat = 2.f;
        
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(1, testFloat, CO_ANY)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test"));

        float assignFloat = 2.f;
        std::string assignString = "";
        
        FuncWithArgsToSet(1, &assignFloat, assignString);
        
        ssTEST_OUTPUT_ASSERT("Pointer", assignString == "test");
        
        CO_OVERRIDE_RETURNS (OverrideObj, ConstStringRefArgFunc(const std::string&))
                            .WhenCalledWith(std::string("test"))
                            .Returns(1);

        ssTEST_OUTPUT_ASSERT("Reference", ConstStringRefArgFunc("test") == 1);
    };
    
    ssTEST("Member Function Test")
    {
        Rectangle rect(1.5, 1.5);
        
        CO_OVERRIDE_RETURNS (rect, GetWidth(float))
                            .WhenCalledWith(2.f)
                            .Returns(5.f);
        
        ssTEST_OUTPUT_ASSERT(rect.GetWidth(2.f) == 5.f);
    };
    
    ssTEST("Pointer Condition Test")
    {
        float testFloat = 1.f;
        
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(1, &testFloat, std::string("test"))
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("pass"));

        std::string assignString = "test";
        
        FuncWithArgsToSet(1, &testFloat, assignString);
        
        ssTEST_OUTPUT_ASSERT(assignString == "pass");
    };
    
    ssTEST("Reference Condition Test")
    {
        std::string testString = "test";
        
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(1, 2.f, &testString)
                        .SetArgs(CO_DONT_SET, 3.f, CO_DONT_SET);

        float assignFloat = 2.f;
        
        FuncWithArgsToSet(1, &assignFloat, testString);
        
        ssTEST_OUTPUT_ASSERT(assignFloat == 3.f);
    };
    
    ssTEST("Const void* Test")
    {
        float testArg = 1;
        
        CO_OVERRIDE_RETURNS (OverrideObj, ConstVoidPointerFunc(const void*, int))
                            .WhenCalledWith(static_cast<void*>(&testArg), 2)
                            .Returns(1);
        
        ssTEST_OUTPUT_ASSERT(ConstVoidPointerFunc(&testArg, 2));
        
    };
    
    ssTEST("Object Missing inequality operator Test")
    {
        NonComparableDummy testDummy(2);
        NonComparableDummy returnDummy(3);
        
        CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
        
        CO_OVERRIDE_RETURNS (OverrideObj, ReturnTemplateObjectFunc(T))
                            .WhenCalledWith(testDummy)
                            .Returns(returnDummy)
                            .AssignStatus(status);
        
        NonComparableDummy resultDummy = ReturnTemplateObjectFunc(testDummy);
        
        ssTEST_OUTPUT_ASSERT(status == 
            CppOverride::OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR);
        
        ssTEST_OUTPUT_ASSERT(resultDummy.GetTestData() == testDummy.GetTestData());
    };
    
    ssTEST_END();
    
    return 0;
}