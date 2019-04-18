#include "tree.cpp"

int main(){
	Tree <int> BTree;
	BTree.Add(50);
	BTree.Print();
	BTree.Find(50);
	system("pause");
	return 0;
}

