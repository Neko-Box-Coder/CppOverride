#ifndef SO_ANY_HPP
#define SO_ANY_HPP

#include <ostream>

namespace SimpleOverride
{
    struct Any
    {
        inline bool operator== (Any& other)
        {
            return true;
        }
        
        inline bool operator!= (Any& other)
        {
            return false;
        }

        friend std::ostream& operator<<(std::ostream& os, const Any& other)
        {
            os << "Any";
            return os;
        }
    };
}

#endif