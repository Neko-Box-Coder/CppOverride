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
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithConstArgsAndArgsToSet)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "test");

        std::string testString;
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        
        ssTEST_OUTPUT_ASSERT(testString == "test");
    };
    
    ssTEST("Modify Object Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        DummyClass&>(   CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        DummyClass(1, 2.0, "test"))
                            .Returns<bool>(true);

        DummyClass testClass(2, 3.0, "test 2");
        
        SetObjectFunc(0, 0, "a", testClass);
        
        ssTEST_OUTPUT_ASSERT(testClass == DummyClass(1, 2.0, "test"));
    };
    
    ssTEST("Modify Object Test with action")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
                            .SetArgsByAction<   CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                DummyClass&>
                            (
                                [](std::vector<void*>& args)
                                {
                                    *((DummyClass*)args.at(3)) = DummyClass(1, 2.0, "test");
                                }
                            )
                            .Returns<bool>(true);

        DummyClass testClass(2, 3.0, "test 2");
        
        SetObjectFunc(0, 0, "a", testClass);
        
        ssTEST_OUTPUT_ASSERT(testClass == DummyClass(1, 2.0, "test"));
    };
    
    ssTEST("Modify Template Object Test")
    {
        TemplateDummy<int> assignDummy(1, 2, 3.f, "test");
        TemplateDummy<int> assignDummy2(2, 3, 4.f, "test2");
        
        CO_SETUP_OVERRIDE   (OverrideObj, SetTemplateObjectFunc)
                            .SetArgs<   TemplateDummy<int>&, 
                                        TemplateDummy<int>*>(   assignDummy, 
                                                                assignDummy2);

        TemplateDummy<int> testDummy(3, 4, 5.f, "test3");
        TemplateDummy<int> testDummy2(4, 5, 6.f, "test4");
        
        SetTemplateObjectFunc(testDummy, &testDummy2);

        ssTEST_OUTPUT_ASSERT(testDummy == assignDummy);
        ssTEST_OUTPUT_ASSERT(testDummy2 == assignDummy2);
    };
    
    ssTEST("Modify Nothing Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgsToSet)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        CO_ANY_TYPE>(   CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        CO_DONT_SET);

        float testArg = 2.f;
        std::string testArg2 = "test";
        
        FuncWithArgsToSet(1, &testArg, testArg2);
        
        ssTEST_OUTPUT_ASSERT(testArg == 2.f);
        ssTEST_OUTPUT_ASSERT(testArg2 == "test");
    };
    
    ssTEST("Modify By Action Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithArgsToSet)
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
    
    
    ssTEST_SKIP("Non copy assignable object Test")
    {
        //NOTE: This is catched by static assert. If somehow it can get to runtime,
        //      it should give MODIFY_NON_ASSIGNABLE_ARG_ERROR status. But this cannot be tested
        
        #if 0
            NonCopyAssignableDummy testObject(1);
            NonCopyAssignableDummy assignObject(2);
            
            CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
            
            CO_SETUP_OVERRIDE   (OverrideObj, SetNonAssignableArgFunc)
                                .SetArgs<NonCopyAssignableDummy>(assignObject)
                                .AssignStatus(status);
            
            SetNonAssignableArgFunc(&testObject);
            
            ssTEST_OUTPUT_ASSERT(testObject.GetTestData() == 1);
            ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR);
        #endif
    };
    
    ssTEST("Modify Const Arg Test")
    {
        CppOverride::OverrideStatus status = CppOverride::DEFAULT_STATUS;
        
        CO_SETUP_OVERRIDE   (OverrideObj, SetArgWithConstArgFunc)
                            .SetArgs<int*, bool*, const float*>(2, true, 3.f)
                            .AssignStatus(status);
        
        int testArg = 1;
        bool testArg2 = false;
        float testArg3 = 1.f;
        
        SetArgWithConstArgFunc(&testArg, &testArg2, &testArg3);
        
        ssTEST_OUTPUT_ASSERT(testArg == 2);
        ssTEST_OUTPUT_ASSERT(testArg2 == true);
        ssTEST_OUTPUT_ASSERT(testArg3 == 1.f);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST_END();
    return 0;
}