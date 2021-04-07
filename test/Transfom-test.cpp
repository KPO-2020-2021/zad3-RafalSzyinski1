//
// Created by rafal on 07.04.2021.
//

#include "gtest/gtest.h"
#include "Transform.h"

TEST (Transform_test, constructor)
{
    Transform t1;
    EXPECT_EQ(t1, Transform());
}

TEST (Transform_test, rotate)
{
    Transform t1;
    t1.rotate(90);
    Vector2D<double> a(1, 2);
    t1.transform(a);
    EXPECT_EQ(a, Vector2D<double>(-2, 1));
}

TEST (Transform_test, scale)
{
    Transform t1;
    t1.scale(2);
    Vector2D<double> a(1, 2);
    t1.transform(a);
    EXPECT_EQ(a, Vector2D<double>(2, 4));
}

TEST (Transform_test, translate)
{
    Transform t1;
    t1.translate(Vector2D<double>(1, 2));
    Vector2D<double> a(1, 1);
    t1.transform(a);
    EXPECT_EQ(a, Vector2D<double>(2, 3));
}

TEST (Transform_test, clear)
{
    Transform t1;
    t1.scale(2).rotate(45);
    t1.clear();
    EXPECT_EQ(t1, Transform());
}

TEST (Transform_test, transfrom_vector)
{
    Transform t1;
    t1.rotate(90).translate(Vector2D<double>(1,1)).scale(2);
    Vector2D<double> a(1, 1);
    t1.transform(a);

    EXPECT_EQ(a, Vector2D<double>(0, 4));
}

TEST (Transform_test, transform_rectangle)
{
    Transform t1;
    t1.translate(Vector2D<double>(1, 1));
    Rectangle<double> a(0, 0, 1, 0, 1, 1, 0, 1);
    t1.transform(a);
    EXPECT_EQ(a, Rectangle<double>(1, 1, 2, 1, 2, 2, 1, 2));
}

TEST (Transform_test, equal_operator)
{
    Transform t1, t2, t3;
    t1.rotate(15).scale(5).translate(Vector2D<double>(1,1));
    t2.rotate(15).scale(5).translate(Vector2D<double>(1,1));

    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

