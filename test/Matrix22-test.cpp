//
// Created by rafal on 06.04.2021.
//

#include "gtest/gtest.h"

#include "Matrix22.h"

TEST (Matrix22_test, equal_operator)
{
    Matrix22<int> a(2, 2, 2, 2);
    EXPECT_TRUE(a == Matrix22<int>(2, 2, 2, 2));
    EXPECT_FALSE(a == Matrix22<int>(1, 2, 2, 2));

    Matrix22<double> b(2.00000000000000001, 2.000000000000001, 2.000000000000002, 2.000000000000003);
    EXPECT_TRUE(b == Matrix22<double>(2., 2., 2., 2.));
    EXPECT_FALSE(b == Matrix22<double>(2.1, 2.1, 2.1, 2.1));
}

TEST (Matrix22_test, constructors)
{
    Matrix22<int> a(2, 2, 2, 2);
    EXPECT_EQ(a, Matrix22<int>(2, 2, 2 ,2));

    Vector2D<int> b1(1, 1);
    Vector2D<int> b2(2, 2);
    Matrix22<int> b(b1, b2);
    EXPECT_EQ(b, Matrix22<int>(1, 1, 2, 2));

    Matrix22<double> c;
    EXPECT_EQ(c, Matrix22<double>(0, 0, 0, 0));
}

TEST (Matrix22_test, index_operator)
{
    Matrix22<int> a(2, 2, 1, 1);
    EXPECT_EQ(a[0], Vector2D<int>(2, 2));
    EXPECT_EQ(a[1], Vector2D<int>(1, 1));
    EXPECT_EQ(a[1][1], 1);
    EXPECT_THROW(a[4], std::out_of_range);
}

TEST (Matrix22_test, ostream)
{
    Matrix22<double> a(1.123, 2.123, 3.123, 4.123);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1.1230000000 2.1230000000\n3.1230000000 4.1230000000");
}

TEST (Matrix22_test, istream)
{
    Matrix22<int> a;
    std::stringstream ss;
    ss << "1 2\n3 4";
    ss >> a;
    EXPECT_EQ(a, Matrix22<int>(1, 2, 3, 4));

    Matrix22<double> b;
    ss = std::stringstream();
    ss << "1.123 3.321\n3.321 1.123";
    ss >> b;
    EXPECT_EQ(b, Matrix22<double>(1.123, 3.321, 3.321, 1.123));
}

TEST (Matrix22_test, matrix_multi_vec)
{
    Vector2D<int> a(3, 4);
    Matrix22<int> b(1, 0, 0, 1);
    EXPECT_EQ(b * a, Vector2D<int>(3, 4));

    Vector2D<double> c(1.123, 3.321);
    Matrix22<double> d(1.1, 2.2, 3.3, 4.4);
    EXPECT_EQ(d * c, Vector2D<double>(8.5415, 18.3183));
}