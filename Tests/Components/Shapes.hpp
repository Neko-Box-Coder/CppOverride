#ifndef CO_SHAPES_HPP
#define CO_SHAPES_HPP

#include "CppOverride.hpp"

#include <tuple>

namespace CppOverrideTest
{
    class Shape
    {
        public:
            virtual float GetArea(float multiplier = 1.f) const = 0;
            virtual float GetPerimeter(float multiplier = 1.f) const = 0;
    };

    class Rectangle : public Shape
    {
        private:
            float Width;
            float Height;
        
        public:
            CO_DECLARE_MEMBER_INSTANCE(Overrider);
            CO_DECLARE_OVERRIDE_METHODS(Overrider);
        
            inline bool operator ==(const Rectangle& other) const
            {
                return GetWidth() == other.GetWidth() && 
                        GetHeight() == other.GetHeight();
            }
            
            inline bool operator !=(const Rectangle& other) const
            {
                return !Rectangle::operator==(other);
            }
            
            inline Rectangle(float width, float height) : Width(width), Height(height)
            {}
            
            virtual inline ~Rectangle(){}
            
            inline virtual void SetWidth(float width)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (width));
                Width = width;
            }
            
            inline virtual void SetWidth(int width)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (width));
                Width = width;
            }
            
            inline virtual float GetWidth(float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, float, (multiplier));
                return Width * multiplier;
            }
            
            inline virtual void GetWidth(float& outWidth, float multiplier = 1.f)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outWidth, multiplier));
                outWidth = Width * multiplier;
            }
            
            inline virtual void GetWidth(float* outWidth, float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outWidth, multiplier));
                *outWidth = Width * multiplier;
            }
            
            inline virtual void SetHeight(float height)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (height));
                Height = height;
            }
            
            inline virtual void SetHeight(int height)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (height));
                Height = height;
            }
            
            inline virtual float GetHeight(float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, float, (multiplier));
                return Height * multiplier;
            }
            
            inline virtual void GetHeight(float& outHeight, float multiplier = 1.f)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outHeight, multiplier));
                outHeight = Height * multiplier;
            }
            
            inline virtual void GetHeight(float* outHeight, float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outHeight, multiplier));
                *outHeight = Height * multiplier;
            }
            
            inline virtual float GetArea(float multiplier = 1.f) const override
            {
                CO_OVERRIDE_IMPL(Overrider, float, (multiplier));
                return Width * Height;
            }
            
            inline virtual void GetArea(float& outArea, float multiplier = 1.f)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outArea, multiplier));
                outArea = Width * Height;
            }
            
            inline virtual void GetArea(float* outArea, float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outArea, multiplier));
                *outArea = Width * Height;
            }
            
            inline virtual float GetPerimeter(float multiplier = 1.f) const override
            {
                CO_OVERRIDE_IMPL(Overrider, float, (multiplier));
                return 2.f * (Width + Height);
            }
            
            inline virtual void GetPerimeter(float& outPerimeter, float multiplier = 1.f)
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outPerimeter, multiplier));
                outPerimeter = 2.f * (Width + Height);
            }
            
            inline virtual void GetPerimeter(float* outPerimeter, float multiplier = 1.f) const
            {
                CO_OVERRIDE_IMPL(Overrider, void, (outPerimeter, multiplier));
                *outPerimeter = 2.f * (Width + Height);
            }
    };

    template<typename T>
    class Square : public Shape
    {
        private:
            T MetaData;
            float Width;
        
        public:
            template<typename T2>
            inline std::tuple<float, T2> TestTemplateFunc(  const std::tuple<float, T2>& testTuple, 
                                                            float testFloat = 1.f)
            {
                std::tuple<float, T2> copy(testTuple);
                std::get<0>(copy) += testFloat;
                return copy;
            }
        
            inline void TestComplexTypes(   std::tuple<int, char> testTuple, 
                                            float testFloat = 1.f)
            {
                (void)testTuple;
                (void)testFloat;
            }
        
            inline bool operator ==(const Square<T>& other) const
            {
                return  Width == other.Width && GetMetaData() == other.GetMetaData();
            }
            
            inline bool operator !=(const Square<T>& other) const
            {
                return !Square::operator==(other);
            }
            
            inline Square(float width, T metaData) : Width(width), MetaData(metaData)
            {}
            
            virtual inline ~Square(){}
            
            inline virtual float GetArea(float multiplier = 1.f) const override
            {
                return Width * Width * multiplier;
            }
            
            inline virtual float GetPerimeter(float multiplier = 1.f) const override
            {
                return 2.f * (Width + Width) * multiplier;
            }
            
            inline virtual void SetWidth(float width)
            {
                Width = width;
            }
            
            inline virtual void SetWidth(int width)
            {
                Width = width;
            }
            
            inline virtual float GetWidth(float multiplier = 1.f) const
            {
                return Width * multiplier;
            }
            
            inline virtual void GetWidth(float& outWidth, float multiplier = 1.f)
            {
                outWidth = Width * multiplier;
            }
            
            inline virtual void GetWidth(float* outWidth, float multiplier = 1.f) const
            {
                *outWidth = Width * multiplier;
            }
            
            inline virtual void SetMetaData(T metaData)
            {
                MetaData = metaData;
            }
            
            inline virtual T GetMetaData() const
            {
                return MetaData;
            }
            
            inline virtual void GetMetaData(T& outMetaData) const
            {
                outMetaData = MetaData;
            }
            
            inline virtual void GetMetaData(T* outMetaData) const
            {
                *outMetaData = MetaData;
            }
    };
}

#endif
