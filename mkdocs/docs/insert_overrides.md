# 2. **Insert** Overrides

After declaring the override instance,
we are now ready to override any function using override implementations macros.

## Overriding Existing Methods

CppOverride works by inserting an interception macro at the beginning of a function that 
intercepts the rest of the logic of a function.

This works for any functions you control. For external functions such as ones from the standard 
library, you can work around it by using macro, which we will cover later in this documentation.

To insert an override for a free function, simply use

```cpp
CO_INSERT_IMPL(overrideInstance, returnType, (argument0, argument1, ...));
```

???+ example
    ```cpp
        extern CO_DECLARE_INSTANCE(MyOverrideInstance);
        
        int MyFreeFunction(int arg1, char* arg2, const std::string& arg3)
        {
            CO_INSERT_IMPL(MyOverrideInstance, int, (arg1, arg2, arg3));
            //Rest of function logic...
            return 0;
        }
    ```

!!! warning
    If you have comma in your return type (such as `#!cpp std::tuple<int, int>`), you need to add an extra
    parenthesis to protect it against macro.

    For example:
    ```cpp
    //std::tuple<int, int> FreeFunction(std::tuple<int, int> value1, float value2)
    CO_INSERT_IMPL(MyOverrideInstance, (std::tuple<int, int>), (value1, value2));
    ```

For class member functions, there are different versions of macro depending what you want to insert 
the override.

For normal member function, it works exactly like `CO_INSERT_IMPL`, except this macro records the 
address of the object as well (`#!cpp this`) which you can match against during instructing the override.

```cpp
CO_INSERT_MEMBER_IMPL(overrideInstance, returnType, (arg0, arg1, ...));
```

For constructor and destructor however, a different macro is needed since they don't return anything.

```cpp
CO_INSERT_MEMBER_IMPL_CTOR_DTOR(overrideInstance, (arg0, arg1, ...));
```

</br>

## Creating Mock Methods

If you want methods that only contains the `CO_INSERT_*_IMPL*` macros, we provide corresponding 
macros that create it for you so you don't have to write the whole function by hand.

We also have a rough mock class generator which generates mock class file by parsing an existing 
header that you provider, this will be covered later in this documentation.

To create an inline free mock function implementation, an overloaded macro is provided for you which
automatically inserts `CO_INSERT_IMPL` macro.

```cpp
CO_INSERT_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...))
CO_INSERT_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend)
CO_INSERT_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend, append)
CO_INSERT_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend, append, 
    (defaultArg0, defaultArg1, ...))
```

!!! warning
    If you have comma in your argument or return types (such as `#!cpp std::tuple<int, int>`), you 
    need to add an extra parenthesis to protect it against macro.

    For example:
    ```cpp
    //std::tuple<int, int> FreeFunction(std::tuple<int, int> value1, float value2)
    CO_INSERT_METHOD(MyOverrideInstance, (std::tuple<int, int>), FreeFunction, ((std::tuple<int, int>), float))
    ```

???+ example
    ```cpp
        extern CO_DECLARE_INSTANCE(MyOverrideInstance);
        
        CO_INSERT_METHOD(MyOverrideInstance,                             //overrideInstance
                         int,                                            //returnType
                         MyFreeFunction,                                 //functionName
                         (int, char*, const std::string&),               //args
                         static,                                         //prepend
                         noexcept,                                       //append
                         (/* no default */, = nullptr, = "default"));    //defaults
        
        //Generated function
        static inline int MyFreeFunction(int arg1, 
                                         char* arg2 = nullptr, 
                                         const std::string& arg3 = "default") noexcept
        {
            CO_INSERT_IMPL(MyOverrideInstance, int, (arg1, arg2, arg3));
            return int();
        }
        
    ```


For member constructor and desturctor functions, there's `CO_INSERT_MEMBER_METHOD_CTOR` and 
`CO_INSERT_MEMBER_METHOD_DTOR` which automatically inserts `CO_INSERT_MEMBER_IMPL_CTOR_DTOR` macro.

Similar to `CO_OVERRIDE_METHOD`, it is overloaded with the same arguments.

```cpp
CO_INSERT_MEMBER_METHOD_CTOR(overrideInstance, className, (argType0, argType1, ...))
CO_INSERT_MEMBER_METHOD_CTOR(overrideInstance, className, (argType0, argType1, ...), prepend)
CO_INSERT_MEMBER_METHOD_CTOR(overrideInstance, className, (argType0, argType1, ...), prepend, append)
CO_INSERT_MEMBER_METHOD_CTOR(overrideInstance, className, (argType0, argType1, ...), prepend, append, 
    (defaultArg0, defaultArg1, ...))

CO_INSERT_MEMBER_METHOD_DTOR(overrideInstance, className)
CO_INSERT_MEMBER_METHOD_DTOR(overrideInstance, className, prepend)
CO_INSERT_MEMBER_METHOD_DTOR(overrideInstance, className, prepend, append)
```

???+ example
    ```cpp
        extern CO_DECLARE_INSTANCE(MyOverrideInstance);
        
        class YourClass
        {
            CO_INSERT_MEMBER_METHOD_CTOR(MyOverrideInstance, YourClass, (int, float))
            CO_INSERT_MEMBER_METHOD_DTOR(MyOverrideInstance, YourClass)

            /*Generates
            inline YourClass::YourClass(int arg1, float arg2)
            {
                CO_INSERT_MEMBER_IMPL_CTOR_DTOR(MyOverrideInstance, (arg1, arg2));
            }

            inline YourClass::~YourClass()
            {
                CO_INSERT_MEMBER_IMPL_CTOR_DTOR(MyOverrideInstance, ());
            }
            */
        }
    ```


For inline member mock function implementation, an overloaded macro is provided which
automatically inserts `CO_INSERT_MEMBER_IMPL` macro.

```cpp
CO_INSERT_MEMBER_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...))
CO_INSERT_MEMBER_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend)
CO_INSERT_MEMBER_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend, append)  
CO_INSERT_MEMBER_METHOD(overrideInstance, returnType, functionName, (argType0, argType1, ...), prepend, append, 
    (defaultArg0, defaultArg1, ...))
```

???+ example
    ```cpp
        extern CO_DECLARE_INSTANCE(MyOverrideInstance);
        
        class MockMyClass : public MyClass
        {
            //int MemberFunction(int value1, float value2)
            CO_INSERT_MEMBER_METHOD(MyOverrideInstance, int, MemberFunction, (int, float))

            //void MemberFunction2(float& value1, int* value2) const
            CO_INSERT_MEMBER_METHOD(MyOverrideInstance, void, MemberFunction2, (float&, int*), 
                /* no prepend */, const)

            //virtual int MemberFunction3(int value1, float value2 = 1.f) const override
            CO_INSERT_MEMBER_METHOD(MyOverrideInstance, int, MemberFunction3, (int, float), 
                virtual, const override, (/* no default */, = 1.f))
        };
    ```
