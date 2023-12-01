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
class TemplateDummy : public DummyClass
{
    private:
        T GenericData;
    
    public:
        inline TemplateDummy() :   
            DummyClass(),
            GenericData()
        {}
        
        //Copy constructor using assignment operator
        inline TemplateDummy(const TemplateDummy<T>& other) : DummyClass()
        {
            *this = other;
        }
        
        inline TemplateDummy(T genericData, int d, double v, std::string n) :   
            DummyClass(d, v, n),
            GenericData(genericData)
        {}
        
        inline TemplateDummy(T genericData) :   DummyClass(),
                                                GenericData(genericData)
        {}
        
        //Assignment operator
        inline TemplateDummy<T>& operator=(const TemplateDummy<T>& other)
        {
            DummyClass::operator=(other);
            GenericData = other.GenericData;
            return *this;
        }

        inline bool operator ==(const TemplateDummy<T>& other) const
        {
            return  DummyClass::operator==(other) && 
                    GenericData == other.GenericData;
        }
        
        inline bool operator!=(const TemplateDummy<T>& other) const
        {
            return !TemplateDummy<T>::operator==(other);
        }
        
        inline void SetGenericData(T genericData)
        {
            GenericData = genericData;
        }
        
        inline T GetGenericData() const
        {
            return GenericData;
        }
};

class NonCopyAssignableDummy
{
    private:
        int TestData;
    
    public:
        inline NonCopyAssignableDummy() :    
                                              TestData(0)
        {}
        
        inline NonCopyAssignableDummy(int testData) :   
                                                        TestData(testData)
        {}
        
        inline NonCopyAssignableDummy(const NonCopyAssignableDummy& other)
        {
            TestData = other.TestData;
        }
        
        inline NonCopyAssignableDummy& operator=(const NonCopyAssignableDummy& other) = delete;
        
        inline bool operator!=(const NonCopyAssignableDummy& other) = delete;
        
        inline void SetTestData(int testData)
        {
            TestData = testData;
        }
        
        inline int GetTestData() const
        {
            return TestData;
        }
};

class NonComparableDummy
{
    private:
        int TestData;
    
    public:
        inline NonComparableDummy() :   
                                        TestData(0)
        {}
        
        inline NonComparableDummy(int testData) :   
                                                    TestData(testData)
        {}
        
        inline NonComparableDummy(const NonComparableDummy& other)
        {
            *this = other.TestData;
        }
        
        inline NonComparableDummy& operator=(const NonComparableDummy& other) 
        {
            
            TestData = other.TestData;
            return *this;
        }
        
        inline bool operator==(const NonComparableDummy& other) = delete;
        inline bool operator!=(const NonComparableDummy& other) = delete;
        
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