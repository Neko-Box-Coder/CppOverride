#ifndef SO_COMPLEX_CLASS_HPP
#define SO_COMPLEX_CLASS_HPP

#include "SimpleOverride.hpp"
#include "./ComplexArg.hpp"

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

#endif