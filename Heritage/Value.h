//#ifndef VALUE_H
//#define VALUE_H
//#include <iostream> 
//
//using namespace std;
//
//template<class T>
//class Value {
//protected:
//	T value;
//public:
//
//	Value()
//	{
//		this->value = value;
//	}
//
//	void print()
//	{
//		cout << this->value;
//	}
//
//	T Value() const {
//		return value;
//	}
//};
//
//template<class T>
//class Int : virtual public Value
//{
//protected:
//	int value;
//public:
//
//};
//
//using Int_2 = Value<int>;
//
//template<class T>
//class Double : virtual public Value
//{
//protected:
//	double value;
//public:
//
//};
//
//template<class T>
//class Complex : virtual public Value
//{
//protected:
//	double re, im;
//public:
//	Complex getComplex
//	ostream &operator<<(ostream &out, complex &c)
//	{
//		out << "(" << c.re << ") + i (" << c.im << ")\n";
//		return out;
//	}
//};
//
//#endif