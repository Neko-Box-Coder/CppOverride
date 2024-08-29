#ifndef MOCK_SHAPE_HPP
#define MOCK_SHAPE_HPP

#include "CppOverride.hpp"
#include "Shapes.hpp"

extern CO_DECLARE_INSTANCE(OverrideObj);

namespace CppOverrideTest
{

class MockShape
{
public:
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, float, GetArea, (float), virtual, const , (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, float, GetPerimeter, (float), virtual, const , (= 1.f))
};

template < typename T > 
class MockSquare : public Shape
{
public:
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, (std::tuple < float , T2 >), TestTemplateFunc, ((const std::tuple < float , T2 > &), float), template < typename T2 > , /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, TestComplexTypes, ((std::tuple < int , char >), float), /* no prepend */, /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, bool, operator==, (const Square < T > &), /* no prepend */, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, bool, operator!=, (const Square < T > &), /* no prepend */, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD_CTOR(OverrideObj, MockSquare, (float, T), /* no prepend */, /* no append */, (/* no default */, /* no default */))
    CO_OVERRIDE_MEMBER_METHOD_DTOR(OverrideObj, MockSquare, virtual , /* no append */)
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, float, GetArea, (float), virtual, const override, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, float, GetPerimeter, (float), virtual, const override, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, SetWidth, (float), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, SetWidth, (int), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, float, GetWidth, (float), virtual, const, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, GetWidth, (float&, float), virtual, /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, GetWidth, (float*, float), virtual, const, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, SetMetaData, (T), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, T, GetMetaData, (), virtual, const, ())
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, GetMetaData, (T&), virtual, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(OverrideObj, void, GetMetaData, (T*), virtual, const, (/* no default */))
};

}
#endif
