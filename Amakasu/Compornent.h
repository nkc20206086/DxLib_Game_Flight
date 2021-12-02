#pragma once
#include "CompornentType.h"
class Compornent
{
public:
	inline Compornent() { compornentname = CompornentType::Null; }
	CompornentType compornentname;
};