#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/TestClasses.hpp"
#include "./Components/Shapes.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("WhenCalledWith Condition Not Met Should Trigger Otherwise_Do For Return")
    {
        ssTEST_OUTPUT_SETUP
        (
            Rectangle rect(1.5, 1.5);
            bool otherwiseDoCalled = false;
        );
        
        
        CO_SETUP_OVERRIDE   (rect, GetWidth)
                            .WhenCalledWith(2.f)
                            .Returns<float>(6.f)
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled] (const std::vector<void *>& args)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );
        
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(2.f);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(3.f);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST("If Condition Not Met Should Trigger Otherwise_Do For Return")
    {
        ssTEST_OUTPUT_SETUP
        (
            Rectangle rect(1.5, 1.5);
            bool otherwiseDoCalled = false;
        );
        
        
        CO_SETUP_OVERRIDE   (rect, GetWidth)
                            .If
                            (
                                [] (const std::vector<void *>& args)
                                {
                                    return (*(float*)args[0] == 2.f);
                                }
                            )
                            .Returns<float>(6.f)
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled] (const std::vector<void *>& args)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );
        
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(2.f);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            rect.GetWidth(3.f);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST("WhenCalledWith Condition Not Met Should Trigger Otherwise_Do For SetArgs")
    {
        ssTEST_OUTPUT_SETUP
        (
            bool otherwiseDoCalled = false;
            std::string testString;
        );
        
        CO_SETUP_OVERRIDE   (OverrideObj, ConstArgsAndArgsToSetFunc)
                            .WhenCalledWith(1, 2.f, CO_ANY)
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "test")
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled] (const std::vector<void *>& args)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST("If Condition Not Met Should Trigger Otherwise_Do For SetArgs")
    {
        ssTEST_OUTPUT_SETUP
        (
            bool otherwiseDoCalled = false;
            std::string testString;
        );
        
        CO_SETUP_OVERRIDE   (OverrideObj, ConstArgsAndArgsToSetFunc)
                            .If
                            (
                                [] (const std::vector<void *>& args)
                                {
                                    return (*(int*)args[0] == 1) && (*(float*)args[1] == 2.f);
                                }
                            )
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "test")
                            .Otherwise_Do
                            (
                                [&otherwiseDoCalled] (const std::vector<void *>& args)
                                {
                                    otherwiseDoCalled = true;
                                }
                            );

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(1, 2.f, testString);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::Const::ConstArgsAndArgsToSetFunc(2, 3.f, testString);
        );
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST_END();
    
    return 0;
}