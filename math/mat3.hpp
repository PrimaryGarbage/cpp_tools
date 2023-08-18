#ifndef __MAT3_HPP__
#define __MAT3_HPP__

namespace prim
{
    template<class T>
    class Mat3
    {
    public:
        T mat[3, 3];

        explicit Mat3() = default;
        explicit Mat3(T mat[3, 3])
        {
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    this->mat[i, j] = mat[i, j];
        }

        inline Mat3<T> operator+(const Mat3<T>& rhs)
        {
            Mat3 result;
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    result[i, j] = mat[i, j] + rhs[i, j];
                }
            }
            return result;
        }

        inline Mat3<T> operator-(const Mat3<T>& rhs)
        {
            Mat3 result;
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    result[i, j] = mat[i, j] - rhs[i, j];
                }
            }
            return result;
        }

        inline Mat3<T> operator*(const Mat3<T>& rhs)
        {
            Mat3 result;
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    for(int k = 0; k < 3; ++k)
                    {
                        result[i, j] = mat[i, k] + rhs[k, j];
                    }
                }
            }
            return result;
        }

        inline float determinant()
        {
            float result;
            const int i = 0;
            for(int j = 0; j < 3; ++j)
            {
                float one = (1 + j) / 2 == 0 ? 1.0f : -1.0;
            }
            return result;
        }
    };
}

#endif // __MAT3_HPP__