# Cpp Override

![](./Logo.png)

A C++ 11 Compatible Framework that allows you to override function behaviors. 

Similar to mocking but with greater flexibility and customizations

### 🚀 Features
#### ⚙️ Override any classes you want, including **non virtual classes**
#### 💡 Override any functions you want, including **free functions**
#### 📑 Doesn't break **C++ Standard**, no need to exploit vtable
#### 🔌 Easy to setup and use
#### 🔋 Batteries included, generate mock classes using the mock class generator

---

### 📦️ Installation

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

- `AddSubDirectory(CppOverride)`
- `TargetLinkLibrary(YourTarget CppOverride)`

---

### 🏃 Quick Start

#### 💡 Override Free Function
```cpp
#include <iostream>

//Define CO_NO_OVERRIDE to disable overriding
//#define CO_NO_OVERRIDE
#include "CppOverride.hpp"

CO_DECLARE_INSTANCE(OverrideInstance);

int FreeFunction(int value1)
{
    CO_OVERRIDE_IMPL(OverrideInstance, int, value1);
    return value1 * 2;
}

int main()
{
    CO_SETUP_OVERRIDE(OverrideInstance, FreeFunction)
                     .WhenCalledWith(5)
                     .Time(1)
                     .Returns<int>(1);
    
    //FreeFunction(0): 0
    std::cout << "FreeFunction(0): " << FreeFunction(0) << std::endl;
    
    //FreeFunction(5): 1
    std::cout << "FreeFunction(5): " << FreeFunction(5) << std::endl;
    
    //FreeFunction(5): 10
    std::cout << "FreeFunction(5): " << FreeFunction(5) << std::endl;
    
    return 0;
}
```

#### ⚙️ Override Class Function
```cpp
class DummyMockClass : public CppOverride::Overridable
{
    public:
        //int MemberFunction(int value1);
        CO_OVERRIDE_METHOD(*this, int, MemberFunction, (int))
};

int main()
{
    DummyMockClass dummyObject;
    
    CO_SETUP_OVERRIDE(dummyObject, MemberFunction)
                     .WhenCalledWith(5)
                     .Time(1)
                     .Returns<int>(1);
    
    //dummyObject.MemberFunction(0): 0
    std::cout << "dummyObject.MemberFunction(0): " << dummyObject.MemberFunction(0) << std::endl;
    
    //dummyObject.MemberFunction(5): 1
    std::cout << "dummyObject.MemberFunction(5): " << dummyObject.MemberFunction(5) << std::endl;
    
    //dummyObject.MemberFunction(5): 5
    std::cout << "dummyObject.MemberFunction(5): " << dummyObject.MemberFunction(5) << std::endl;
    
    return 0;
}
```

This is just a quick taste on what it looks like. 
There are many other things you can do. 

For a more detailed guide, check out the user guide
[https://neko-box-coder.github.io/CppOverride/](https://neko-box-coder.github.io/CppOverride/)
