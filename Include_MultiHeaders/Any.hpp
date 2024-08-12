#ifndef CO_ANY_HPP
#define CO_ANY_HPP

#include <ostream>

namespace CppOverride
{
    struct Any
    {
        inline bool operator== (Any&) { return true;}
        inline bool operator!= (Any&) { return false; }

        friend std::ostream& operator<<(std::ostream& os, const Any&)
        {
            os << "Any";
            return os;
        }
    };
}

#endif
