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
    
    ssTEST("Return Test")
    {
        SO_OVERRIDE_RETURNS (OverrideObj, FuncWithConstArgs(const int, const bool, float))
                            .If
                            (
                                [] (const std::vector<void *>& args) -> bool
                                {
                                    if( *static_cast<const int*>(args.at(0)) == 1 &&
                                        *static_cast<const bool*>(args.at(1)) == true &&
                                        *static_cast<float*>(args.at(2)) == 2.f)
                                    {
                                        return true;
                                    }
                                    
                                    return false;
                                }
                            )
                            .Returns(1);
    
        ssTEST_OUTPUT_ASSERT(FuncWithConstArgs(1, true, 2.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(FuncWithConstArgs(2, false, 3.f) != 1);
    };
    
    ssTEST("SetArgs Test")
    {
        SO_OVERRIDE_ARGS(OverrideObj, FuncWithConstArgsAndArgsToSet(const int, 
                                                                    const float, 
                                                                    std::string&))
                        .If
                        (
                            [] (const std::vector<void *>& args) -> bool
                            {
                                if( *static_cast<const int*>(args.at(0)) == 1 &&
                                    *static_cast<const float*>(args.at(1)) == 2.f &&
                                    *static_cast<std::string*>(args.at(2)) == "Test String")
                                {
                                    return true;
                                }
                                
                                return false;
                            }
                        )
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, std::string("Test String 2"));

        std::string testString = "";
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);

        ssTEST_OUTPUT_ASSERT(testString.empty());
        
        testString = "Test String";
        
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        
        ssTEST_OUTPUT_ASSERT(testString == "Test String 2");
    };
    
    ssTEST_END();
    
    return 0;
}