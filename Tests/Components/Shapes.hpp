#ifndef CO_SHAPES_HPP
#define CO_SHAPES_HPP

#include "CppOverride.hpp"

class Shape
{
    public:
        CO_DECLARE_MEMBER_INSTANCE(Overrider);
        CO_DECLARE_OVERRIDE_METHODS(Overrider)
    
        virtual float GetArea(float multiplier = 1.f) const = 0;
        virtual float GetPerimeter(float multiplier = 1.f) const = 0;
};

class Rectangle : public Shape
{
    private:
        float Width;
        float Height;
    public:
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
class Square : public Rectangle
{
    private:
        T MetaData;
    
    public:
        inline bool operator ==(const Square& other) const
        {
            return Rectangle::operator==(other) && 
                    GetMetaData() == other.GetMetaData();
        }
        
        inline bool operator !=(const Square& other) const
        {
            return !Square::operator==(other);
        }
        
        inline Square(float size, T metaData) : Rectangle(size, size), MetaData(metaData)
        {}
        
        inline virtual void SetSize(float size)
        {
            CO_OVERRIDE_IMPL(Overrider, void, (size));
            Rectangle::SetWidth(size);
            Rectangle::SetHeight(size);
        }
        
        inline virtual void SetSize(int size)
        {
            CO_OVERRIDE_IMPL(Overrider, void, (size));
            Rectangle::SetWidth(size);
            Rectangle::SetHeight(size);
        }
        
        inline virtual float GetSize(float multiplier = 1.f) const
        {
            CO_OVERRIDE_IMPL(Overrider, float, (multiplier));
            return Rectangle::GetWidth(multiplier);
        }
        
        inline virtual void GetSize(float& outSize, float multiplier = 1.f)
        {
            CO_OVERRIDE_IMPL(Overrider, void, (outSize, multiplier));
            Rectangle::GetWidth(outSize, multiplier);
        }
        
        inline virtual void GetSize(float* outSize, float multiplier = 1.f) const
        {
            CO_OVERRIDE_IMPL(Overrider, void, (outSize, multiplier));
            Rectangle::GetWidth(outSize, multiplier);
        }
        
        void SetMetaData(T metaData)
        {
            CO_OVERRIDE_IMPL(Overrider, void, (metaData));
            MetaData = metaData;
        }
        
        inline virtual T GetMetaData() const
        {
            CO_OVERRIDE_IMPL(Overrider, T, ());
            return MetaData;
        }
        
        inline virtual void GetMetaData(T& outMetaData) const
        {
            CO_OVERRIDE_IMPL(Overrider, void, (outMetaData));
            outMetaData = MetaData;
        }
        
        inline virtual void GetMetaData(T* outMetaData) const
        {
            CO_OVERRIDE_IMPL(Overrider, void, (outMetaData));
            *outMetaData = MetaData;
        }
};




#endif