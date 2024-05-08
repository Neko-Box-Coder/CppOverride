#ifndef CO_DUMMY_CLASS_HPP
#define CO_DUMMY_CLASS_HPP

#include <iostream>

class DummyClass {
    private:
        int data;
        double value;
        std::string name;

    public:
        // Constructor
        DummyClass() : data(0), value(0.0), name("") { }
        DummyClass(int d, double v, std::string n) : data(d), value(v), name(n) {}

        DummyClass(const DummyClass& other)
        {
            *this = other;
        }

        // Comparison operator
        inline bool operator==(const DummyClass& other) const 
        {
            return (data == other.data) && (value == other.value) && (name == other.name);
        }
        
        inline bool operator!=(const DummyClass& other) const
        {
            return !DummyClass::operator==(other);
        }
        
        inline DummyClass& operator=(const DummyClass& other) 
        {
            data = other.data;
            value = other.value;
            name = other.name;
            return *this;
        }
        
        inline void SetData(int d)
        {
            data = d;
        }
        
        inline int GetData() const 
        {
            return data;
        }
        
        inline void SetValue(double v) 
        {
            value = v;
        }

        inline double GetValue() const 
        {
            return value;
        }
        
        inline void SetName(const std::string& n)
        {
            name = n;
        }

        inline std::string GetName() const 
        {
            return name;
        }
};

template <typename T>
class TemplateTestClass : public DummyClass
{
    private:
        T GenericTestData;
    
    public:
        inline TemplateTestClass() :   
            DummyClass(),
            GenericTestData()
        {}
        
        //Copy constructor using assignment operator
        inline TemplateTestClass(const TemplateTestClass<T>& other) : DummyClass()
        {
            *this = other;
        }
        
        inline TemplateTestClass(T genericData, int d, double v, std::string n) :   
            DummyClass(d, v, n),
            GenericTestData(genericData)
        {}
        
        inline TemplateTestClass(T genericData) :   DummyClass(),
                                                GenericTestData(genericData)
        {}
        
        //Assignment operator
        inline TemplateTestClass<T>& operator=(const TemplateTestClass<T>& other)
        {
            DummyClass::operator=(other);
            GenericTestData = other.GenericTestData;
            return *this;
        }

        inline bool operator ==(const TemplateTestClass<T>& other) const
        {
            return  DummyClass::operator==(other) && 
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

class NonCopyableTestClass
{
    private:
        int TestData;
    
    public:
        inline NonCopyableTestClass() :    
                                              TestData(0)
        {}
        
        inline NonCopyableTestClass(int testData) :   
                                                        TestData(testData)
        {}
        
        inline NonCopyableTestClass(const NonCopyableTestClass& other)
        {
            TestData = other.TestData;
        }
        
        inline NonCopyableTestClass& operator=(const NonCopyableTestClass& other) = delete;
        
        inline bool operator!=(const NonCopyableTestClass& other) = delete;
        
        inline void SetTestData(int testData)
        {
            TestData = testData;
        }
        
        inline int GetTestData() const
        {
            return TestData;
        }
};

class NonComparableTestClass
{
    private:
        int TestData;
    
    public:
        inline NonComparableTestClass() :   
                                        TestData(0)
        {}
        
        inline NonComparableTestClass(int testData) :   
                                                    TestData(testData)
        {}
        
        inline NonComparableTestClass(const NonComparableTestClass& other)
        {
            *this = other.TestData;
        }
        
        inline NonComparableTestClass& operator=(const NonComparableTestClass& other) 
        {
            
            TestData = other.TestData;
            return *this;
        }
        
        inline bool operator==(const NonComparableTestClass& other) = delete;
        inline bool operator!=(const NonComparableTestClass& other) = delete;
        
        inline void SetTestData(int testData)
        {
            TestData = testData;
        }
        
        inline int GetTestData() const
        {
            return TestData;
        }
};


#endif