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
    
    ssTEST("Modify Primitive types Test")
    {
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithConstArgsAndArgsToSet(    const int, 
                                                                        const float, 
                                                                        std::string&))
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test"));

        std::string testString;
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        
        ssTEST_OUTPUT_ASSERT(testString == "test");
    };
    
    ssTEST("Modify Object Test")
    {
        CO_OVERRIDE_ARGS(OverrideObj, SetObjectFunc(int, double, std::string, DummyClass&))
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, CO_DONT_SET, DummyClass(1, 2.0, "test"));

        DummyClass testClass(2, 3.0, "test 2");
        
        SetObjectFunc(0, 0, "a", testClass);
        
        ssTEST_OUTPUT_ASSERT(testClass == DummyClass(1, 2.0, "test"));
    };
    
    ssTEST("Modify Template Object Test")
    {
        TemplateDummy<int> assignDummy(1, 2, 3.f, "test");
        TemplateDummy<int> assignDummy2(2, 3, 4.f, "test2");
        
        CO_OVERRIDE_ARGS(OverrideObj, SetTemplateObjectFunc(T&, T*))
                        .SetArgs(assignDummy, assignDummy2);

        TemplateDummy<int> testDummy(3, 4, 5.f, "test3");
        TemplateDummy<int> testDummy2(4, 5, 6.f, "test4");
        
        SetTemplateObjectFunc(testDummy, &testDummy2);

        ssTEST_OUTPUT_ASSERT(testDummy == assignDummy);
        ssTEST_OUTPUT_ASSERT(testDummy2 == assignDummy2);
    };
    
    ssTEST("Modify Nothing Test")
    {
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, CO_DONT_SET);

        float testArg = 2.f;
        std::string testArg2 = "test";
        
        FuncWithArgsToSet(1, &testArg, testArg2);
        
        ssTEST_OUTPUT_ASSERT(testArg == 2.f);
        ssTEST_OUTPUT_ASSERT(testArg2 == "test");
    };
    
    ssTEST("Modify By Action Test")
    {
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithArgsToSet(int, float*, std::string&))
                        .SetArgsByAction<int, float*, std::string&>
                        (
                            [](std::vector<void*>& args)
                            {
                                *((std::string*)args.at(2)) = "test";
                            }
                        );
        
        int testArg = 1;
        float testArg2 = 1.f;
        std::string testArg3 = "";
        
        FuncWithArgsToSet(testArg, &testArg2, testArg3);
        
        ssTEST_OUTPUT_ASSERT(testArg3 == "test");
    };
    
    ssTEST_END();
    return 0;
}