#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

int GreatestCommonDivisor(int a, int b);

class Rational {
public:
	Rational();
	Rational(int new_numerator, int new_denominator);
	int Numerator() const;
	int Denominator() const;

friend Rational& operator += (Rational& lhs, const Rational& rhs);
friend Rational& operator -= (Rational& lhs, const Rational& rhs);
friend Rational& operator *= (Rational& lhs, const Rational& rhs);
friend Rational& operator /= (Rational& lhs, const Rational& rhs);
	
private:
	int numerator;
	int denominator;
};

Rational operator + (const Rational& lhs, const Rational& rhs);
Rational operator - (const Rational& lhs, const Rational& rhs);
Rational operator * (const Rational& lhs, const Rational& rhs);
Rational operator / (const Rational& lhs, const Rational& rhs);

bool operator == (const Rational& lhs, const Rational& rhs);
bool operator < (const Rational& lhs, const Rational& rhs);

istream& operator >> (istream& is, Rational& r);
ostream& operator << (ostream& os, const Rational& r);

#endif