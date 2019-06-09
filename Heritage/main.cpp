#include <iostream>

//#include <vector>
//#include <list>
//#include "../../Rational/Rational.h"

//#include "Heritage.h"
#include "Plist.h"

using namespace std;


int main()
{

	Int i1(1), i2(2), i3(3);
	Double d1(23.), d2(42.), d3(150.);
	PComplex c1(Complex(1., 0.)), c2(Complex(1., 1.)), c3(Complex(0., 1.));

	auto int1 = make_shared<Int>(i1);
	auto int2 = make_shared<Int>(i2);
	auto int3 = make_shared<Int>(i3);

	auto dbl1 = make_shared<Double>(d1);
	auto dbl2 = make_shared<Double>(d2);
	auto dbl3 = make_shared<Double>(d3);

	auto cpx1 = make_shared<PComplex>(c1);
	auto cpx2 = make_shared<PComplex>(c2);
	auto cpx3 = make_shared<PComplex>(c3);

	Plist list;

	list.push_back(dbl1); 
	list.push_back(int1); 
	list.push_front(cpx2); 
	list.print();

	cout << "is ";
	cpx1->print(); 
	cout << " here: " << list.has(cpx1) << endl; //true

	cout << "is ";
	dbl3->print(); 
	cout << " here: " << list.has(dbl3) << endl; //false

	cout << "is ";
	dbl2->print(); 
	cout << " here: " << list.has(dbl2) << endl; //false

	list.drop(dbl1); 
	list.print();
	list.clean();

	list.push_back(dbl2); 
	list.push_back(cpx1); 
	list.push_back(dbl2); 
	list.push_front(cpx3);
	list.push_back(dbl2); 
	list.print();
	list.add(cpx2, list.end()->prev_ptr); 
	list.print();

	cout << "is ";
	dbl1->print(); 
	cout << " here: " << list.has(dbl1) << endl;

	cout << "is ";
	dbl2->print(); 
	cout << " here: " << list.has(dbl2) << endl;

	list.clean();
	cout << "done" << endl;

	list.print();

	system("pause");
	return 0;
}
