#include "Rational.h"
#include <string>

using namespace std;

int main()
{
	Rational a, b;

	string c;

	bool next = true;
	while (next)
	{
		cout << "Enter first rational: " << endl;
		cin >> a;
		cout << "Enter operation" << endl;
		cin >> c;
		cout << "Enter second rational: " << endl;
		cin >> b;
		switch (*c.rbegin())
		{
		case '=':
			switch (c[0])
			{
			case '+':
				cout << "Answer: " << (a += b) << endl << endl;
				break;

			case '-':
				cout << "Answer: " << (a -= b) << endl << endl;
				break;

			case '*':
				cout << "Answer: " << (a *= b) << endl << endl;
				break;

			case '/':
				cout << "Answer: " << (a /= b) << endl << endl;
				break;

			case '=':
				cout << "Answer: " << (a == b) << endl << endl;
				break;
			default:
				next = false;
			}
			break;
		default:
			switch (c[0])
			{
			case '+':
				cout << " Answer: " << (a + b) << endl << endl;
				break;

			case '-':
				cout << " Answer: " << (a - b) << endl << endl;
				break;

			case '*':
				cout << " Answer: " << (a * b) << endl << endl;
				break;

			case '/':
				cout << " Answer: " << (a / b) << endl << endl;
				break;

			default:
				next = false;
			}
			break;
		}

		cout << "Do you want one more operation? (yes / no)" << endl;
		cin >> c;
		if (c == "no")
			next = false;
	}

	system("pause");
	return 0;
}