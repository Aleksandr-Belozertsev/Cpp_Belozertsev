#include <iostream>
using namespace std;

template <class T>
class Tree
{
private:
	class Item{
		friend Tree;
		Item* parent;
		Item* left;
		Item* right;
		T value;
		Item(T value, Item* parent, Item* left = nullptr, Item* right = nullptr) : value(value), parent(parent), left(left), right(right) {}
	};

	Item* root;

	void Add(T& value, Item* ptr)
	{
		if (ptr->value > value)
		{
			if (ptr->left)
			{
				Add(value, ptr);
			}
			else
			{
				ptr->left = new Item(value, ptr);
			}
		}
		else
		{
			if (ptr->right)
			{
				Add(value, ptr->right);
			}
			else
			{
				ptr->right = new Item(value, ptr);
			}
		}
	}

	Item* Find(Item * root_subtree, const T& val)
	{
		if (root_subtree == 0) return 0;
		Item * cur = root_subtree;

		if (!(val < cur->value) && !(cur->value < val)) return cur;
		if (val < cur->value) return Find(cur->left, val);
		else return Find(cur->right, val);
	}

	void Print(Item* ptr)
	{
		if (ptr->left)Print(ptr->left);
		cout << ptr->value << "; " << endl;
		if (ptr->right)Print(ptr->right);
	}

	void Destroy(Item* ptr)
	{
		if (ptr->left)Destroy(ptr->left);
		if (ptr->right)Destroy(ptr->right);
		delete ptr;
	}

public:
	Tree() :root(nullptr)
	{

	}

	bool Find(const T& val)
	{
		Item * temp = Find(root, val);
		if (temp != 0) {
			cout << "true" << endl;
			return true;
		}
		else {
			cout << "false" << endl;
			return false;
		}
	}

	void Add(T value)
	{
		if (root)
		{
			Add(value, root);
		}
		else
			root = new Item(value, nullptr);
	}

	void Print()
	{
		if (!root)
		{
			cout << "Tree is empty" << endl;
		}
		else
			Print(root);
	}

	~Tree(){
		if (root)Destroy(root);
	}
};