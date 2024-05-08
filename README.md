# Cpp Override

![](./Logo.png)

A C++ 11 Compatible Framework that allows you to override function behaviors. 

Similar to mocking but with greater flexibility.

- Override any classes you want, including **non virtual classes**
- Override any functions you want, including **free functions**
- Doesn't break **C++ Standard**, no need to exploit vtable
- Easy to setup and use

Of course, you can still create mock classes if you want.

---

<!-- Links to all the headings -->
## Table of Contents
- [Installation](#installation)
- [Quick Start](#quick-start)
    - [Override Free Function](#override-free-function)
    - [Override Class Function](#override-class-function)
- [Documentation](#documentation)
    - [Declare Override Instance](#declare-override-instance)
        - [Global / File Scope](#global--file-scope)
        - [Class Member Variable](#class-member-variable)
    - [Implement Override Action](#implement-override-action)
    - [Disable Overrides](#disable-overrides)
    - [Setup Override Actions](#setup-override-actions)
        - [Override Returns](#override-returns)
        - [Override Arguments Values](#override-arguments-values)
        - [Override Returns And Arguments With Function / Lambda](#override-returns-and-arguments-with-function--lambda)
            - [Override Returns](#override-returns)
            - [Override Arguments](#override-arguments)
    - [Override Rules And Actions](#override-rules-and-actions)
        - [When Called With](#when-called-with)
        - [Times](#times)
        - [If Condition Function / Lambda](#if-condition-function--lambda)
        - [When Called Expectedly Do Function / Lambda](#when-called-expectedly-do-function--lambda)
        - [Otherwise Do Function / Lambda](#otherwise-do-function--lambda)
        - [Get Override Result](#get-override-result)

---

## Installation

- Header Only
    - Just include `CppOverride.hpp` in `Include_SingleHeader` or `Include_MultiHeader`
- CMake
    - `AddSubDirectory(CppOverride)`
    - `TargetLinkLibrary(YourTarget CppOverride)`

---

## Quick Start

### Override Free Function
```cpp
#include <iostream>

//Define CO_NO_OVERRIDE to disable overriding
//#define CO_NO_OVERRIDE
#include "CppOverride.hpp"

CO_DECLARE_INSTANCE(OverrideInstance);

int DummyFunction(int value1)
{
    CO_OVERRIDE_IMPL(OverrideInstance, int, value1);
    
    return value1;
}

int main()
{
    CO_SETUP_OVERRIDE(OverrideInstanceName, DummyFunction)
                     .WhenCalledWith(5)
                     .Time(1)
                     .Returns<int>(1);
    
    //DummyFunction(0): 0
    std::cout << "DummyFunction(0): " << DummyFunction(0) << std::endl;
    
    //DummyFunction(5): 1
    std::cout << "DummyFunction(5): " << DummyFunction(5) << std::endl;
    
    //DummyFunction(5): 5
    std::cout << "DummyFunction(5): " << DummyFunction(5) << std::endl;
    
    return 0;
}
```

### Override Class Function
```cpp
#include <iostream>

//Define CO_NO_OVERRIDE to disable overriding
//#define CO_NO_OVERRIDE
#include "CppOverride.hpp"

class DummyClass
{
    private:
        CO_DECLARE_MEMBER_INSTANCE(OverrideInstance);
        
    public:
        CO_DECLARE_OVERRIDE_METHODS(OverrideInstance);
        
        int DummyMemberFunction(int value1)
        {
            CO_OVERRIDE_IMPL(OverrideInstance, int, value1);
            
            return value1;
        }
};

int main()
{
    DummyClass dummyObject;
    
    CO_SETUP_OVERRIDE(dummyObject, DummyMemberFunction)
                     .WhenCalledWith(5)
                     .Time(1)
                     .Returns<int>(1);
    
    //dummyObject.DummyMemberFunction(0): 0
    std::cout << "dummyObject.DummyMemberFunction(0): " << dummyObject.DummyMemberFunction(0) << std::endl;
    
    //dummyObject.DummyMemberFunction(5): 1
    std::cout << "dummyObject.DummyMemberFunction(5): " << dummyObject.DummyMemberFunction(5) << std::endl;
    
    //dummyObject.DummyMemberFunction(5): 5
    std::cout << "dummyObject.DummyMemberFunction(5): " << dummyObject.DummyMemberFunction(5) << std::endl;
    
    return 0;
}
```


---

## Documentation

### Declare Override Instance

In order to override anything, we will first need an override instance to store all the override 
information that the function can reference from. 

#### Global / File Scope
```cpp
CO_DECLARE_INSTANCE(<Override Instance Name>);
```
#### Class Member Variable
```cpp
class YourClass
{
    private:
        CO_DECLARE_MEMBER_INSTANCE(<Override Instance Name>);
        
        //Other variables for your class...
    
    public:
        CO_DECLARE_OVERRIDE_METHODS(<Override Instance Name>);
        
        //Other methods for your class...
};
```

---

### Implement Override Action
In order to override a function, we will need to hijack the function using override implementations macros

```cpp
CO_OVERRIDE_IMPL(<Override Instance Name>, <Return Type>, (<Arguments>))
```

Example:
```cpp
int OverrideMyReturnValue(int value1, float value2)
{
    CO_OVERRIDE_IMPL(OverrideInstanceName, int, (value1, value2))
    
    //The rest of the implementations...
    
    return 0;
}

void OverrideMyArgs(float& value1, int* value2)
{
    CO_OVERRIDE_IMPL(OverrideInstanceName, void, (value1, value2))
    
    //The rest of the implementations...
}

```

---

### Disable Overrides

```cpp
//Just define CO_NO_OVERRIDE before including "CppOverride.hpp" or in compile definitions
//So like this:
#define CO_NO_OVERRIDE
#include "CppOverride.hpp"
```

---

### Setup Override Actions
Now we have the override implementations in place, 
we will just need to interact with the override instance to control the override functions when called.

To start setting up the override actions, call `CO_SETUP_OVERRIDE` macro
```cpp
CO_SETUP_OVERRIDE(<Override Instance Name>, <Function Name>);
```

This can be chained with different actions like this

```cpp
CO_SETUP_OVERRIDE(<Override Instance Name>, <Function Name>)
                 .WhenCalledWith(<Values...>)
                 .Returns(<Return Value>);
                 //etc...
```

Anything beyond this point are assuming that you have called `CO_SETUP_OVERRIDE` macro.

---

### Override Returns

You must specify the return type with template to avoid any ambiguity as we match the return type 
with the function signature

```cpp
//CO_SETUP_OVERRIDE...
.Returns<[Return Type]>(<Return Value>);
```

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
                 .Returns<int>(1);
```

---

### Override Arguments Values
```cpp
//CO_SETUP_OVERRIDE...
.SetArgs<[Override Function Arg Types...]>(<Args Values...>);
```

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
                 .SetArgs<float&, int*>(1.f, 3);
```

The types of the argument specified with template must match the function argument types exactly.

You can also use `CO_ANY_TYPE` and `CO_DONT_SET` to not set some of the arguments.

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
                 .SetArgs<CO_ANY_TYPE, int*>(CO_DONT_SET, 3);
```

In this case, the first argument is not touched, while the second argument is set to 3.

> It is **common to pair** `.SetArgs` with `.Returns` so that the execution doesn't continue when
we finish overriding the arguments.

> Given we have this
> ```cpp
> void OverrideMyArgs(float& value1, int* value2)
> {
>     CO_OVERRIDE_IMPL(OverrideInstanceName, void, (value1, value2))
>     std::cout << "Rest of the OverrideMyArgs execution..." << std::endl;
> }
> ```
> So something like this:
> ```cpp
>  CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
>                   .SetArgs<float&, int*>(1.f, 3);
> ```
> Will output: "Rest of the OverrideMyArgs execution..."
> 
> But something like this won't:
> ```cpp
>  CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
>                   .SetArgs<float&, int*>(1.f, 3);
>                   .Returns<void>();
>                   //Or .ReturnsVoid();
>                   //Or a normal .Returns<...>(...);
> ```

---

### Override Returns And Arguments With Function / Lambda

When an override action requires external context or some logic to decide how to override,
you can use `ReturnsByAction` and `SetArgsByAction`.

#### Override Returns

```cpp
//CO_SETUP_OVERRIDE...
.ReturnsByAction<[Return Type]>(<void(const std::vector<void*>& args, void* out) Function>);
```

When the function is called, the `args` vector will contain the pointer to the arguments. You must
cast them to their original type pointers to get the values inside.

The return value should be set by modifying the `out` pointer (Pointer to the return value).

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
                 .ReturnsByAction<int>
                 ( 
                     [](const std::vector<void*>& args, void* out)
                     { 
                         if(*static_cast<int*>(args[0]) == 5)
                             *static_cast<int*>(out) = 1;
                         else
                             *static_cast<int*>(out) = 0;
                     }
                 );
```

#### Override Arguments

```cpp
//CO_SETUP_OVERRIDE...
.SetArgsByAction<[Override Function Arg Types...]>(<void(std::vector<void*>& args) Function>);
```

This the same as the `ReturnsByAction`, but without the need of modifying any return value.
Again, you must cast the arguments pointers to their original type pointers to get the values inside.

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
                 .SetArgsByAction<float&, int*>
                 (
                     [](std::vector<void*>& args)
                     {
                         //Pointer to float& is just float*
                         *static_cast<float*>(args.at(0)) = 1.f;
                         
                         //Pointer to int* is int**
                         **static_cast<int**>(args.at(1)) = 2;
                     }
                 );
```

Similar to `.SetArgs<...>(...)`, you can use `CO_ANY_TYPE` to match any type or to indicate 
that it won't be set.

---

## Override Rules And Actions

Just like any mocking library, you can also control when and how the override functions will behave,
as well as registering callbacks when the override is successful or not.

---

### When Called With

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
                 .WhenCalledWith(2, 3.f)
                 .Returns<int>(1);

int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1
```

---

### Times

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyArgs)
                 .SetArgs<float&, int*>(1.f, 2)
                 .Times(1)
                 .Returns<void>();

float testFloat = 2.f;
int testInt = 3;
OverrideMyArgs(testFloat, &testInt);    //The argument values are set to 1.f and 2

testFloat = 2.f;
testInt = 3;
OverrideMyArgs(testFloat, &testInt);    //The argument values are still 2.f and 3
```

---

### If Condition Function / Lambda

Example:
```cpp
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
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
                 .Returns<int>(1);

int ret1 = OverrideMyReturnValue(1, 2.f);   //Returns 1
int ret2 = OverrideMyReturnValue(2, 3.f);   //Won't return 1
```

---

### When Called Expectedly Do Function / Lambda

Example:
```cpp
bool called = false;
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
                 .WhenCalledWith(2, 3.f)
                 .Returns<int>(1)
                 .WhenCalledExpectedly_Do
                 (
                     [&called](const std::vector<void*>& args)
                     {
                         called = true;
                         //...
                     }
                 );

int ret1 = OverrideMyReturnValue(1, 2.f);   //called is still false
int ret2 = OverrideMyReturnValue(2, 3.f);   //called is true now
```

> If you just want to see if the function is called without overriding anything, you can use
> `CO_ANY` and `CO_DONT_OVERRIDE_RETURN` to not return anything. So something like:
> ```cpp
> //CO_SETUP_OVERRIDE...
> .Returns<CO_ANY>(CO_DONT_OVERRIDE_RETURN)
> .WhenCalledExpectedly_Do
> (
>     //...
> )
> ```

---

### Otherwise Do Function / Lambda

Example:
```cpp
bool called = false;
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue(int, float))
                 .WhenCalledWith(2, 3.f)
                 .Returns<int>(1)
                 .Otherwise_Do
                 (
                     [&called](const std::vector<void*>& args)
                     {
                         called = true;
                     }
                 );

int ret2 = OverrideMyReturnValue(2, 3.f);   //called is still false
int ret1 = OverrideMyReturnValue(1, 2.f);   //called is true now
```

---

### Get Override Result

Example:
```cpp
CppOverride::OverrideResult result;
CO_SETUP_OVERRIDE(OverrideInstanceName, OverrideMyReturnValue)
                 .WhenCalledWith(2, 3.f)
                 .Returns<int>(1)
                 .AssignOverrideResult(result);

int ret1 = OverrideMyReturnValue(1, 2.f);
//result.Status will be OverrideStatus::MATCHING_CONDITION_VALUE_FAILED

ret1 = OverrideMyReturnValue(2, 3.f);
//result.Status will be OverrideStatus::OVERRIDE_SUCCESS

//For all the override status, see `enum class OverrideStatus`
```



---