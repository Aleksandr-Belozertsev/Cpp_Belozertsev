#include "Heritage.h"

bool operator==(const Value& lhs, const Value& rhs)
{
	bool ret;
	switch (rhs.typeOfValue())
	{
	case TypeOfValue::DOUBLE:
		ret = compareWithCast(const_cast<Value*>(&lhs),
			dynamic_cast<Double*>(const_cast<Value*>(&rhs))->value());
		break;
	case TypeOfValue::INT:
		ret = compareWithCast(const_cast<Value*>(&lhs),
			static_cast<double>(dynamic_cast<Int*>(const_cast<Value*>(&rhs))->value()));
		break;
	case TypeOfValue::COMPLEX:
		ret = compareWithCast(const_cast<Value*>(&lhs),
			dynamic_cast<PComplex*>(const_cast<Value*>(&rhs))->value());
		break;
	default:
		ret = false;
		break;
	}
	return ret;
}


bool operator!=(const Value& lhs, const Value& rhs)
{
	return (!(lhs == rhs));
}