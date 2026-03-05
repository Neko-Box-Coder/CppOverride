#include "./Components/MockShapes.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>


DS::Result<void> TestMain()
{
    //Testing pointer compatibility with mock macros
    CppOverrideTest::MockSquare<char>* mockSquare;
    
    auto setup = [&mockSquare]()
    {
        mockSquare = new CppOverrideTest::MockSquare<char>();
    };
    
    auto cleanup = [&mockSquare]()
    {
        delete mockSquare;
        mockSquare = nullptr;
    };
    
    //Return Value In Mock Class Should Be Overridable
    {
        setup();
        CO_INSTRUCT_NO_REF(*mockSquare, GetWidth).Returns<float>(3.f).Expected();
        DS_ASSERT_EQ(mockSquare->GetWidth(), 3.f);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(*mockSquare).empty());
        cleanup();
    };
    
    //Return Reference In Mock Class Should Be Overridable
    {
        setup();
        CppOverrideTest::MockSquare<char> mockSquare2 = {};
        CO_INSTRUCT_REF (*mockSquare, CppOverrideTest::MockSquare<char>, GetThis)
                        .Returns<CppOverrideTest::MockSquare<char>&>(mockSquare2)
                        .Expected();
        DS_ASSERT_EQ(&mockSquare->GetThis(), &mockSquare2);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(*mockSquare).empty());
        cleanup();
    };
    
    //Argument Value In Mock Class Should Be Overridable
    {
        setup();
        CO_INSTRUCT_NO_REF  (*mockSquare, GetWidth)
                            .SetArgs<float&, CO_ANY_TYPE>(10.f, CO_ANY)
                            .Expected();
        float width;
        mockSquare->GetWidth(width);

        DS_ASSERT_EQ(width, 10.f);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(*mockSquare).empty());
        cleanup();
    };
    
    //Template Function In Mock Class Should Be Overridable
    {
        setup();
        std::tuple<float, uint8_t> overrideTuple = std::make_tuple<float, uint8_t>(1.f, 5);
        std::tuple<float, uint8_t> testTuple = std::make_tuple<float, uint8_t>(3.f, 15);
        std::tuple<float, uint8_t> test2Tuple = std::make_tuple<float, uint8_t>(3.f, 16);
        
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (*mockSquare, CppOverrideTest::MockSquare<char>, TestTemplateFunc<uint8_t>)
                        .WhenCalledWith(testTuple, 20.f)
                        .Returns<std::tuple<float, uint8_t>>(overrideTuple)
                        //.SetArgs<const std::tuple<float, uint8_t>&, float>(overrideTuple, 20)
                        .AssignsResult(result);
        
        std::tuple<float, uint8_t> returnTuple = mockSquare->TestTemplateFunc(testTuple, 20);
        DS_ASSERT_EQ(std::get<0>(returnTuple), std::get<0>(overrideTuple));
        DS_ASSERT_EQ((int)std::get<1>(returnTuple), (int)std::get<1>(overrideTuple));
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        
        returnTuple = mockSquare->TestTemplateFunc(test2Tuple, 20);
        DS_ASSERT_EQ(std::get<0>(returnTuple), 0);
        DS_ASSERT_EQ((int)std::get<1>(returnTuple), (int)0);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        cleanup();
    };

    return {};
}

int main(int, char**)
{
    try
    {
        TestMain().DS_TRY_ACT(std::cout << DS_TMP_ERROR.ToString() << std::endl; return 1);
        return 0;
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    return 1;
}
