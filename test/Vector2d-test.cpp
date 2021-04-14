//
// Created by rafal on 05.04.2021.
//

#include "gtest/gtest.h"
#include "Vector2D.h"

#include <sstream>

TEST (Vector2D_test, equal_operator)
{
    Vector2D<int> a(1, 2);
    EXPECT_TRUE(a == Vector2D<int>(1, 2));
    EXPECT_FALSE(a == Vector2D<int>(1, 3));

    Vector2D<double> b(1, 5);
    EXPECT_TRUE(b == Vector2D<double>(1.00000000000000003, 5.00000000000000000000001));
    EXPECT_FALSE(b == Vector2D<double>(1.0000000000000003, 4.00000000000000001));
}

TEST (Vector2D_test, constructor)
{
    Vector2D<int> a(1,1);
    EXPECT_EQ(a, Vector2D<int>(1, 1));

    Vector2D<double> b;
    EXPECT_EQ(b, Vector2D<double>(0, 0));
}

TEST (Vector2D_test, abs)
{
    Vector2D<int> a(3, 4);
    EXPECT_EQ(a.abs(), 5);

    Vector2D<int> b(1, 3);
    EXPECT_NEAR(b.abs(), 3.1622776, 0.000001);

    Vector2D<double> c(5.5, 4.3);
    EXPECT_NEAR(c.abs(), 6.98140, 0.00001);
}

TEST (Vector2D_test, index_operator)
{
    Vector2D<int> a(1, 2);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
    EXPECT_THROW(a[4], std::out_of_range);
}

TEST (Vector2D_test, sum_operator)
{
    Vector2D<int> a(1, 2);
    Vector2D<int> b(3, 4);
    EXPECT_EQ(a + b, Vector2D<int>(4, 6));

    Vector2D<double> c(1.123, 4.321);
    Vector2D<double> d(4.321, 1.123);
    EXPECT_EQ(c + d, Vector2D<double>(5.444, 5.444));
}

TEST (Vector2D_test, diff_operator)
{
    Vector2D<int> a(1, 2);
    Vector2D<int> b(3, 4);
    EXPECT_EQ(a - b, Vector2D<int>(-2, -2));

    Vector2D<double> c(1.123, 4.321);
    Vector2D<double> d(4.321, 1.123);
    EXPECT_EQ(c - d, Vector2D<double>(-3.198, 3.198));
}

TEST (Vector2D_test, ostream)
{
    Vector2D<double> a(2, 2);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "2.0000000000 2.0000000000");
}

TEST (Vector2D_test, istream)
{
    Vector2D<double> a;
    std::stringstream ss;
    ss << "1 2";
    ss >> a;
    EXPECT_EQ(a, Vector2D<double>(1, 2));

    Vector2D<double> b;
    ss = std::stringstream();
    ss << "1.123 3.321";
    ss >> b;
    EXPECT_EQ(b, Vector2D<double>(1.123, 3.321));
}