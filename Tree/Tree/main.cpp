#include <string>
#include "tree.h"

int main(){

	Tree <int> BTree;
	BTree.Add(50);
	BTree.Add(200);
	BTree.Add(100);
	BTree.Print();
	BTree.Find(10);
	BTree.Find(100);
	system("pause");

	//Tree <double> BTree;
	//BTree.Add(3.5);
	//BTree.Add(2.1);
	//BTree.Add(9.9);
	//BTree.Print();
	//BTree.Find(2.1);
	//system("pause");

	//Tree <string> BTree;
	//BTree.Add("string1");
	//BTree.Add("string2");
	//BTree.Add("string");
	//BTree.Print();
	//BTree.Find("string1");
	//system("pause");

	return 0;
}

