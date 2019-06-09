#include <complex>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <type_traits>

#include "Types.h"

class Value{
public:
	virtual ~Value() {}

	virtual void print() const = 0;

	virtual TypeOfValue typeOfValue() const { return TypeOfValue::ABSTRACT; }
};

class Int : public Value {
protected:
	int m_value;

public:
	Int(int value_ = 0.) : m_value(value_) {}
	Int(const Int& rhs)
	{
		m_value = rhs.m_value;;
	}

	Int& operator=(const Int& rhs)
	{
		if (&rhs == this)
			return *this;
		m_value = rhs.m_value;
		return *this;
	}

	~Int() {}

	virtual TypeOfValue typeOfValue() const override { return TypeOfValue::INT; }

	inline int value() const { return m_value; }

	void print() const override
	{
		std::cout << m_value;
	}
};

class Double : public Value {
protected:

	double m_value;

public:

	Double(double value_ = 0.) : m_value(value_) {}

	Double(const Double& rhs)
	{
		m_value = rhs.m_value;
	}

	Double& operator=(const Double& rhs)
	{
		if (&rhs == this)
			return *this;
		m_value = rhs.m_value;
		return *this;
	}

	~Double() { }

	virtual TypeOfValue typeOfValue() const override { return TypeOfValue::DOUBLE; }

	inline double value() const { return m_value; }

	void print() const override
	{
		std::cout << m_value;
	}

	Double operator+(const Double& rhs) { return Double(m_value + rhs.m_value); }
	Double operator-(const Double& rhs) { return Double(m_value - rhs.m_value); }
	Double operator*(const Double& rhs) { return Double(m_value * rhs.m_value); }
	Double operator/(const Double& rhs)
	{
		if ((rhs.m_value < 2e-15) && (rhs.m_value > -2e-15))
			throw std::domain_error("Division by zero");
		return Double(m_value / (rhs.m_value));
	}

	//bool operator<(const Double& rhs) { return  m_value < rhs.m_value; }
	//bool operator>(const Double& rhs) { return  m_value > rhs.m_value; }
	//bool operator==(const Double& rhs) { return m_value == rhs.m_value; }

	template <typename T>
	Double operator+(const T rhs) { return Double((*this) + Double(rhs)); }
	template <typename T>
	Double operator-(const T rhs) { return Double((*this) - Double(rhs)); }
	template <typename T>
	Double operator*(const T rhs) { return Double((*this) * Double(rhs)); }
	template <typename T>
	Double operator/(const T rhs) { return Double((*this) / Double(rhs)); }
};

class PComplex : public Value{
protected:

	Complex m_value;

public:

	PComplex(Complex value_ = 0.) : m_value(value_) {}

	PComplex(const PComplex& rhs)
	{
		m_value = rhs.m_value;
	}

	PComplex& operator=(const PComplex& rhs)
	{
		if (&rhs == this)
			return *this;
		m_value = rhs.m_value;
		return *this;
	}

	~PComplex() {}

	virtual TypeOfValue typeOfValue() const override { return TypeOfValue::COMPLEX; }

	const Complex& value() const { return m_value; }

	void print() const override
	{
		std::cout << m_value;
	}
};

bool operator==(const Value& lhs, const Value& rhs);

bool operator!=(const Value& lhs, const Value& rhs);

template <typename T>
bool compareWithCast(Value* lhs, T rhs)
{
	bool ret;
	switch (lhs->typeOfValue())
	{
	case TypeOfValue::DOUBLE:
		ret = (rhs == dynamic_cast<Double*>(lhs)->value());
		break;
	case TypeOfValue::INT:
		ret = (rhs == static_cast<double>(dynamic_cast<Int*>(lhs)->value()));
		break;
	case TypeOfValue::COMPLEX:
		ret = (rhs == dynamic_cast<PComplex*>(lhs)->value());
		break;
	default:
		ret = false;
		break;
	}

	return ret;
}