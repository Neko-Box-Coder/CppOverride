#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_COMMON_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };


    ssTEST("Array Parameter Function Should Be Overridable With Return")
    {
        ssTEST_OUTPUT_SETUP
        (
            int nums[4] = {0, 1, 2, 3};
            CppOverride::OverrideResult result;
            CO_SETUP_OVERRIDE   (OverrideObj, IntArrayParameterFunc)
                                .Returns<int>(5)
                                .AssignOverrideResult(result);
        );

        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums);
        );

        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            result = CppOverride::OverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, CharArrayParameterFunc)
                                .Returns<int>(5)
                                .AssignOverrideResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars);
        );
        
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST("Array Parameter Function Should Be Matchable As Pointer")
    {
        ssTEST_OUTPUT_SETUP
        (
            int nums[4] = {0, 1, 2, 3};
            int nums2[4] = {0, 1, 2, 3};
            CppOverride::OverrideResult result;
            CO_SETUP_OVERRIDE   (OverrideObj, IntArrayParameterFunc)
                                .WhenCalledWith(nums)
                                .Returns<int>(5)
                                .AssignOverrideResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums);
        );
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::IntArrayParameterFunc(nums2);
        );
        ssTEST_OUTPUT_ASSERT(returnValue != 5);
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            char chars2[4] = "abc";
            result = CppOverride::OverrideResult();
            CO_SETUP_OVERRIDE   (OverrideObj, CharArrayParameterFunc)
                                .WhenCalledWith(chars)
                                .Returns<int>(5)
                                .AssignOverrideResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars);
        );
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(   "",
                                static_cast<int>(result.Status), 
                                static_cast<int>(CppOverride::OverrideStatus::OVERRIDE_SUCCESS));

        ssTEST_OUTPUT_EXECUTION
        (
            returnValue = CppOverrideTest::NonConst::CharArrayParameterFunc(chars2);
        );
        ssTEST_OUTPUT_ASSERT(returnValue != 5);
        ssTEST_OUTPUT_ASSERT(   "",
                                static_cast<int>(result.Status),
                                static_cast<int>(   CppOverride::
                                                    OverrideStatus::
                                                    MATCHING_CONDITION_VALUE_FAILED));
    };

    ssTEST("Array As Template Parameter Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            char chars[4] = "abc";
            CppOverride::OverrideResult result;
            CO_SETUP_OVERRIDE   (OverrideObj, TemplateArgRefFunc)
                                .WhenCalledWith(chars)
                                .Returns<int>(5)
                                .AssignOverrideResult(result);
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            int returnValue = CppOverrideTest::NonConst::Template::TemplateArgRefFunc(chars);
        );
        
        ssTEST_OUTPUT_ASSERT(returnValue == 5);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    };
    
    ssTEST_END_TEST_GROUP();
}
