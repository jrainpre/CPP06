

#include <iostream>
#include <string>
#include <cctype>


enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	ERROR,
	NOTYPE
};

int type_detetion(std::string input)
{
	int type = NOTYPE;
	//check double pseudo literals
	if (input == "nan" || input == "-inf" || input == "+inf")
		int type = PSEUDO_DOUBLE;
	if (input == "nanf" || input == "-inff" || input == "+inff")
		int type = PSEUDO_FLOAT;
	//check char
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (CHAR);
	if (input.length() == 1 && !std::isdigit(input[0]))
		return(ERROR);
	//check valid floatin point or int
	int point = 0;
	if (std::isdigit(input[0]) || ((input[0] == '-' || input[0] == '+') && std::isdigit(input[1])))
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (std::isdigit(input[i]))
				continue;
			else if (input[i] == '.')
			{
				point++;
				if (point > 1)
					return (ERROR);
			}
			if (input[i] == 'f')
			{
				if (type == NOTYPE)
					type = FLOAT;
				else if (type == DOUBLE)
					type = ERROR;
			}
			else if (point)
		    	type = DOUBLE;
			else if (!point)
				type = INT;
			else
				return (ERROR);
		}
	}
	return (type);
}

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