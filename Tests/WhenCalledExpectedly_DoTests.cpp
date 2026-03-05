#include "CppOverride.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto setup = []()
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    //Calling WhenCalledWith Correctly Should Call WhenCalledExpectedly_Do For Returns
    {
        setup();
        CppOverrideTest::Rectangle rect(1.5, 1.5);
        bool calledExpectedly = false;
        
        CO_INSTRUCT_NO_REF  (rect, GetWidth)
                            .WhenCalledWith(2.f)
                            .Returns<float>(6.f)
                            .WhenCalledExpectedly_Do
                            (
                                [&calledExpectedly](...)
                                {
                                    calledExpectedly = true;
                                }
                            );
        rect.GetWidth(3.f);
        DS_ASSERT_FALSE(calledExpectedly);
        
        rect.GetWidth(2.f);
        DS_ASSERT_TRUE(calledExpectedly);
    }
    
    //Calling WhenCalledWith Correctly Should Call WhenCalledExpectedly_Do For SetArgs
    {
        setup();
        bool calledExpectedly = false;
        
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::Const, ConstArgsAndArgsToSetFunc)
                        .WhenCalledWith(1, 2.f, CO_ANY)
                        .SetArgs<   CO_ANY_TYPE, 
                                    CO_ANY_TYPE, 
                                    std::string&>(  CO_DONT_SET, 
                                                    CO_DONT_SET, 
                                                    "test")
                        .WhenCalledExpectedly_Do
                        (
                            [&calledExpectedly](...)
                            {
                                calledExpectedly = true;
                            }
                        );

        std::string testString;
        
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        DS_ASSERT_FALSE(calledExpectedly);
        
        CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        DS_ASSERT_TRUE(calledExpectedly);
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
