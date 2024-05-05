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
    
    ssTEST("Set Single Primitive Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            float testFloat = 0.f;
            std::string testString;
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<   CO_ANY_TYPE, 
                                            float*, 
                                            CO_ANY_TYPE>(   CO_DONT_SET, 
                                                            5, 
                                                            CO_DONT_SET)
                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 5);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
        
    ssTEST("Set Multiple Primitive Types Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            float testFloat = 0.f;
            bool testBool = true;
            std::string testString;
            
            (CO_SETUP_OVERRIDE  (OverrideObj, MoreArgsToSetFunc)
                                .SetArgs<   CO_ANY_TYPE, 
                                            float*, 
                                            bool*, 
                                            CO_ANY_TYPE>(   CO_DONT_SET, 
                                                            15, 
                                                            false, 
                                                            CO_DONT_SET)
                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::MoreArgsToSetFunc(1, &testFloat, &testBool, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 15);
        ssTEST_OUTPUT_ASSERT(testBool == false);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };

    ssTEST("Set Non Pointer/Reference Arg Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::string outString;
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, AssignArgInternallyFunc)
                                .SetArgs<std::string, CO_ANY_TYPE>("Test", CO_DONT_SET)
                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc("Test 2", outString);
        );
        ssTEST_OUTPUT_ASSERT(outString == "Test");
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };

    ssTEST("Set Void Pointer Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            int TestArg = 2;
            int TestArg2 = 4;
            (CO_SETUP_OVERRIDE  (OverrideObj, AddNumFromVoidPointerFunc)
                                .SetArgs<void*, CO_ANY_TYPE>(&TestArg, CO_DONT_SET)
                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int returnResult = CppOverrideTest::NonConst::AddNumFromVoidPointerFunc(&TestArg2, 5);
        );
        ssTEST_OUTPUT_ASSERT(returnResult == 7);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            TestClass testClass;
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, SetObjectFunc)
                                .SetArgs<   CO_ANY_TYPE, 
                                            CO_ANY_TYPE, 
                                            CO_ANY_TYPE, 
                                            TestClass&>(    CO_DONT_SET, 
                                                            CO_DONT_SET, 
                                                            CO_DONT_SET, 
                                                            TestClass(1, 2.0, "test"))
                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        );
        ssTEST_OUTPUT_ASSERT(testClass == TestClass(1, 2.0, "test"));
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Template Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            TemplateTestClass<int> overrideDummy(1, 2, 3.f, "test");
            TemplateTestClass<int> overrideDummy2(2, 3, 4.f, "test2");
            
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, TemplateSetArgFunc)
                                .SetArgs<   TemplateTestClass<int>&, 
                                            TemplateTestClass<int>*>(   overrideDummy, 
                                                                        overrideDummy2)
                                .AssignOverrideResult(result));

            TemplateTestClass<int> testDummy(3, 4, 5.f, "test3");
            TemplateTestClass<int> testDummy2(4, 5, 6.f, "test4");
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Template::TemplateSetArgFunc(testDummy, &testDummy2);
        );
        ssTEST_OUTPUT_ASSERT(testDummy == overrideDummy);
        ssTEST_OUTPUT_ASSERT(testDummy2 == overrideDummy2);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Begin Const Arg Should Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, SetBeginConstArgFunc)
                                .SetArgs<const int*, bool*, float*>(2, true, 3.f)
                                .AssignOverrideResult(result));
            
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
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST("Set End Const Arg Should Modify Non Const Args Then Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, SetEndConstArgFunc)
                                .SetArgs<int*, bool*, const float*>(2, true, 3.f)
                                .AssignOverrideResult(result));
            
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
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST("Set Args For Overloaded Function Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CppOverride::OverrideResult result2;
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 4.f, "Test")
                                .AssignOverrideResult(result));
            
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, float&, float*>(CO_DONT_SET, true, 3.f)
                                .AssignOverrideResult(result2));
            
            int testArg = 0;
            float testArg2 = 0;
            std::string testArg3;
            float testArg4 = 0;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == 4.f);
        ssTEST_OUTPUT_ASSERT(testArg3 == "Test");
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        ssTEST_OUTPUT_ASSERT(result2.Status == CppOverride::OverrideStatus::NO_OVERRIDE);
        
        ssTEST_OUTPUT_SETUP
        (
            result = CppOverride::OverrideResult();
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == true);
        ssTEST_OUTPUT_ASSERT(testArg4 == 3.f);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::NO_OVERRIDE);
        ssTEST_OUTPUT_ASSERT(result2.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Args For Member Function Should Override")
    {
        
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            class Rectangle rect(5, 5);
            float outWidth = 0;
            (CO_SETUP_OVERRIDE(rect, GetWidth)  .SetArgs<float&, CO_ANY_TYPE>(2, CO_DONT_SET)
                                                .ReturnsVoid()
                                                .AssignOverrideResult(result));
        );
        ssTEST_OUTPUT_EXECUTION( rect.GetWidth(outWidth); );
        ssTEST_OUTPUT_ASSERT(outWidth == 2);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Don't Set Anything Should Modify Nothing")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<   CO_ANY_TYPE, 
                                            CO_ANY_TYPE, 
                                            CO_ANY_TYPE>(   CO_DONT_SET, 
                                                            CO_DONT_SET, 
                                                            CO_DONT_SET)
                                .AssignOverrideResult(result));
            
            float testArg = 2.f;
            std::string testArg2 = "test";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testArg, testArg2);
        );
        ssTEST_OUTPUT_ASSERT(testArg == 2.f);
        ssTEST_OUTPUT_ASSERT(testArg2 == "test");
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST_SKIP("Non Copy Assignable Object Should Fail To Compile")
    {
        //NOTE: This is catched by static assert. If somehow it can get to runtime,
        //      it should give MODIFY_NON_ASSIGNABLE_ARG_ERROR status. But this cannot be tested
        
        #if 0
            ssTEST_OUTPUT_SETUP
            (
                NonCopyableTestClass testObject(1, 2.f, "test");
                NonCopyableTestClass assignObject(2, 3.f, "test 2");
                CppOverride::OverrideResult result;
                
                (CO_SETUP_OVERRIDE   (OverrideObj, SetNonAssignableArgFunc)
                                    .SetArgs<NonCopyableTestClass*>(assignObject)
                                    .AssignOverrideResult(result));
            );
            ssTEST_OUTPUT_EXECUTION
            (
                CppOverrideTest::NonConst::Object::SetNonCopyableArgFunc(&testObject);
            );
            ssTEST_OUTPUT_ASSERT(testObject.GetTestData() == 0);
            ssTEST_OUTPUT_ASSERT(   result.Status == 
                                    CppOverride::OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR);
        #endif
    };
    
    ssTEST("Set Primitive Types By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<int, float*, std::string&>
                                (
                                    [](std::vector<void*>& args)
                                    {
                                        **((float**)args.at(1)) = 2.f;
                                        *((std::string*)args.at(2)) = "test";
                                    }
                                )
                                .AssignOverrideResult(result));
            int testArg = 1;
            float testArg2 = 1.f;
            std::string testArg3 = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == 2.f);
        ssTEST_OUTPUT_ASSERT(testArg3 == "test");
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Object By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            
            (CO_SETUP_OVERRIDE  (OverrideObj, SetObjectFunc)
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
                                .Returns<bool>(true)
                                .AssignOverrideResult(result));
            
            TestClass testClass;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        );
        ssTEST_OUTPUT_ASSERT(testClass == TestClass(1, 2.0, "test"));
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Set Args By Action For Overloaded Function Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CppOverride::OverrideResult result2;
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<CO_ANY_TYPE, float*, std::string&>
                                (
                                    [](std::vector<void*>& args)
                                    {
                                        **((float**)args.at(1)) = 4.f;
                                        *((std::string*)args.at(2)) = "Test";
                                    }
                                )
                                .AssignOverrideResult(result));
            
            (CO_SETUP_OVERRIDE  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<CO_ANY_TYPE, float&, float*>
                                (
                                    [](std::vector<void*>& args)
                                    {
                                        *((float*)args.at(1)) = true;
                                        **((float**)args.at(2)) = 3.f;
                                    }
                                )
                                .AssignOverrideResult(result2));
            int testArg = 0;
            float testArg2 = 0;
            std::string testArg3;
            float testArg4 = 0;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == 4.f);
        ssTEST_OUTPUT_ASSERT(testArg3 == "Test");
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        ssTEST_OUTPUT_ASSERT(result2.Status == CppOverride::OverrideStatus::NO_OVERRIDE);


        ssTEST_OUTPUT_SETUP
        (
            result = CppOverride::OverrideResult();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == true);
        ssTEST_OUTPUT_ASSERT(testArg4 == 3.f);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::NO_OVERRIDE);
        ssTEST_OUTPUT_ASSERT(result2.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST_END();
    return 0;
}