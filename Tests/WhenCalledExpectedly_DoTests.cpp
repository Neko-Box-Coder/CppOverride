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
        
        bool calledExpectedly = false;
        
        SO_OVERRIDE_RETURNS (rect, GetWidth(float))
                            .WhenCalledWith(2.f)
                            .Returns(6.f)
                            .WhenCalledExpectedly_Do
                            (
                                [&calledExpectedly] (const std::vector<void *>& args)
                                {
                                    calledExpectedly = true;
                                }
                            );
        
        rect.GetWidth(3.f);
        ssTEST_OUTPUT_ASSERT(calledExpectedly == false);
        
        rect.GetWidth(2.f);
        ssTEST_OUTPUT_ASSERT(calledExpectedly == true);
    };
    
    ssTEST("SetArgs Test")
    {
        bool calledExpectedly = false;
        
        SO_OVERRIDE_ARGS(OverrideObj, FuncWithConstArgsAndArgsToSet(    const int, 
                                                                        const float, 
                                                                        std::string&))
                        .WhenCalledWith(1, 2.f, SO_ANY)
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, std::string("test"))
                        .WhenCalledExpectedly_Do
                        (
                            [&calledExpectedly] (const std::vector<void *>& args)
                            {
                                calledExpectedly = true;
                            }
                        );

        std::string testString;
        
        FuncWithConstArgsAndArgsToSet(2, 3.f, testString);
        ssTEST_OUTPUT_ASSERT(calledExpectedly == false);
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        ssTEST_OUTPUT_ASSERT(calledExpectedly == true);
    };
    
    ssTEST_END();
    
    return 0;
}