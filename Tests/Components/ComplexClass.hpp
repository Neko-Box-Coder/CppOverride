#ifndef CO_COMPLEX_CLASS_HPP
#define CO_COMPLEX_CLASS_HPP

#include "CppOverride.hpp"
#include "./ComplexArg.hpp"

class ComplexClass
{
    private:
        ComplexClass(const ComplexClass& other) = delete;
        ComplexClass& operator=(const ComplexClass& other) = delete;
        CO_DECLARE_INSTNACE(CurrentOverrideObj);

    public:
        ComplexClass() = default;
        CO_DECLARE_OVERRIDE_METHODS(CurrentOverrideObj);
    
        inline int ComplexMemberFunction(ComplexArg<char*> charComplex, ComplexArg<std::vector<int>> vectorComplex)
        {
            CO_RETURN_IF_FOUND(CurrentOverrideObj, ComplexMemberFunction(ComplexArg<char*>, ComplexArg<std::vector<int>>), int, charComplex, vectorComplex);
            return -1;
        }
};

#endif