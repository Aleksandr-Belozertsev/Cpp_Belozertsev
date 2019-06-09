#pragma once

#include <memory>

class Value;
class Int;
class Double;
class PComplex;
struct Node;

using Complex = std::complex<double>;
using S_ptr = std::shared_ptr<Value>;
using Node_ptr = std::shared_ptr<Node>;

enum class TypeOfValue
{
	ABSTRACT,
	INT,
	DOUBLE,
	COMPLEX
};






