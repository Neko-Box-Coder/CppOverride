#include "./Components/GlobalInstanceMockShapes.hpp"
#include "DSResult/DSResult.hpp"
#include <iostream>

CppOverride::Overrider OverrideObj;

DS::Result<void> TestMain()
{
    auto cleanup = []()
    {
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
    };
    
    //Constructor Should Be Overridable
    {
        CppOverride::ResultPtr result;
        CO_INSTRUCT_NO_REF  (OverrideObj, MockSquare)
                            .WhenCalledWith<float, int>(1.f, 2)
                            .AssignsResult(result);
        CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
    
        CppOverrideTest::MockSquare<int> testSquare2(2.f, 3);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        cleanup();
    }

    //Destructor Should Be Overridable
    {
        void* createdInstance = nullptr;
        uint64_t temp;
        void* destructInstance = nullptr;
        
        {
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
            temp = (uint64_t)&testSquare;
            CO_INSTRUCT_NO_REF  (OverrideObj, ~MockSquare)
                                .WhenCalledExpectedly_Do
                                (
                                    [&destructInstance]
                                    (
                                        void* instance, 
                                        std::vector<CppOverride::TypedDataInfo>&
                                    )
                                    {
                                        destructInstance = instance;
                                    }
                                )
                                .MatchesObject(&testSquare)
                                .Expected();
        }
        
        createdInstance = (void*)temp;
        DS_ASSERT_EQ(createdInstance, destructInstance);
        DS_ASSERT_TRUE(CO_GET_FAILED_FUNCTIONS(OverrideObj).empty());
        cleanup();
    }

    //Object Should Be Overridable When Instance Is Specified
    {
        CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::MockSquare<int>, GetArea)
                        .Returns<float>(13.f)
                        .WhenCalledWith(42.f)
                        .MatchesObject(&testSquare)
                        .AssignsResult(result);
        DS_ASSERT_EQ(testSquare.GetArea(42.f), 13.f);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        DS_ASSERT_NOT_EQ(testSquare.GetArea(43.f), 13.f);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        cleanup();
    }

    //Object Should Be Overridable When Any Instance Is Specified
    {
        CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
        CppOverride::ResultPtr result;
        CO_INSTRUCT_REF (OverrideObj, CppOverrideTest::MockSquare<int>, GetArea)
                        .Returns<float>(13.f)
                        .WhenCalledWith(42.f)
                        .MatchesAny()
                        .AssignsResult(result);
        DS_ASSERT_EQ(testSquare.GetArea(42.f), 13.f);
        DS_ASSERT_TRUE(result->LastStatusSucceed());
        
        DS_ASSERT_NOT_EQ(testSquare.GetArea(43.f), 13.f);
        DS_ASSERT_EQ(   (int)result->GetLastStatus(),
                        (int)CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
        cleanup();
    }

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
