#include "SimpleOverride.hpp"
#include "ssTest.hpp"


namespace 
{
    SimpleOverride::Overrider OverrideObj;
}

int FuncWithoutArgs()
{
    SO_RETURN_IF_FOUND(OverrideObj, TestFuncWithoutArgs(), int);
    return -1;
}

int FuncWithArgs(int testArg, bool testArg2, float testArg3)
{
    SO_RETURN_IF_FOUND(OverrideObj, TestFuncWithArgs(int, bool, float), int, testArg, testArg2, testArg3);
    return -1;
}

int FuncWithConstArgs(const int testArg, const bool testArg2, float testArg3)
{
    SO_RETURN_IF_FOUND(OverrideObj, TestFuncWithConstArgs(const int, const bool, float), int, testArg, testArg2, testArg3);
    return -1;
}

void* FuncWIthVoidPointer(int testArg, void* testArg2)
{
    SO_RETURN_IF_FOUND(OverrideObj, TestFuncWIthVoidPointer(int, void*), void*, testArg, testArg2);
    return nullptr;
}

void FuncWithArgsToSet(int testArg, float* testArg2, std::string& testArg3)
{
    SO_MODIFY_ARGS_IF_FOUND(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&), testArg, testArg2, testArg3);
}

void FuncWithConstArgsAndArgsToSet(const int testArg, const float testArg2, std::string& testArg3)
{
    SO_MODIFY_ARGS_IF_FOUND(OverrideObj, TestFuncWithConstArgsAndArgsToSet(const int, const float, std::string&), testArg, testArg2, testArg3);
}

template<typename T>
class ComplexArg
{
    public:
        std::string TestString = "";
        int TestInt = 0;
        float TestFloat = 0.f;
        T TestGenericType;
        
        inline ComplexArg(std::string testString, int testInt, float testFloat, T testGeneric) :    
            TestString(testString), TestInt(testInt), TestFloat(testFloat), TestGenericType(testGeneric)
        {}
        
        inline bool operator== (ComplexArg& other)
        {
            return TestString == other.TestString && TestInt == other.TestInt && TestFloat == other.TestFloat && TestGenericType == other.TestGenericType;
        }
        
        inline bool operator!= (ComplexArg& other)
        {
            return !ComplexArg::operator==(other);
        }
};

class ComplexClass
{
    private:
        ComplexClass(const ComplexClass& other) = delete;
        ComplexClass& operator=(const ComplexClass& other) = delete;
        SO_DECLARE_INSTNACE(CurrentOverrideObj);

    public:
        ComplexClass() = default;
        SO_DECLARE_OVERRIDE_METHODS(CurrentOverrideObj);
    
        inline int ComplexMemberFunction(ComplexArg<char*> charComplex, ComplexArg<std::vector<int>> vectorComplex)
        {
            SO_RETURN_IF_FOUND(CurrentOverrideObj, ComplexMemberFunction(ComplexArg<char*>, ComplexArg<std::vector<int>>), int, charComplex, vectorComplex);
            return -1;
        }
};

int FuncWithNonCopyableNonComparableArg(int testArg, ComplexClass& nonCopyableComparableArg)
{
    SO_RETURN_IF_FOUND( OverrideObj, 
                        TestFuncWithNonCopyableArg(int, ComplexClass&), 
                        int, 
                        testArg, 
                        (SO_NonComparableCopyable<ComplexClass>&)nonCopyableComparableArg);
    return -1;
}

class NonCopyableTestClass
{
    private:
        NonCopyableTestClass(const NonCopyableTestClass& other) = delete;
        NonCopyableTestClass& operator= (const NonCopyableTestClass& other) = delete;
        
    public:
        int A = 0;
    
        NonCopyableTestClass() = default;
        
        inline bool operator== (NonCopyableTestClass& other)
        {
            return A == other.A;
        }
        
        inline bool operator!= (NonCopyableTestClass& other)
        {
            return !NonCopyableTestClass::operator==(other);
        }
};

class NonComparableTestClass
{
    private:
        bool operator== (NonComparableTestClass& other) = delete;
        bool operator!= (NonComparableTestClass& other) = delete;
        
    public:
        int A = 0;
    
        NonComparableTestClass() = default;
        
        inline NonComparableTestClass(const NonComparableTestClass& other)
        {
            A = other.A;
        }
        
        inline NonComparableTestClass& operator= (const NonComparableTestClass& other)
        {
            A = other.A;
            return *this;
        }
};

