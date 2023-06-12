#include "Serializer.hpp"
#include <iostream>



int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << ptr->s1 << std::endl;
	std::cout << ptr->n << std::endl;
	std ::cout << "raw: 0x" << std::hex << raw << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	return (0);
}
