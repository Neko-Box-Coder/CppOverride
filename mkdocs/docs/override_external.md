# 5. Overriding External Symbols

## Overriding External Libraries

It is very difficult to override external functions or objects since unlike other languages like C#,
everything is compiled and there's no way to change the behavior of it.

In order to override an external function or objects, 
we first need to create an override version of it.

Let's say we have the following external class and function.

```cpp title="External/GenericCloudWriter/Writer.hpp"
...

//External Class, cannot edit this
class FileWriter
{
    public:
        bool CreateFile(std::string fileName);
        bool WriteContent(const std::string& content);
        bool Close();
};

...

//External Function, cannot edit this
FileWriter GetCloudFileWriter(std::string tableName);
```

We should create the corresponding override versions of them. 

<!-- Inheriting from `CppOverride::Overridable` is used here but would be the same when using  -->
<!-- `CO_OVERRIDE_IMPL(...)` -->

```cpp title="Tests/MockComponents/MockWriter.hpp"
extern CO_DECLARE_INSTANCE(MyOverrideInstance);

class MockFileWritter
{
    public:
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, CreateFile, (std::string));
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, WriteContent, (std::string));
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, Close, ());
}

CO_INSERT_METHOD(MyOverrideInstance, MockFileWritter, MockGetCloudFileWriter, (std::string));
```

Let's say we have a piece of code like this in our codebase

```cpp title="Source/RecordWriter.hpp"
#include "External/GenericCloudWriter/Writer.hpp"

...

bool WriteRecord(int key, const std::string& data)
{
    FileWriter cloudWriter = GetCloudFileWriter("UserData");
    if(!cloudWriter.WriteContent(std::to_string(key) + "," + data))
        return false;
    
    ...
    
    return cloudWriter.Close();
}
```

As you can see, we don't even hold a reference to `cloudWriter` outside of this function,
let alone overriding and testing it. 

That's why it is recommended to declare the override instance in global scope. So that you can
override the behavior of objects that you cannot reference in test.

In order to override it, we would have to make some changes to this code unfortunately.

While people would normally suggest rewriting the code using template or interface, 
this normally requires a lot of rewriting and restructure to the codebase.

Instead, we can just use the powerful (yet dangerous) preprocessing system.

Without rewriting and restructuring, we can just

```cpp title="Tests/MockComponents/MockWriter.hpp"
...

#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
    #define GetCloudFileWriter MockGetCloudFileWriter
    #define FileWritter MockFileWritter
#endif
```

Then, we can include the mock writer like this to our `RecordWriter.cpp`, and maybe control it either
via `CO_NO_OVERRIDE` or a codebase specific macro like `IS_UNIT_TEST`

```cpp title="Source/RecordWriter.hpp"
//Normal includes go here...
#include "External/GenericCloudWriter/Writer.hpp"
...

//System includes go here...
...

#if defined(IS_UNIT_TEST) && IS_UNIT_TEST
    #inlcude "Tests/MockComponents/MockWriter.hpp"  //IMPORTANT: Mock headers should be included last
#endif

...

bool WriteRecord(int key, const std::string& data)
{
    FileWriter cloudWriter = GetCloudFileWriter("UserData");
    if(!cloudWriter.WriteContent(std::to_string(key) + "," + data))
        return false;
    
    ...
    
    return cloudWriter.Close();
}
```

!!! warning
    It is important to remember that the mock file should be included **LAST** since it performs
    text swapping on the rest of the text after it.

This way, the original code is modified when testing while being untouched.

This is what it will look like after the macro replacement.

```cpp title="Build/Source/RecordWriter.i"
...

bool WriteToDatabaseRecord(int key, const std::string& data)
{
    MockFileWritter cloudWriter = MockGetCloudFileWriter("UserData");
    if(!cloudWriter.WriteContent(std::to_string(key) + "," + data))
        return false;
    
    ...
    
    return cloudWriter.Close();
}
```

## Overriding Std Libraries

