#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

#include "tree.h"
#include <iostream>
using namespace std;

template <class T>
class Tree
{
private:
	class Item;

	Item* root;

	void Add(T& value, Item* ptr);

	Item* Find(Item * root_subtree, const T& val);

	void Print(Item* ptr);
	
	void Destroy(Item* ptr);

	//void pretty_Print(Item* ptr)
	//{
	//	
	//}

public:
	Tree() :root(nullptr);

	bool Find(const T& val);

	void Add(T value);

	void Print();

	~Tree();
};

#endif