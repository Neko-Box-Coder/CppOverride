#ifndef SO_CLASS_FUNCTIONS_HPP
#define SO_CLASS_FUNCTIONS_HPP

#include "SimpleOverride.hpp"

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
        SO_DECLARE_MEMBER_INSTNACE(Overrider);
        SO_DECLARE_OVERRIDE_METHODS(Overrider)
        
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
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetWidth(float), 
                                    width);

            Width = width;
        }
        
        inline virtual void SetWidth(int width)
        {
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetWidth(int), 
                                    width);

            Width = width;
        }
        
        inline virtual float GetWidth(float multiplier = 1.f) const
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetWidth(float), 
                                float,
                                multiplier);

            return Width * multiplier;
        }
        
        inline virtual void SetHeight(float height)
        {
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetHeight(float), 
                                    height);
            
            Height = height;
        }
        
        inline virtual void SetHeight(int height)
        {
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetHeight(int), 
                                    height);
            
            Height = height;
        }
        
        inline virtual float GetHeight(float multiplier = 1.f) const
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetHeight(float), 
                                float,
                                multiplier);
            
            return Height * multiplier;
        }
        
        inline virtual float GetArea(float multiplier = 1.f) const override
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetArea(float), 
                                float,
                                multiplier);
            
            return Width * Height;
        }
        
        inline virtual float GetPerimeter(float multiplier = 1.f) const override
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetPerimeter(float), 
                                float,
                                multiplier);
            
            return 2.f * (Width + Height);
        }
};

template<typename T>
class Square : public Rectangle
{
    private:
        T MetaData;
    
    public:
        SO_DECLARE_MEMBER_INSTNACE(Overrider);
        SO_DECLARE_OVERRIDE_METHODS(Overrider)
        
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
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetSize(float), 
                                    size);
            
            Rectangle::SetWidth(size);
            Rectangle::SetHeight(size);
        }
        
        inline virtual void SetSize(int size)
        {
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetSize(int), 
                                    size);
            
            Rectangle::SetWidth(size);
            Rectangle::SetHeight(size);
        }
        
        inline virtual float GetSize(float multiplier = 1.f) const
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetSize(float), 
                                float,
                                multiplier);
            
            return Rectangle::GetWidth(multiplier);
        }
        
        void SetMetaData(T metaData)
        {
            SO_MODIFY_ARGS_IF_FOUND(Overrider, 
                                    SetMetaData(T), 
                                    metaData);
            
            MetaData = metaData;
        }
        
        inline virtual T GetMetaData() const
        {
            SO_RETURN_IF_FOUND( Overrider, 
                                GetMetaData(), 
                                T);
            
            return MetaData;
        }
};




#endif