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
        
        CO_OVERRIDE_RETURNS (rect, GetWidth(float))
                            .WhenCalledWith(2.f)
                            .Returns(6.f)
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
        
        CO_OVERRIDE_ARGS(OverrideObj, FuncWithConstArgsAndArgsToSet(    const int, 
                                                                        const float, 
                                                                        std::string&))
                        .WhenCalledWith(1, 2.f, CO_ANY)
                        .SetArgs(CO_DONT_SET, CO_DONT_SET, std::string("test"))
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