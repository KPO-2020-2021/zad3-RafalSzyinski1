//
// Created by rafal on 06.04.2021.
//

#ifndef ROTATION2D_MATRIX22_H
#define ROTATION2D_MATRIX22_H

#include "Vector2D.h"

template<typename T>
class Rectangle;

template<typename T>
class Matrix22{
private:
    Vector2D<T> x;
    Vector2D<T> y;
public:
    Matrix22();
    Matrix22(T _x1, T _x2, T _y1, T _y2);
    Matrix22(Vector2D<T> _x, Vector2D<T> _y);
    Matrix22(const Matrix22& other) = default;
    Matrix22& operator=(const Matrix22& other) = default;

    template<typename P>
    friend bool operator==(const Matrix22<P>& first, const Matrix22<P>& second);

    template<typename P>
    friend std::ostream& operator<<(std::ostream& os, const Matrix22<P>& matrix);

    template<typename P>
    friend std::istream& operator>>(std::istream& is, Matrix22<P>& matrix);

    template<typename P>
    friend Vector2D<P> operator*(const Matrix22<P>& mat, const Vector2D<P>& vec);

    template<typename P>
    friend Rectangle<P> operator*(const Matrix22<P>& mat, const Rectangle<P>& rec);

    Vector2D<T>& operator[](int index);
    const Vector2D<T>& operator[](int index) const;
};

template<typename T>
Matrix22<T>::Matrix22() : x(), y()
{}

template<typename T>
Matrix22<T>::Matrix22(T _x1, T _x2, T _y1, T _y2) : x(_x1, _x2), y(_y1, _y2)
{}

template<typename T>
Matrix22<T>::Matrix22(Vector2D<T> _x, Vector2D<T> _y) : x(_x), y(_y)
{}

template<typename P>
bool operator==(const Matrix22<P>& first, const Matrix22<P>& second)
{
    if (first.x == second.x && first.y == second.y)
        return true;
    return false;
}

template<typename P>
std::ostream& operator<<(std::ostream& os, const Matrix22<P>& matrix)
{
    os << matrix.x << std::endl << matrix.y;
    return os;
}

template<typename P>
std::istream& operator>>(std::istream& is, Matrix22<P>& matrix)
{
    is >> matrix.x >> matrix.y;
    return is;
}

template<typename P>
Vector2D<P> operator*(const Matrix22<P>& mat, const Vector2D<P>& vec)
{
    return Vector2D<P>(mat[0][0] * vec[0] + mat[0][1] * vec[1], mat[1][0] * vec[0] + mat[1][1] * vec[1]);
}

template<typename T>
Vector2D<T>& Matrix22<T>::operator[](int index)
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Out of matrix range");
}

template<typename T>
const Vector2D<T>& Matrix22<T>::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Out of matrix range");
}
#endif //ROTATION2D_MATRIX22_H
