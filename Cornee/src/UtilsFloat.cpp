#include "UtilsFloat.h"


UtilsFloat::UtilsFloat()
{
    //ctor
}

std::string UtilsFloat::float2string(float f){
	std::ostringstream os;
	os << f;
	return os.str();
}


UtilsFloat::~UtilsFloat()
{
    //ctor
}