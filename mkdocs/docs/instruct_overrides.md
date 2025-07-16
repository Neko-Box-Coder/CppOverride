# 3. **Instruct** Overrides

After inserting the override implementations, you can **instruct** the override instance to control 
what the override functions do when called.

## Instructing Referenceable Function

```cpp
CO_INSTRUCT_REF(overrideInstance, scope, functionName)
               .Action1(...)
               .Action2(...);
```

`CO_GLOBAL` can be used as `scope` when you are trying to instruct global function.

All the actions are defined in `OverrideInfoSetter` for normal overrides and 
`OverridePassthroughInfoSetter` for passthrough. The detail for each action is covered later in this 
documentation.

???+ example
    ```cpp
    //int FreeFunction(int value1, float value2)
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
                   .Returns<int>(42);
    
    //template<typename T>
    //int FreeTemplateFunction(T value1)
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeTemplateFunction<int>)
                   .Returns<int>(42);
    
    //int MyClass::MemberFunction(int value1, float value2);
    CO_INSTRUCT_REF(MyOverrideInstance, MyClass, MemberFunction)
                   .Returns<int>(42);
    
    //template<typename T>
    //int MyTemplateClass<T>::AnotherMemberFunction(int value1, float value2);
    CO_INSTRUCT_REF(MyOverrideInstance, MyTemplateClass<int>, AnotherMemberFunction)
                   .Returns<int>(42);
    ```

!!!important
    Here are the things we look at when selecting which override instruction to use:
    
    - Function name (`__func__`)
    - Argument Types
    - Return Types
    - Additional action requirement such as `If`, `WhenCalledWith`, etc.

!!!important
    The `scope` is only used for referencing the function so that it verify if the function exists
    or not, as well as allowing renaming for LSP. It is **NOT** used for filtering override 
    functions.

</br>

## Instructing Non Referenceable Function

There is a limitation to this where some type of functions cannot be reference with `CO_INSTRUCT_REF`.
In this case, you will need to use `CO_INSTRUCT_NO_REF` variant.

```cpp
CO_INSTRUCT_NO_REF(overrideInstance, functionName)
                  .Action1(...)
                  .Action2(...);
```

You should use this macro variant for:

- Unreferencable function, such as ones in anonymous namespace or not included in the file which 
performs `CO_INSTRUCT`
- Overloaded functions
- Constructor, Destructor
- Complexly declared function

If you encountered one that you think it should work with `CO_INSTRUCT_REF`, please let us know.

</br>

## Instructs Evaluation Order

The order of your instructs are evaluated (and consumed) in the order you invoked, i.e. FIFO, 
assuming the conditions of said instructs are satisfied.

For example, if you have

```cpp
//int FreeFunction(int value1, float value2)
CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
               .Times(2)
               .Returns<int>(1);
CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
               .Times(2)
               .Returns<int>(2);
CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
               .Times(2)
               .Returns<int>(3);
```

`FreeFunction` will return `1` 2 times, `2` 2 times and `3` 2 times in this order.

</br>

## Instructing Passthrough

Functions without explicit instructions are called passthrough, and is recorded everytime when it 
happens. Only a limited subset of actions are allowed for passthrough but it works the same as 
the normal `CO_INSTRUCT` macros.

```cpp
CO_INSTRUCT_PASSTHROUGH(overrideInstance)
                       .Action1(...)
                       .Action2(...);
```

</br>

## Removing Instructs

Here are the macros for removing instructs.

```cpp
CO_REMOVE_INSTRUCT_REF(overrideInstance, scope, functionName);
CO_REMOVE_INSTRUCT_NO_REF(overrideInstance, functionName);
CO_REMOVE_INSTRUCT_PASSTHROUGH(overrideInstance);
CO_CLEAR_ALL_INSTRUCTS(overrideInstance);
```

</br>

## Action Chaining

Actions can be chained together in any order:

```cpp
CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
               .WhenCalledWith(42, 3.14f)
               .SetArgs<CO_ANY_TYPE, float&>(CO_DONT_SET, 2.71f)
               .Returns<int>(100)
               .Times(2)
               .Expected();
```

## Actions: Returns

### Returns a specific value (`Returns`):
```cpp
.Returns<ReturnType>(value)
```

!!! important
    All the values are evaluated immediately, if you need to return a dynamic value, use 
    `ReturnsByAction` instead (See below).

</br>

### Returns void (early return) (`ReturnsVoid`):
```cpp
.Returns<void>()
//or
.ReturnsVoid()
```

</br>

