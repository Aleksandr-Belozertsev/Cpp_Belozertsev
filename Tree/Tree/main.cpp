#include "tree.h"

int main(){
	Tree <int> BTree;
	BTree.Add(50);
	BTree.Add(200);
	BTree.Add(100);
	BTree.Print();
	BTree.Find(10);
	system("pause");
	return 0;
}

