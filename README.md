## Cpp Override

![](./Logo.png)

A Framework that allows you to override function behaviours

- Which allows you to mock classes without:
    - Virtual Classes
    - Crowding your project with Mock Classes
    - Breaking C++ Standard

You can also just alter the behaviour of a function you want.

This is like mocking but more flexible.

Of course, you still have the flexibility to create mock classes

---

<!-- Links to all the headings -->
### Table of Contents
- [Installation](#installation)
- [Quick Start](#quick-start)
- [Usage](#usage)
    - [Declare Override Instance](#declare-override-instance)
        - [Global / File Scope](#global-file-scope)
        - [Class Member Variable](#class-member-variable)
    - [Add Override Implementations](#add-override-implementations)
        - [Add Override Return Value](#add-override-return-value)
        - [Add Override Argument Values](#add-override-argument-values)
    - [Disable Overrides](#disable-overrides)
    - [Control Override Functions](#control-override-functions)
        - [Override Returns](#override-returns)
        - [Override Arguments Values](#override-arguments-values)
        - [Override Returns With Action Lambda](#override-returns-with-action-lambda)
        - [Override Arguments With Action Lambda](#override-arguments-with-action-lambda)
    - [Override Rules](#override-rules)
        - [When Called With](#when-called-with)
        - [Times](#times)
        - [If Condition Lambda](#if-condition-lambda)
        - [When Called Expectedly Do Lambda](#when-called-expectedly-do-lambda)
        - [Otherwise Do Lambda](#otherwise-do-lambda)

---

### Installation

- Header Only
    - Just include `CppOverride.hpp` in `Include_SingleHeader` or `Include_MultiHeader`
- CMake
    - `AddSubDirectory(CppOverride)`
    - `TargetLinkLibrary(YourTarget CppOverride)`

- C++ 11 Compatible

---

### Quick Start

```cpp
int DummyFunction(int value1)
{
    CO_RETURN_IF_FOUND( OverrideInstanceName, 
                        DummyFunction(int), 
                        int,
                        value1);
    
    return value1;
}

int main()
{
    CO_OVERRIDE_RETURNS (OverrideInstanceName, DummyFunction(int))
                        .WhenCalledWith(5)
                        .Time(1)
                        .Returns(1);
    
    //DummyFunction(0): 0
    std::cout << "DummyFunction(0): " << DummyFunction(0) << std::endl;
    
    //DummyFunction(5): 1
    std::cout << "DummyFunction(5): " << DummyFunction(5) << std::endl;
    
    //DummyFunction(5): 5
    std::cout << "DummyFunction(5): " << DummyFunction(5) << std::endl;
    
    return 0;
}
```

---

### Usage

### Declare Override Instance
#### Global / File Scope
```cpp
CO_DECLARE_INSTNACE(OverrideInstanceName);
```
#### Class Member Variable
```cpp
class YourClass
{
    private:
        CO_DECLARE_MEMBER_INSTNACE(OverrideInstanceName);
        
        //Other variables for your class...
    
    public:
        CO_DECLARE_OVERRIDE_METHODS(OverrideInstanceName);
        
        //Other methods for your class...
};
```

---

### Add Override Implementations
#### Add Override Return Value
```cpp
CO_RETURN_IF_FOUND( <Override Instance Name>, 
                    <Function Name>(<Args Types...>), 
                    <Return Type>,
                    <Args Names...>);
//or
CO_RETURN_REF_IF_FOUND( <Override Instance Name>)
                        <Function Name>(<Args Types...>), 
                        <Return Type>,
                        <Args Names...>);
```

Example:
```cpp
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
```
or
```cpp
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
```

#### Add Override Argument Values
```cpp
CO_MODIFY_ARGS_IF_FOUND(<Override Instance Name>, 
                        <Function Name>(<Args Types...>), 
                        <Args Names...>);
//or
CO_MODIFY_ARGS_AND_RETURN_IF_FOUND( <Override Instance Name>, 
                                    <Return Value>,
                                    <Function Name>(<Args Types...>), 
                                    <Args Names...>);
```

Examples:
```cpp
void OverrideMyArgs(float& value1, int* value2)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideInstanceName, 
                            OverrideMyArgs(float&, int*), 
                            value1, 
                            value2);
}
```
or
```cpp
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
```

### Disable Overrides
```cpp
//Just define CO_NO_OVERRIDE before including "CppOverride.hpp" or in compile definitions
#define CO_NO_OVERRIDE
```

---

### Control Override Functions

#### Override Returns
```cpp
CO_OVERRIDE_RETURNS (<Override Instance Name>, <Function Name>(<Args Types...>))
                    .Returns(<Return Value>);
//or
CO_OVERRIDE_RETURNS (<Override Instance Name>, <Function Name>(<Args Types...>))
                    .ReturnsReference(<Return Reference>);
```
Example:
```cpp
CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                    .Returns(1);
//or
int returnRef = 1;
CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnRef(int, float))
                    .ReturnsReference(returnRef);
```
#### Override Arguments Values
```cpp
CO_OVERRIDE_ARGS(<Override Instance Name>, <Function Name>(<Args Types...>))
                .SetArgs(<Args Values...>);
```
Example:
```cpp
CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                .SetArgs(1.f, 3);
```

> When Overriding types that can promote/demote, match the type **exactly**

> For example, `std::string("test")` instead of `"test"` for a function that accepts string

> Similarly, `2.f` instaed of `2.0` for a function that accepts float

#### Override Returns With Action Lambda
```cpp
CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                    .ReturnsByAction<int>
                    ( 
                        [](const std::vector<void*>& args, void* out)
                        { 
                            *static_cast<int*>(out) = 5;
                        }
                    );
```

#### Override Arguments With Action Lambda
```cpp
CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                .SetArgsByAction<float&, int*>
                (
                    [](std::vector<void*>& args)
                    {
                        *static_cast<float*>(args.at(0)) = 1.f;
                        **static_cast<int**>(args.at(1)) = 2;
                    }
                );
```

---

### Override Rules
#### When Called With
```cpp
CO_OVERRIDE_RETURNS (OverrideInstanceName, OverrideMyReturnValue(int, float))
                    .WhenCalledWith(2, 3.f)
                    .Returns(1);

int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1
```

#### Times
```cpp
CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                .SetArgs(1.f, 2)
                .Times(1);

float testFloat = 2.f;
int testInt = 3;
OverrideMyArgs(testFloat, &testInt);    //The argument values are set to 1.f and 2

testFloat = 2.f;
testInt = 3;
OverrideMyArgs(testFloat, &testInt);    //The argument values are still 2.f and 3
```

#### If Condition Lambda
```cpp
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
```

#### When Called Expectedly Do Lambda
```cpp
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
```

#### Otherwise Do Lambda
```cpp
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
```




---