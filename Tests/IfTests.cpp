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
    
    ssTEST("Return Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithConstArgs)
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
                            .Returns<int>(1);
    
        ssTEST_OUTPUT_ASSERT(FuncWithConstArgs(1, true, 2.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(FuncWithConstArgs(2, false, 3.f) != 1);
    };
    
    ssTEST("SetArgs Test")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, FuncWithConstArgsAndArgsToSet)
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
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(   CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "Test String 2");

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