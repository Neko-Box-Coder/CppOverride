#ifndef CO_CPP_OVERRIDE_HPP
#define CO_CPP_OVERRIDE_HPP


#include "./CppOverrideInstance.hpp"
#include "./OverrideInfoSetterImplementation.hpp"
#include "./Macros.hpp"
#include "./AliasTypes.hpp"

namespace CppOverride
{
    class MockClass
    {
        protected:
            CO_DECLARE_MEMBER_INSTANCE(CurrentOverrideInstance);
        
        public:
            CO_DECLARE_OVERRIDE_METHODS(CurrentOverrideInstance);
    };
}

#endif