

#include <iostream>
#include <string>
#include <cctype>





int main()
{
	while (1)
	{
	std::string input;
	std::cout << "Enter a value: ";
	std::cin >> input;
	std::cout << "Type: " << type_detetion(input) << std::endl;
	}
}