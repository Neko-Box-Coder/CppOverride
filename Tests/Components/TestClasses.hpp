#ifndef CO_TEST_CLASSES_HPP
#define CO_TEST_CLASSES_HPP

#include <iostream>

class TestClass {
    private:
        int TestData;
        double TestData2;
        std::string TestData3;

    public:
        // Constructor
        TestClass() : TestData(0), TestData2(0.0), TestData3("") { }
        TestClass(int d, double v, std::string n) : TestData(d), TestData2(v), TestData3(n) {}

        TestClass(const TestClass& other)
        {
            *this = other;
        }

        // Comparison operator
        inline bool operator==(const TestClass& other) const 
        {
            return  (TestData == other.TestData) && 
                    (TestData2 == other.TestData2) && 
                    (TestData3 == other.TestData3);
        }
        
        inline bool operator!=(const TestClass& other) const
        {
            return !TestClass::operator==(other);
        }
        
        inline TestClass& operator=(const TestClass& other) 
        {
            TestData = other.TestData;
            TestData2 = other.TestData2;
            TestData3 = other.TestData3;
            return *this;
        }
        
        inline void SetTestData(int d)
        {
            TestData = d;
        }
        
        inline int GetTestData() const 
        {
            return TestData;
        }
        
        inline void SetTestData2(double v) 
        {
            TestData2 = v;
        }

        inline double GetTestData2() const 
        {
            return TestData2;
        }
        
        inline void SetTestData3(const std::string& n)
        {
            TestData3 = n;
        }

        inline std::string GetTestData3() const 
        {
            return TestData3;
        }
};

template <typename T>
class TemplateTestClass : public TestClass
{
    private:
        T GenericTestData;
    
    public:
        inline TemplateTestClass() :    TestClass(), 
                                        GenericTestData()
        {}
        
        //Copy constructor using assignment operator
        inline TemplateTestClass(const TemplateTestClass<T>& other) : TestClass()
        {
            *this = other;
        }
        
        inline TemplateTestClass(T genericData, int d, double v, std::string n) :   
            TestClass(d, v, n),
            GenericTestData(genericData)
        {}
        
        inline TemplateTestClass(T genericData) :   TestClass(),
                                                    GenericTestData(genericData)
        {}
        
        //Assignment operator
        inline TemplateTestClass<T>& operator=(const TemplateTestClass<T>& other)
        {
            TestClass::operator=(other);
            GenericTestData = other.GenericTestData;
            return *this;
        }

        inline bool operator==(const TemplateTestClass<T>& other) const
        {
            return  TestClass::operator==(other) && 
                    GenericTestData == other.GenericTestData;
        }
        
        inline bool operator!=(const TemplateTestClass<T>& other) const
        {
            return !TemplateTestClass<T>::operator==(other);
        }
        
        inline void SetGenericTestData(T genericData)
        {
            GenericTestData = genericData;
        }
        
        inline T GetGenericTestData() const
        {
            return GenericTestData;
        }
};

class NonCopyableTestClass : public TestClass
{
    public:
        inline NonCopyableTestClass() : TestClass()
        {}
        
        inline NonCopyableTestClass(const NonCopyableTestClass& other) = delete;
        inline NonCopyableTestClass& operator=(const NonCopyableTestClass& other) = delete;
        
        inline bool operator==(const NonCopyableTestClass& other) const
        {
            return TestClass::operator==(other);
        }
        
        inline bool operator!=(const NonCopyableTestClass& other) const
        {
            return !NonCopyableTestClass::operator==(other);
        }
};

class NonComparableTestClass : public TestClass
{
    public:
        inline NonComparableTestClass() : TestClass()
        {}
        
        inline NonComparableTestClass(const NonComparableTestClass& other) : TestClass(other)
        {
            TestClass::operator=(other);
        }
        
        inline NonComparableTestClass& operator=(const NonComparableTestClass& other)
        {
            TestClass::operator=(other);
            return *this;
        }
        
        inline bool operator==(const NonComparableTestClass& other) const = delete;
        inline bool operator!=(const NonComparableTestClass& other) const = delete;
};

class ImmutableTestClass : public TestClass
{
    public:
        inline ImmutableTestClass() : TestClass()
        {}
        
        inline ImmutableTestClass(const ImmutableTestClass& other) = delete;
        inline ImmutableTestClass& operator=(const ImmutableTestClass& other) = delete;
        inline bool operator==(const ImmutableTestClass& other) const = delete;
        inline bool operator!=(const ImmutableTestClass& other) const = delete;
};


#endif