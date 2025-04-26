#ifndef MOCK_SHAPE_HPP
#define MOCK_SHAPE_HPP

#include "CppOverride.hpp"
#include "Shapes.hpp"

namespace CppOverrideTest
{

class MockShape : public CppOverride::Overridable
{
public:
    CO_OVERRIDE_MEMBER_METHOD(*this, float, GetArea, (float), virtual, const , (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, float, GetPerimeter, (float), virtual, const , (= 1.f))
};

template < typename T > 
class MockSquare : public Shape, public CppOverride::Overridable
{
public:
    CO_OVERRIDE_MEMBER_METHOD(*this, (std::tuple < float , T2 >), TestTemplateFunc, ((const std::tuple < float , T2 > &), float), template < typename T2 > , /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, TestComplexTypes, ((std::tuple < int , char >), float), /* no prepend */, /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, bool, operator==, (const Square < T > &), /* no prepend */, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, bool, operator!=, (const Square < T > &), /* no prepend */, const, (/* no default */))
    inline MockSquare(...) 
    {
    }

    virtual inline ~MockSquare() 
    {
    }

    CO_OVERRIDE_MEMBER_METHOD(*this, float, GetArea, (float), virtual, const override, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, float, GetPerimeter, (float), virtual, const override, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, SetWidth, (float), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, SetWidth, (int), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, float, GetWidth, (float), virtual, const, (= 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, GetWidth, (float&, float), virtual, /* no append */, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, GetWidth, (float*, float), virtual, const, (/* no default */, = 1.f))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, SetMetaData, (T), virtual, /* no append */, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, T, GetMetaData, (), virtual, const, ())
    CO_OVERRIDE_MEMBER_METHOD(*this, void, GetMetaData, (T&), virtual, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, void, GetMetaData, (T*), virtual, const, (/* no default */))
    CO_OVERRIDE_MEMBER_METHOD(*this, MockSquare&, GetThis, (), virtual, /* no append */, (/* no default */))
};

}
#endif
