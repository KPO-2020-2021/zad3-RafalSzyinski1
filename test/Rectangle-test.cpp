//
// Created by rafal on 06.04.2021.
//

#include "gtest/gtest.h"
#include "Rectangle.h"

#include <cmath>

TEST (Rectangle_test, equal_operator)
{
    Rectangle<int> a(1, 1, 1, -1, -1, 1, -1, -1);
    EXPECT_TRUE(a == Rectangle<int>(1, 1, 1, -1, -1, 1, -1, -1));

    Rectangle<double> b(Vector2D<double>(1.1, 1.1), Vector2D<double>(1.1, -1.1), Vector2D<double>(-1.1, 1.1), Vector2D<double>(-1.1, -1.1));
    EXPECT_TRUE(b == Rectangle<double>(1.1, 1.1, 1.1, -1.1, -1.1, 1.1, -1.1, -1.1));
}

TEST (Rectangle_test, construct)
{
    Rectangle<int> a;
    EXPECT_EQ(a, Rectangle<int>(0, 0, 0, 0, 0, 0, 0, 0));

    Rectangle<int> b(1, 1, 1, -1, -1, 1, -1, -1);
    EXPECT_EQ(b, Rectangle<int>(1, 1, 1, -1, -1, 1, -1, -1));

    Rectangle<double> c(Vector2D<double>(1.1, 1.1), Vector2D<double>(1.1, -1.1), Vector2D<double>(-1.1, 1.1), Vector2D<double>(-1.1, -1.1));
    EXPECT_EQ(c, Rectangle<double>(1.1, 1.1, 1.1, -1.1, -1.1, 1.1, -1.1, -1.1));
}

TEST (Rectangle_test, index_operator)
{
    Rectangle<int> a(1, 1, 2, 2, 3, 3, 4, 4);
    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(a[3][1], 4);
    EXPECT_THROW(a[5][3], std::out_of_range);
}

TEST (Rectangle_test, ostream)
{
    Rectangle<int> a(1, 1, 1, 1, 1, 1, 1, 1);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1 1\n1 1\n1 1\n1 1");
}

TEST(Rectangle_test, mat_mulit_rec)
{
    Matrix22<double> a(1, 0, 0, 1);
    Rectangle<double> b(1, 1, 1, 1, 1, 1, 1, 1);

    EXPECT_EQ(a * b, b);

    Matrix22<double> c(1, 1, 1, 1);
    Rectangle<double> d(1, 1, 1, 1, 1, 1, 1, 1);

    EXPECT_EQ(c * d, Rectangle<double>(2, 2, 2, 2, 2, 2, 2, 2));
}

TEST (Rectangle_test, rec_plus_vec)
{
    Vector2D<int> a(5, 5);
    Rectangle<int> b(0, 0, 1, 0, 1, 1, 0, 1);
    EXPECT_EQ(a + b, Rectangle<int>(5, 5, 6, 5, 6, 6, 5, 6));
}

TEST (Rectangle_test, rec_mnius_vec)
{
    Vector2D<int> a(5, 5);
    Rectangle<int> b(0, 0, 1, 0, 1, 1, 0, 1);
    EXPECT_EQ(a - b, Rectangle<int>(-5, -5, -4, -5, -4, -4, -5, -4));
}

TEST (Rectangle_test, centerOfMass)
{
    Rectangle<double> a(1, 2, 2, 1, 4, 2, 3, 3);
    EXPECT_EQ(a.getCenter(), Vector2D<double>(2.5, 2));
}

TEST (Rectangle_test, sizeOfSides)
{
    Rectangle<double> a(0, 0, 2, 0, 2, 3, 0, 3);
    auto b = a.getSizeOfSides();
    EXPECT_EQ(b[0], 2);
    EXPECT_EQ(b[1], 3);
    EXPECT_EQ(b[2], 2);
    EXPECT_EQ(b[3], 3);
}