#ifndef __VEC2_HPP__
#define __VEC2_HPP__

#include <cmath>

namespace prim
{
    template<class T>
    class Vec2
    {
    public:
        T x{};       
        T y{};

        Vec2() = default;
        Vec2(T v) : Vec2(v, v) {}
        Vec2(T x, T y) : x(x), y(y) {}

        inline float lengthSq() const
        {
            return x*x + y*y;
        }

        inline float length() const
        {
            return std::sqrt(lengthSq());
        }

        inline float dot(const Vec2<T> rhs) const
        {
            return x * rhs.x + y * rhs.y;
        }

        inline bool operator==(const Vec2<T>& rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }
        inline Vec2<T> operator*(const T& scalar) const
        {
            return Vec2<T>(x * scalar, y * scalar);
        }
        inline Vec2<T> operator/(const T& scalar) const
        {
            return Vec2<T>(x / scalar, y / scalar);
        }
        inline Vec2<T>& operator*=(const T& scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }
        inline Vec2<T>& operator/=(const T& scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }
        inline Vec2<T> operator+(const Vec2<T>& rhs) const
        {
            return Vec2<T>(x + rhs.x, y + rhs.y);
        }
        inline Vec2<T> operator-(const Vec2<T>& rhs) const
        {
            return Vec2<T>(x - rhs.x, y - rhs.y);
        }
        inline Vec2<T> operator*(const Vec2<T>& rhs) const
        {
            return Vec2<T>(x * rhs.x, y * rhs.y);
        }
        inline Vec2<T> operator/(const Vec2<T>& rhs) const
        {
            return Vec2<T>(x / rhs.x, y / rhs.y);
        }
        inline Vec2<T> rotate(float angle)
        {
            float cos = std::cos(angle);
            float sin = std::sin(angle);
            return {x * cos - y * sin, x * sin + y * cos };
        }
    };

    typedef Vec2<float> Vec2f;
    typedef Vec2<int> Vec2i;
    typedef Vec2<unsigned int> Vec2u;
}

#endif // __VEC2_HPP__