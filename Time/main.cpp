#include <iostream>

#include "Time.h"
#include "BasicTime.h"

using namespace std;
using namespace DateTime;

int main()
{
	try {
		Time t1(01, 23, 03, 04, 2005, false);
		Time t2(02, 34, 04, 05, 2006, false);
		cout << t1 << endl;
		cout << t2 << endl;
		t1.Switch(false);
		t2.Switch(false);
		cout << t1 << endl;
		cout << t2 << endl;
		t1.Switch(true);
		t2.Switch(true);
		cout << t1 << endl;
		cout << t2 << endl;
		/*T + / -TI = T
		T - T = TI
		TI + / -TI = T*/

		//TimeInterval ti1(0, 0, 10, 1, 1);
		//TimeInterval ti2(0, 0, 1, 1, 2);
		//Time tt = t1 + ti1;
		//cout << tt << endl;
		//Time tt1 = t2 - ti1;
		//cout << tt1 << endl;
		//TimeInterval t = t2 - t1;
		//cout << t << endl;
		//TimeInterval tt2 = ti2 - ti1;
		//cout << tt2 << endl;
		//TimeInterval tt3 = ti2 + ti1;
		//cout << tt3 << endl;
	}
	catch (std::exception& e) { cout << e.what(); }
	system("pause");
}