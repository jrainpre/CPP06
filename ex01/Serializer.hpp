
#pragma once
#include <string>
#include "Data.hpp"
#include <iostream>
#include <stdint.h>





class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();

private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
};