int FuncWithNonCopyableArg(int testArg, NonCopyableTestClass& nonCopyableArg)
{
    SO_RETURN_IF_FOUND( OverrideObj, 
                        TestFuncWithNonCopyableArg(int, NonCopyableTestClass&), 
                        int, 
                        testArg, 
                        (SO_NonCopyable<NonCopyableTestClass>&)nonCopyableArg);
    
    return -1;
}

void FuncWithNonComparableArg(int testArg, NonComparableTestClass& nonComparableArg)
{
    SO_MODIFY_ARGS_IF_FOUND(   OverrideObj, 
                                    TestFuncWithNonComparableArg(int, NonComparableTestClass&), 
                                    testArg, 
                                    (SO_NonComparable<NonComparableTestClass>&)nonComparableArg);
}

template<typename T>
int TemplateFunction(T testArg)
{
    SO_RETURN_IF_FOUND( OverrideObj, 
                        template<typename T>\
                        int TemplateFunctionTest(T),
                        int,
                        testArg);

    return -1;
}

int main()
{
    ssTEST_INIT();
    
    ssTEST_SET_UP
    {
        OverrideObj = SimpleOverride::Overrider();
    };
    
    ssTEST("Returns Test")
    {
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()).Returns(5);
        
        ssTEST_OUTPUT_ASSERT(FuncWithoutArgs() == 5);
        
        ssTEST_CALL_SET_UP();
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()) .ReturnsByAction<int>
                                                                (
                                                                    [](const std::vector<void*>& args, void* out)
                                                                    {
                                                                        *(static_cast<int*>(out)) = 5;
                                                                    }
                                                                );
        
        ssTEST_OUTPUT_ASSERT("Action", FuncWithoutArgs() == 5);

        ssTEST_CALL_SET_UP();
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()).Times(3);

        ssTEST_OUTPUT_ASSERT("Missing Returns", FuncWithoutArgs() == -1);
    };
    
    ssTEST("Arguments Test")
    {
        float setFloat = 2.f;
        std::string setString = "setString";

        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, setFloat, setString);

        float testFloat = 1.f;
        std::string testString = "";

        FuncWithArgsToSet(3, &testFloat, testString);
        
        ssTEST_OUTPUT_ASSERT(testFloat == setFloat && testString == setString);
        
        ssTEST_CALL_SET_UP();
        testFloat = 1.f;
        testString = "";
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, setFloat, SO_DONT_SET);
        
        FuncWithArgsToSet(3, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("Don't Set", testFloat == setFloat && testString != setString);
        
        ssTEST_CALL_SET_UP();
        testFloat = 1.f;
        testString = "";
        
        #if 0
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET)
                        .SetArgsByAction<float>
                        (
                            [setFloat](const std::vector<void*>& args, void* out)
                            {
                                *(static_cast<float*>(out)) = setFloat;
                            }
                        )
                        .SetArgByAction<std::string>
                        (
                            [setString](const std::vector<void*>& args, void* out)
                            {
                                *(static_cast<std::string*>(out)) = setString;
                            }
                        );
        #endif
        
        FuncWithArgsToSet(3, &testFloat, testString);

        ssTEST_OUTPUT_ASSERT("Action", testFloat == setFloat && testString == setString);
        
        ssTEST_CALL_SET_UP();
        testFloat = 1.f;
        testString = "";
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .Times(3);

        ssTEST_OUTPUT_ASSERT("Missing Arguments", testFloat == 1.f && testString == "");
    };
    
    ssTEST("Times Test")
    {
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()) .Returns(5)
                                                                .Times(2);
        
        ssTEST_OUTPUT_ASSERT("Return",  FuncWithoutArgs() == 5 && FuncWithoutArgs() == 5 && 
                                        FuncWithoutArgs() == -1);
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()) .Returns(3)
                                                                .Times(1);
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithoutArgs()) .Returns(2)
                                                                .Times(1);
        
        ssTEST_OUTPUT_ASSERT("Multiple",    FuncWithoutArgs() == 3 && 
                                            FuncWithoutArgs() == 2 && 
                                            FuncWithoutArgs() == -1);

        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, 3.f, std::string("Test"))
                        .Times(2);
        
        float testFloats[3] = {1.f, 1.f, 1.f};
        std::string testStrings[3] = {"", "", ""};
        
        FuncWithArgsToSet(2, &testFloats[0], testStrings[0]);
        FuncWithArgsToSet(2, &testFloats[1], testStrings[1]);
        FuncWithArgsToSet(2, &testFloats[2], testStrings[2]);
        
        //for(int i = 0; i < 3; i++)
        //{
        //    std::cout << "testFloats[" << i << "]: " << testFloats[i] << std::endl;
        //    std::cout << "testStrings[" << i << "]: " << testStrings[i] << std::endl;
        //}
        
        ssTEST_OUTPUT_ASSERT("SetArgs", testFloats[0] == 3.f && testFloats[1] == 3.f && testFloats[2] == 1.f &&
                                        testStrings[0] == "Test" && testStrings[1] == "Test" && testStrings[2] == "");
    };

    ssTEST("WhenCalledWith Test")
    {
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithArgs(int, bool, float)).Returns(5)
                                                                            .WhenCalledWith(1, true, 3.f);
        
        ssTEST_OUTPUT_ASSERT("Return", FuncWithArgs(1, true, 3.f) == 5);
        
        ssTEST_OUTPUT_ASSERT("Non expected args", FuncWithArgs(1, true, 4.f) == -1);
    
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithArgs(int, bool, float)).Returns(2)
                                                                            .WhenCalledWith(2, true, 3.f);
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithArgs(int, bool, float)).Returns(3)
                                                                            .WhenCalledWith(3, false, 3.f);

        //int result = TestFuncWithArgs(2, true, 3.f);
        //int result2 = TestFuncWithArgs(1, false, 3.f);
        //std::cout << "TestFuncWithArgs(2, true, 3.f): " << result << std::endl;
        //std::cout << "TestFuncWithArgs(1, false, 3.f): " << result2 << std::endl;

        ssTEST_OUTPUT_ASSERT("Multiple",    FuncWithArgs(2, true, 3.f) == 2 && 
                                            FuncWithArgs(3, false, 3.f) == 3);
                                            
        
        SO_OVERRIDE_RETURNS(OverrideObj, TestFuncWithArgs(int, bool, float)).Returns(7)
                                                                            .WhenCalledWith(4, SO_ANY, SO_ANY);
        
        ssTEST_OUTPUT_ASSERT("Any", FuncWithArgs(4, true, 1.f) == 7 && 
                                    FuncWithArgs(4, false, 4.f) == 7 &&
                                    FuncWithArgs(5, true, 4.f) == -1);
        
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_ANY, 3.f, std::string("Test"))
                        .WhenCalledWith(1, 2.f, std::string("Called"));
        
        float testFloat = 2.f;
        std::string testString = "Called";
        FuncWithArgsToSet(1, &testFloat, testString);
        
        ssTEST_OUTPUT_ASSERT("SetArgs", testFloat == 3.f && testString == "Test");
    };
    
    ssTEST("If Test")
    {
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithArgs(int, bool, float))
                            .Returns(5)
                            .If
                            (
                                [](const std::vector<void*>& args) -> bool
                                {
                                    return  args.size() == 3 && 
                                            *static_cast<int*>(args[0]) == 1 &&
                                            *static_cast<bool*>(args[1]) &&
                                            *static_cast<float*>(args[2]) == 3.f;
                                }
                            );

        ssTEST_OUTPUT_ASSERT("Return", FuncWithArgs(1, true, 3.f) == 5);
        ssTEST_OUTPUT_ASSERT("Non expected args", FuncWithArgs(2, true, 3.0f) == -1);
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, 3.f, SO_DONT_SET)
                        .If
                        (
                            [](const std::vector<void*>& args) -> bool
                            {
                                return  args.size() == 3 &&
                                        *static_cast<int*>(args[0]) == 1 &&
                                        **static_cast<float**>(args[1]) == 2.f &&
                                        *static_cast<std::string*>(args[2]) == "Test";
                            }
                        );
        
        float testFloat = 2.f;
        std::string testString = "Test";
        FuncWithArgsToSet(1, &testFloat, testString);
        
        ssTEST_OUTPUT_ASSERT("SetArgs", testFloat == 3.f && testString == "Test");
    };
    
    ssTEST("WhenCalledExpectedly_Do Test")
    {
        bool calledCorrectly = false;
    
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithArgs(int, bool, float))
                            .Returns(5)
                            .WhenCalledWith(1, true, 3.f)
                            .WhenCalledExpectedly_Do
                            (
                                [&calledCorrectly](const std::vector<void*>& args)
                                {
                                    calledCorrectly =   args.size() == 3 && 
                                                        *static_cast<int*>(args[0]) == 1 &&
                                                        *static_cast<bool*>(args[1]) &&
                                                        *static_cast<float*>(args[2]);
                                }
                            );

        FuncWithArgs(2, true, 3.0f);
        ssTEST_OUTPUT_ASSERT("Non expected args", !calledCorrectly);
        
        FuncWithArgs(1, true, 3.f);
        ssTEST_OUTPUT_ASSERT(calledCorrectly);
        
        
        calledCorrectly = false;
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, SO_DONT_SET)
                        .WhenCalledWith(1, 2.f, std::string("Test"))
                        .WhenCalledExpectedly_Do
                        (
                            [&calledCorrectly](const std::vector<void*>& args)
                            {
                                calledCorrectly =   args.size() == 3 &&
                                                    *static_cast<int*>(args[0]) == 1 &&
                                                    **static_cast<float**>(args[1]) == 2.f &&
                                                    *static_cast<std::string*>(args[2]) == "Test";
                            }
                        );
        
        float testFloat = 2.f;
        std::string testString = "Test";
        FuncWithArgsToSet(1, &testFloat, testString);
        
        ssTEST_OUTPUT_ASSERT("SetArgs", calledCorrectly);
    };
    
    ssTEST("Otherwise_Do Test")
    {
        bool calledIncorrectly = false;
    
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithArgs(int, bool, float))
                            .Returns(5)
                            .WhenCalledWith(1, true, 3.f)
                            .Otherwise_Do
                            (
                                [&calledIncorrectly](const std::vector<void*>& args)
                                {
                                    calledIncorrectly = !(args.size() == 3 && 
                                                        *static_cast<int*>(args[0]) == 1 &&
                                                        *static_cast<bool*>(args[1]) &&
                                                        *static_cast<float*>(args[2]));
                                }
                            );
        
        FuncWithArgs(1, true, 3.f);
        ssTEST_OUTPUT_ASSERT("Return", !calledIncorrectly);
        
        FuncWithArgs(2, true, 3.f);
        ssTEST_OUTPUT_ASSERT("Non expected args", calledIncorrectly);
        
        calledIncorrectly = false;
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithArgsToSet(int, float*, std::string&))
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, std::string("What?"))
                        .WhenCalledWith(1, 2.f, std::string("Test"))
                        .Otherwise_Do
                        (
                            [&calledIncorrectly](const std::vector<void*>& args)
                            {
                                calledIncorrectly = args.size() == 3 &&
                                                    *static_cast<int*>(args[0]) == 1 &&
                                                    **static_cast<float**>(args[1]) == 2.f &&
                                                    *static_cast<std::string*>(args[2]) == "Test2";
                            }
                        );
        
        float testFloat = 2.f;
        std::string testString = "Test2";
        FuncWithArgsToSet(1, &testFloat, testString);
        ssTEST_OUTPUT_ASSERT("SetArgs", calledIncorrectly && testString == "Test2");
    };
    
    ssTEST("Complex Test")
    {
        ComplexClass testClass;
        
        char testChar[] = "Test";
        std::vector<int> testIntVec = {1, 2, 3, 4};
        
        ComplexArg<char*> testCharComplex = ComplexArg<char*>("test", 1, 2.f, testChar);
        ComplexArg<std::vector<int>> testIntComplex = ComplexArg<std::vector<int>>("test2", 2, 3.f, testIntVec);
    
        bool callAllow = true;
        
        SO_OVERRIDE_RETURNS (testClass, ComplexMemberFunction(ComplexArg<char*>, ComplexArg<std::vector<int>>))
                            .Returns(5)
                            .WhenCalledWith(testCharComplex, testIntComplex)
                            .If([&callAllow](...){return callAllow;});
        
        ComplexArg<char*> callCharComplex = testCharComplex;
        ComplexArg<std::vector<int>> callIntComplex = testIntComplex;
        
        ssTEST_OUTPUT_ASSERT("Return",  testClass.ComplexMemberFunction(callCharComplex, callIntComplex) == 5);
        
        callAllow = false;
        
        ssTEST_OUTPUT_ASSERT("Return Disallowed",  testClass.ComplexMemberFunction(callCharComplex, callIntComplex) == -1);
        
        callAllow = true;
        callIntComplex.TestGenericType[2] = 4;
        ssTEST_OUTPUT_ASSERT("Return when Not equal",  testClass.ComplexMemberFunction(callCharComplex, callIntComplex) == -1);
        
        SO_OVERRIDE_RETURNS (testClass, ComplexMemberFunction(ComplexArg<char*>, ComplexArg<std::vector<int>>))
                            .ReturnsByAction<int>
                            (
                                [](const std::vector<void*>& args, void* out)
                                {
                                    (*static_cast<int*>(out)) = 6;
                                }
                            )
                            .WhenCalledWith(SO_ANY, SO_ANY);
        
        ssTEST_OUTPUT_ASSERT("Return with Action",  testClass.ComplexMemberFunction(callCharComplex, callIntComplex) == 6);
    };
    
    ssTEST("Const Test")
    {
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithConstArgs(const int, const bool, float))   
                            .Returns(5)
                            .WhenCalledWith(1, true, 3.f);
        
        ssTEST_OUTPUT_ASSERT("Return", FuncWithConstArgs(1, true, 3.f) == 5);
    
        const float constFloat = 4.f;
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithConstArgs(const int, const bool, float))
                            .Returns(6)
                            .WhenCalledWith(1, true, constFloat);
        
        ssTEST_OUTPUT_ASSERT("Return with const passed in", FuncWithConstArgs(1, true, constFloat) == 6);
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithConstArgsAndArgsToSet(const int, const float, std::string&))
                        .SetArgs(SO_DONT_SET, SO_DONT_SET, std::string("Test"))
                        .WhenCalledWith(1, 2.f, SO_ANY);
        
        std::string testString = "";
        FuncWithConstArgsAndArgsToSet(1, 2.f, testString);
        
        ssTEST_OUTPUT_ASSERT("SetArgs", testString == "Test");
    };
    
    ssTEST("Void* Test")
    {
        int returnPtr = 1;
        int testPtr2 = 2;
        
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWIthVoidPointer(int, void*))   
                            .Returns((void*)&returnPtr)
                            .WhenCalledWith(3, (void*)&testPtr2);
        
        ssTEST_OUTPUT_ASSERT(FuncWIthVoidPointer(3, &testPtr2) == &returnPtr);
    };
    
    ssTEST("NonCopyable NonComparable Test")
    {
        ComplexClass testClass;
        
        bool correctPtr = false;
        
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithNonCopyableArg(int, ComplexClass&))
                            .Returns(1)
                            .WhenCalledWith(2, SO_ANY)
                            .WhenCalledExpectedly_Do
                            (
                                [&correctPtr, &testClass](const std::vector<void*>& args)
                                {
                                    if( args.size() == 2 && 
                                        args[1] == &testClass)
                                    {
                                        correctPtr = true;
                                    }
                                }
                            );
        
        ssTEST_OUTPUT_ASSERT(FuncWithNonCopyableNonComparableArg(2, testClass) == 1 && correctPtr);
    };
    
    ssTEST("NonCopyable Test")
    {
        NonCopyableTestClass testClass;
        
        bool correctPtr = false;
        
        SO_OVERRIDE_RETURNS (OverrideObj, TestFuncWithNonCopyableArg(int, NonCopyableTestClass&)) 
                            .Returns(1)
                            .WhenCalledWith(2, SO_NonCopyable<NonCopyableTestClass>(testClass))
                            .WhenCalledExpectedly_Do
                            (
                                [&correctPtr, &testClass](const std::vector<void*>& args)
                                {
                                    if( args.size() == 2 && 
                                        args[1] == &testClass)
                                    {
                                        correctPtr = true;
                                    }
                                }
                            );

        ssTEST_OUTPUT_ASSERT(FuncWithNonCopyableArg(2, testClass) == 1 && correctPtr);
    };

    ssTEST("NonComparable Test")
    {
        NonComparableTestClass testClass;
        NonComparableTestClass setClass;
        setClass.A = 5;
        
        bool correctPtr = false;
        
        SO_OVERRIDE_ARGS(OverrideObj, TestFuncWithNonComparableArg(int, NonComparableTestClass&))
                        .SetArgs(SO_DONT_SET, setClass)
                        .WhenCalledWith(2, SO_ANY)
                        .WhenCalledExpectedly_Do
                        (
                            [&correctPtr, &testClass](const std::vector<void*>& args)
                            {
                                if( args.size() == 2 && 
                                    args[1] == &testClass)
                                {
                                    correctPtr = true;
                                }
                            }
                        );

        FuncWithNonComparableArg(2, testClass);
        
        ssTEST_OUTPUT_ASSERT(testClass.A == setClass.A && correctPtr);
    };
    
    ssTEST("Template Function Test")
    {
        SO_OVERRIDE_RETURNS(OverrideObj,    template<typename T>\
                                            int TemplateFunctionTest(T)).WhenCalledWith(3)
                                                                        .Returns(0);
        
        int result = TemplateFunction(3);
        
        ssTEST_OUTPUT_ASSERT(result == 0);
        
        result = TemplateFunction("test");
        
        ssTEST_OUTPUT_ASSERT("Different argument type", result == -1);
    };

    ssTEST_END();
    
    return 0;
}