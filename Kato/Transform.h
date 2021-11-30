#pragma once
#include "Quaternion.h"
#include "Vector.h"

class Transform
{
public:
	VECTOR Forward(QUATERNION q, VECTOR v)
	{
		VECTOR vector;
		vector = q * v;
		return vector;
	};

private:

};