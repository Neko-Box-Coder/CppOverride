#ifndef CO_FILE_FUNCTIONS_HPP
#define CO_FILE_FUNCTIONS_HPP

#include "./Components/DummyClass.hpp"
#include "CppOverride.hpp"

extern CppOverride::Overrider OverrideObj;

inline int FuncWithoutArgs()
{
    CO_OVERRIDE_IMPL(OverrideObj, int, ());
    return -1;
}

inline int FuncWithArgs(int testArg, bool testArg2, float testArg3)
{
    CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
    return -1;
}

inline int FuncWithConstArgs(const int testArg, const bool testArg2, float testArg3)
{
    CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
    return -1;
}

inline void FuncWithArgsToSet(int testArg, float* testArg2, std::string& testArg3)
{
    CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
}

inline void FuncWithConstArgsAndArgsToSet(  const int testArg, 
                                            const float testArg2, 
                                            std::string& testArg3)
{
    CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
}

inline DummyClass ReturnObjectFunc(int data, double value, std::string name)
{
    CO_OVERRIDE_IMPL(OverrideObj, DummyClass, (data, value, name));
    return DummyClass(data, value, name);
}

inline bool SetObjectFunc(int data, double value, std::string name, DummyClass& dummyClass)
{
    CO_OVERRIDE_IMPL(OverrideObj, bool, (data, value, name, dummyClass));
    dummyClass = DummyClass(data, value, name);
    return true;
}

inline int ConstStringRefArgFunc(const std::string& test)
{
    CO_OVERRIDE_IMPL(OverrideObj, int, (test));
    return -1;
}

inline std::string ReturnStringFunc(int value)
{
    CO_OVERRIDE_IMPL(OverrideObj, std::string, (value));
    return "";
}

template<typename T>
inline T ReturnTemplateObjectFunc(T testArg)
{
    CO_OVERRIDE_IMPL(OverrideObj, T, (testArg));
    return testArg;
}

template<typename T>
inline void SetTemplateObjectFunc(T& testArg, T* testArg2)
{
    CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2));
}

static int ReferenceInt = 0;

inline int& ReturnReferenceFunc(int a)
{
    CO_OVERRIDE_IMPL(OverrideObj, int&, (a));
    return ReferenceInt;
}

inline int* ReturnPointerFunc(int a)
{
    CO_OVERRIDE_IMPL(OverrideObj, int*, (a));
    return nullptr;
}

inline void SetNonAssignableArgFunc(NonCopyAssignableDummy* testArg)
{
    CO_OVERRIDE_IMPL(OverrideObj, void, (testArg));
}

inline void SetArgWithConstArgFunc(int* testArg, bool* testArg2, const float* testArg3)
{
    CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
}

inline int ConstVoidPointerFunc(const void* testArg, int testArg2)
{
    CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
    return -1;
}

#endif