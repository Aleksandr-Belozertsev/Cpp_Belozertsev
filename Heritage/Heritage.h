#include <iostream>
#include <vector>

class Value{
public:
	void print() const;
	friend bool operator==(const Value left, const Value right);
};


class Int : Value {
public:
	Int(const int t) : value(t){};
	void print() const{
		std::cout << value << std::endl;
	}
	int value;
	friend bool operator==(const Int left, const Int right){
		return left.value == right.value;
	}
};

class Double : Value {
public:
	Double(const double t) : value(t){};
	void print() const{
		std::cout << value << std::endl;
	}
	double value;
	friend bool operator==(const Double left, const Double right){
		return left.value == right.value;
	}
};

class PList {
public:
	PList(){};
	std::vector<Value*> data;
	bool has(Value* entry) const {
		for (auto val : data){
			if (*val == *entry){
				std::cout << "True" << std::endl;
				return true;
			}
		}
		std::cout << "False" << std::endl;
		return false;
	}
	
	void print() const {
		for (auto val : data){
			std::cout << val << std::endl;
		}
	}

	void add(Value* entry){
		data.push_back(entry);
	}

	void drop(Value* entry){
		auto pos = data.begin();
		for (auto it = data.begin(); it < data.end(); it++){
			if (*(*it) == *entry){
				pos = it;
			}
		}
		data.erase(pos);
	}
};