#ifndef CO_COMPLEX_ARG_HPP
#define CO_COMPLEX_ARG_HPP

#include <string>
template<typename T>
class ComplexArg
{
    public:
        std::string TestString = "";
        int TestInt = 0;
        float TestFloat = 0.f;
        T TestGenericType;
        
        inline ComplexArg(  std::string testString, 
                            int testInt, 
                            float testFloat, 
                            T testGeneric) :    TestString(testString), 
                                                TestInt(testInt), 
                                                TestFloat(testFloat), 
                                                TestGenericType(testGeneric)
        {}
        
        inline bool operator== (ComplexArg& other)
        {
            return  TestString == other.TestString && 
                    TestInt == other.TestInt && 
                    TestFloat == other.TestFloat && 
                    TestGenericType == other.TestGenericType;
        }
        
        inline bool operator!= (ComplexArg& other)
        {
            return !ComplexArg::operator==(other);
        }
};

#endif