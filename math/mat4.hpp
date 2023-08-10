#ifndef __MAT4_HPP__
#define __MAT4_HPP__


template<class T>
class Mat4
{
public:
    T mat[4, 4];

    inline Mat4<T> operator+(const Mat4<T>& rhs)
    {
        Mat4 result;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                result[i, j] = mat[i, j] + rhs[i, j];
            }
        }
        return result;
    }

    inline Mat4<T> operator-(const Mat4<T>& rhs)
    {
        Mat4 result;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                result[i, j] = mat[i, j] - rhs[i, j];
            }
        }
        return result;
    }

    inline Mat4<T> operator*(const Mat4<T>& rhs)
    {
        Mat4 result;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                for(int k = 0; k < 4; ++k)
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
        for(int j = 0; j < 4; ++j)
        {
            float one = (1 + j) / 2 == 0 ? 1.0f : -1.0;
            
        }
        return result;
    }
};

#endif // __MAT4_HPP__