#pragma once

#include "Base.hpp"

class B : public Base
{
public:
	B() {std::cout << "B created" << std::endl;}
	~B() {}
};