#include "./Components/GlobalInstanceMockShapes.hpp"
#include "ssTest.hpp"

CppOverride::Overrider OverrideObj;

int main()
{
    ssTEST_INIT_TEST_GROUP();
    
    ssTEST_COMMON_SET_UP
    {};
    
    ssTEST_COMMON_CLEAN_UP
    {
        CO_CLEAR_ALL_OVERRIDE_SETUP(OverrideObj);
    };
    
    ssTEST("Constructor Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CO_SETUP_OVERRIDE   (OverrideObj, MockSquare)
                                .WhenCalledWith<float, int>(1.f, 2)
                                .AssignOverrideResult(result);
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
        );
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
    
        ssTEST_OUTPUT_SETUP
        (
            result = CppOverride::OverrideResult();
        );
        ssTEST_OUTPUT_EXECUTION
        (
            CppOverrideTest::MockSquare<int> testSquare2(2.f, 3);
        );
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST("Destructor Should Be Overridable")
    {
        ssTEST_OUTPUT_SETUP
        (
            void* createdInstance = nullptr;
            void* destructInstance = nullptr;
            CppOverride::OverrideResult result;
        );
        {
            ssTEST_OUTPUT_SETUP
            (
                CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
                createdInstance = &testSquare;
                CO_SETUP_OVERRIDE   (OverrideObj, ~MockSquare)
                                    .WhenCalledExpectedly_Do
                                    (
                                        [&destructInstance](void* instance, 
                                                            const std::vector<void*>&)
                                        {
                                            destructInstance = instance;
                                        }
                                    )
                                    .OverrideObject(&testSquare)
                                    .AssignOverrideResult(result);
            );
        }
        
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        ssTEST_OUTPUT_ASSERT(createdInstance == destructInstance);
    };

    ssTEST("Object Should Be Overridable When Instance Is Specified")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
            CO_SETUP_OVERRIDE   (OverrideObj, GetArea)
                                .Returns<float>(13.f)
                                .WhenCalledWith(42.f)
                                .OverrideObject(&testSquare)
                                .AssignOverrideResult(result);
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(42.f) == 13.f);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        ssTEST_OUTPUT_SETUP
        (
            result = CppOverride::OverrideResult();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(43.f) != 13.f);
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST("Object Should Be Overridable When Any Instance Is Specified")
    {
        ssTEST_OUTPUT_SETUP
        (
            CppOverride::OverrideResult result;
            CppOverrideTest::MockSquare<int> testSquare(1.f, 2);
            CO_SETUP_OVERRIDE   (OverrideObj, GetArea)
                                .Returns<float>(13.f)
                                .WhenCalledWith(42.f)
                                .OverrideAny()
                                .AssignOverrideResult(result);
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(42.f) == 13.f);
        ssTEST_OUTPUT_ASSERT(result.Status == CppOverride::OverrideStatus::OVERRIDE_SUCCESS);
        
        ssTEST_OUTPUT_SETUP
        (
            result = CppOverride::OverrideResult();
        );
        ssTEST_OUTPUT_ASSERT(testSquare.GetArea(43.f) != 13.f);
        ssTEST_OUTPUT_ASSERT(   result.Status == 
                                CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    };

    ssTEST_END_TEST_GROUP();

    return 0;
}
