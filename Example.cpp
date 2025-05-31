#include "CppOverride.hpp"

CO_DECLARE_INSTANCE(OverrideInstanceName);

int OverrideMyReturnValue(int value1, float value2)
{
    CO_INSERT_IMPL(OverrideInstanceName, int, (value1, value2));
    //The rest of the implementations...
    return 0;
}

int SomeRef = 0;

int& OverrideMyReturnRef(int value1, float value2)
{
    CO_INSERT_IMPL(OverrideInstanceName, int&, (value1, value2));
    //The rest of the implementations...
    return SomeRef;
}

void OverrideMyArgs(float& value1, int* value2)
{
    CO_INSERT_IMPL(OverrideInstanceName, void, (value1, value2));
}

bool OverrideMyArgsWithStstus(float& value1, int* value2)
{
    CO_INSERT_IMPL(OverrideInstanceName, bool, (value1, value2));
    return false;
}

#define CO_QUICK_ASSERT(expr)\
do\
{\
    bool assertion = (expr);\
    if(assertion)\
    {\
        std::cout << "Assertion succeeded: \"" << #expr << "\"" << std::endl;\
    }\
    else\
    {\
        std::cerr << "Assertion failed: \"" << #expr << "\"" << std::endl;\
        exit(-1);\
    }\
} while(0)

void ResetAll()
{
    CO_CLEAR_ALL_INSTRUCTS(OverrideInstanceName);
}

void OverrideReturnsExample()
{
    CO_INSTRUCT(OverrideInstanceName, OverrideMyReturnValue).Returns<int>(1);

    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 1);

    int returnRef = 1;
    CO_INSTRUCT   (OverrideInstanceName, OverrideMyReturnRef)
                        .Returns<int&>(returnRef);

    CO_QUICK_ASSERT(&returnRef == &OverrideMyReturnRef(0, 0.f));
    
    ResetAll();
}

void OverrideArgumentsExample()
{
    CO_INSTRUCT(OverrideInstanceName, OverrideMyArgs).SetArgs<float&, int*>(1.f, 3);

    float arg1 = 0.f;
    int arg2 = 0;
    OverrideMyArgs(arg1, &arg2);
    CO_QUICK_ASSERT(arg1 == 1.f);
    CO_QUICK_ASSERT(arg2 == 3);
    
    ResetAll();
}

void OverrideReturnsWithActionLambda()
{
    CO_INSTRUCT (OverrideInstanceName, OverrideMyReturnValue)
                .ReturnsByAction<int>
                ( 
                    [](void*, const std::vector<void*>&, void* out)
                    { 
                        *static_cast<int*>(out) = 5;
                    }
                );
    
    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 5);

    ResetAll();
}

void OverrideArgumentsWithActionLambda()
{
    CO_INSTRUCT (OverrideInstanceName, OverrideMyArgs)
                .SetArgsByAction<float&, int*>
                (
                    [](void*, std::vector<void*>& args)
                    {
                        *static_cast<float*>(args.at(0)) = 1.f;
                        **static_cast<int**>(args.at(1)) = 2;
                    }
                );

    float arg1 = 0.f;
    int arg2 = 0;
    OverrideMyArgs(arg1, &arg2);
    CO_QUICK_ASSERT(arg1 == 1.f);
    CO_QUICK_ASSERT(arg2 == 2);
    
    ResetAll();
}

void WhenCalledWithExample()
{
    CO_INSTRUCT(OverrideInstanceName, OverrideMyReturnValue).WhenCalledWith(2, 3.f).Returns<int>(1);

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1

    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(ret2 != 1);
    
    ResetAll();
}

void TimesExample()
{
    CO_INSTRUCT(OverrideInstanceName, OverrideMyArgs).SetArgs<float&, int*>(1.f, 2).Times(1);
    
    float testFloat = 2.f;
    int testInt = 3;
    OverrideMyArgs(testFloat, &testInt);    //The argument values are set to 1.f and 2

    CO_QUICK_ASSERT(testFloat == 1.f);
    CO_QUICK_ASSERT(testInt == 2);

    testFloat = 2.f;
    testInt = 3;
    OverrideMyArgs(testFloat, &testInt);    //The argument values are still 2.f and 3
    
    CO_QUICK_ASSERT(testFloat == 2.f);
    CO_QUICK_ASSERT(testInt == 3);
    
    ResetAll();
}

void IfConditionLambdaExample()
{
    CO_INSTRUCT (OverrideInstanceName, OverrideMyReturnValue)
                .If
                (
                    [](void*, const std::vector<void*>& args)
                    {
                        if(*static_cast<int*>(args.at(0)) == 1)
                            return true;
                        else
                            return false;
                    }
                )
                .Returns<int>(1);

    int ret1 = OverrideMyReturnValue(1, 2.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(2, 3.f);   //Won't return 1
    
    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(ret2 != 1);

    ResetAll();
}

void WhenCalledExpectedlyDoLambdaExample()
{
    bool called = false;
    CO_INSTRUCT (OverrideInstanceName, OverrideMyReturnValue)
                .WhenCalledWith(2, 3.f)
                .Returns<int>(1)
                .WhenCalledExpectedly_Do
                (
                    [&called](...)
                    {
                        called = true;
                    }
                );

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1 and sets called to true
    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(called == true);

    ResetAll();
}

void OtherwiseDoLambdaExample()
{
    bool called = false;
    CO_INSTRUCT (OverrideInstanceName, OverrideMyReturnValue)
                .WhenCalledWith(2, 3.f)
                .Returns<int>(1)
                .Otherwise_Do
                (
                    [&called](...)
                    {
                        called = true;
                    }
                );
    
    int ret1 = OverrideMyReturnValue(1, 2.f);   //Won't return 1
    CO_QUICK_ASSERT(ret1 != 1);
    CO_QUICK_ASSERT(called == true);

    ResetAll();
}

void AssignStatusExample()
{
    std::shared_ptr<CppOverride::OverrideResult> result = CppOverride::CreateOverrideResult();
    CO_INSTRUCT (OverrideInstanceName, OverrideMyReturnValue)
                .WhenCalledWith(2, 3.f)
                .Returns<int>(1)
                .AssignsResult(result);
    
    int ret1 = OverrideMyReturnValue(1, 2.f);
    
    //status will be OverrideStatus::MATCHING_CONDITION_VALUE_FAILED
    CO_QUICK_ASSERT(ret1 != 1);
    CO_QUICK_ASSERT(result->GetLastStatus() == 
                    CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);

    ResetAll();
}

int main(int, char**)
{
    OverrideReturnsExample();
    
    OverrideArgumentsExample();
    
    OverrideReturnsWithActionLambda();
    
    OverrideArgumentsWithActionLambda();
    
    WhenCalledWithExample();
    
    IfConditionLambdaExample();
    
    WhenCalledExpectedlyDoLambdaExample();
    
    OtherwiseDoLambdaExample();
    
    AssignStatusExample();
    
    std::cout << "All examples are running correctly" << std::endl;
    
    return 0;
}
