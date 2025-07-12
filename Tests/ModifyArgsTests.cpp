#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"
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
    
    ssTEST("Set Single Primitive Type Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            float testFloat = 0.f;
            std::string testString;
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, float*, CO_ANY_TYPE>(CO_DONT_SET, 5, CO_DONT_SET)
                                .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 5);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
        
    ssTEST("Set Multiple Primitive Types Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            float testFloat = 0.f;
            bool testBool = true;
            std::string testString;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, MoreArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, bool*, CO_ANY_TYPE>(  CO_DONT_SET, 
                                                                                15, 
                                                                                false, 
                                                                                CO_DONT_SET)
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::MoreArgsToSetFunc(1, &testFloat, &testBool, testString);
        );
        ssTEST_OUTPUT_ASSERT(testFloat == 15);
        ssTEST_OUTPUT_ASSERT(testBool == false);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };

    ssTEST("Set Non Pointer/Reference Arg Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::string outString;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                            .SetArgs<std::string, CO_ANY_TYPE>("Test", CO_DONT_SET)
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::AssignArgInternallyFunc("Test 2", outString);
        );
        ssTEST_OUTPUT_ASSERT(outString == "Test");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };

    ssTEST("Set Void Pointer Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            int TestArg = 2;
            int TestArg2 = 4;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromVoidPointerFunc)
                            .SetArgs<void*, CO_ANY_TYPE>(&TestArg, CO_DONT_SET)
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            int returnsResult = CppOverrideTest::NonConst::AddNumFromVoidPointerFunc(&TestArg2, 5);
        );
        ssTEST_OUTPUT_ASSERT(returnsResult == 7);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TestClass testClass;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst::Object, SetObjectFunc)
                            .SetArgs
                            <
                                CO_ANY_TYPE, 
                                CO_ANY_TYPE, 
                                CO_ANY_TYPE, 
                                CppOverrideTest::TestClass&
                            >
                            (
                                CO_DONT_SET, 
                                CO_DONT_SET, 
                                CO_DONT_SET, 
                                CppOverrideTest::TestClass(1, 2.0, "test")
                            )
                            .Expected();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        );
        ssTEST_OUTPUT_ASSERT(testClass == CppOverrideTest::TestClass(1, 2.0, "test"));
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Template Object Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TemplateTestClass<int> overrideDummy(1, 2, 3.f, "test");
            CppOverrideTest::TemplateTestClass<int> overrideDummy2(2, 3, 4.f, "test2");
            
            CO_INSTRUCT_REF 
            (
                OverrideObj, 
                CppOverrideTest::NonConst::Template, 
                TemplateSetArgFunc<CppOverrideTest::TemplateTestClass<int>>
            )
            .SetArgs
            <
                CppOverrideTest::TemplateTestClass<int>&, 
                CppOverrideTest::TemplateTestClass<int>*
            >
            (
                overrideDummy, 
                overrideDummy2
            )
            .Expected();

            CppOverrideTest::TemplateTestClass<int> testDummy(3, 4, 5.f, "test3");
            CppOverrideTest::TemplateTestClass<int> testDummy2(4, 5, 6.f, "test4");
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Template::TemplateSetArgFunc(testDummy, &testDummy2);
        );
        ssTEST_OUTPUT_ASSERT(testDummy == overrideDummy);
        ssTEST_OUTPUT_ASSERT(testDummy2 == overrideDummy2);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Begin Const Arg Should Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, SetBeginConstArgFunc)
                            .SetArgs<const int*, bool*, float*>(2, true, 3.f)
                            .AssignsResult(result);
            
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
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST("Set End Const Arg Should Modify Non Const Args Then Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, SetEndConstArgFunc)
                            .SetArgs<int*, bool*, const float*>(2, true, 3.f)
                            .AssignsResult(result);
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
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    };
    
    ssTEST("Set Args For Overloaded Function Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, float*, std::string&>(CO_DONT_SET, 4.f, "Test")
                                .Times(1)
                                .Expected();
            
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, float&, float*>(CO_DONT_SET, 5.f, 3.f)
                                .Times(1)
                                .Expected();
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
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).size() == 1);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == 5.f);
        ssTEST_OUTPUT_ASSERT(testArg4 == 3.f);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Args For Member Function Should Override")
    {
        
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::Rectangle rect(5, 5);
            float outWidth = 0;
            CO_INSTRUCT_NO_REF  (rect, GetWidth)
                                .SetArgs<float&, CO_ANY_TYPE>(2, CO_DONT_SET)
                                .ReturnsVoid()
                                .Expected();
        );
        ssTEST_OUTPUT_EXECUTION( rect.GetWidth(outWidth); );
        ssTEST_OUTPUT_ASSERT(outWidth == 2);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Don't Set Anything Should Modify Nothing")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, CO_ANY_TYPE>(CO_DONT_SET, 
                                                                                CO_DONT_SET, 
                                                                                CO_DONT_SET)
                                .Expected();
            
            float testArg = 2.f;
            std::string testArg2 = "test";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testArg, testArg2);
        );
        ssTEST_OUTPUT_ASSERT(testArg == 2.f);
        ssTEST_OUTPUT_ASSERT(testArg2 == "test");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
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
                
                CppOverride::ResultPtr result;
                CO_INSTRUCT_REF
                (
                    OverrideObj, 
                    CppOverrideTest::NonConst::Object, 
                    SetNonAssignableArgFunc
                )
                .SetArgs<NonCopyableTestClass*>(assignObject)
                .AssignsResult(result);
            );
            ssTEST_OUTPUT_EXECUTION
            (
                CppOverrideTest::NonConst::Object::SetNonCopyableArgFunc(&testObject);
            );
            ssTEST_OUTPUT_ASSERT(testObject.GetTestData() == 0);
            ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                    CppOverride::OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR);
        #endif
    };
    
    ssTEST("Set Primitive Types By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<int, float*, std::string&>
                                (
                                    [](void*, std::vector<CppOverride::TypedDataInfo>& args)
                                    {
                                        if(args.at(1).IsType<float*>())
                                            **args.at(1).GetTypedDataPtr<float*>() = 2.f;
                                        if(args.at(2).IsType<std::string>())
                                            *args.at(2).GetTypedDataPtr<std::string>() = "test";
                                    }
                                )
                                .Expected();
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
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Object By Action Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst::Object, SetObjectFunc)
                            .SetArgsByAction<   CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                CO_ANY_TYPE, 
                                                CppOverrideTest::TestClass&>
                            (
                                [](void*, std::vector<CppOverride::TypedDataInfo>& args)
                                {
                                    if(args.at(3).IsType<CppOverrideTest::TestClass>())
                                    {
                                        *args.at(3).GetTypedDataPtr<CppOverrideTest::TestClass>() = 
                                        CppOverrideTest::TestClass(1, 2.0, "test");
                                    }
                                }
                            )
                            .Returns<bool>(true)
                            .Expected();
            CppOverrideTest::TestClass testClass;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        );
        ssTEST_OUTPUT_ASSERT(testClass == CppOverrideTest::TestClass(1, 2.0, "test"));
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Set Args By Action For Overloaded Function Should Override")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<CO_ANY_TYPE, float*, std::string&>
                                (
                                    [](void*, std::vector<CppOverride::TypedDataInfo>& args)
                                    {
                                        if(args.at(1).IsType<float*>())
                                            **args.at(1).GetTypedDataPtr<float*>() = 4.f;
                                        if(args.at(2).IsType<std::string>())
                                            *args.at(2).GetTypedDataPtr<std::string>() = "Test";
                                    }
                                )
                                .AssignsResult(result);
            CppOverride::ResultPtr result2;
            CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                                .SetArgsByAction<CO_ANY_TYPE, float&, float*>
                                (
                                    [](void*, std::vector<CppOverride::TypedDataInfo>& args)
                                    {
                                        if(args.at(1).IsType<float&>())
                                            *args.at(1).GetTypedDataPtr<float&>() = 5.f;
                                        if(args.at(2).IsType<float*>())
                                            **args.at(2).GetTypedDataPtr<float*>() = 3.f;
                                    }
                                )
                                .AssignsResult(result2);
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
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        ssTEST_OUTPUT_ASSERT(result2->GetLastStatus() == CppOverride::OverrideStatus::NO_OVERRIDE);


        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        );
        ssTEST_OUTPUT_ASSERT(testArg2 == 5.f);
        ssTEST_OUTPUT_ASSERT(testArg4 == 3.f);
        ssTEST_OUTPUT_ASSERT(result->GetLastStatus() == CppOverride::OverrideStatus::NO_OVERRIDE);
        ssTEST_OUTPUT_ASSERT(result2->LastStatusSucceed());
    };
    
    ssTEST_END_TEST_GROUP();
    return 0;
}
