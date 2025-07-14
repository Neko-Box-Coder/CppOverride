# 4. **Inspect** Override Expectations

After finish running the overrided functions, you can inspect what functions did not meet the
expectations you set during the instruct phase.

</br>

## Get Report Of Failed Expectations, Results And Statuses

Use `CO_GET_FAILED_REPORT` to get a report string in the form of
```
FailedFunction1():
    Instruct[0]:
        Status[0]: <Instruct Attempt Status String>
        Status[1]: <Instruct Attempt Status String>
        Status[2]: <Instruct Attempt Status String>
    Instruct[1]:
        Status[0]: <Instruct Attempt Status String>
        Status[1]: <Instruct Attempt Status String>
        Status[2]: <Instruct Attempt Status String>
FailedFunction2():
    Instruct[0]:
        Status[0]: <Instruct Attempt Status String>
        Status[1]: <Instruct Attempt Status String>
        Status[2]: <Instruct Attempt Status String>
...
```

```cpp
std::string reportString = CO_GET_FAILED_REPORT(overrideInstance);
```

where it prints all the functions that failed the expectations, then a list of the instructs commands
for each of the functions, then a list of override attempts as override status for each of the 
instructs commands.

For getting each component (failed functions, instructs and statuses) of the report, see the next
section and the one after.

</br>

## Get List Of Functions That Failed Expectations

Use `CO_GET_FAILED_FUNCTIONS` to get a list of functions that failed to meet their expectations:

```cpp
std::vector<std::string> failedFunctions = CO_GET_FAILED_FUNCTIONS(overrideInstance);
```

This returns a vector of function names (as strings) that
- Failed the `.Expected()` checks
- Failed the `.ExpectedNotSatisfy()` checks

In addition to that, if passthrough doesn't meet the expectation but cannot contribute to any 
specific function (Say must passthrough 5 times, but only passthrough 3 times), then the string
`"Passthrough"` will be added to the vector. Otherwise, the string `"(Passthrough)"` will be 
appended to the functions that contributes to the failure of the expectation.

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    
    //Set up expectations
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(42)
                   .Returns<int>(100)
                   .Times(2)
                   .Expected();
    
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, AnotherFunction)
                   .Returns<void>()
                   .ExpectedNotSatisfy();
    
    //Run your code
    MyFunction(42);        //Called once, but expected twice
    AnotherFunction();     //Called, but expected not to be called
    
    //Check for failed expectations
    std::vector<std::string> failed = CO_GET_FAILED_FUNCTIONS(MyOverrideInstance);
    
    if(!failed.empty())
    {
        std::cout << "Failed expectations:" << std::endl;
        for(const std::string& funcName : failed)
        {
            std::cout << "- " << funcName << std::endl;
        }
    }
    ```

</br>

## Get Override Results For A Specific Function

### Override Result

`CppOverride::ResultPtr` is just a shared_ptr defined as this 

```cpp
using ResultPtr = std::shared_ptr<OverrideResult>;
```

Each time when there's an override attempt (whether successful or not), 
it will add to the list of override status.

To get the list of status:
```cpp
std::vector<OverrideStatus> statuses = result.GetAllStatuses();
```

??? info "`OverrideResult.hpp`"
    ```cpp

    --8<-- "Src/OverrideResult.hpp"

    ```

??? info "List of possible status `OverrideStatus.hpp`"
    ```cpp
    
    --8<-- "Src/OverrideStatus.hpp"
    
    ```

Use `CO_GET_OVERRIDE_RESULTS` to get detailed result information for a specific function:

```cpp
std::vector<CppOverride::ResultPtr> results = CO_GET_OVERRIDE_RESULTS(overrideInstance, functionName);
```

This returns a vector of `ResultPtr` objects (one for each override instruction for that function) 
containing detailed status information.

!!! note
    If you have multiple overrides for the same function, the results will be returned in the order 
    you set up the instructs for the overrides.

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    
    //Set up multiple overrides for the same function
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(1)
                   .Returns<int>(100)
                   .Expected();
    
    CO_INSTRUCT_REF(MyOverrideInstance, CO_GLOBAL, MyFunction)
                   .WhenCalledWith(2)
                   .Returns<int>(200)
                   .Expected();
    
    //Run your code
    MyFunction(1);
    MyFunction(3);  //This won't match any override
    
    //Get detailed results
    std::vector<CppOverride::ResultPtr> results = 
        CO_GET_OVERRIDE_RESULTS(MyOverrideInstance, "MyFunction");
    
    for(size_t i = 0; i < results.size(); ++i)
    {
        if(results[i])
        {
            std::cout << "Override " << i << ":" << std::endl;
            std::cout << "  Success count: " << results[i]->GetSucceedCount() << std::endl;
            std::cout << "  Failed count: " << results[i]->GetFailedCount() << std::endl;
            std::cout << "  Last status: " << 
                CppOverride::OverrideStatusToString(results[i]->GetLastStatus()) << std::endl;
        }
    }
    ```

</br>

## Debug Override Logs

If for any reason, it is unclear why the override did not get triggered and the override result
did not give any useful information. You can force CppOverride to output verbose logs by
defining `CO_SHOW_OVERRIDE_LOG 1` before `#include "CppOverride.hpp"`. 

This will show all the debug logs on each stage of selecting override data and what conditions 
are not met.

