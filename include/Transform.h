//
// Created by rafal on 07.04.2021.
//

#ifndef ROTATION2D_TRANSFORM_H
#define ROTATION2D_TRANSFORM_H

#include "Rectangle.h"
#include <vector>


class Transform
{
private:
    Vector2D<double> tra;
    Matrix22<double> rot;
    Matrix22<double> rotArZero;
    double sca;
public:
    Transform();
    Transform(const Transform& other) = default;
    Transform& operator=(const Transform& other) = default;

    friend bool operator==(const Transform& first, const Transform& second);

    Transform& rotate(double degree);
    Transform& rotateAroundZero(double degree);
    Transform& translate(Vector2D<double> translation);
    Transform& scale(double _scale);
    Transform& clear();

    void transform(Rectangle<double>& rec) const;
    void transform(Vector2D<double>& vec) const;
};

#endif //ROTATION2D_TRANSFORM_H
