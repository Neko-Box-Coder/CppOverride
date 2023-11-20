#ifndef SO_NON_COPYABLE_TEST_CLASS_HPP
#define SO_NON_COPYABLE_TEST_CLASS_HPP

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

#endif