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
    virtual inline float GetArea(float arg0 = 1.f) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, float, (arg0));
        return float();
    }

    virtual inline float GetPerimeter(float arg0 = 1.f) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, float, (arg0));
        return float();
    }

};

template < typename T > 
class MockSquare : public Shape
{
public:
    template < typename T2 > inline std::tuple < float , T2 > TestTemplateFunc(const std::tuple < float , T2 > & arg0, float arg1 = 1.f) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, (std::tuple < float , T2 >), (arg0, arg1));
        return std::tuple < float , T2 >();
    }

    inline void TestComplexTypes(std::tuple < int , char > arg0, float arg1 = 1.f) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0, arg1));
        return void();
    }

    inline bool operator==(const Square < T > & arg0) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, bool, (arg0));
        return bool();
    }

    inline bool operator!=(const Square < T > & arg0) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, bool, (arg0));
        return bool();
    }

    inline MockSquare(float arg0, T arg1) 
    {
        CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(OverrideObj, (arg0, arg1));
    }

    virtual inline ~MockSquare() 
    {
        CO_OVERRIDE_IMPL_INSTANCE_CTOR_DTOR(OverrideObj, ());
    }

    inline virtual float GetArea(float arg0 = 1.f) const override 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, float, (arg0));
        return float();
    }

    inline virtual float GetPerimeter(float arg0 = 1.f) const override 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, float, (arg0));
        return float();
    }

    inline virtual void SetWidth(float arg0) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0));
        return void();
    }

    inline virtual void SetWidth(int arg0) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0));
        return void();
    }

    inline virtual float GetWidth(float arg0 = 1.f) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, float, (arg0));
        return float();
    }

    inline virtual void GetWidth(float& arg0, float arg1 = 1.f) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0, arg1));
        return void();
    }

    inline virtual void GetWidth(float* arg0, float arg1 = 1.f) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0, arg1));
        return void();
    }

    inline virtual void SetMetaData(T arg0) 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0));
        return void();
    }

    inline virtual T GetMetaData() const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, T, ());
        return T();
    }

    inline virtual void GetMetaData(T& arg0) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0));
        return void();
    }

    inline virtual void GetMetaData(T* arg0) const 
    {
        CO_OVERRIDE_IMPL_INSTANCE(OverrideObj, void, (arg0));
        return void();
    }

};

}
#endif
