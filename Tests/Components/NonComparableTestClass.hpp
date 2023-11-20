#ifndef SO_NON_COMPARABLE_TEST_CLASS_HPP
#define SO_NON_COMPARABLE_TEST_CLASS_HPP

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

#endif