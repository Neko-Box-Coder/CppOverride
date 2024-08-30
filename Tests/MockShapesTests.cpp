#include "./Components/MockShapes.hpp"
#include "ssTest.hpp"


int main()
{
    // Testing pointer compatibility with mock macros
    CppOverrideTest::MockSquare<char>* mockSquare;
    
    ssTEST_INIT_TEST_GROUP();
    
    ssTEST_COMMON_SET_UP
    {
        mockSquare = new CppOverrideTest::MockSquare<char>();
    };
    
    ssTEST_COMMON_CLEAN_UP
    {
        delete mockSquare;
        mockSquare = nullptr;
    };
    
    ssTEST("Return Value In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   ((*mockSquare), GetWidth)
                                .Returns<float>(3.f)
                                .AssignResult(result);
        );

        ssTEST_OUTPUT_EXECUTION
        (
            float width = mockSquare->GetWidth();
        );

        ssTEST_OUTPUT_ASSERT("", width, 3.f);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    };
    
    ssTEST("Argument Value In Mock Class Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            CO_SETUP_OVERRIDE   ((*mockSquare), GetWidth)
                                .SetArgs<float&, CO_ANY_TYPE>(10.f, CO_ANY)
                                .AssignResult(result);
        
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
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
            
            std::tuple<float, uint8_t> overrideTuple = std::make_tuple(1.f, 5);
            std::tuple<float, uint8_t> testTuple = std::make_tuple(3.f, 15);
            std::tuple<float, uint8_t> test2Tuple = std::make_tuple(3.f, 16);
            
            CO_SETUP_OVERRIDE   ((*mockSquare), TestTemplateFunc)
                                .WhenCalledWith(testTuple, 20.f)
                                .Returns<std::tuple<float, uint8_t>>(overrideTuple)
                                // .SetArgs<const std::tuple<float, uint8_t>&, float>(overrideTuple, 20)
                                .AssignResult(result);
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
