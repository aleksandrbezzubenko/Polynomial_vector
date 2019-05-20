// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <polynomial.hpp>

TEST(Polynomial, Init) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    EXPECT_EQ(p[0], 1);
    EXPECT_EQ(p[1], 2);
    EXPECT_EQ(p[2], 3);
    EXPECT_EQ(p[3], 4);
}

TEST(Polynomial, CopyAssign) {
    Polynomial<int> p(4);
    Polynomial<int> copy(p);
    EXPECT_EQ(p, copy);

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    EXPECT_NE(p, copy);

    copy = p;
    EXPECT_EQ(p, copy);
}

TEST(Polynomial, Add) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<int> c = p;

    Polynomial<int> s = p + c;
    Polynomial<int> s2 = c + c;
    EXPECT_EQ(s2, s);

    ASSERT_EQ(s.Degree(), 4);
    EXPECT_EQ(s[0], 2);
    EXPECT_EQ(s[1], 4);
    EXPECT_EQ(s[2], 6);
    EXPECT_EQ(s[3], 8);
}

TEST(Polynomial, AddInEnd) {
    Polynomial<float> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<float> c(3);
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;

    Polynomial<float> s = p + c;
    Polynomial<float> s1 = c + p;
    EXPECT_EQ(s1, s);

    ASSERT_EQ(s.Degree(), 4);
    EXPECT_EQ(s[0], 1);
    EXPECT_EQ(s[1], 3);
    EXPECT_EQ(s[2], 5);
    EXPECT_EQ(s[3], 7);
}

TEST(Polynomial, Sub) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<int> c = p;

    Polynomial<int> s = p - c;
    Polynomial<int> s2 = c - c;
    EXPECT_EQ(s2, s);

    ASSERT_EQ(s.Degree(), 4);
    EXPECT_EQ(s[0], 0);
    EXPECT_EQ(s[1], 0);
    EXPECT_EQ(s[2], 0);
    EXPECT_EQ(s[3], 0);
}

TEST(Polynomial, SubFromEnd) {
    Polynomial<float> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<float> c(3);
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;

    Polynomial<float> s = p - c;

    ASSERT_EQ(s.Degree(), 4);
    EXPECT_EQ(s[0], 1);
    EXPECT_EQ(s[1], 1);
    EXPECT_EQ(s[2], 1);
    EXPECT_EQ(s[3], 1);
}

TEST(Polynomial, Mult) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<int> c(4);
    c[0] = 4;
    c[1] = 3;
    c[2] = 2;
    c[3] = 1;

    Polynomial<int> s = p * c;

    ASSERT_EQ(s.Degree(), 7);
    EXPECT_EQ(s[0], 4);
    EXPECT_EQ(s[1], 11);
    EXPECT_EQ(s[2], 20);
    EXPECT_EQ(s[3], 30);
    EXPECT_EQ(s[4], 20);
    EXPECT_EQ(s[5], 11);
    EXPECT_EQ(s[6], 4);
}

TEST(Polynomial, MultByNumber) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    int a = 3;

    Polynomial<int> s = p * a;

    ASSERT_EQ(s.Degree(), 4);
    EXPECT_EQ(s[0], 3);
    EXPECT_EQ(s[1], 6);
    EXPECT_EQ(s[2], 9);
    EXPECT_EQ(s[3], 12);
}

TEST(Polynomial, Division) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<int> c(4);
    c[0] = 4;
    c[1] = 3;
    c[2] = 2;
    c[3] = 1;

    Polynomial<int> s = p * c;
    Polynomial<int> s1 = s / p;
    EXPECT_EQ(s1, c);
}

TEST(Polynomial, DivisionWithRemainder) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    Polynomial<int> c(4);
    c[0] = 4;
    c[1] = 3;
    c[2] = 2;
    c[3] = 1;

    Polynomial<int> s = p * c;
    s[3] += 3;
    s[4] += 1;
    s[5] += 2;
    s[6] += 1;
    Polynomial<int> s1 = s % p;

    ASSERT_EQ(s1.Degree(), 7);
    EXPECT_EQ(s1[0], 0);
    EXPECT_EQ(s1[1], 0);
    EXPECT_EQ(s1[2], 0);
    EXPECT_EQ(s1[3], 3);
    EXPECT_EQ(s1[4], 1);
    EXPECT_EQ(s1[5], 2);
    EXPECT_EQ(s1[6], 1);
}

TEST(Polynomial, Sum) {
    Polynomial<int> p(4);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;

    int sum = p(3);
    EXPECT_EQ(sum, 58);
}
