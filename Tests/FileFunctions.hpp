#ifndef CO_FILE_FUNCTIONS_HPP
#define CO_FILE_FUNCTIONS_HPP

#include "./Components/DummyClass.hpp"
#include "CppOverride.hpp"

extern CppOverride::Overrider OverrideObj;

inline int FuncWithoutArgs()
{
    CO_RETURN_IF_FOUND(OverrideObj, FuncWithoutArgs(), int);
    return -1;
}

inline int FuncWithArgs(int testArg, bool testArg2, float testArg3)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        FuncWithArgs(int, bool, float), 
                        int, 
                        testArg, 
                        testArg2, 
                        testArg3);
    return -1;
}

inline int FuncWithConstArgs(const int testArg, const bool testArg2, float testArg3)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        FuncWithConstArgs(const int, const bool, float), 
                        int, 
                        testArg, 
                        testArg2, 
                        testArg3);
    return -1;
}

inline void FuncWithArgsToSet(int testArg, float* testArg2, std::string& testArg3)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            FuncWithArgsToSet(int, float*, std::string&), 
                            testArg, 
                            testArg2, 
                            testArg3);
}

inline void FuncWithConstArgsAndArgsToSet(  const int testArg, 
                                            const float testArg2, 
                                            std::string& testArg3)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            FuncWithConstArgsAndArgsToSet(  const int, 
                            const float, 
                            std::string&), 
                            testArg, 
                            testArg2, 
                            testArg3);
}

inline DummyClass ReturnObjectFunc(int data, double value, std::string name)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            ReturnObjectFunc(int, double, std::string), 
                            data,
                            value,
                            name);
    
    CO_RETURN_IF_FOUND( OverrideObj,
                        ReturnObjectFunc(int, double, std::string),
                        DummyClass,
                        data,
                        value,
                        name);

    return DummyClass(data, value, name);
}

inline bool SetObjectFunc(int data, double value, std::string name, DummyClass& dummyClass)
{
    CO_MODIFY_ARGS_AND_RETURN_IF_FOUND( OverrideObj, 
                                        true,
                                        SetObjectFunc(int, double, std::string, DummyClass&), 
                                        data, 
                                        value, 
                                        name, 
                                        dummyClass);

    CO_RETURN_IF_FOUND( OverrideObj,
                        SetObjectFunc(int, double, std::string, DummyClass&),
                        bool,
                        data,
                        value,
                        name,
                        dummyClass);
    
    dummyClass = DummyClass(data, value, name);
    return true;
}

inline int ConstStringRefArgFunc(const std::string& test)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        ConstStringRefArgFunc(const std::string&), 
                        int, 
                        test);
    return -1;
}

inline std::string ReturnStringFunc(int value)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        ReturnStringFunc(int), 
                        std::string, 
                        value);
    
    return "";
}

template<typename T>
inline T ReturnTemplateObjectFunc(T testArg)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        ReturnTemplateObjectFunc(T), 
                        T, 
                        testArg);

    return testArg;
}

template<typename T>
inline void SetTemplateObjectFunc(T& testArg, T* testArg2)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            SetTemplateObjectFunc(T&, T*),
                            testArg,
                            testArg2);
}

static int ReferenceInt = 0;

inline int& ReturnReferenceFunc(int a)
{
    CO_RETURN_REF_IF_FOUND( OverrideObj, 
                            ReturnReferenceFunc(int), 
                            int&, 
                            a);

    return ReferenceInt;
}

inline int* ReturnPointerFunc(int a)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        ReturnPointerFunc(int), 
                        int*, 
                        a);

    return nullptr;
}

inline void SetNonAssignableArgFunc(NonCopyAssignableDummy* testArg)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            SetNonAssignableArgFunc(NonCopyAssignableDummy*), 
                            testArg);
}

inline void SetArgWithConstArgFunc(int* testArg, bool* testArg2, const float* testArg3)
{
    CO_MODIFY_ARGS_IF_FOUND(OverrideObj, 
                            SetArgWithConstArgFunc(int*, bool*, const float*), 
                            testArg, 
                            testArg2, 
                            testArg3);
}

inline int ConstVoidPointerFunc(const void* testArg, int testArg2)
{
    CO_RETURN_IF_FOUND( OverrideObj, 
                        ConstVoidPointerFunc(const void*, int), 
                        int, 
                        testArg, 
                        testArg2);

    return -1;
}

#endif