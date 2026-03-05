#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"
#include "./Components/TestClasses.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Set Single Primitive Type Should Override
    {
        setup();
        float testFloat = 0.f;
        std::string testString;
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, float*, CO_ANY_TYPE>(CO_DONT_SET, 5, CO_DONT_SET)
                            .Expected();
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        DS_ASSERT_EQ(testFloat, 5);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Multiple Primitive Types Should Override
    {
        setup();
        float testFloat = 0.f;
        bool testBool = true;
        std::string testString;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, MoreArgsToSetFunc)
                        .SetArgs<CO_ANY_TYPE, float*, bool*, CO_ANY_TYPE>(  CO_DONT_SET, 
                                                                            15, 
                                                                            false, 
                                                                            CO_DONT_SET)
                        .Expected();
        CppOverrideTest::NonConst::MoreArgsToSetFunc(1, &testFloat, &testBool, testString);
        DS_ASSERT_EQ(testFloat, 15);
        DS_ASSERT_EQ(testBool, false);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }

    //Set Non Pointer/Reference Arg Should Override
    {
        setup();
        std::string outString;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AssignArgInternallyFunc)
                        .SetArgs<std::string, CO_ANY_TYPE>("Test", CO_DONT_SET)
                        .Expected();
        CppOverrideTest::NonConst::AssignArgInternallyFunc("Test 2", outString);
        DS_ASSERT_EQ(outString, "Test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }

    //Set Void Pointer Should Override
    {
        setup();
        int TestArg = 2;
        int TestArg2 = 4;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, AddNumFromVoidPointerFunc)
                        .SetArgs<void*, CO_ANY_TYPE>(&TestArg, CO_DONT_SET)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::AddNumFromVoidPointerFunc(&TestArg2, 5), 7);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Object Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        DS_ASSERT_TRUE(testClass == CppOverrideTest::TestClass(1, 2.0, "test"));
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Template Object Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::Template::TemplateSetArgFunc(testDummy, &testDummy2);
        DS_ASSERT_TRUE(testDummy == overrideDummy);
        DS_ASSERT_TRUE(testDummy2 == overrideDummy2);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Begin Const Arg Should Fail With Status
    {
        setup();
        CppOverride::ResultPtr result;
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, SetBeginConstArgFunc)
                        .SetArgs<const int*, bool*, float*>(2, true, 3.f)
                        .AssignsResult(result);
        
        int testArg = 1;
        bool testArg2 = false;
        float testArg3 = 1.f;
        CppOverrideTest::Const::SetBeginConstArgFunc(&testArg, &testArg2, &testArg3);
        DS_ASSERT_EQ(testArg, 1);
        DS_ASSERT_EQ(testArg2, false);
        DS_ASSERT_EQ(testArg3, 1.f);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    }
    
    //Set End Const Arg Should Modify Non Const Args Then Fail With Status
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, SetEndConstArgFunc)
                        .SetArgs<int*, bool*, const float*>(2, true, 3.f)
                        .AssignsResult(result);
        int testArg = 1;
        bool testArg2 = false;
        float testArg3 = 1.f;
        CppOverrideTest::Const::SetEndConstArgFunc(&testArg, &testArg2, &testArg3);
        DS_ASSERT_EQ(testArg, 2);
        DS_ASSERT_EQ(testArg2, true);
        DS_ASSERT_EQ(testArg3, 1.f);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MODIFY_CONST_ARG_ERROR);
    }
    
    //Set Args For Overloaded Function Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        DS_ASSERT_EQ(testArg2, 4.f);
        DS_ASSERT_EQ(testArg3, "Test");
        DS_ASSERT_EQ(CO_GET_FAILED_FUNCTIONS(OverrideObj).size(), 1);
        
        CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        DS_ASSERT_EQ(testArg2, 5.f);
        DS_ASSERT_EQ(testArg4, 3.f);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Args For Member Function Should Override
    {
        setup();
        CppOverrideTest::Rectangle rect(5, 5);
        float outWidth = 0;
        CO_INSTRUCT_NO_REF  (rect, GetWidth)
                            .SetArgs<float&, CO_ANY_TYPE>(2, CO_DONT_SET)
                            .ReturnsVoid()
                            .Expected();
        rect.GetWidth(outWidth);
        DS_ASSERT_EQ(outWidth, 2);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Don't Set Anything Should Modify Nothing
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, CO_ANY_TYPE>(CO_DONT_SET, 
                                                                            CO_DONT_SET, 
                                                                            CO_DONT_SET)
                            .Expected();
        
        float testArg = 2.f;
        std::string testArg2 = "test";
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &testArg, testArg2);
        DS_ASSERT_EQ(testArg, 2.f);
        DS_ASSERT_EQ(testArg2, "test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Non Copy Assignable Object Should Fail To Compile
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
    }
    
    //Set Primitive Types By Action Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        DS_ASSERT_EQ(testArg2, 2.f);
        DS_ASSERT_EQ(testArg3, "test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Object By Action Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::Object::SetObjectFunc(0, 0, "a", testClass);
        DS_ASSERT_TRUE(testClass == CppOverrideTest::TestClass(1, 2.0, "test"));
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Set Args By Action For Overloaded Function Should Override
    {
        setup();
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
        CppOverrideTest::NonConst::ArgsToSetFunc(testArg, &testArg2, testArg3);
        DS_ASSERT_EQ(testArg2, 4.f);
        DS_ASSERT_EQ(testArg3, "Test");
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        DS_ASSERT_EQ((int)result2->GetLastStatus(), (int)CppOverride::OverrideStatus::NO_OVERRIDE);


        result->ClearStatuses();
        CppOverrideTest::NonConst::ArgsToSetFunc(testArg, testArg2, &testArg4);
        DS_ASSERT_EQ(testArg2, 5.f);
        DS_ASSERT_EQ(testArg4, 3.f);
        DS_ASSERT_EQ((int)result->GetLastStatus(), (int)CppOverride::OverrideStatus::NO_OVERRIDE);
        DS_ASSERT_TRUE(result2->LastStatusSucceed());
    }
    
    return {};
}

int main(int, char**)
{
    try
    {
        TestMain().DS_TRY_ACT(std::cout << DS_TMP_ERROR.ToString() << std::endl; return 1);
        return 0;
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    return 1;
}