### Returns using a function (`ReturnsByAction`):
```cpp
.ReturnsByAction<ReturnType>(std::function<TypedDataInfo(void* instance, 
                                                         const std::vector<TypedDataInfo>& args, 
                                                         cosnt TypedInfo& returnInfo)>)
```

??? info "`TypedDataInfo.hpp`"
    ```cpp
    
    --8<-- "Src/TypedDataInfo.hpp"
    
    ```

??? info "`TypedInfo.hpp`"
    ```cpp
    
    --8<-- "Src/TypedInfo.hpp"
    
    ```

???+ example
    ```cpp
    //Return a specific value
    //int MyFunction()
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .Returns<int>(42);
    
    //Return void early
    //void MyVoidFunction()
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyVoidFunction)
                   .ReturnsVoid();
    
    //Return using lambda
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .ReturnsByAction<int>
                   (
                       [](void* instance, 
                          const std::vector<TypedDataInfo>& args, 
                          const TypedInfo& returnInfo) -> TypedDataInfo
                       {
                           //NOTE: instance can be nullptr if it is a free function
                           if(returnInfo.IsType<int>())
                               return TypeDataInfo().CreateValue<int>(100);
                            
                            return TypeDataInfo();
                       }
                   });

    //Return a reference using lambda
    //int& MyFunction()
    int returnValue = 0;
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .ReturnsByAction<int&>
                   (
                       [&returnValue](void* instance, 
                                      const std::vector<TypedDataInfo>& args, 
                                      const TypedInfo& returnInfo) -> TypedDataInfo
                       {
                           if(returnInfo.IsType<int&>())
                               return TypeDataInfo().CreateReference<int&>(&returnValue);
                            
                            return TypeDataInfo();
                       }
                   });
    ```

</br>

## Actions: Arguments

### Set specific argument values (`SetArgs`):
```cpp
.SetArgs<ArgType1, ArgType2, ...>(value1, value2, ...)
```

!!! important
    `SetArgs()` expects argument values to be passed in instead of a reference, even if the types of 
    the parameter you are trying to override are pointers or references.
    
    For example, if a function accepts `#!cpp int&` or `#!cpp int*` which it can modify, 
    you are expected to pass an integer value like `5` which it will use to set.
    
    All the values are evaluated immediately, if you need to set a dynamic value, use 
    `SetArgsByAction` instead (See below).

</br>

### Set arguments using a function (`SetArgsByAction`):
```cpp
.SetArgsByAction<ArgType1, ArgType2, ...>(std::function<void(void* instance, 
                                                             std::vector<TypedDataInfo>& args)>)
```

`instance` can be `nullptr` if it is a free function.

Use `CO_ANY_TYPE` and `CO_DONT_SET` to skip certain arguments.

???+ example
    ```cpp
    //Set specific values
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .SetArgs<int*, float&>(42, 3.14f);
    
    //Skip first argument, set second
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .SetArgs<CO_ANY_TYPE, float&>(CO_DONT_SET, 3.14f);
    
    //Set using lambda
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .SetArgsByAction<int*, float&>
                   (
                       [](void* instance, std::vector<TypedDataInfo>& args) 
                       {
                           //NOTE: instance can be nullptr if it is a free function
                           (void)instance;
                           
                           if(args[0].IsType<int*>())
                               **args[0].GetTypedDataPtr<int*>() = 42;
                           if(args[1].IsType<float&>())
                               *args[1].GetTypedDataPtr<float&>() = 3.14f;
                       }
                   );
    ```

</br>

## Actions: Conditions

### Match specific argument values (`WhenCalledWith`):
```cpp
.WhenCalledWith(value1, value2, ...)
```

!!! important
    All the values are evaluated immediately, if you need to set a dynamic value, use 
    `If` instead (See below).

</br>

### Custom condition using function (`If`):
```cpp
.If(std::function<bool(void* instance, const std::vector<TypedDataInfo>& args)>)
```

Use `CO_ANY` to match any value for specific arguments.

??? example
    ```cpp
    //Match specific values
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(42, 3.14f)
                   .Returns<int>(100);
    
    //Match any value for second argument
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(42, CO_ANY)
                   .Returns<int>(100);
    
    //Custom condition
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .If
                   (
                       [](void* instance, const std::vector<TypedDataInfo>& args) 
                       {
                           //NOTE: instance can be nullptr if it is a free function
                           (void)instance;
                           
                           return args[0].IsType<int>() && *args[0].GetTypedDataPtr<int>() > 10;
                       }
                   )
                   .Returns<int>(100);
    ```

</br>

## Actions: Controls

### Limit number of times override is triggered (`Times`):
```cpp
.Times(count)
```

</br>

### Match specific object instance (for member functions) (`MatchesObject`):
```cpp
.MatchesObject(&objectInstance)
```

