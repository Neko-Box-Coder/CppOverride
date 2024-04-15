#include "CppOverride.hpp"
#include "ssTest.hpp"
#include "./Components/FileFunctions.hpp"
#include "./Components/Shapes.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT();
    ssTEST_SET_UP
    {
        OverrideObj = CppOverride::Overrider();
    };
    
    ssTEST("If Condition Should Affect Return")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsFunc)
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
    
        ssTEST_OUTPUT_ASSERT(   "Meet If Condition", 
                                ::CppOverrideTest::NonConst::ArgsFunc(1, true, 2.f) == 1);
        
        ssTEST_OUTPUT_ASSERT(   "Fail If Condition", 
                                ::CppOverrideTest::NonConst::ArgsFunc(2, false, 3.f) != 1);
    };
    
    ssTEST("If Condition Should Affect Set Args")
    {
        CO_SETUP_OVERRIDE   (OverrideObj, ArgsToSetFunc)
                            .If
                            (
                                [] (const std::vector<void *>& args) -> bool
                                {
                                    if( *static_cast<int*>(args.at(0)) == 1 &&
                                        **static_cast<float**>(args.at(1)) == 2.f &&
                                        *static_cast<std::string*>(args.at(2)) == "Test String")
                                    {
                                        return true;
                                    }
                                    
                                    return false;
                                }
                            )
                            .SetArgs<   CO_ANY_TYPE, 
                                        CO_ANY_TYPE, 
                                        std::string&>(  CO_DONT_SET, 
                                                        CO_DONT_SET, 
                                                        "Test String 2");

        ssTEST_OUTPUT_SETUP
        (
            std::string testString = "";
            float testFloat = 1.f;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT("Fail If Condition", testString.empty());
        
        ssTEST_OUTPUT_SETUP
        (
            testString = "Test String";
            testFloat = 2.f;
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::NonConst::ArgsToSetFunc(1, &testFloat, testString);
        );
        ssTEST_OUTPUT_ASSERT("Meet If Condition", testString == "Test String 2");
    };
    
    ssTEST_END();
    
    return 0;
}