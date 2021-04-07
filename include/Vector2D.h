//
// Created by rafal on 05.04.2021.
//

#ifndef ROTATION2D_VECTOR2D_H
#define ROTATION2D_VECTOR2D_H

#include <iostream>
#include <cmath>

#define DEC_PLACE 3

template<typename T>
class Matrix22;

template<typename T>
class Rectangle;

template<typename T>
class Vector2D{
private:
    T x;
    T y;
public:
    Vector2D();
    Vector2D(T _x, T _y);
    Vector2D(const Vector2D& other) = default;
    Vector2D& operator=(const Vector2D& other) = default;

    template<typename P>
    friend bool operator==(const Vector2D<P>& first, const Vector2D<P>& second);

    template<typename P>
    friend std::ostream& operator<<(std::ostream& os, const Vector2D<P>& vector);

    template<typename P>
    friend std::istream& operator>>(std::istream& os, Vector2D<P>& vector);

    template<typename P>
    friend Vector2D<P> operator*(const Matrix22<P>& mat, const Vector2D<P>& vec);

    template<typename P>
    friend Rectangle<P> operator+(const Vector2D<P>& vec, const Rectangle<P>& rec);

    template<typename P>
    friend Rectangle<P> operator-(const Vector2D<P>& vec, const Rectangle<P>& rec);

    T& operator[](int index);
    const T& operator[](int index) const;
    constexpr Vector2D operator+(const Vector2D<T>& other) const;
    constexpr Vector2D operator-(const Vector2D<T>& other) const;

    constexpr double abs() const;
};

template<typename T>
Vector2D<T>::Vector2D() : x(0), y(0)
{}

template<typename T>
Vector2D<T>::Vector2D(T _x, T _y) : x(_x), y(_y)
{}

template<typename P>
bool operator==(const Vector2D<P>& first, const Vector2D<P>& second)
{
    if (std::abs(first.x - second.x) <= std::pow(10, -DEC_PLACE) && std::abs(first.y - second.y) <= std::pow(10, -DEC_PLACE))
        return true;
    return false;
}

template<typename P>
std::ostream& operator<<(std::ostream& os, const Vector2D<P>& vector)
{
    os << vector.x << " " << vector.y;
    return os;
}

template<typename P>
std::istream& operator>>(std::istream& is, Vector2D<P>& vector)
{
    is >> vector.x >> vector.y;
    return is;
}

template<typename T>
T& Vector2D<T>::operator[](int index)
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Out of vector range");
}

template<typename T>
const T& Vector2D<T>::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else
        throw std::out_of_range("Out of vector range");
}

template<typename T>
constexpr Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& other) const
{
    return Vector2D<T>(x + other.x, y + other.y);
}

template<typename T>
constexpr Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& other) const
{
    return Vector2D<T>(x - other.x, y - other.y);
}

template<typename T>
constexpr double Vector2D<T>::abs() const
{
    return std::sqrt((x * x) + (y * y));
}

#endif //ROTATION2D_VECTOR2D_H
