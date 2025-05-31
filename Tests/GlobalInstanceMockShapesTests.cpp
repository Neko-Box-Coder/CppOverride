#include "./Components/GlobalInstanceMockShapes.hpp"
#include "ssTest.hpp"

CppOverride::Overrider OverrideObj;

int main(int argc, char** argv)
{
    ssTEST_INIT_TEST_GROUP();
    ssTEST_PARSE_ARGS(argc, argv);
    
    ssTEST_COMMON_SETUP
    {};
    
    ssTEST_COMMON_CLEANUP
    {
        CO_CLEAR_ALL_INSTRUCTS(OverrideObj);
    };
    
    ssTEST("Constructor Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::ResultPtr result = CO_INSTRUCT (OverrideObj, MockSquare)
                                                        .WhenCalledWith<float, int>(1.f, 2)
                                                        .ReturnsResult();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
        );
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
    
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::MockSquare<int> testSquare2(2.f, 3);
        );
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST("Destructor Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            void* createdInstance = nullptr;
            void* destructInstance = nullptr;
            std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
        );
        {
            ssTEST_OUTPUT_SETUP
            (
                CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
                createdInstance = &testSquare;
                CO_INSTRUCT (OverrideObj, ~MockSquare)
                            .WhenCalledExpectedly_Do
                            (
                                [&destructInstance](void* instance, 
                                                    const std::vector<void*>&)
                                {
                                    destructInstance = instance;
                                }
                            )
                            .MatchesObject(&testSquare)
                            .AssignsResult(result);
            );
        }
        
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        ssTEST_OUTPUT_ASSERT(createdInstance == destructInstance);
    };

    ssTEST("Object Should Be Overridable When Instance Is Specified")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
            CppOverride::ResultPtr result = CO_INSTRUCT (OverrideObj, GetArea)
                                                        .Returns<float>(13.f)
                                                        .WhenCalledWith(42.f)
                                                        .MatchesObject(&testSquare)
                                                        .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(42.f) == 13.f);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(43.f) != 13.f);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST("Object Should Be Overridable When Any Instance Is Specified")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
            CppOverride::ResultPtr result = CO_INSTRUCT (OverrideObj, GetArea)
                                                        .Returns<float>(13.f)
                                                        .WhenCalledWith(42.f)
                                                        .MatchesAny()
                                                        .ReturnsResult();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(42.f) == 13.f);
        ssTEST_OUTPUT_ASSERT(result->LastStatusSucceed());
        
        ssTEST_OUTPUT_SETUP
        (
            result->ClearStatuses();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(43.f) != 13.f);
        ssTEST_OUTPUT_ASSERT(   result->GetLastStatus() == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST_END_TEST_GROUP();

    return 0;
}
