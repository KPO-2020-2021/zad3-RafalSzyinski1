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

/**
 * Method make and save rotation matrix
 * @param degree angle in degrees
 * @return this object
 */
Transform& Transform::rotate(double degree)
{
    double rad = (M_PI / 180) * degree;
    rot = Matrix22<double>(std::cos(rad), -std::sin(rad), std::sin(rad), std::cos(rad));
    return *this;
}

/**
 * Method make and save rotation matrix
 * @param degree angle in degrees
 * @return this object
 */
Transform& Transform::rotateAroundZero(double degree)
{
    double rad = (M_PI / 180) * degree;
    rotArZero = Matrix22<double>(std::cos(rad), -std::sin(rad), std::sin(rad), std::cos(rad));
    return *this;
}

/**
 * Method save translate vector
 * @param translation vector of translation
 * @return this object
 */
Transform& Transform::translate(Vector2D<double> translation)
{
    tra = translation;
    return *this;
}

/**
 * Method save scale
 * @param _scale scale relative to the center
 * @return this object
 */
Transform& Transform::scale(double _scale)
{
    sca = _scale;
    return *this;
}


/**
 * Clear every transform
 * @return this object
 */
Transform& Transform::clear()
{
    tra = Vector2D<double>(0, 0);
    rot = Matrix22<double>(1, 0, 0, 1);
    rotArZero = Matrix22<double>(1, 0, 0, 1);
    sca = 1.0;
    return *this;
}

/**
 * Method transform vector
 * Order of transformation: rotate, translate, scale
 * @param vec Vector2D to transform
 */
void Transform::transform(Vector2D<double>& vec) const
{
    vec = rot * vec;
    vec = tra + vec;
    vec[0] = vec[0] * sca;
    vec[1] = vec[1] * sca;
}

/**
 * Method transform rectangle
 * Order of transformation: rotate, translate, scale, rotateAroundZero
 * @param rec Rectangle to transform
 */
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


