#include "CppOverride.hpp"

#include <iostream>
#include <vector>
#include <string>

CO_DECLARE_INSTANCE(OverrideInstanceName);

namespace MyNameSpace
{
    int OverrideMyScopedFunc(int value1, float& value2)
    {
        CO_INSERT_IMPL(OverrideInstanceName, int, (value1, value2));
        //The rest of the implementations...
        return 0;
    }
}

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
    CO_INSTRUCT_REF(OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue).Returns<int>(1);

    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 1);

    int returnRef = 1;
    CO_INSTRUCT_REF(OverrideInstanceName, CO_GLOBAL, OverrideMyReturnRef).Returns<int&>(returnRef);

    CO_QUICK_ASSERT(&returnRef == &OverrideMyReturnRef(0, 0.f));
    
    ResetAll();
}

void OverrideArgumentsExample()
{
    CO_INSTRUCT_REF(OverrideInstanceName, CO_GLOBAL, OverrideMyArgs).SetArgs<float&, int*>(1.f, 3);

    float arg1 = 0.f;
    int arg2 = 0;
    OverrideMyArgs(arg1, &arg2);
    CO_QUICK_ASSERT(arg1 == 1.f);
    CO_QUICK_ASSERT(arg2 == 3);
    
    ResetAll();
}

void OverrideScopedFunctionExample()
{
    CO_INSTRUCT_REF(OverrideInstanceName, MyNameSpace, OverrideMyScopedFunc).Returns<int>(1);

    float floatArg = 0.f;
    CO_QUICK_ASSERT(MyNameSpace::OverrideMyScopedFunc(1, floatArg) == 1);
    
    CO_REMOVE_INSTRUCT_REF(OverrideInstanceName, MyNameSpace, OverrideMyScopedFunc);
    
    CO_INSTRUCT_REF (OverrideInstanceName, MyNameSpace, OverrideMyScopedFunc)
                    .SetArgs<CO_ANY_TYPE, float&>(CO_DONT_SET, 3);

    MyNameSpace::OverrideMyScopedFunc(1, floatArg);
    CO_QUICK_ASSERT(floatArg == 3);
}

void OverrideReturnsWithActionLambda()
{
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .ReturnsByAction<int>
                    ( 
                        []( void*, 
                            const std::vector<CppOverride::TypedDataInfo>& args, 
                            const CppOverride::TypedInfo& returnInfo) -> CppOverride::TypedDataInfo
                        { 
                            (void)args;
                            //Can access args with type safety if needed
                            //e.g., if(args.at(0).IsType<int>()) { ... }
                            
                            //When returning a value, you should use CreateValue<int>(int value)
                            if(returnInfo.IsType<int>())
                                return CppOverride::TypedDataInfo().CreateValue<int>(5);
                            
                            //When returning a reference, 
                            //you should use CreateReference<int&>(int* valuePtr)
                            
                            return CppOverride::TypedDataInfo();
                        }
                    );
    
    CO_QUICK_ASSERT(OverrideMyReturnValue(0, 0.f) == 5);

    ResetAll();
}

void OverrideArgumentsWithActionLambda()
{
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyArgs)
                    .SetArgsByAction<float&, int*>
                    (
                        [](void*, std::vector<CppOverride::TypedDataInfo>& args)
                        {
                            if(args.at(0).IsType<float>())
                                *args.at(0).GetTypedDataPtr<float>() = 1.f;
                            if(args.at(1).IsType<int*>())
                                **args.at(1).GetTypedDataPtr<int*>() = 2;
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
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .WhenCalledWith(2, 3.f)
                    .Returns<int>(1);

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1

    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(ret2 != 1);
    
    ResetAll();
}

void TimesExample()
{
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyArgs)
                    .SetArgs<float&, int*>(1.f, 2)
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
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .If
                    (
                        [](void*, const std::vector<CppOverride::TypedDataInfo>& args)
                        {
                            if(args.at(0).IsType<int>() && *args.at(0).GetTypedDataPtr<int>() == 1)
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
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .WhenCalledWith(2, 3.f)
                    .Returns<int>(1)
                    .WhenCalledExpectedly_Do
                    (
                        [&called](  void* instance, 
                                    const std::vector<CppOverride::TypedDataInfo>& args)
                        {
                            (void)instance;
                            (void)args;
                            //Can access args with type safety if needed
                            //e.g., if(args.at(0).IsType<int>()) { ... }
                            
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
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .WhenCalledWith(2, 3.f)
                    .Returns<int>(1)
                    .Otherwise_Do
                    (
                        [&called](  void* instance, 
                                    const std::vector<CppOverride::TypedDataInfo>& args)
                        {
                            (void)instance;
                            (void)args;
                            //Can access args with type safety if needed
                            //e.g., if(args.at(0).IsType<int>()) { ... }
                            
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
    CppOverride::ResultPtr result;
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
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

void ExpectedExample()
{
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .WhenCalledWith(2, 3.f)
                    .Times(1)
                    .Returns<int>(1)
                    .Expected();
    
    CO_INSTRUCT_REF (OverrideInstanceName, CO_GLOBAL, OverrideMyReturnValue)
                    .WhenCalledWith(3, 4.f)
                    .Returns<int>(1)
                    .ExpectedNotSatisfied();
    
    std::vector<CppOverride::FunctionName> failedFunctions;
    
    //Not triggering any instructed overrides when we expected to do so, 
    //therefore failed expectations.
    int ret1 = OverrideMyReturnValue(1, 2.f);
    failedFunctions = CO_GET_FAILED_FUNCTIONS(OverrideInstanceName);
    CO_QUICK_ASSERT(ret1 != 1);
    CO_QUICK_ASSERT(failedFunctions.size() == 1);
    
    //Triggered the first instructed override, filled all expectations.
    ret1 = OverrideMyReturnValue(2, 3.f);
    failedFunctions = CO_GET_FAILED_FUNCTIONS(OverrideInstanceName);
    CO_QUICK_ASSERT(ret1 == 1);
    CO_QUICK_ASSERT(failedFunctions.empty());
    
    //Triggered the second instructed override when we expect to not be triggered, 
    //therefore failing expectation
    OverrideMyReturnValue(3, 4.f);
    failedFunctions = CO_GET_FAILED_FUNCTIONS(OverrideInstanceName);
    CO_QUICK_ASSERT(failedFunctions.size() == 1);

    ResetAll();
}

int main(int, char**)
{
    OverrideReturnsExample();
    
    OverrideArgumentsExample();
    
    OverrideScopedFunctionExample();
    
    OverrideReturnsWithActionLambda();
    
    OverrideArgumentsWithActionLambda();
    
    WhenCalledWithExample();
    
    IfConditionLambdaExample();
    
    WhenCalledExpectedlyDoLambdaExample();
    
    OtherwiseDoLambdaExample();
    
    AssignStatusExample();
    
    ExpectedExample();
    
    std::cout << "All examples are running correctly" << std::endl;
    
    return 0;
}
