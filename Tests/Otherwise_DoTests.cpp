#include "SimpleOverride.hpp"
#include "ssTest.hpp"
#include "./FileFunctions.hpp"
#include "./ClassFunctions.hpp"

SimpleOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = SimpleOverride::Overrider();
    };
    
    ssTEST("Returns Test")
    {
        Rectangle rect(1.5, 1.5);
        
        bool otherwiseDoCalled = false;
        
        SO_OVERRIDE_RETURNS (rect, GetWidth(float))
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
        
        SO_OVERRIDE_ARGS(OverrideObj, FuncWithConstArgsAndArgsToSet(    const int, 
                                                                        const float, 
                                                                        std::string&))
                        .WhenCalledWith(1, 2.f, SO_ANY)
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, std::string("test"))
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