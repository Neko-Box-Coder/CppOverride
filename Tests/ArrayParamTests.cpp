#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main(int argc, char** argv)
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    ssTEST_COMMON_SETUP
    {
        OverrideObj = CppOverride::Overrider();
    };

    ssTEST("Array Parameter Function Should Be Overridable With Return")
    {
        ssTEST_OUTPUT_SETUP
        (
            int nums[4] = {0, 1, 2, 3};
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, IntArrayParameterFunc)
                            .Returns<int>(5)
                            .Expected();
        );

        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums);
        );

        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, CharArrayParameterFunc)
                            .Returns<int>(5)
                            .Expected();
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars);
        );
        
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST("Array Parameter Function Should Be Matchable As Pointer")
    {
        ssTEST_OUTPUT_SETUP
        (
            int nums[4] = {0, 1, 2, 3};
            int nums2[4] = {0, 1, 2, 3};
            CppOverride::ResultPtr result;
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, IntArrayParameterFunc)
                            .WhenCalledWith(nums)
                            .Returns<int>(5)
                            .AssignsResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums);
        );
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums2);
        );
        ssTEST_OUTPUT_ASSERT(returnValue != 5);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            char chars2[4] = "abc";
            result = CppOverride::ResultPtr();
            CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, CharArrayParameterFunc)
                            .WhenCalledWith(chars)
                            .Returns<int>(5)
                            .AssignsResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars);
        );
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());

        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars2);
        );
        ssTEST_OUTPUT_ASSERT(returnValue != 5);
        ssTEST_OUTPUT_ASSERT(   "",
                                static_cast<int>(result->GetLastStatus()),
                                static_cast<int>(   CppOverride::
                                                    OverrideStatus::
                                                    MATCHING_CONDITION_VALUE_FAILED));
    };

    ssTEST("Array As Template Parameter Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            CO_INSTRUCT_REF
            (
                OverrideObj, 
                CppOverrideTest::NonConst::Template, 
                TemplateArgRefFunc<char[]>
            )
            .WhenCalledWith(chars)
            .Returns<int>(5)
            .Expected();
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::Template::TemplateArgRefFunc(chars);
        );
        
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(CO_GET_FAILED_EXPECTS(OverrideObj).empty());
    };
    
    ssTEST_END_TEST_GROUP();
}
