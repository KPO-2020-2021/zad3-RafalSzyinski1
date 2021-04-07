//
// Created by rafal on 07.04.2021.
//

#include "Transform.h"

#include <cmath>

Transform::Transform()
{
    clear();
}

bool operator==(const Transform& first, const Transform& second)
{
    if ((first.tra == second.tra) && (first.rot == second.rot) && (first.sca == second.sca))
        return true;
    return false;
}

Transform& Transform::rotate(double radian)
{
    double rad = (M_PI / 180) * radian;
    rot = Matrix22<double>(std::cos(rad), -std::sin(rad), std::sin(rad), std::cos(rad));
    return *this;
}

Transform& Transform::translate(Vector2D<double> translation)
{
    tra = translation;
    return *this;
}

Transform& Transform::scale(double _scale)
{
    sca = _scale;
    return *this;
}

Transform& Transform::clear()
{
    tra = Vector2D<double>(0, 0);
    rot = Matrix22<double>(1, 0, 0, 1);
    sca = 1.0;
    return *this;
}