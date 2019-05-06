#include "Heritage.h"

int main()
{
	PList list;
	list.add(*Int(1));
	list.has(Int(1));
	list.print();
	list.drop(Int(1));
	list.print();
	return 0;
}