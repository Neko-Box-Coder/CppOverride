#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"
#include "./Components/TestClasses.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Modify Single Primitive Type Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsToSetFunc)
                            .SetArgs<   CO_ANY_TYPE, 
                                        float*, 
                                        CO_ANY_TYPE>(   CO_DONT_SET, 
                                                        5, 
                                                        CO_DONT_SET)
                            .AssignStatus(status);
        
        float testFloat = 0.f;
        std::string testString;

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 5);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
        
    ssTEST("Modify Multiple Primitive Types Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, MoreArgsToSetFunc)
                            .SetArgs<   CO_ANY_TYPE, 
                                        float*, 
                                        bool*, 
                                        CO_ANY_TYPE>(   CO_DONT_SET, 
                                                        15, 
                                                        false, 
                                                        CO_DONT_SET)
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_SETUP
        (
            float testFloat = 0.f;
            bool testBool = true;
            std::string testString;
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::MoreArgsToSetFunc(1, &testFloat, &testBool, testString);
        );
        
        ssTEST_OUTPUT_ASSERT(testFloat == 15);
        ssTEST_OUTPUT_ASSERT(testBool == false);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Modify Object Should Succeed")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        TestClass&>(    CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        TestClass(1, 2.0, "test"))
                            .AssignStatus(status);

        ssTEST_OUTPUT_SETUP
        (
            TestClass testClass;
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        );
        
        ssTEST_OUTPUT_ASSERT(testClass == TestClass(1, 2.0, "test"));
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Modify Template Object Should Succeed")
    {
        TemplateTestClass<int> overrideDummy(1, 2, 3.f, "test");
        TemplateTestClass<int> overrideDummy2(2, 3, 4.f, "test2");
        
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, TemplateSetArgFunc)
                            .SetArgs<   TemplateTestClass<int>&, 
                                        TemplateTestClass<int>*>(   overrideDummy, 
                                                                    overrideDummy2)
                            .AssignStatus(status);

        TemplateTestClass<int> testDummy(3, 4, 5.f, "test3");
        TemplateTestClass<int> testDummy2(4, 5, 6.f, "test4");
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Template::TemplateSetArgFunc(testDummy, &testDummy2);
        );

        ssTEST_OUTPUT_ASSERT(testDummy == overrideDummy);
        ssTEST_OUTPUT_ASSERT(testDummy2 == overrideDummy2);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Begin Const Arg Should Fail With Status")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, SetBeginConstArgFunc)
                            .SetArgs<const int*, bool*, float*>(2, true, 3.f)
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_SETUP
        (
            int testArg = 1;
            bool testArg2 = false;
            float testArg3 = 1.f;
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::SetBeginConstArgFunc(&testArg, &testArg2, &testArg3);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 1);
        ssTEST_OUTPUT_ASSERT(testArg2 == false);
        ssTEST_OUTPUT_ASSERT(testArg3 == 1.f);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST("Set End Const Arg Should Modify Non Const Args Then Fail With Status")
    {
        CppOverride::OverrideStatus status;
        CO_SETUP_OVERRIDE   (OverrideObj, SetEndConstArgFunc)
                            .SetArgs<int*, bool*, const float*>(2, true, 3.f)
                            .AssignStatus(status);
        
        ssTEST_OUTPUT_SETUP
        (
            int testArg = 1;
            bool testArg2 = false;
            float testArg3 = 1.f;
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::SetEndConstArgFunc(&testArg, &testArg2, &testArg3);
        );
        
        ssTEST_OUTPUT_ASSERT(testArg == 2);
        ssTEST_OUTPUT_ASSERT(testArg2 == true);
        ssTEST_OUTPUT_ASSERT(testArg3 == 1.f);
        ssTEST_OUTPUT_ASSERT(status == CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    
    #if 0
    
    ssTEST("Modify Object Test with action")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
                            .SetArgsByAction<   CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                TestClass&>
                            (
                                [](std::vector<void*>& args)
                                {
                                    *((TestClass*)args.at(3)) = TestClass(1, 2.0, "test");
                                }
                            )
                            .Returns<bool>(true);

        TestClass testClass(2, 3.0, "test 2");
        
        SetObjectFunc(0, 0, "a", testClass);
        
        ssTEST_OUTPUT_ASSERT(testClass == TestClass(1, 2.0, "test"));
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
        
        ArgsToSetFunc(1, &testArg, testArg2);
        
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
        
        ArgsToSetFunc(testArg, &testArg2, testArg3);
        
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
    
    #endif
    
    ssTEST_END();
    return 0;
}