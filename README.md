## Cpp Override

A simple framework for overriding function behaviours.

This allows overriding return value or setting arguments, similar to mocking but more flexible

---

### Declare Override Instance
#### Global / File Scope
```cpp
CO_DECLARE_INSTNACE(OverrideInstanceName);
```
#### Class Member Variable
```cpp
class DummyClassMock
{
    private:
        CO_DECLARE_MEMBER_INSTNACE(OverrideInstanceName);
    //...
    public:
        CO_DECLARE_OVERRIDE_METHODS(OverrideInstanceName);
    //...
};
```

---

### Override Implementations
#### Override Implementation Return Value
```cpp
CO_RETURN_IF_FOUND( [Override Instance Name], 
                    [Function Name]([Args Types...]), 
                    [Args Names...]);
```

Example:
```cpp
int OverrideMyReturnValue(int value1, float value2)
{
    CO_RETURN_IF_FOUND(OverrideInstanceName, 
                       OverrideMyReturnValue(int, float), 
                       value, 
                       value2);
    return 0;
}
```
#### Override Implementation Argument Values
```cpp
CO_MODIFY_ARGS_IF_FOUND([Override Instance Name], 
                        [Function Name]([Args Types...]), 
                        [Args Names...]);

//or

CO_MODIFY_ARGS_AND_RETURN_IF_FOUND( [Override Instance Name], 
                                    [Return Value],
                                    [Function Name]([Args Types...]), 
                                    [Args Names...]);
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

---

### Override Functions
#### Override Returns
```cpp
CO_OVERRIDE_RETURNS([Override Instance Name], [Function Name]([Args Types...]))
                   .Returns([Return Value]);
```
Example:
```cpp
CO_OVERRIDE_RETURNS(OverrideInstanceName, OverrideMyReturnValue(int, float))
                   .Returns(1);
```
#### Override Arguments Values
```cpp
CO_OVERRIDE_ARGS([Override Instance Name], [Function Name]([Args Types...]))
                .SetArgs([Args Values...]);
```
Example:
```cpp
CO_OVERRIDE_ARGS(OverrideInstanceName, OverrideMyArgs(float&, int*))
                .SetArgs(1.f, 3);
```
#### Override Returns With Action Lambda
```cpp
CO_OVERRIDE_RETURNS(OverrideInstanceName, OverrideMyReturnValue(int, float))
                   .ReturnsByAction
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
                .SetArgByAction //First Argument
                (
                    [](const std::vector<void*>& args, void* currentArg)
                    {
                        *static_cast<float*>(currentArg) = 1.f;
                    }
                )
                .SetArgByAction //Second Argument
                (
                    [](const std::vector<void*>& args, void* currentArg)
                    {
                        *static_cast<float*>(currentArg) = 2;
                    }
                );
```

---

### Specify Override Rules
#### When Called With
```cpp
CO_OVERRIDE_RETURNS(OverrideInstanceName, OverrideMyReturnValue(int, float))
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
CO_OVERRIDE_RETURNS(OverrideInstanceName, OverrideMyReturnValue(int, float))
                   .If
                    (
                        [](const std::vector<void*>& args)
                        {
                            if(*static_cast<int*>(args.at(0) == 1)
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



#### Otherwise Do Lambda





---