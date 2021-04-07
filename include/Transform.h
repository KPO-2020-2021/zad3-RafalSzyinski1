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
    double sca;
public:
    Transform();
    Transform(const Transform& other) = default;
    Transform& operator=(const Transform& other) = default;

    friend bool operator==(const Transform& first, const Transform& second);

    Transform& rotate(double radian);
    Transform& translate(Vector2D<double> translation);
    Transform& scale(double _scale);
    Transform& clear();

    template<typename T>
    void transform(Rectangle<T>& rec) const;

    template<typename T>
    void transform(Vector2D<T>& vec) const;
};


//first rotate then translate then scale
template<typename T>
void Transform::transform(Vector2D<T>& vec) const
{
    vec = rot * vec;
    vec = tra + vec;
    vec[0] = vec[0] * sca;
    vec[1] = vec[1] * sca;
}

//first rotate then translate then scale
template<typename T>
void Transform::transform(Rectangle<T>& rec) const
{
    Vector2D<T> center = rec.getCenter();
    std::vector<Vector2D<T>> vertex;
    for (int i = 0; i < 4; i++)
        vertex.push_back(rec[i] - center);
    for(auto& i : vertex)
        transform(i);
    center = rec.getCenter();
    for(int i = 0; i < 4; i++)
        rec[i] = vertex[i] + center;
}

#endif //ROTATION2D_TRANSFORM_H
