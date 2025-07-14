#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/Shapes.hpp"
#include "./Components/FileFunctions.hpp"
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
    
    ssTEST("Comparing Primitive Type Should Override Return If Match")
    {
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ArgsFunc)
                        .Returns<int>(1)
                        .WhenCalledWith(1, true, 2.f)
                        .AssignsResult(result);
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(1, true, 2.f) == 1);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions",
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(2, false, 2.f) != 1);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions",
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Comparing Primitive Type Should Override Arguments If Match")
    {
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, MoreArgsToSetFunc)
                        .SetArgs<CO_ANY_TYPE, float*, bool*, std::string&>( CO_DONT_SET, 
                                                                            1.f, 
                                                                            true, 
                                                                            "test")
                        .WhenCalledWith(5, CO_ANY, CO_ANY, CO_ANY)
                        .AssignsResult(result);
        
        ssTEST_OUTPUT_SETUP
        (
            float assignFloat = 2.f;
            bool assignBool = false;
            std::string assignString = "";
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::MoreArgsToSetFunc(5, &assignFloat, &assignBool, assignString);
        );
        
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", assignFloat == 1.f);
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", assignBool == true);
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", assignString == "test");
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            assignFloat = 2.f;
            assignBool = false;
            assignString = "";
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::MoreArgsToSetFunc(2, &assignFloat, &assignBool, assignString);
        );
        
        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", assignFloat == 2.f);
        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", assignBool == false);
        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", assignString == "");
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions",
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Comparing Nothing Should Always Override")
    {
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, ArgsFunc)
                        .WhenCalledWith(CO_ANY, CO_ANY, CO_ANY)
                        .Returns<int>(1)
                        .Expected();
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(1, false, 2.f) == 1);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    };
    
    ssTEST("Comparing Const Void Pointer Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
            float testArg = 1;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstVoidPointerFunc)
                            .WhenCalledWith<const void*, int>(&testArg, 2)
                            .Returns<int>(1)
                            .Expected();
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::Const::ConstVoidPointerFunc(&testArg, 2) == 1);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    };
    
    ssTEST("Pointer Type Argument Should Demote To Value Type For Comparison")
    {
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, 2.f, CO_ANY)
                            .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, std::string&>(   CO_DONT_SET, 
                                                                                CO_DONT_SET, 
                                                                                "test")
                            .Expected();
        ssTEST_OUTPUT_SETUP
        (
            float assignFloat = 2.f;
            std::string assignString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, assignString);
        );
        ssTEST_OUTPUT_ASSERT(assignString == "test");
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        
        //TODO: Add test for not meeting conditions
    };
    
    ssTEST("Pointer Argument Matches Pointer Condition Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            float assignFloat = 2.f;
            std::string assignString = "";
        );
        
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, &assignFloat, CO_ANY)
                            .SetArgs<CO_ANY_TYPE, CO_ANY_TYPE, std::string&>(   CO_DONT_SET, 
                                                                                CO_DONT_SET, 
                                                                                "test")
                            .AssignsResult(result);

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, assignString);
        );
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", assignString == "test");
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            assignFloat = 2.f;
            float assignFloat2 = 2.f;
            assignString = "";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat2, assignString);
        );
        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", assignString == "");
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Reference Type Argument Should Promote To Pointer Type For Comparison")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            float assignFloat = 2.f;
            std::string testString = "test";
        );
        CO_INSTRUCT_NO_REF  (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, CO_ANY, &testString)
                            .SetArgs<CO_ANY_TYPE, float*, CO_ANY_TYPE>(CO_DONT_SET, 3.f, CO_DONT_SET)
                            .AssignsResult(result);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions",
                                assignFloat == 3.f);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
    
        ssTEST_OUTPUT_SETUP
        (
            assignFloat = 2.f;
            testString = "test";
            std::string testString2 = "test";
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &assignFloat, testString2);
        );
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", assignFloat == 2.f);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Reference Type Argument Should Demote To Value Type For Comparison")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            std::string testString = "test";
        );
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstStringRefArgFunc)
                        .WhenCalledWith<std::string>("test")
                        .Returns<int>(5)
                        .AssignsResult(result);
        
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                CppOverrideTest::Const::ConstStringRefArgFunc(testString) == 5);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            testString = "test2";
        );
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                CppOverrideTest::Const::ConstStringRefArgFunc(testString) == -1);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Comparing Object Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
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
        );

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(10, 20.0, "test10", setObject);
        );
        
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", setObject == overrideObject);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            setObject = CppOverrideTest::TestClass(3, 4.0, "test3");
            overrideObject = CppOverrideTest::TestClass(2, 3.0, "test2");
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::Object::SetObjectFunc(10, 20.0, "test10", setObject);
        );
        
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                setObject == CppOverrideTest::TestClass(3, 4.0, "test3"));
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions",
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Templated Object Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
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
        );

        namespace CppOverrideTemplateTest = CppOverrideTest::NonConst::Template;
        
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                CppOverrideTemplateTest::TemplateReturnFunc(conditionTemplate) == 
                                returnTemplate);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::TemplateTestClass<int> testTemplate(4, 5, 6.f, "test2");
        );
        
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                CppOverrideTemplateTest::TemplateReturnFunc(testTemplate) == 
                                testTemplate);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions",
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Member Function Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result;
            CppOverrideTest::Rectangle rect(1.5, 1.5);
            CO_INSTRUCT_NO_REF  (rect, GetWidth)
                                .WhenCalledWith(2.f)
                                .Returns<float>(5.f)
                                .AssignsResult(result);
        );
        
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", rect.GetWidth(2.f) == 5.f);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());

        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", rect.GetWidth(1.f) == 1.5);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Object Missing Inequality Operator Should Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
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
        );
        
        namespace CppOverrideTemplateTest = CppOverrideTest::NonConst::Template;
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonComparableTestClass resultDummy = 
                CppOverrideTemplateTest::TemplateReturnFunc(testDummy);
        );
        
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR);
        ssTEST_OUTPUT_ASSERT(resultDummy.GetTestData() == testDummy.GetTestData());
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}
