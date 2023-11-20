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
    
    ssTEST("Return With One Override Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .Times(3)
                            .Returns(1);

        ssTEST_OUTPUT_ASSERT(FuncWithArgs(1, true, 2.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(FuncWithArgs(2, false, 3.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(FuncWithArgs(3, true, 4.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(FuncWithArgs(4, true, 5.f) != 1);
    };
    
    ssTEST("Return With Multiple Overrides Test")
    {
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .WhenCalledWith(1, true, 2.f)
                            .Times(1)
                            .Returns(1);
        
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .Times(1)
                            .WhenCalledWith(2, false, 3.f)
                            .Returns(2);
        
        CO_OVERRIDE_RETURNS (OverrideObj, FuncWithArgs(int, bool, float))
                            .Times(2)
                            .WhenCalledWith(3, true, 4.f)
                            .Returns(3);
        
        ssTEST_OUTPUT_ASSERT("3rd Override", FuncWithArgs(3, true, 4.f) == 3);
        ssTEST_OUTPUT_ASSERT("3rd Override", FuncWithArgs(3, true, 4.f) == 3);
        ssTEST_OUTPUT_ASSERT("3rd Override", FuncWithArgs(3, true, 4.f) != 3);
        
        ssTEST_OUTPUT_ASSERT("2nd Override", FuncWithArgs(2, false, 3.f) == 2);
        ssTEST_OUTPUT_ASSERT("2nd Override", FuncWithArgs(2, false, 3.f) != 2);
        
        ssTEST_OUTPUT_ASSERT("1st Override", FuncWithArgs(1, true, 2.f) == 1);
        ssTEST_OUTPUT_ASSERT("1st Override", FuncWithArgs(1, true, 2.f) != 1);
    };
    
    ssTEST("SetArg With One Override Test")
    {
        DummyClass assignObject = DummyClass(2, 3.0, "test2");
        
        CO_OVERRIDE_ARGS(OverrideObj, SetObjectFunc(int, double, std::string, DummyClass&))
                        .WhenCalledWith(10, 20.0, std::string("test10"), CO_ANY)
                        .Times(2)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, CO_DONT_SET, assignObject);

        
        DummyClass testObject;
        SetObjectFunc(10, 20.0, "test10", testObject);
        ssTEST_OUTPUT_ASSERT(testObject == assignObject);
        
        testObject = DummyClass();
        SetObjectFunc(10, 20.0, "test10", testObject);
        ssTEST_OUTPUT_ASSERT(testObject == assignObject);
        
        testObject = DummyClass();
        SetObjectFunc(10, 20.0, "test10", testObject);
        ssTEST_OUTPUT_ASSERT(testObject == DummyClass(10, 20.0, "test10"));
    };
    
    ssTEST("SetArg With Multiple Overrides Test")
    {
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(1, 2.f, CO_ANY)
                        .Times(1)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test"));

        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(2, 3.f, CO_ANY)
                        .Times(1)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test2"));

        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .WhenCalledWith(3, 4.f, CO_ANY)
                        .Times(2)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test3"));

        float testFloat = 4.f;
        std::string testString = "";
        
        FuncWithArgsToSet(3, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("3rd Override", testString == "test3");
        testString.clear();
        
        FuncWithArgsToSet(3, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("3rd Override", testString == "test3");
        testString.clear();
        
        FuncWithArgsToSet(3, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("3rd Override", testString.empty());
        testString.clear();
        
        testFloat = 3.f;
        FuncWithArgsToSet(2, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("2nd Override", testString == "test2");
        testString.clear();
        
        FuncWithArgsToSet(2, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("2nd Override", testString.empty());
        testString.clear();
        
        testFloat = 2.f;
        FuncWithArgsToSet(1, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("1st Override", testString == "test");
        testString.clear();
        
        FuncWithArgsToSet(1, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("1st Override", testString.empty());
    };
    
    ssTEST_END();
    
    return 0;
}