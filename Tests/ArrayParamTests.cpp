#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"

#include "DSResult/DSResult.hpp"

#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Array Parameter Function Should Be Overridable With Return
    {
        setup();
        
        int nums[4] = {0, 1, 2, 3};
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, IntArrayParameterFunc)
                        .Returns<int>(5)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::IntArrayParameterFunc(nums), 5);
        
        char chars[4] = "abc";
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, CharArrayParameterFunc)
                        .Returns<int>(5)
                        .Expected();
        DS_ASSERT_EQ(CppOverrideTest::NonConst::CharArrayParameterFunc(chars), 5);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
    }
    
    //Array Parameter Function Should Be Matchable As Pointer
    {
        setup();
        
        int nums[4] = {0, 1, 2, 3};
        int nums2[4] = {0, 1, 2, 3};
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, IntArrayParameterFunc)
                        .WhenCalledWith(nums)
                        .Returns<int>(5)
                        .AssignsResult(result);
        DS_ASSERT_EQ(CppOverrideTest::NonConst::IntArrayParameterFunc(nums), 5);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        DS_ASSERT_NOT_EQ(CppOverrideTest::NonConst::IntArrayParameterFunc(nums2), 5);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(), 
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        
        char chars[4] = "abc";
        char chars2[4] = "abc";
        result = CppOverride::ResultPtr();
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::NonConst, CharArrayParameterFunc)
                        .WhenCalledWith(chars)
                        .Returns<int>(5)
                        .AssignsResult(result);
        DS_ASSERT_EQ(CppOverrideTest::NonConst::CharArrayParameterFunc(chars), 5);
        DS_ASSERT_TRUE(result->LastStatusSucceed());

        DS_ASSERT_NOT_EQ(CppOverrideTest::NonConst::CharArrayParameterFunc(chars2), 5);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(), 
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    }

    //Array As Template Parameter Should Be Overridable
    {
        setup();
        
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
        
        DS_ASSERT_EQ(CppOverrideTest::NonConst::Template::TemplateArgRefFunc(chars), 5);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
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
