//#include "SimpleOverride.hpp"
#include "SimpleOverride.hpp"

SO_DECLARE_INSTNACE(Overrider);

int ChangeReturnValue(int a, float* b)
{
    //SO_RETURN_IF_FOUND(functionOverrideObj, functionRef, returnType, args...)
    SO_RETURN_IF_FOUND(Overrider, ChangeReturnValue(int, float*), int, a, b);
    
    return 0;
}

void SetArgumentValue(int a, float& b, int* c)
{
    //SO_MODIFY_ARGS_IF_FOUND(overrideObj, functionRef, args...)
    SO_MODIFY_ARGS_IF_FOUND(Overrider, SetArgumentValue(int, float&, int*), a, b, c);
    
    //You can also use SO_ARGUMENTS_AND_RETURN_IF_FOUND to return a specify value
    //  When the condition is met
}

int main()
{
    //Example of overriding return value
    //Pointers are automatically dereferenced when getting compared.
    //      Unless it is cast to void*, then it won't be dereferenced.
    SO_OVERRIDE_RETURNS (Overrider, ChangeReturnValue(int, float*))  
                        .Returns(1)
                        .WhenCalledWith(2, 3.f)
                        .Times(2);

    float testFloat = 3.f;
    assert(ChangeReturnValue(2, &testFloat) == 1 && ChangeReturnValue(2, &testFloat) == 1);
    assert(ChangeReturnValue(4, &testFloat) != 1);
    
    
    //Example of overriding argument value
    SO_OVERRIDE_ARGS(Overrider, SetArgumentValue(int, float&, int*))
                    .SetArgs(SO_DONT_SET, 2.f, 3)
                    .WhenCalledWith(4, SO_ANY, SO_ANY);

    int testInt = 5;
    SetArgumentValue(4, testFloat, &testInt);
    assert(testFloat == 2.f && testInt == 3);
    
    std::cout << "Success\n";
    
    //------------------------------------------------
    //Extra:
    //------------------------------------------------
    
    //ReturnsByAction and SetArgByAction can also be used to return or set arguments by lambda
    
    //SO_DECLARE_INSTNACE(OverrideObjName) macro can be used inside a class declaration to 
    //  declare an instance of overriding object

    //SO_DECLARE_OVERRIDE_METHODS(OverrideObjName) macro can be used inside a class declaration 
    //  to declare proxy methods inline implementations to the override object
    
    //SO_NonCopyable and SO_NonComparable can be used for objects that are not copyable or comparable.
    //  These objects won't be compared against in WhenCalledWith.
    
    //You also have access to "If" clause for additonal conditions
    
    //Similarly, you have "WhenCalledExpectedly_Do" and "Otherwise_Do" clauses for performing custom actions
    //  when the condition is matched or not respectively
    
    //For usage on these extra actions, see Tests/SimpleOverrideTests.cpp
    
    return 0;
}