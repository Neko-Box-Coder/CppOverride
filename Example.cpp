//#include "CppOverride.hpp"
#if 0
#include "CppOverride.hpp"

CO_DECLARE_INSTNACE(Overrider);

int ChangeReturnValue(int a, float* b)
{
    //CO_RETURN_IF_FOUND(functionOverrideObj, functionRef, returnType, args...)
    CO_RETURN_IF_FOUND(Overrider, ChangeReturnValue(int, float*), int, a, b);
    
    return 0;
}

void SetArgumentValue(int a, float& b, int* c)
{
    //CO_MODIFY_ARGS_IF_FOUND(overrideObj, functionRef, args...)
    CO_MODIFY_ARGS_IF_FOUND(Overrider, SetArgumentValue(int, float&, int*), a, b, c);
    
    //You can also use CO_ARGUMENTS_AND_RETURN_IF_FOUND to return a specify value
    //  When the condition is met
}

int main()
{
    //Example of overriding return value
    //Pointers are automatically dereferenced when getting compared.
    //      Unless it is cast to void*, then it won't be dereferenced.
    CO_OVERRIDE_RETURNS (Overrider, ChangeReturnValue(int, float*))  
                        .Returns(1)
                        .WhenCalledWith(2, 3.f)
                        .Times(2);

    float testFloat = 3.f;
    assert(ChangeReturnValue(2, &testFloat) == 1 && ChangeReturnValue(2, &testFloat) == 1);
    assert(ChangeReturnValue(4, &testFloat) != 1);
    
    
    //Example of overriding argument value
    CO_OVERRIDE_ARGS(Overrider, SetArgumentValue(int, float&, int*))
                    .SetArgs(CO_DONT_SET, 2.f, 3)
                    .WhenCalledWith(4, CO_ANY, CO_ANY);

    int testInt = 5;
    SetArgumentValue(4, testFloat, &testInt);
    assert(testFloat == 2.f && testInt == 3);
    
    std::cout << "Success\n";
    
    //------------------------------------------------
    //Extra:
    //------------------------------------------------
    
    //ReturnsByAction and SetArgByAction can also be used to return or set arguments by lambda
    
    //CO_DECLARE_INSTNACE(OverrideObjName) macro can be used inside a class declaration to 
    //  declare an instance of overriding object

    //CO_DECLARE_OVERRIDE_METHODS(OverrideObjName) macro can be used inside a class declaration 
    //  to declare proxy methods inline implementations to the override object
    
    //CO_NonCopyable and CO_NonComparable can be used for objects that are not copyable or comparable.
    //  These objects won't be compared against in WhenCalledWith.
    
    //You also have access to "If" clause for additonal conditions
    
    //Similarly, you have "WhenCalledExpectedly_Do" and "Otherwise_Do" clauses for performing custom actions
    //  when the condition is matched or not respectively
    
    //For usage on these extra actions, see Tests/SimpleOverrideTests.cpp
    
    return 0;
}
#endif