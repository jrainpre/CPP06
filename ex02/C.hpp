#pragma once

#include "Base.hpp"

class C : public Base
{
public:
	C() {std::cout << "C created" << std::endl;}
	~C() {}
};
