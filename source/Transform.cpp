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

Transform& Transform::rotateAroundZero(double radian)
{
    double rad = (M_PI / 180) * radian;
    rotArZero = Matrix22<double>(std::cos(rad), -std::sin(rad), std::sin(rad), std::cos(rad));
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
    rotArZero = Matrix22<double>(1, 0, 0, 1);
    sca = 1.0;
    return *this;
}

//first rotate then translate then scale
void Transform::transform(Vector2D<double>& vec) const
{
    vec = rot * vec;
    vec = tra + vec;
    vec[0] = vec[0] * sca;
    vec[1] = vec[1] * sca;
}

//first rotate then translate then scale
void Transform::transform(Rectangle<double>& rec) const
{
    Vector2D<double> center = rec.getCenter();
    std::vector<Vector2D<double>> vertex(4);
    for (int i = 0; i < 4; i++)
        vertex[i] = rec[i] - center;
    for(auto& i : vertex)
        transform(i);
    center = rec.getCenter();
    for(int i = 0; i < 4; i++)
        rec[i] = rotArZero * (vertex[i] + center);
}


