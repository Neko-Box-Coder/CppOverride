#include "./Components/MockShapes.hpp"
#include "ssTest.hpp"


int main(int argc, char** argv)
{
    //Testing pointer compatibility with mock macros
    CppOverrideTest::MockSquare<char>* mockSquare;
    
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    
    ssTEST_COMMON_SETUP
    {
        mockSquare = new CppOverrideTest::MockSquare<char>();
    };
    
    ssTEST_COMMON_CLEANUP
    {
        delete mockSquare;
        mockSquare = nullptr;
    };
    
    ssTEST("Return Value In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_SETUP_OVERRIDE   ((*mockSquare), GetWidth)
                                                                .Returns<float>(3.f)
                                                                .ReturnsResult();
        );

        ssTEST_OUTPUT_EXECUTION
        (
            float width = mockSquare->GetWidth();
        );

        ssTEST_OUTPUT_ASSERT("", width, 3.f);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Return Reference In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::MockSquare<char> mockSquare2 = {};
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   ((*mockSquare), GetThis)
                                    .Returns<CppOverrideTest::MockSquare<char>&>(mockSquare2)
                                    .ReturnsResult();
        );

        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::MockSquare<char>& thisRef = mockSquare->GetThis();
        );

        ssTEST_OUTPUT_ASSERT(&thisRef == &mockSquare2);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Argument Value In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   ((*mockSquare), GetWidth)
                                    .SetArgs<float&, CO_ANY_TYPE>(10.f, CO_ANY)
                                    .ReturnsResult();
            float width;
        );

        ssTEST_OUTPUT_EXECUTION
        (
            mockSquare->GetWidth(width);
        );

        ssTEST_OUTPUT_ASSERT("", width, 10.f);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Template Function In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::tuple<float, uint8_t> overrideTuple = std::make_tuple<float, uint8_t>(1.f, 5);
            std::tuple<float, uint8_t> testTuple = std::make_tuple<float, uint8_t>(3.f, 15);
            std::tuple<float, uint8_t> test2Tuple = std::make_tuple<float, uint8_t>(3.f, 16);
            
            CppOverride::ResultPtr result = 
                CO_SETUP_OVERRIDE   ((*mockSquare), TestTemplateFunc)
                                    .WhenCalledWith(testTuple, 20.f)
                                    .Returns<std::tuple<float, uint8_t>>(overrideTuple)
                                    //.SetArgs<const std::tuple<float, uint8_t>&, float>(overrideTuple, 20)
                                    .ReturnsResult();
        );
        
        ssTEST_OUTPUT_EXECUTION
        (
            std::tuple<float, uint8_t> returnTuple = mockSquare->TestTemplateFunc(testTuple, 20);
        );
        
        ssTEST_OUTPUT_ASSERT("", std::get<0>(returnTuple), std::get<0>(overrideTuple));
        ssTEST_OUTPUT_ASSERT("", (int)std::get<1>(returnTuple), (int)std::get<1>(overrideTuple));
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        
        ssTEST_OUTPUT_EXECUTION
        (
            returnTuple = mockSquare->TestTemplateFunc(test2Tuple, 20);
        );
        
        ssTEST_OUTPUT_ASSERT("", std::get<0>(returnTuple), 0);
        ssTEST_OUTPUT_ASSERT("", (int)std::get<1>(returnTuple), (int)0);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST_END_TEST_GROUP();

    return 0;
}
