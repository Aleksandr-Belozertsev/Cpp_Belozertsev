#include "Rational.h"

int GreatestCommonDivisor(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int new_numerator, int new_denominator) {
	const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
	numerator = new_numerator / gcd;
	denominator = new_denominator / gcd;
	if (denominator < 0) {
		denominator = -denominator;
		numerator = -numerator;
	}
}

int Rational::Numerator() const {
	return numerator;
}

int Rational::Denominator() const {
	return denominator;
}

bool operator == (const Rational& lhs, const Rational& rhs) {
	return lhs.Numerator() == rhs.Numerator() &&
		lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
	return{
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational& operator += (Rational& lhs, const Rational& rhs) {
	lhs = lhs + rhs;
	return lhs;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	return{
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational& operator -= (Rational& lhs, const Rational& rhs) {
	lhs = lhs - rhs;
	return lhs;
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return{
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational& operator *= (Rational& lhs, const Rational& rhs) {
	lhs = lhs * rhs;
	return lhs;
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

Rational& operator /= (Rational& lhs, const Rational& rhs) {
	lhs = lhs / rhs;
	return lhs;
}

istream& operator >> (istream& is, Rational& r) {
	int n, d;
	char c;
	is >> n >> c >> d;
	if (is && c == '/') {
		r = Rational(n, d);
	}
	return is;
}

ostream& operator << (ostream& os, const Rational& r) {
	return os << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}