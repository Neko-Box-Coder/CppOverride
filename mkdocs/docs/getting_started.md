# 1. Getting Started

## 1. Installation

Cpp Override is hosted on github at 
[https://github.com/Neko-Box-Coder/CppOverride](https://github.com/Neko-Box-Coder/CppOverride). 
Feel free to check out the source code yourself.

To start off, you first need to clone (git submodule) the repository to a location of your choice.
```shell
# Submodule
git submodule add https://github.com/Neko-Box-Coder/CppOverride.git <folder name>
git submodule update --init --recursive

# Cloning
git clone --recursive https://github.com/Neko-Box-Coder/CppOverride.git
```

This framework is header only so you can just include it with

`CppOverride.hpp` in `Include_SingleHeader` or `Include_MultiHeader`

Additionally, you can add the include directory with

``` cmake
add_subdirectory(CppOverride)
target_link_libraries(YourTarget CppOverride)
```

---

## 2. Override Behavior

CppOverride uses the **"Insert, Instruct, Inspect"** phases.

The override works by **inserting** override logic at the beginning of a function. 

Then, the user can **instruct** how the overrides behave. The override perform "passthrough" 
where it will do nothing and continue execution for the rest of the function if no instructs are
given for that function.

Finally, the user can **inspect** overrides results that do not meet the expectations.

Since CppOverride is a macro driven framework, you can disable all macros by just defining 
`CO_NO_OVERRIDE` to 1 or true. 

```cpp
#define CO_NO_OVERRIDE 1
#include "CppOverride.hpp"
```

This way, you only need to pay for the functions you need to override 
and not anything else.

---

## 3. Declare Override Instance

In order to override anything, we need to declare an override instance to store all the 
override information that the function and test can reference from.

#### Global / File Scope (Recommended)
Declaring it in global scope makes it easy to be accessed from both the function and the test.

```cpp
CO_DECLARE_INSTANCE(OverrideObjName);

//Or this if you want to reference an instance defined somewhere else
extern CO_DECLARE_INSTANCE(OverrideObjName);
```

#### Class Scope
Declaring it in class scope is more similar to the traditional mock class approach

You can do so by inheriting from `CppOverride::Overridable`

```cpp
class YourClass : public CppOverride::Overridable
```

In this case, you can just pass `*this` as the override instance, or the instance name you declared 
for the class. 