Sometimes when running tests, it might not be desirable to trigger some of the std functions or 
objects, for example a file write with `std::ofstream`.

While we can perform the same "text swapping" with preprocessor like what we did before, 
it might be tempting to just override the class only by inserting the mock implementation to the 
`std` namespace, like this:

```cpp title="Incorrect way of overriding std classes/functions"
namespace std
{
    struct Mock_ofstream
    {
        CO_INSERT_MEMBER_METHOD_CTOR(OverrideInstance, Mock_ofstream, const std::string&)
        CO_INSERT_MEMBER_METHOD(OverrideInstance, bool, is_open, ())
        CO_INSERT_MEMBER_METHOD(OverrideInstance, void, close, ())
        CO_INSERT_MEMBER_METHOD(OverrideInstance, 
                                Mock_ofstream&, 
                                operator<<, 
                                (T const&), 
                                template<typename T>)
        ...
    };
}

#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
    #define ofstream Mock_ofstream
#endif
```

While this works on most compilers, it is an undefined behavior to "expand" on the `std` namespace.

So the only "proper" way of overriding `std` is to "text swap" the `std` namespace as well, so like 
this:

```cpp title="Correct way of overriding std classes/functions"
namespace Mock_std
{
    struct Mock_ofstream
    {
        ...
    };
}

#if !defined(CO_NO_OVERRIDE) || !CO_NO_OVERRIDE
    #define std Mock_std
    #define ofstream Mock_ofstream
#endif
```

This will however carry the side effect of invalidating the rest of `std` classes or functions.

!!! danger
    Again, remember to include the mock file **LAST** since it performs text swapping on the rest of 
    the text after it. You **DO NOT** want to perform text swapping on system libraries.

### Forwarding Std Or External Types

To preserve the same behavior as before for the rest of the non-overridding classes or functions,
we provide a set of macros of forwarding types and functions.

To forward a normal type, you can use the macro below inside the mock `std` namespace.
```cpp
CO_FORWARD_TYPE(forwardNamespace, name)
```
???+ example
    ```cpp
    namespace Mock_std
    {
        ...
        CO_FORWARD_TYPE(std, string);       //Forward `Mock_std::string` to `std::string`
    }
    ```

Similarly, to forward a templated type, you can use the following macro.
```cpp
CO_FORWARD_TEMPLATE_TYPE(forwardNamespace, name)
```
???+ example
    ```cpp
    namespace Mock_std
    {
        ...
        CO_FORWARD_TEMPLATE_TYPE(std, vector);      //Forward `Mock_std::vector` to `std::vector`
    }
    ```

!!! note
    These macros can also be used for external libraries/namespaces as well, not just std.


### Forwarding Std Or External Functions

Forwarding std or external functions however, it's not as simple. In general you will need to write 
the wrapper yourself with the same return type and parameters and call the actual function inside it.

???+ example "Forwarding `std::filesystem::exists()`"
    ```cpp
    namespace Mock_std
    {
        namespace filesystem
        {
            CO_FORWARD_TYPE(std::filesystem, path);
            bool exists(const std::filesystem::path& p)
            {
                return std::filesystem::exists(p);
            }
        }
    }
    ```

There are a few macros that forward a few commonly used std functions:
```cpp
CO_FORWARD_STD_COUT()
CO_FORWARD_STD_ENDL()
CO_FORWARD_STD_TO_STRING()
CO_FORWARD_STD_GET_LINE()
```

???+ example
    ```cpp
    namespace Mock_std
    {
        ...
        CO_FORWARD_STD_COUT()           //Forward `Mock_std::cout` to `std::cout`
        CO_FORWARD_STD_ENDL()           //Forward `Mock_std::endl()` to `std::endl()`
        CO_FORWARD_STD_TO_STRING()      //Forward `Mock_std::to_string()` to `std::to_string()`
        CO_FORWARD_STD_GET_LINE()       //Forward `Mock_std::getline()` to `std::getline()`
    }
    ```
