#include <iostream>

using namespace std;

template<class T>
T GreatestCommonDivisor(T a, T b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

template<class T>
class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(T new_numerator, T new_denominator) {
		const T gcd = GreatestCommonDivisor(new_numerator, new_denominator);
		numerator = new_numerator / gcd;
		denominator = new_denominator / gcd;
		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
		if (denominator == 0) {
			throw invalid_argument("Denominator = 0");
		}
	}

	T Numerator() const {
		return numerator;
	}

	T Denominator() const {
		return denominator;
	}

private:
	T numerator;
	T denominator;
};

template<class T>
bool operator == (const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.Numerator() == rhs.Numerator() &&
		lhs.Denominator() == rhs.Denominator();
}

template<class T>
Rational<T> operator + (const Rational<T>& lhs, const Rational<T>& rhs) {
	return{
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

template<class T>
Rational<T>& operator += (Rational<T>& lhs, const Rational<T>& rhs) {
	lhs = lhs + rhs;
	return lhs;
}

template<class T>
Rational<T> operator - (const Rational<T>& lhs, const Rational<T>& rhs) {
	return{
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

template<class T>
Rational<T>& operator -= (Rational<T>& lhs, const Rational<T>& rhs) {
	lhs = lhs - rhs;
	return lhs;
}

template<class T>
Rational<T> operator * (const Rational<T>& lhs, const Rational<T>& rhs) {
	return{
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

template<class T>
Rational<T>& operator *= (Rational<T>& lhs, const Rational<T>& rhs) {
	lhs = lhs * rhs;
	return lhs;
}

template<class T>
Rational<T> operator / (const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs * Rational<T>(rhs.Denominator(), rhs.Numerator());
}

template<class T>
Rational<T>& operator /= (Rational<T>& lhs, const Rational<T>& rhs) {
	lhs = lhs / rhs;
	return lhs;
}

template<class T>
istream& operator >> (istream& is, Rational<T>& r) {
	int n, d;
	char c;
	is >> n >> c >> d;
	if (is && c == '/') {
		r = Rational<T>(n, d);
	}
	return is;
}

template<class T>
ostream& operator << (ostream& os, const Rational<T>& r) {
	return os << r.Numerator() << '/' << r.Denominator();
}