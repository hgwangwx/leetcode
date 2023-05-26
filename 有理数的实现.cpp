// 用c++实现一个有理数Rational类，实现基本的加减乘除比较以及输入输出操作

// 存在越界问题
#include <iostream>

class Rational {
private:
    int numerator;    //分子
    int denominator;  //分母

public:
    // 构造函数
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {}

    // 加法运算符重载
    Rational operator+(const Rational& other) const {
        int num = numerator*other.denominator + other.numerator*denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);   
    }

    // 减法运算符重载
    Rational operator-(const Rational& other) const {
        int num = numerator*other.denominator - other.numerator*denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);   
    } 

    // 乘法运算符重载
    Rational operator*(const Rational& other) const {
        int num = numerator*other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);   
    } 

    // 除法运算符重载
    Rational operator/(const Rational& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // 小于运算符重载
    bool operator<(const Rational& other) const {
        int lhs = numerator * other.denominator;
        int rhs = other.numerator * denominator;
        return lhs < rhs;
    }

    // 大于运算符重载
    bool operator>(const Rational& other) const {
        int lhs = numerator * other.denominator;
        int rhs = other.numerator * denominator;
        return lhs > rhs;
    }

    // 输入运算符重载
    friend std::istream& operator>>(std::istream& is, Rational& rational) {
        char slash;
        is >> rational.numerator >> slash >> rational.denominator;
        return is;
    }

    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << rational.numerator << '/' << rational.denominator;
        return os;
    }
};