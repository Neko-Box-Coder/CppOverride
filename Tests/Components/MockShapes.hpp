#ifndef MOCK_SHAPE_HPP
#define MOCK_SHAPE_HPP

#include "CppOverride.hpp"
#include "Shapes.hpp"

namespace CppOverrideTest
{

class MockShape : public CppOverride::Overridable
{
public:
    CO_OVERRIDE_METHOD(virtual, float, GetArea, (float), (= 1.f), const )
    CO_OVERRIDE_METHOD(virtual, float, GetPerimeter, (float), (= 1.f), const )
};

template < typename T > 
class MockSquare : public Shape, public CppOverride::Overridable
{
public:
    CO_OVERRIDE_METHOD(template < typename T2 > , (std::tuple < float , T2 >), TestTemplateFunc, ((const std::tuple < float , T2 > &), float), (/* no default */, = 1.f), /* no append */)
    CO_OVERRIDE_METHOD(/* no prepend */, void, TestComplexTypes, ((std::tuple < int , char >), float), (/* no default */, = 1.f), /* no append */)
    CO_OVERRIDE_METHOD(/* no prepend */, bool, operator==, (const Square < T > &), (/* no default */), const)
    CO_OVERRIDE_METHOD(/* no prepend */, bool, operator!=, (const Square < T > &), (/* no default */), const)
    inline MockSquare(...) 
    {
    }

    virtual inline ~MockSquare() 
    {
    }

    CO_OVERRIDE_METHOD(virtual, float, GetArea, (float), (= 1.f), const override)
    CO_OVERRIDE_METHOD(virtual, float, GetPerimeter, (float), (= 1.f), const override)
    CO_OVERRIDE_METHOD(virtual, void, SetWidth, (float), (/* no default */), /* no append */)
    CO_OVERRIDE_METHOD(virtual, void, SetWidth, (int), (/* no default */), /* no append */)
    CO_OVERRIDE_METHOD(virtual, float, GetWidth, (float), (= 1.f), const)
    CO_OVERRIDE_METHOD(virtual, void, GetWidth, (float&, float), (/* no default */, = 1.f), /* no append */)
    CO_OVERRIDE_METHOD(virtual, void, GetWidth, (float*, float), (/* no default */, = 1.f), const)
    CO_OVERRIDE_METHOD(virtual, void, SetMetaData, (T), (/* no default */), /* no append */)
    CO_OVERRIDE_METHOD(virtual, T, GetMetaData, (), (), const)
    CO_OVERRIDE_METHOD(virtual, void, GetMetaData, (T&), (/* no default */), const)
    CO_OVERRIDE_METHOD(virtual, void, GetMetaData, (T*), (/* no default */), const)
};

}
#endif
