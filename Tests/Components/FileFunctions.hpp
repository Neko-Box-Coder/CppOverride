#ifndef CO_FILE_FUNCTIONS_HPP
#define CO_FILE_FUNCTIONS_HPP

#include "./TestClasses.hpp"
#include "CppOverride.hpp"

extern CppOverride::Overrider OverrideObj;

namespace CppOverrideTest
{
    namespace NonConst
    {
        //Used In:
        //  ModifyReturnsTests
        //  TimesTests
        inline int NoArgsFunc()
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, ());
            return -1;
        }

        //Used In:
        //  IfTests
        //  WhenCalledWithTests
        inline int ArgsFunc(int testArg, bool testArg2, float testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
            return -1;
        }

        //Used In:
        //  IfTests
        //  ModifyArgsTests
        //  TimesTests
        //  WhenCalledWithTests
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
        //  WhenCalledWithTests
        inline void MoreArgsToSetFunc(int testArg, float* testArg2, bool* testArg3, std::string& testArg4)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3, testArg4));
        }
        
        //Used In:
        //  ModifyReturnsTests
        inline std::string ReturnStringFunc(int value)
        {
            CO_OVERRIDE_IMPL(OverrideObj, std::string, (value));
            return "";
        }
        
        //Used In:
        //  ModifyArgsTests
        inline int AddNumFromVoidPointerFunc(void* testArg, int testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
            return (*(int*)testArg) + testArg2;
        }
        
        //Used In:
        //  MixedModifyArgsAndReturnsTest
        inline int AddNumFromNumPointerFunc(int* testArg, int testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
            return *testArg + testArg2;
        }
        
        //Used In:
        //  ModifyArgsTests
        //  ModifyReturnsTests
        inline void AssignArgInternallyFunc(std::string testArg, std::string& testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2));
            testArg2 = testArg;
        }

        static int ReferenceInt = 0;

        //Used In:
        //  ModifyReturnsTests
        inline int& ReturnReferenceFunc(int a)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int&, (a));
            return ReferenceInt;
        }

        //Used In:
        //  ModifyReturnsTests
        inline int* ReturnPointerFunc(int a)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int*, (a));
            return nullptr;
        }
        
        //Used In:
        //  ArrayParamTests
        inline int IntArrayParameterFunc(int nums[4])
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (nums));
            return nums[0];
        }
        
        //Used In:
        //  ArrayParamTests
        inline int CharArrayParameterFunc(char chars[4])
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (chars));
            return (int)(chars[0]);
        }
        
        inline bool CompoundedNonComparableParameterFunc(std::vector<NonComparableTestClass>& outArg)
        {
            CO_OVERRIDE_IMPL(OverrideObj, bool, (outArg));
            return true;
        }
        
        namespace Object
        {
            //Used In:
            //  ModifyReturnsTests
            inline TestClass ReturnObjectFunc(int data, double value, std::string name)
            {
                CO_OVERRIDE_IMPL(OverrideObj, TestClass, (data, value, name));
                return TestClass();
            }
            
            //Used In:
            //  ModifyArgsTests
            //  WhenCalledWithTests
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
            //Used In:
            //  ModifyReturnsTests
            //  WhenCalledWithTests
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
            
            //Used In:
            //  ArrayParamTests
            template<typename T>
            inline int TemplateArgRefFunc(T& testArg)
            {
                CO_OVERRIDE_IMPL(OverrideObj, int, (testArg));
                return 0;
            }
        }
    }
    
    namespace Const
    {
        //Used In:
        inline int ConstArgsFunc(const int testArg, const bool testArg2, float testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2, testArg3));
            return -1;
        }

        //Used In:
        //  Otherwise_DoTests
        //  WhenCalledExpectedly_DoTests
        inline void ConstArgsAndArgsToSetFunc(  const int testArg, 
                                                const float testArg2, 
                                                std::string& testArg3)
        {
            CO_OVERRIDE_IMPL(OverrideObj, void, (testArg, testArg2, testArg3));
        }

        //Used In:
        //  WhenCalledWithTests
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

        //Used In:
        //  WhenCalledWithTests
        inline int ConstVoidPointerFunc(const void* testArg, int testArg2)
        {
            CO_OVERRIDE_IMPL(OverrideObj, int, (testArg, testArg2));
            return -1;
        }
    }
}


#endif
