#include "CppOverride.hpp"
#include "./Components/Shapes.hpp"
#include "./Components/FileFunctions.hpp"
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
    
    //Comparing Primitive Type Should Override Return If Match
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ArgsFunc)
                        .Returns<int>(1)
                        .WhenCalledWith(1, true, 2.f)
                        .AssignsResult(result);
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::ArgsFunc(1, true, 2.f), 1);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        DS_ASSERT_NOT_EQ(CppOverrideTest::NonConst::ArgsFunc(2, false, 2.f), 1);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Comparing Primitive Type Should Override Arguments If Match
    {
        setup();
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, MoreArgsToSetFunc)
                        .SetArgs<CO_ANY_TYPE, float*, bool*, std::string&>( CO_DONT_SET, 
                                                                            1.f, 
                                                                            true, 
                                                                            "test")
                        .WhenCalledWith(5, CO_ANY, CO_ANY, CO_ANY)
                        .AssignsResult(result);
        
        float assignFloat = 2.f;
        bool assignBool = false;
        std::string assignString = "";
        
        CppOverrideTest::NonConst::MoreArgsToSetFunc(5, &assignFloat, &assignBool, assignString);
        
        DS_ASSERT_EQ(assignFloat, 1.f);
        DS_ASSERT_EQ(assignBool, true);
        DS_ASSERT_EQ(assignString, "test");
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        assignFloat = 2.f;
        assignBool = false;
        assignString = "";
        
        CppOverrideTest::NonConst::MoreArgsToSetFunc(2, &assignFloat, &assignBool, assignString);
        
        DS_ASSERT_EQ(assignFloat, 2.f);
        DS_ASSERT_EQ(assignBool, false);
        DS_ASSERT_EQ(assignString, "");
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Comparing Nothing Should Always Override
    {
        setup();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ArgsFunc)
                        .WhenCalledWith(CO_ANY, CO_ANY, CO_ANY)
                        .Returns<int>(1)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::ArgsFunc(1, false, 2.f), 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Comparing Const Void Pointer Should Override If Match
    {
        setup();
        float testArg = 1;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstVoidPointerFunc)
                        .WhenCalledWith<const void*, int>(&testArg, 2)
                        .Returns<int>(1)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::Const::ConstVoidPointerFunc(&testArg, 2), 1);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Pointer Type Argument Should Demote To Value Type For Comparison
    {
        setup();
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, 2.f, CO_ANY)
                            .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, std::string&>(   CO_DONT_SET, 
                                                                                CO_DONT_SET, 
                                                                                "test")
                            .Expected();
        float assignFloat = 2.f;
        std::string assignString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, assignString);
        DS_ASSERT_EQ(assignString, "test");
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Pointer Argument Matches Pointer Condition Should Override If Match
    {
        setup();
        CppOverride::ResultPtr result;
        float assignFloat = 2.f;
        std::string assignString = "";
        
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, &assignFloat, CO_ANY)
                            .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, std::string&>(   CO_DONT_SET, 
                                                                                CO_DONT_SET, 
                                                                                "test")
                            .AssignsResult(result);

        CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, assignString);
        DS_ASSERT_EQ(assignString, "test");
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        assignFloat = 2.f;
        float assignFloat2 = 2.f;
        assignString = "";
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat2, assignString);
        DS_ASSERT_EQ(assignString, "");
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Reference Type Argument Should Promote To Pointer Type For Comparison
    {
        setup();
        CppOverride::ResultPtr result;
        float assignFloat = 2.f;
        std::string testString = "test";
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, CO_ANY, &testString)
                            .SetArgs<CO_ANY_TYPE, float*, CO_ANY_TYPE>(CO_DONT_SET, 3.f, CO_DONT_SET)
                            .AssignsResult(result);
        
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, testString);
        DS_ASSERT_EQ(assignFloat, 3.f);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
    
        assignFloat = 2.f;
        testString = "test";
        std::string testString2 = "test";
        CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, testString2);
        DS_ASSERT_EQ(assignFloat, 2.f);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Reference Type Argument Should Demote To Value Type For Comparison
    {
        setup();
        CppOverride::ResultPtr result;
        std::string testString = "test";
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstStringRefArgFunc)
                        .WhenCalledWith<std::string>("test")
                        .Returns<int>(5)
                        .AssignsResult(result);
        
        DS_ASSERT_EQ(CppOverrideTest::Const::ConstStringRefArgFunc(testString), 5);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        testString = "test2";
        DS_ASSERT_EQ(CppOverrideTest::Const::ConstStringRefArgFunc(testString), -1);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Comparing Object Should Override If Match
    {
        setup();
        CppOverride::ResultPtr result;
        CppOverrideTest::TestClass conditionObject(1, 2.0, "test");
        CppOverrideTest::TestClass setObject(1, 2.0, "test");
        CppOverrideTest::TestClass overrideObject(2, 3.0, "test2");
    
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst::Object, SetObjectFunc)
                    .WhenCalledWith(10, 20.0, std::string("test10"), conditionObject)
                    .SetArgs<   CO_ANY_TYPE, 
                                CO_ANY_TYPE, 
                                CO_ANY_TYPE, 
                                CppOverrideTest::TestClass&>(   CO_DONT_SET, 
                                                                CO_DONT_SET, 
                                                                CO_DONT_SET, 
                                                                overrideObject)
                    .Returns<bool>(true)
                    .AssignsResult(result);

        CppOverrideTest::NonConst::Object::SetObjectFunc(10, 20.0, "test10", setObject);
        
        DS_ASSERT_TRUE(setObject == overrideObject);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        setObject = CppOverrideTest::TestClass(3, 4.0, "test3");
        overrideObject = CppOverrideTest::TestClass(2, 3.0, "test2");
        
        CppOverrideTest::NonConst::Object::SetObjectFunc(10, 20.0, "test10", setObject);
        
        DS_ASSERT_TRUE(setObject == CppOverrideTest::TestClass(3, 4.0, "test3"));
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Templated Object Should Override If Match
    {
        setup();
        CppOverride::ResultPtr result;
        CppOverrideTest::TemplateTestClass<int> conditionTemplate(1, 2, 3.f, "test");
        CppOverrideTest::TemplateTestClass<int> returnTemplate(2, 3, 4.f, "test2");
        
        CO_INSTRUCT_REF 
        (
            OverrideObj, 
            CppOverrideTest::NonConst::Template, 
            TemplateReturnFunc<CppOverrideTest::TemplateTestClass<int>>
        )
        .WhenCalledWith(conditionTemplate)
        .Returns<CppOverrideTest::TemplateTestClass<int>>(returnTemplate)
        .AssignsResult(result);

        namespace CppOverrideTemplateTest = CppOverrideTest::NonConst::Template;
        
        DS_ASSERT_TRUE( CppOverrideTemplateTest::TemplateReturnFunc(conditionTemplate) == 
                        returnTemplate);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        CppOverrideTest::TemplateTestClass<int> testTemplate(4, 5, 6.f, "test2");
        
        DS_ASSERT_TRUE(CppOverrideTemplateTest::TemplateReturnFunc(testTemplate) == testTemplate);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Member Function Should Override If Match
    {
        setup();
        CppOverride::ResultPtr result;
        CppOverrideTest::Rectangle rect(1.5, 1.5);
        CO_INSTRUCT_NO_REF  (rect, GetWidth)
                            .WhenCalledWith(2.f)
                            .Returns<float>(5.f)
                            .AssignsResult(result);
        
        DS_ASSERT_EQ(rect.GetWidth(2.f), 5.f);
        DS_ASSERT_TRUE(result->LastStatusSucceed());

        DS_ASSERT_EQ(rect.GetWidth(1.f), 1.5);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }
    
    //Object Missing Inequality Operator Should Fail With Status
    {
        setup();
        CppOverride::ResultPtr result;
        CppOverrideTest::NonComparableTestClass testDummy(2, 3.0, "test");
        CppOverrideTest::NonComparableTestClass returnDummy(3, 4.0, "test2");
        CO_INSTRUCT_REF
        (
            OverrideObj, 
            CppOverrideTest::NonConst::Template,
            TemplateReturnFunc<CppOverrideTest::NonComparableTestClass>
        )
        .WhenCalledWith(testDummy)
        .Returns<CppOverrideTest::NonComparableTestClass>(returnDummy)
        .AssignsResult(result);
        
        namespace CppOverrideTemplateTest = CppOverrideTest::NonConst::Template;
        CppOverrideTest::NonComparableTestClass resultDummy = 
            CppOverrideTemplateTest::TemplateReturnFunc(testDummy);
        
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR);
        DS_ASSERT_EQ(resultDummy.GetTestData(), testDummy.GetTestData());
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
