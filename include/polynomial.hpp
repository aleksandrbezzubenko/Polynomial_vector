// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_POLYNOMIAL_HPP_
#define INCLUDE_POLYNOMIAL_HPP_

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
template <typename T>
class Polynomial
{
private:
    int count;
    std::vector<T> coef;
public:
    Polynomial()
    {
        count = 0u;
        coef = {};
    }
    explicit Polynomial(const int cnt)
    {
        count = cnt;
        std::vector<T> coef1(cnt);
        coef = coef1;
    }
    Polynomial(const Polynomial<T>& rhs)
    {
        count = rhs.count;
        coef = rhs.coef;
    }
    explicit Polynomial(const std::vector<T>& rhs)
    {
        count = rhs.size();
        coef = rhs;
    }
    Polynomial<T>& operator=(const Polynomial<T>& rhs)
    {
        count = rhs.count;
        coef = rhs.coef;
        return *this;
    }
    Polynomial<T>& operator+=(const Polynomial<T>& rhs)
    {
        if (count >= rhs.count) {
            Polynomial<T> tmp = *this;
            int a = count - rhs.count;
            for (int i = a, j = 0; i < count; ++i, ++j) {
                tmp[i] += rhs.coef[j];
            }
            *this = tmp;
            return *this;
        } else {
            Polynomial<T> tmp = rhs;
            int a = rhs.count - count;
            for (int i = a, j = 0; i < rhs.count; ++i, ++j) {
                tmp[i] += coef[j];
            }
            *this = tmp;
            return *this;
        }
    }
    Polynomial<T>& operator-=(const Polynomial<T>& rhs)
    {
        if (count >= rhs.count) {
            Polynomial<T> tmp = *this;
            int a = count - rhs.count;
            for (int i = a, j = 0; i < count; ++i, ++j) {
                tmp[i] -= rhs.coef[j];
            }
            *this = tmp;
            return *this;
        } else {
            Polynomial<T> tmp = rhs;
            int a = rhs.count - count;
            for (int i = a, j = 0; i < rhs.count; ++i, ++j) {
                tmp[i] -= coef[j];
            }
            *this = tmp;
            return *this;
        }
    }
    Polynomial<T>& operator*=(const Polynomial<T>& rhs)
    {
        Polynomial<T> tmp(count + rhs.count - 1);
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < rhs.count; j++) {
                tmp.coef[i + j] += coef[i] * rhs.coef[j];
            }
        }
        *this = tmp;
        return *this;
    }
    Polynomial<T>& operator*=(const T a)
    {
        for (int i = 0; i < count; ++i) {
            coef[i] *= a;
        }
        return *this;
    }
    Polynomial<T>& operator/=(const Polynomial<T>& rhs)
    {
        Polynomial<T> res(count - rhs.count + 1);
        for (int i = 0; i < res.count; i++) {
            res.coef[res.count - i - 1] = coef[count - i - 1] /
                rhs.coef[rhs.count - 1];
            for (int j = 0; j < rhs.count; j++) {
                coef[count - j - i - 1] -= rhs.coef[rhs.count - j - 1] *
                    res.coef[res.count - i - 1];
            }
        }
        *this = res;
        return *this;
    }
    Polynomial<T>& operator%=(const Polynomial<T>& rhs)
    {
        Polynomial<T> tmp = *this / rhs;
        tmp *= rhs;
        *this -= tmp;
        return *this;
    }
    int Degree()
    {
        return count;
    }
    T& operator[](int index)
    {
        return coef[index];
    }
    T operator[](int index) const
    {
        return coef[index];
    }
    T operator()(const T x) const
    {
        T sum = 0;
        for (int i = 0, j = count - 1; i < count; ++i, --j) {
            sum += coef[i] * pow(x, j);
        }
        return sum;
    }
    bool operator!=(const Polynomial<T>& rhs) const
    {
        return !(*this == rhs);
    }
    bool operator==(const Polynomial<T>& rhs) const
    {
        if (count != rhs.count) {
            return false;
        }
        for (int i = 0; i < count; ++i) {
            if (coef[i] != rhs.coef[i]) {
                return false;
            }
        }
        return true;
    }
};

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& p1, const Polynomial<T>& p2)
{
    Polynomial<T> tmp(p1);
    tmp += p2;
    return tmp;
}
template <typename T>
Polynomial<T> operator-(const Polynomial<T>& p1, const Polynomial<T>& p2)
{
    Polynomial<T> tmp(p1);
    tmp -= p2;
    return tmp;
}
template <typename T>
Polynomial<T> operator*(const Polynomial<T>& p1, const Polynomial<T>& p2)
{
    Polynomial<T> tmp(p1);
    tmp *= p2;
    return tmp;
}
template <typename T>
Polynomial<T> operator*(const Polynomial<T>& p1, const T a)
{
    Polynomial<T> tmp(p1);
    tmp *= a;
    return tmp;
}
template <typename T>
Polynomial<T> operator/(const Polynomial<T>& p1, const Polynomial<T>& p2)
{
    Polynomial<T> tmp(p1);
    tmp /= p2;
    return tmp;
}
template <typename T>
Polynomial<T> operator%(const Polynomial<T>& p1, const Polynomial<T>& p2)
{
    Polynomial<T> tmp(p1);
    tmp %= p2;
    return tmp;
}

#endif // INCLUDE_POLYNOMIAL_HPP_
