#ifndef CO_TEMPLATE_TYPE_SPECIFIER_HPP
#define CO_TEMPLATE_TYPE_SPECIFIER_HPP

namespace CppOverride
{
    template <typename T> struct TypeSpecifier { using Type = T; };
    //template <typename T, typename... Args> struct TypeSpecifier : TypeSpecifier<Args...>
    //{ using Type = T; };
    //template <typename... Args> struct TypeSpecifier { using Type = Args; };
    
}

#endif