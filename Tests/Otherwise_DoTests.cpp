#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./FileFunctions.hpp"
#include "./ClassFunctions.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("Returns Test")
    {
        Rectangle rect(1.5, 1.5);
        
        bool otherwiseDoCalled = false;
        
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
        
        rect.GetWidth(2.f);
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        rect.GetWidth(3.f);
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST("SetArgs Test")
    {
        bool otherwiseDoCalled = false;
        
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithConstArgsAndArgsToSet)
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

        std::string testString;
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == false);
        
        FuncWithConstArgsAndArgsToSet(2, 3.f, testString);
        ssTEST_OUTPUT_ASSERT(otherwiseDoCalled == true);
    };
    
    ssTEST_END();
    
    return 0;
}