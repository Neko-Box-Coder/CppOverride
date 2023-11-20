#include "CppOverride.hpp"

CO_DECLARE_INSTNACE(OverrideInstanceName);

int OverrideMyReturnValue(int value1, float value2)
{
    CO_RETURN_IF_FOUND( OverrideInstanceName, 
                        OverrideMyReturnValue(int, float), 
                        int,
                        value1, 
                        value2);
    
    //The rest of the implementations...
    
    return 0;
}

int SomeRef = 0;

int& OverrideMyReturnRef(int value1, float value2)
{
    CO_RETURN_REF_IF_FOUND( OverrideInstanceName, 
                            OverrideMyReturnRef(int, float), 
                            int,
                            value1, 
                            value2);
    
    //The rest of the implementations...
    
    return SomeRef;
}

void OverrideMyArgs(float& value1, int* value2)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideInstanceName, 
                            OverrideMyArgs(float&, int*), 
                            value1, 
                            value2);
}

bool OverrideMyArgsWithStstus(float& value1, int* value2)
{
    //Returns true if there's an override for setting arguments
    CO_MODIFY_ARGS_AND_RETURN_IF_FOUND(OverrideInstanceName, 
                                       true,
                                       OverrideMyArgs(float&, int*), 
                                       value1, 
                                       value2);

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
    CO_CLEAR_ALL_OVERRIDE_RETURNS(OverrideInstanceName);
    CO_CLEAR_ALL_OVERRIDE_ARGS(OverrideInstanceName);
}

void OverrideReturnsExample()
{
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .Returns(1);

    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 1);

    int returnRef = 1;
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnRef(int, float))
                        .ReturnsReference(returnRef);

    CO_QUICK_ASSERT(&returnRef == &OverrideMyReturnRef(0, 0.f));
    
    ResetAll();
}

void OverrideArgumentsExample()
{
    CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                    .SetArgs(1.f, 3);

    float arg1 = 0.f;
    int arg2 = 0;
    OverrideMyArgs(arg1, &arg2);
    CO_QUICK_ASSERT(arg1 == 1.f);
    CO_QUICK_ASSERT(arg2 == 3);
    
    ResetAll();
}

void OverrideReturnsWithActionLambda()
{
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .ReturnsByAction<int>
                        ( 
                            [](const std::vector<void*>& args, void* out)
                            { 
                                *static_cast<int*>(out) = 5;
                            }
                        );
    
    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 5);

    ResetAll();
}

void OverrideArgumentsWithActionLambda()
{
    CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                    .SetArgsByAction<float&, int*>
                    (
                        [](std::vector<void*>& args)
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
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .WhenCalledWith(2, 3.f)
                        .Returns(1);

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1

    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(ret2 != 1);
    
    ResetAll();
}

void TimesExample()
{
    CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                    .SetArgs(1.f, 2)
                    .Times(1);
    
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
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .If
                        (
                            [](const std::vector<void*>& args)
                            {
                                if(*static_cast<int*>(args.at(0)) == 1)
                                    return true;
                                else
                                    return false;
                            }
                        )
                        .Returns(1);

    int ret1 = OverrideMyReturnValue(1, 2.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(2, 3.f);   //Won't return 1
    
    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(ret2 != 1);

    ResetAll();
}

void WhenCalledExpectedlyDoLambdaExample()
{
    bool called = false;
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .WhenCalledWith(2, 3.f)
                        .Returns(1)
                        .WhenCalledExpectedly_Do
                        (
                            [&called](const std::vector<void*>& args)
                            {
                                called = true;
                            }
                        );

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1 and sets called to true
    CO_QUICK_ASSERT(called == true);

    ResetAll();
}

void OtherwiseDoLambdaExample()
{
    bool called = false;
    CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                        .WhenCalledWith(2, 3.f)
                        .Returns(1)
                        .Otherwise_Do
                        (
                            [&called](const std::vector<void*>& args)
                            {
                                called = true;
                            }
                        );
    
    int ret1 = OverrideMyReturnValue(1, 2.f);   //Won't return 1
    CO_QUICK_ASSERT(called == true);

    ResetAll();
}

int main(int argc, char** argv)
{
    OverrideReturnsExample();
    
    OverrideArgumentsExample();
    
    OverrideReturnsWithActionLambda();
    
    OverrideArgumentsWithActionLambda();
    
    WhenCalledWithExample();
    
    IfConditionLambdaExample();
    
    WhenCalledExpectedlyDoLambdaExample();
    
    OtherwiseDoLambdaExample();
    
    std::cout << "All examples are running correctly" << std::endl;
    
    return 0;
}