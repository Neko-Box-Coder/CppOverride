#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_COMMON_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Calling WhenCalledWith Correctly Should Call WhenCalledExpectedly_Do For Returns")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::Rectangle rect(1.5, 1.5);
            bool calledExpectedly = false;
            
            CO_SETUP_OVERRIDE   (rect, GetWidth)
                                .WhenCalledWith(2.f)
                                .Returns<float>(6.f)
                                .WhenCalledExpectedly_Do
                                (
                                    [&calledExpectedly] (const std::vector<void *>& args)
                                    {
                                        calledExpectedly = true;
                                    }
                                );
        );
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(3.f);
        );
        ssTEST_OUTPUT_ASSERT("Not Meeting WhenCalledWith", calledExpectedly == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(2.f);
        );
        ssTEST_OUTPUT_ASSERT("Meeting WhenCalledWith", calledExpectedly == true);
    };
    
    ssTEST("Calling WhenCalledWith Correctly Should Call WhenCalledExpectedly_Do For SetArgs")
    {
        ssTEST_OUTPUT_SETUP
        (
            bool calledExpectedly = false;
            
            CO_SETUP_OVERRIDE   (OverrideObj, ConstArgsAndArgsToSetFunc)
                                .WhenCalledWith(1, 2.f, CO_ANY)
                                .SetArgs<   CO_ANY_TYPE, 
                                            CO_ANY_TYPE, 
                                            std::string&>(  CO_DONT_SET, 
                                                            CO_DONT_SET, 
                                                            "test")
                                .WhenCalledExpectedly_Do
                                (
                                    [&calledExpectedly] (const std::vector<void *>& args)
                                    {
                                        calledExpectedly = true;
                                    }
                                );

            std::string testString;
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        );
        ssTEST_OUTPUT_ASSERT("Not Meeting WhenCalledWith", calledExpectedly == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        );
        ssTEST_OUTPUT_ASSERT("Meeting WhenCalledWith", calledExpectedly == true);
    };
    
    ssTEST_END_TEST_GROUP();
    
    return 0;
}