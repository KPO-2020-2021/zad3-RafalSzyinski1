//
// Created by rafal on 06.04.2021.
//

#ifndef ROTATION2D_RECTANGLE_H
#define ROTATION2D_RECTANGLE_H

#include "Vector2D.h"
#include "Matrix22.h"


template<typename T>
class Rectangle
{
private:
    Vector2D<T> a;
    Vector2D<T> b;
    Vector2D<T> c;
    Vector2D<T> d;
public:
    Rectangle();
    Rectangle(Vector2D<T> _a, Vector2D<T> _b, Vector2D<T> _c, Vector2D<T> _d);
    Rectangle(T _a1, T _a2, T _b1, T _b2, T _c1, T _c2, T _d1, T _d2);
    Rectangle(const Rectangle<T>& other) = default;
    Rectangle& operator=(const Rectangle<T>& other) = default;

    template<typename P>
    friend bool operator==(const Rectangle<P>& first, const Rectangle<P>& second);

    template<typename P>
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<P>& rec);

    template<typename P>
    friend Rectangle<P> operator*(const Matrix22<P>& mat, const Rectangle<P>& rec);

    template<typename P>
    friend Rectangle<P> operator+(const Vector2D<P>& vec, const Rectangle<P>& rec);

    template<typename P>
    friend Rectangle<P> operator-(const Vector2D<P>& vec, const Rectangle<P>& rec);

    Vector2D<T>& operator[](int index);
    const Vector2D<T>& operator[](int index) const;

    constexpr Vector2D<T> getCenter() const;
};

template<typename T>
Rectangle<T>::Rectangle() : a(), b(), c(), d()
{}

template<typename T>
Rectangle<T>::Rectangle(Vector2D<T> _a, Vector2D<T> _b, Vector2D<T> _c, Vector2D<T> _d) : a(_a), b(_b), c(_c), d(_d)
{}

template<typename T>
Rectangle<T>::Rectangle(T _a1, T _a2, T _b1, T _b2, T _c1, T _c2, T _d1, T _d2) : a(_a1, _a2), b(_b1, _b2), c(_c1, _c2), d(_d1, _d2)
{}

template<typename P>
bool operator==(const Rectangle<P>& first, const Rectangle<P>& second)
{
    if ((first.a == second.a) && (first.b == second.b) && (first.c == second.c) && (first.d == second.d))
        return true;
    return false;
}

template<typename P>
std::ostream& operator<<(std::ostream& os, const Rectangle<P>& rec)
{
    os << rec.a << std::endl;
    os << rec.b << std::endl;
    os << rec.c << std::endl;
    os << rec.d;
    return os;
}

template<typename P>
Rectangle<P> operator*(const Matrix22<P>& mat, const Rectangle<P>& rec)
{
    return Rectangle<P>(mat * rec.a, mat * rec.b, mat * rec.c, mat * rec.d);
}

template<typename P>
Rectangle<P> operator+(const Vector2D<P>& vec, const Rectangle<P>& rec)
{
    return Rectangle<P>(rec.a + vec, rec.b + vec, rec.c + vec, rec.d + vec);
}

template<typename P>
Rectangle<P> operator-(const Vector2D<P>& vec, const Rectangle<P>& rec)
{
    return Rectangle<P>(rec.a - vec, rec.b - vec, rec.c - vec, rec.d - vec);
}

template<typename T>
Vector2D<T> & Rectangle<T>::operator[](int index)
{
    if (index == 0)
        return a;
    else if (index == 1)
        return b;
    else if (index == 2)
        return c;
    else if (index == 3)
        return d;
    else
        throw std::out_of_range("Out of rectangle range");
}

template<typename T>
const Vector2D<T> & Rectangle<T>::operator[](int index) const
{
    if (index == 0)
        return a;
    else if (index == 1)
        return b;
    else if (index == 2)
        return c;
    else if (index == 3)
        return d;
    else
        throw std::out_of_range("Out of rectangle range");
}

template<typename T>
constexpr Vector2D<T> Rectangle<T>::getCenter() const
{
    Vector2D<T> ret;
    ret = ret + a + b + c + d;
    ret[0] = ret[0] / 4;
    ret[1] = ret[1] / 4;
    return ret;
}

#endif //ROTATION2D_RECTANGLE_H
