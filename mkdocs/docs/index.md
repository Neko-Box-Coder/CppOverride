# Cpp Override User Guide

![](./Logo.png)

Cpp Override is a C++ 11 Compatible Framework that allows you to override function behaviors. 

Similar to mocking but with greater flexibility and customizations

### 📦️ 1. Installation

Cpp Override is hosted on github at 
[https://github.com/Neko-Box-Coder/CppOverride](https://github.com/Neko-Box-Coder/CppOverride). 
Feel free to check out the source code yourself.

To start off, you first need to clone the repository with
```shell
git submodule add https://github.com/Neko-Box-Coder/CppOverride.git <folder name>
git submodule update --init --recursive
```
or
```shell
git clone https://github.com/Neko-Box-Coder/CppOverride.git
```

This framework is header only so you can just include it with

`CppOverride.hpp` in `Include_SingleHeader` or `Include_MultiHeader`

Additionally, you can add the include directory with

- `#!cmake AddSubDirectory(CppOverride)`
- `#!cmake TargetLinkLibrary(YourTarget CppOverride)`

---

### 📢 2. Declare Override Instance

In order to override anything, we will first need an override instance to store all the override 
information that the function and test can reference from. 

#### Global / File Scope
Declaring it in global scope makes it easy to be accessed from both the function and the test.

```cpp
CO_DECLARE_INSTANCE(MyOverrideInstance);

//Or this if you want to reference an instance declared somewhere else
extern CO_DECLARE_INSTANCE(MyOverrideInstance);
```

#### Class Scope
Declaring it in class scope is more similar to the traditional mock class approach

```c++
class YourClass
{
    private:
        CO_DECLARE_MEMBER_INSTANCE(MyOverrideInstance);
        ...
    public:
        CO_DECLARE_OVERRIDE_METHODS(MyOverrideInstance);
        ...
};
```

Or alternatively inherits from `#!cpp CppOverride::Overridable`.
Inheriting from it has less flexibility but easier to setup. 

See [📥️ 8. Inheriting from Overridable](#8-inheriting-from-overridable) for more details

<!-- ```cpp -->
<!-- //CO_DECLARE_MEMBER_INSTANCE and CO_DECLARE_OVERRIDE_METHODS is inside CppOverride::MockClass -->
<!-- class YourMockClass : public CppOverride::MockClass -->
<!-- { -->
<!--     ... -->
<!-- } -->
<!-- ``` -->

!!! tip
    Declaring override instance in **Global/File scope** is recommended for overriding 
    member functions.
    This is because it allows you to override constructor and destructor. 
    If the override information is saved inside the class, 
    that information is bounded to the object lifetime.

---

### ⚙️ 3. Insert Override Implementations
After declaring the override instance,
we are now ready to override any function using override implementations macros

```cpp
CO_OVERRIDE_IMPL(Override Instance, Return Type, (Arguments))
```

???+ example
    ```cpp
    #include "CppOverride.hpp"
    int FreeFunction(int value1, float value2)
    {
        CO_OVERRIDE_IMPL(MyOverrideInstance, int, (value1, value2));
        return value1 * value2;
    }
    ```

For overriding member functions, you can use this

```cpp
CO_OVERRIDE_IMPL_INSTANCE(Override Instance, Return Type, (Arguments))
```

and 

```cpp
CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(Override Instance, (Arguments))
```

??? example
    ```cpp
    #include "CppOverride.hpp"
    int SomeClass::MemberFunction(int value1, float value2)
    {
        CO_OVERRIDE_IMPL_INSTANCE(MyOverrideInstance, int, (value1, value2));
        return value1 * value2;
    }

    SomeClass::SomeClass(int value1, float value2)
    {
        CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(MyOverrideInstance, (value1, value2));
    }

    SomeClass::~SomeClass()
    {
        CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(MyOverrideInstance, ());
    }
    ```

!!! important
    If you have comma in your return type (such as `#!cpp std::tuple<int, int>`), you need to add an extra
    parenthesis to protect it against macro.
    
    For a function like 
    
    ```cpp
    std::tuple<int, int> FreeFunction(int value1, float value2)
    ```
    
    It will be
    
    ```cpp
    CO_OVERRIDE_IMPL(MyOverrideInstance, (std::tuple<int, int>), (value1, value2))
    ```

---

### 🧲 4. Setup Override Actions
Now we have inserted the override implementations, 
we will just need to interact with the override instance to control the override functions when called.

To start setting up the override actions, call `CO_SETUP_OVERRIDE` macro
```cpp
CO_SETUP_OVERRIDE(Override Instance, Function Name);
```

This can be chained with different actions like this

```cpp
CO_SETUP_OVERRIDE(Override Instance, Function Name)
                 .WhenCalledWith(Values...)
                 .Returns<Return Type>(Return Value);
                 //etc...
```

???+ example
    ```cpp
    #include "CppOverride.hpp"
    #include <iostream>
    
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    
    int FreeFunction(int value1, float value2)
    {
        CO_OVERRIDE_IMPL(MyOverrideInstance, int, (value1, value2));
        return value1 * value2;
    }
    
    int main()
    {
        CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                         .WhenCalledWith(1, 2.f)
                         .Returns<int>(42);

        int result = FreeFunction(1, 2.f);
        std::cout << "result: " << result << std::endl; //result: 42
        
        result = FreeFunction(2, 3.f);
        std::cout << "result: " << result << std::endl; //result: 6
    }
    ```

If you have your override instance declared inside a class, pass that object as 
`Override Instance` instead

???+ example
    ```cpp
    //YourClass.hpp
    #include "CppOverride.hpp"
    class YourClass
    {
        private:
            CO_DECLARE_MEMBER_INSTANCE(MyOverrideInstance);
            ...
        public:
            CO_DECLARE_OVERRIDE_METHODS(MyOverrideInstance);
            int MemberFunction(int value1, float value2);
            ...
    };
    ...
    
    //main.cpp
    #include "YourClass.hpp"
    #include "CppOverride.hpp"
    #include <iostream>
    
    int main()
    {
        YourClass classObject;
        
        CO_SETUP_OVERRIDE(classObject, MemberFunction)
                         .WhenCalledWith(1, 2.f)
                         .Returns<int>(42);
        ...
    }
    ```

---

If you want to override a function for a specific object, 
you can specify with 
```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .OverrideObject(Your Object address)
```

!!! note
    This requires `CO_OVERRIDE_IMPL_INSTANCE(...)` to be used instead of `CO_OVERRIDE_IMPL(...)`

???+ example
    ```cpp
    int main()
    {
        YourClass classObject;
        YourClass classObject2;
        
        CO_SETUP_OVERRIDE(classObject, MemberFunction)
                         .WhenCalledWith(1, 2.f)
                         .OverrideObject(&classObject2)
                         .Returns<int>(42);
        
        int result = classObject.MemberFunction(1, 2.f);    //Won't override
        result = classObject2.MemberFunction(1, 2.f);       //Will override
    }
    ```

---

#### Get Override Result

To get the result of an override action, whether it was successful or not, you can use

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .AssignOverrideResult(Result Object)
```

The status of the result can be read with `.Status`

???+ example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    CppOverride::OverrideResult result;
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .WhenCalledWith(2, 3.f)
                     .Returns<int>(1)
                     .AssignOverrideResult(result);

    int ret1 = FreeFunction(1, 2.f);
    //result.Status will be OverrideStatus::MATCHING_CONDITION_VALUE_FAILED

    ret1 = FreeFunction(2, 3.f);
    //result.Status will be OverrideStatus::OVERRIDE_SUCCESS
    ```

Here are the list of possible status

```cpp
enum class OverrideStatus
{
    //Default status.
    //  Any matching override will modify the status to not be this value.
    //  If the status is not modified (i.e. staying in this value), 
    //  Could be one of these reasons:
    //  - Function name not matching
    //  - Argument types not matching
    //  - Return type not matching
    NO_OVERRIDE,
    
    //The last override was successful. 
    //  Please reset the status to NO_OVERRIDE before every expected override. 
    //  If the status is not reset, it will not be modified if no matching override is found.
    OVERRIDE_SUCCESS,
    
    MATCHING_CONDITION_VALUE_FAILED,
    MATCHING_CONDITION_ACTION_FAILED,
    MATCHING_OVERRIDE_TIMES_FAILED,
    
    ...
};
```

You can convert the result status to string with 
```cpp
std::string OverrideStatusToString(Override Status)
```

---

#### Disable Overrides

By default, the override implementations won't do anything if nothing is setup, which 
will behave exactly as the original function.

However, if you want zero overhead when the override is disabled, you can define `CO_NO_OVERRIDE`
before including the header file.

```cpp
//Just define CO_NO_OVERRIDE before including "CppOverride.hpp" or in compile definitions
//So like this:
#define CO_NO_OVERRIDE
#include "CppOverride.hpp"
```

---

To remove the override setups for a particular function, call `CO_REMOVE_OVERRIDE_SETUP` macro

```cpp
CO_REMOVE_OVERRIDE_SETUP(Override Instance, Function Name)
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    CO_REMOVE_OVERRIDE_SETUP(MyOverrideInstance, FreeFunction);
    ```


Similarly, to remove all override setups, call `CO_CLEAR_ALL_OVERRIDE_SETUP` macro

```cpp
CO_CLEAR_ALL_OVERRIDE_SETUP(Override Instance)
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    ...
    CO_CLEAR_ALL_OVERRIDE_SETUP(MyOverrideInstance);
    ```

---

### ↩️ 5. Override Returns

You can override what a function returns by providing a value.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .Returns<Return Type>(Return Value);
```

??? example
    ```cpp
    int FreeFunction(int value1, float value2);
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .Returns<int>(1);
    ```

!!! important
    The override return type **must** match exactly to the function return type, 
    otherwise the override will not be triggered

??? note
    For a function that returns void, you can also override the return to return early
    ```cpp
    .Returns<void>();
    //Or .ReturnsVoid();
    ```

---

You can also set the return value by specifying a function, normally lambda.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .ReturnsByAction<Return Type>
                 (
                    void(void* instance, const std::vector<void*>& args, void* out) Function
                 );
```

When the override is triggered, the function is called with the following arguments:

- `void* instance`: The object that is being overridden, only set when `CO_OVERRIDE_IMPL_INSTANCE(...)`
or `CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(...)` are used, otherwise `nullptr`.
- `const std::vector<void*>& args`: List of pointers to the arguments. 
You must cast them to the original type pointers in order to use them.
- `void* out`: The pointer to the return value to be returned. 
You must cast it to back to return type pointer in order to use it.

???+ example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    ...
    int SomeClass::MemberFunction(int value1, float value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, MemberFunction)
                     .ReturnsByAction<int>
                     ( 
                         [](void* instance, const std::vector<void*>& args, void* out)
                         {
                             //instance is same as "this" in MemberFunction
                             std::cout << "instance: " << instance << std::endl;
                             
                             //*args[0] is value1
                             std::cout << "*args[0]: " *static_cast<int*>(args.at(0)) << std::endl;
                             
                             //*args[1] is value2
                             std::cout << "*args[1]: " *static_cast<float*>(args.at(1)) << std::endl;
                             
                             //out is what we return
                             *static_cast<int*>(out) = 42;
                         }
                     );
    ...
    SomeClass someObject;
    std::cout << someObject.MemberFunction(1, 2.f) << std::endl;    //42
    ```

---

### 📬️ 6. Override Arguments Values

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .SetArgs<Function Argument Types>(Argument Values);
```

The argument values can be a dereference version of the corresponding argument type.

For example, an integer pointer type can be set with an integer value.

???+ example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    ...
    void FreeFunction(float& value1, int* value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .SetArgs<float&, int*>(1.f, 3);
    ```

!!! important
    The template types of the argument specified must match the function argument types exactly.

You can also use `CO_ANY_TYPE` and `CO_DONT_SET` to not set some of the arguments.

???+ example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    ...
    void FreeFunction(float& value1, int* value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .SetArgs<CO_ANY_TYPE, int*>(CO_DONT_SET, 3);
    ```

    In this case, the first argument is not touched, while the second argument is set to 3.

???+ note
    It is **common to pair** `.SetArgs` with `.Returns` so that the execution doesn't continue when
    we finish overriding the arguments.

    Given we have this
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    void FreeFunction(float& value1, int* value2)
    {
        CO_OVERRIDE_IMPL(MyOverrideInstance, void, (value1, value2));
        std::cout << "Rest of the OverrideMyArgs execution..." << std::endl;
        value1 = *value2;
        ...
    }
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                      .SetArgs<float&, int*>(1.f, 3);
    ...
    FreeFunction(value1, value2);
    ```
    
    What will happen when we call the function is
    
    1. Override occurs, `value1` is set to `1.f` and `value2` is set to `3`
    2. Execution **does not** stop
    3. Output: "Rest of the OverrideMyArgs execution..."
    4. `#!cpp value1 = *value2;` happens, setting `value1` to `*value2` which is `3`
    
    To return early after we set the arguments, we can do
    ```cpp
     CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                      .SetArgs<float&, int*>(1.f, 3);
                      .Returns<void>();
                      //Or .ReturnsVoid();
    ```
    Which will return early after step 1.

---

Similar to override return, 
you can also set the argument values by specifying a function, normally lambda.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .SetArgsByAction<Function Argument Types>
                 (
                    void(void* instance, std::vector<void*>& args) Function
                 );
```

This the same as the `ReturnsByAction`, but without the need of modifying any return value.
Again, you must cast the arguments pointers to their original type pointers in order to use them.

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    ...
    void FreeFunction(float& value1, int* value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .SetArgsByAction<float&, int*>
                     (
                         [](void* instance, std::vector<void*>& args)
                         {
                             (void)instance; //This will be nullptr in this case
                             
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

### 📐 7. Override Rules And Actions

Just like any mocking library, you can also control when and how the override functions will behave,
as well as registering callbacks when the override is successful or not.

---

#### When Called With

This triggers the override only when the value matches. 
This also auto dereference any pointer to match for the value if possible, 
if not it will then try to match pointer instead.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .WhenCalledWith<Condition Types>(Condition Values)
```

???+ example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .WhenCalledWith(2, 3.f)
                     .Returns<int>(1);

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
    int ret2 = OverrideMyReturnValue(1, 2.f);   //Won't return 1
    ```

If you don't care about a certain parameter, you can use `CO_ANY_TYPE` and `CO_ANY` to skip it

???+ example
    ```cpp
        CO_DECLARE_INSTANCE(MyOverrideInstance);
        int FreeFunction(int value1, float value2);
        ...
        CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                         .WhenCalledWith<int, CO_ANY_TYPE>(2, CO_ANY)
                         .Returns<int>(1);

        int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
        int ret2 = OverrideMyReturnValue(2, 2.f);   //Returns 1
    ```

---

#### Times

This allows override to be triggered for the set amount of times.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .Times(Override Amount)
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .Times(1)
                     .Returns<int>(1);

    int ret1 = OverrideMyReturnValue(2, 3.f);   //Returns 1
    ret1 = OverrideMyReturnValue(2, 3.f);       //Won't returns 1
    ```

---

#### If

This sets the condition to decide to run the override action or not

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .If
                 (
                    bool(void* instance, const std::vector<void*>& args) Function
                 )
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .If
                     (
                         [](void* instance, const std::vector<void*>& args) 
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

#### When Called Expectedly Do

This allows you to setup a function callback that gets called before an override will be used

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .WhenCalledExpectedly_Do
                 (
                    void(void* instance, std::vector<void*>& args) Function
                 );
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    bool called = false;
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .WhenCalledWith(2, 3.f)
                     .Returns<int>(1)
                     .WhenCalledExpectedly_Do
                     (
                         [&called](void* instance, const std::vector<void*>& args)
                         {
                             called = true;
                             //...
                         }
                     );

    int ret1 = FreeFunction(1, 2.f);   //called is still false
    int ret2 = FreeFunction(2, 3.f);   //called is true and ret2 is 1 now
    ```

??? tip
    If you just want to see if the function is called without overriding anything, 
    simple don't override anything.
    So like:
    ```cpp
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .WhenCalledWith(2, 3.f)
                     .WhenCalledExpectedly_Do
                     (
                         [&called](void* instance, const std::vector<void*>& args)
                         {
                             called = true;
                             //...
                         }
                     )
    ```

---

#### Otherwise Do Function / Lambda

This allows you to setup a function callback that gets called when an override can't be used 
because of failing to meet conditions or failing to match the correct argument values.

```cpp
CO_SETUP_OVERRIDE(Override Instance, Your Function)
                 .Otherwise_Do
                 (
                    void(void* instance, std::vector<void*>& args) Function
                 );
```

??? example
    ```cpp
    CO_DECLARE_INSTANCE(MyOverrideInstance);
    int FreeFunction(int value1, float value2);
    ...
    bool called = false;
    CO_SETUP_OVERRIDE(MyOverrideInstance, FreeFunction)
                     .WhenCalledWith(2, 3.f)
                     .Returns<int>(1)
                     .Otherwise_Do
                     (
                         [&called](void* instance, const std::vector<void*>& args)
                         {
                             called = true;
                             ...
                         }
                     );

    int ret2 = FreeFunction(2, 3.f);   //called is still false
    int ret1 = FreeFunction(1, 2.f);   //called is true now
    ```

---

### 📥️ 8. Inheriting from Overridable

We have talked about inheriting `#!cpp CppOverride::Overridable` briefly in [📢 2. Declare Override Instance](#2-declare-override-instance)

Similarly to other mocking frameworks, we provide macros for you to automatically declare 
and create the methods to be overridden using the override instance in `#!cpp CppOverride::Overridable`

This comes in as an overloaded macro so you can use the one you need.

```cpp
CO_OVERRIDE_METHOD(Return Type, Function Name, (Args Types), Function Append)
CO_OVERRIDE_METHOD(Function Prepend, Return Type, Function Name, (Args Types), Function Append)
CO_OVERRIDE_METHOD(Function Prepend, Return Type, Function Name, (Args Types), (Args Defaults), Function Append)
```

???+ example
    ```cpp
    class MockMyClass : public CppOverride::Overridable
    {
        //int MemberFunction(int value1, float value2)
        CO_OVERRIDE_METHOD(int, MemberFunction, (int, float), /* no append */)

        //void MemberFunction2(float& value1, int* value2) const
        CO_OVERRIDE_METHOD(/* no prepend */, void, MemberFunction2, (float&, int*), const)

        //virtual int MemberFunction3(int value1, float value2 = 1.f) const override
        CO_OVERRIDE_METHOD(virtual, int, MemberFunction3, (int, float), (/* no default */, = 1.f), const override)
    };
    ```

!!! important
    Similar to `CO_OVERRIDE_IMPL`, any type that has a comma in it needs to be protected with parenthesis

    For example:
    ```cpp
    //std::tuple<int, int> MemberFunction(std::tuple<int, int> value1, float value2)
    CO_OVERRIDE_METHOD((std::tuple<int, int>), MemberFunction, ((std::tuple<int, int>), float), /* no append */)
    ```

### 📠 9. Mock Class Generator

Unlike other mocking frameworks, we ship with a mock class generator that is built along with
the project that parses a given header and output the equivalent mock class header.

Do keep in mind that this is just a rough header parser so manual adjustment might
still be needed. For more details, do `GenerateMockClass --help`.

To write the output to a file on Unix do

```shell
./GenerateMockClass <options...> <input header> > ./MyMockClass.hpp
```

or in Windows Powershell

```powershell
./GenerateMockClass <options...> <input header> | Set-Content -Encoding UTF8NoBOM ./MyMockClass.hpp
```

### 🔌 10. Overriding External Functions and Objects

It is very difficult to override external functions or objects since unlike other languages like C#,
everything is compiled and there's no way to change the behavior of it.

In order to override an external function or objects, 
we first need to create an override version of it.

Let's say we have the following external class and function.

```cpp
//External Class, cannot edit this
class FileWriter
{
    public:
        bool CreateFile(std::string fileName);
        bool WriteContent(const std::string& content);
        bool Close();
};

//External Function, cannot edit this
FileWriter GetDatabaseInternalWriter(std::string tableName);
```

We should create the corresponding override versions of them. 

<!-- Inheriting from `CppOverride::Overridable` is used here but would be the same when using  -->
<!-- `CO_OVERRIDE_IMPL(...)` -->

```cpp
extern CO_DECLARE_INSTANCE(MyOverrideInstance);

class MockFileWritter
{
    public:
    inline bool CreateFile(std::string fileName)
    {
        CO_OVERRIDE_IMPL_INSTANCE(MyOverrideInstance, bool, (fileName));
        return false;
    }
    
    inline bool WriteContent(std::string content)
    {
        CO_OVERRIDE_IMPL_INSTANCE(MyOverrideInstance, bool, (content));
        return false;
    }
    
    inline bool Close()
    {
        CO_OVERRIDE_IMPL_INSTANCE(MyOverrideInstance, bool, ());
        return false;
    }
}

//FileWriter GetDatabaseDataWriter(std::string tableName);
inline MockFileWritter MockGetDatabaseInternalWriter(std::string tableName)
{
    CO_OVERRIDE_IMPL(MyOverrideInstance, MockFileWritter, (tableName));
    return FileWriter();
}
```

Let's say we have a piece of code like this in our codebase

```cpp
bool WriteToDatabaseRecord(int key, const std::string& data)
{
    FileWriter databaseWriter = GetDatabaseInternalWriter("UserData");
    if(!databaseWriter.WriteContent(std::to_string(key) + "," + data))
        return false;
    
    ...
    
    return databaseWriter.Close();
}
```

As you can see, we don't even hold a reference to `databaseWriter` outside of this function,
let alone overriding and testing it. 

That's why it is recommended to declare the override instance in global scope. So that you can
override the behavior of objects that you cannot reference in test.

In order to override it, we would have to make some changes to this code unfortunately.

While people would normally suggest rewriting the code using template or interface, 
this normally requires a lot of rewriting and restructure to the codebase.

Instead, we can just use the powerful (yet dangerous) preprocessing system.

Without rewriting and restructuring, we can just

```cpp
#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
    #define GetDatabaseInternalWriter MockGetDatabaseInternalWriter
    #define FileWritter MockFileWritter
#endif
```

This way, the original code is modified when testing while being untouched.

This is what it will look like after the macro replacement.

```cpp
bool WriteToDatabaseRecord(int key, const std::string& data)
{
    MockFileWritter databaseWriter = MockGetDatabaseInternalWriter("UserData");
    if(!databaseWriter.WriteContent(std::to_string(key) + "," + data))
        return false;
    
    ...
    
    return databaseWriter.Close();
}
```
