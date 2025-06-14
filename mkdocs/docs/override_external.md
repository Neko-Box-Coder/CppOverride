# Overriding External Symbols

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
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, CreateFile, (std::string));
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, WriteContent, (std::string));
        CO_INSERT_MEMBER_METHOD(MyOverrideInstance, bool, Close, ());
}

CO_INSERT_METHOD(MyOverrideInstance, MockFileWritter, MockGetDatabaseInternalWriter, (std::string));
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
