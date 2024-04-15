#ifndef CO_FILE_FUNCTIONS_HPP
#define CO_FILE_FUNCTIONS_HPP

#include "./TestClasses.hpp"
#include "CppOverride.hpp"

extern CppOverride::Overrider OverrideObj;

namespace CppOverrideTest
{
    namespace NonConst
    {
        inline int NoArgsFunc()
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, ());
            return -1;
        }

        //Used In:
        //  IfTests
        inline int ArgsFunc(int testArg, bool testArg2, float testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
            return -1;
        }

        //Used In:
        //  IfTests
        //  ModifyArgsTests
        inline void ArgsToSetFunc(int testArg, float* testArg2, std::string& testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }
        
        //Used In:
        //  ModifyArgsTests
        inline void ArgsToSetFunc(int testArg, float& testArg2, float* testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }
        
        //Used In:
        //  ModifyArgsTests
        inline void MoreArgsToSetFunc(int testArg, float* testArg2, bool* testArg3, std::string& testArg4)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3, testArg4));
        }
        
        inline std::string ReturnStringFunc(int value)
        {
            CO_OVERRIDE_IMPL(OverrideObj, std::string, (value));
            return "";
        }
        
        inline int VoidPointerFunc(void* testArg, int testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
            return -1;
        }
        
        inline void AssignArgInternallyFunc(std::string testArg, std::string& testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2));
            testArg2 = testArg;
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
        
        namespace Object
        {
            inline TestClass ReturnObjectFunc(int data, double value, std::string name)
            {
                CO_OVERRIDE_IMPL(OverrideObj, TestClass, (data, value, name));
                return TestClass();
            }
            
            //Used In:
            //  ModifyArgsTests
            inline bool SetObjectFunc(int data, double value, std::string name, TestClass& testClass)
            {
                CO_OVERRIDE_IMPL(OverrideObj, bool, (data, value, name, testClass));
                return false;
            }
            
            //Used In:
            //  ModifyArgsTests
            inline void SetNonCopyableArgFunc(NonCopyableTestClass* testClass)
            {
                CO_OVERRIDE_IMPL(OverrideObj, void, (testClass));
            }
        }
        
        namespace Template
        {
            template<typename T>
            inline T TemplateReturnFunc(T testArg)
            {
                CO_OVERRIDE_IMPL(OverrideObj, T, (testArg));
                return testArg;
            }

            //Used In:
            //  ModifyArgsTests
            template<typename T>
            inline void TemplateSetArgFunc(T& testArg, T* testArg2)
            {
                CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2));
            }
        }
    }
    
    namespace Const
    {
        inline int ConstArgsFunc(const int testArg, const bool testArg2, float testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
            return -1;
        }

        inline void ConstArgsAndArgsToSetFunc(  const int testArg, 
                                                const float testArg2, 
                                                std::string& testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }

        inline int ConstStringRefArgFunc(const std::string& test)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (test));
            return -1;
        }
        
        //Used In:
        //  ModifyArgsTests
        inline void SetEndConstArgFunc(int* testArg, bool* testArg2, const float* testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }
        
        //Used In:
        //  ModifyArgsTests
        inline void SetBeginConstArgFunc(const int* testArg, bool* testArg2, float* testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }

        inline int ConstVoidPointerFunc(const void* testArg, int testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
            return -1;
        }
    }
}


#endif