!!! important
    The object pointer is evaluated immediately, if you need to set a dynamic value, use 
    `If` instead (See above).

</br>

### Match any object instance (`MatchesAny`):
```cpp
.MatchesAny()
```

??? example
    ```cpp
    //Trigger only once
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .Times(1)
                   .Returns<int>(42);
    
    //Match specific object
    MyClass obj;
    CO_INSTRUCT_REF(MyOverrideInstance, MyClass, MemberFunction)
                   .MatchesObject(&obj)
                   .Returns<int>(42);
    ```

</br>

## Actions: Callbacks

### Execute code when override is triggered (`WhenCalledExpectedly_Do`):
```cpp
.WhenCalledExpectedly_Do(std::function<void(void* instance, std::vector<TypedDataInfo>& args)>)
```

</br>

### Execute code when override is NOT triggered (`Otherwise_Do`):

An override can fail to trigger due to override conditions not met or having error while overriding.

See [4. **Inspect** Override Expectations](inspect_overrides.md) on getting details regarding the
failure of triggering override.

```cpp
.Otherwise_Do(std::function<void(void* instance, std::vector<TypedDataInfo>& args)>)
```

??? example
    ```cpp
    bool wasCalled = false;
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(42)
                   .Returns<int>(100)
                   .WhenCalledExpectedly_Do
                   (
                       [&wasCalled](void*, std::vector<TypedDataInfo>&) 
                       {
                           wasCalled = true;
                       }
                   )
                   .Otherwise_Do
                   (
                       [](void*, std::vector<TypedDataInfo>&) 
                       {
                           std::cout << "Override condition not met!" << std::endl;
                       }
                   );
    ```

</br>

## Actions: Expectations And Results

### Mark override as expected to satisfy all conditions (`Expected`):
```cpp
.Expected()
```

!!! note
    This means that if there's a `Times(count)` condition, the override will be expected to be 
    triggered exactly `count` times. Otherwise, the override will be expected to be triggered at 
    least once.

!!! important
    If you want to create expectations for multiple instructs that have the conditions evaluate to 
    the same thing (excluding `Times(count)`), you should add the expectation only on the last 
    one but not on every one of them.
    
    For example
    ```cpp
    //int FreeFunction(int value1, float value2)
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
                   .WhenCalledWith<int, CO_ANY_TYPE>(1, CO_ANY)
                   .Times(2)
                   //This expect will fail the moment `FreeFunction` is called the 3rd time or more.
                   //.Expected();
                   .Returns<int>(1);
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, FreeFunction)
                   .WhenCalledWith<int, CO_ANY_TYPE>(1, CO_ANY)
                   .Times(2)
                   .Returns<int>(2)
                   .Expected();
    ```
    
    The last expectation will be successful only when both of these instructs are satisfied, since
    they are consumed in order, assuming both conditions evaluate to the same thing 
    (excluding `Times(count)`).
    
    If you add `Expected()` to all of the instructs (with same conditions), only the last 
    expectation would be filled and the previous ones would fail since the `Times(x)` requirement
    expects exactly `Times(x)` to be called, not more.
    
</br>

### Mark override as expected NOT to satisfy all conditions (`ExpectedNotSatisfied`):
```cpp
ExpectedNotSatisfied()
```

!!! warning
    `Expected` and `ExpectedNotSatisfied` are mutually exclusive. Only one of them is true. 
    
    So if you have `Times(count)` condition, `ExpectedNotSatisfied` will be true if the override is 
    triggered not **EXACTLY** `count` times.

</br>

### Get override result (`AssignsResult`):
```cpp
CppOverride::ResultPtr result; //using ResultPtr = std::shared_ptr<OverrideResult>;
.AssignsResult(result)
```

For more information about `#!cpp CppOverride::ResultPtr`, see [Override Result](inspect_overrides.md#override-result) section.

??? example
    ```cpp
    CppOverride::ResultPtr result;
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(42)
                   .Returns<int>(100)
                   .AssignsResult(result)
                   .Expected();
    
    MyFunction(42);  //Should succeed
    assert(result->LastStatusSucceed());
    
    MyFunction(99);  //Should fail condition
    assert(result->GetLastStatus() == CppOverride::OverrideStatus::MATCHING_CONDITION_VALUE_FAILED);
    ```

</br>

## Passthrough Actions

For `CO_INSTRUCT_PASSTHROUGH`, only a subset of actions are available:

```cpp
CO_INSTRUCT_PASSTHROUGH(overrideInstance)
                       .Times(count)
                       .Expected()
                       .ExpectedNotSatisfy();
```

</br>
