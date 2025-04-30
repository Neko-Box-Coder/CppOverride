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
        std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsFunc)
                            .Returns<int>(1)
                            .WhenCalledWith(1, true, 2.f)
                            .AssignsResult(result);
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(1, true, 2.f) == 1);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions",
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(2, false, 2.f) != 1);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions",
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Comparing Primitive Type Should Override Arguments If Match")
    {
        std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        CO_SETUP_OVERRIDE   (OverrideObj, MoreArgsToSetFunc)
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
            result->ClearStatuses();
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
        std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsFunc)
                            .WhenCalledWith(CO_ANY, CO_ANY, CO_ANY)
                            .Returns<int>(1)
                            .AssignsResult(result);

        ssTEST_OUTPUT_ASSERT(CppOverrideTest::NonConst::ArgsFunc(1, false, 2.f) == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Comparing Const Void Pointer Should Override If Match")
    {
        ssTEST_OUTPUT_SETUP
        (
            float testArg = 1;
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            
            (CO_SETUP_OVERRIDE  (OverrideObj, ConstVoidPointerFunc)
                                .WhenCalledWith<const void*, int>(&testArg, 2)
                                .Returns<int>(1))
                                .AssignsResult(result);
        );
        ssTEST_OUTPUT_ASSERT(CppOverrideTest::Const::ConstVoidPointerFunc(&testArg, 2) == 1);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Pointer Type Argument Should Demote To Value Type For Comparison")
    {
        std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, 2.f, CO_ANY)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "test")
                            .AssignsResult(result);

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
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        //TODO: Add test for not meeting conditions
    };
    
    ssTEST("Pointer Argument Matches Pointer Condition Should Override If Match")
    {
        std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        
        ssTEST_OUTPUT_SETUP
        (
            float assignFloat = 2.f;
            std::string assignString = "";
        );
        
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, &assignFloat, CO_ANY)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
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
            result->ClearStatuses();
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            float assignFloat = 2.f;
            std::string testString = "test";
        );
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsToSetFunc)
                            .WhenCalledWith(1, CO_ANY, &testString)
                            .SetArgs<   CO_ANY_TYPE, 
                                        float*, 
                                        CO_ANY_TYPE>(   CO_DONT_SET, 
                                                        3.f, 
                                                        CO_DONT_SET)
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
            result->ClearStatuses();
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            std::string testString = "test";
        );
        CO_SETUP_OVERRIDE   (OverrideObj, ConstStringRefArgFunc)
                            .WhenCalledWith<std::string>("test")
                            .Returns<int>(5)
                            .AssignsResult(result);
        
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                CppOverrideTest::Const::ConstStringRefArgFunc(testString) == 5);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CppOverrideTest::TestClass conditionObject(1, 2.0, "test");
            CppOverrideTest::TestClass setObject(1, 2.0, "test");
            CppOverrideTest::TestClass overrideObject(2, 3.0, "test2");
        
            CO_SETUP_OVERRIDE   (OverrideObj, SetObjectFunc)
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
            result->ClearStatuses();
            setObject = CppOverrideTest::TestClass (3, 4.0, "test3");
            overrideObject = CppOverrideTest::TestClass (2, 3.0, "test2");
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CppOverrideTest::TemplateTestClass<int> conditionTemplate(1, 2, 3.f, "test");
            CppOverrideTest::TemplateTestClass<int> returnTemplate(2, 3, 4.f, "test2");
            
            CO_SETUP_OVERRIDE   (OverrideObj, TemplateReturnFunc)
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
            result->ClearStatuses();
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CppOverrideTest::Rectangle rect(1.5, 1.5);
            CO_SETUP_OVERRIDE   (rect, GetWidth)
                                .WhenCalledWith(2.f)
                                .Returns<float>(5.f)
                                .AssignsResult(result);
        );
        
        ssTEST_OUTPUT_ASSERT("Meet WhenCalledWith Conditions", rect.GetWidth(2.f) == 5.f);
        ssTEST_OUTPUT_ASSERT(   "Meet WhenCalledWith Conditions", 
                                result->LastStatusSucceed());

        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        ssTEST_OUTPUT_ASSERT("Fail WhenCalledWith Conditions", rect.GetWidth(1.f) == 1.5);
        ssTEST_OUTPUT_ASSERT(   "Fail WhenCalledWith Conditions", 
                                result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };
    
    ssTEST("Object Missing Inequality Operator Should Fail With Status")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CppOverrideTest::NonComparableTestClass testDummy(2, 3.0, "test");
            CppOverrideTest::NonComparableTestClass returnDummy(3, 4.0, "test2");
            CO_SETUP_OVERRIDE   (OverrideObj, TemplateReturnFunc)
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
