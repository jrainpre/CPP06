#include "ScalarConverter.hpp"


char	Parsing( const std::string & Number )
{
	char type = 0;
	if (Number == "nanf" || Number == "-inff" || Number == "+inff")
		return ('x');
	if (Number == "nan" || Number == "-inf" || Number == "+inf")
		return ('y');
	if (std::isdigit(Number[0]) ||
		((Number[0] == '-' && std::isdigit(Number[1])) ||
			(Number[0] == '+' && std::isdigit(Number[1]))))
	{
		int point = 0;
		for(size_t i = 0; i < Number.length(); i++)
		{
			if (std::isdigit(Number[i]) || Number[i] == 'f' ||
				(i == 0 && Number[0] == '-') || (i == 0 && Number[0] == '+'))
				continue;
			else if (Number[i] == '.')
			{
				if (point == 1)
					throw Casts::ArgsError();
				point = 1;
				if (Number.back() == 'f')
					type = 'f';
				else
					type = 'd';
			}
			else
				throw Casts::ArgsError();
		}
		if (type == 0)
			type = 'i';
	}
	else
	{
		if (Number.length() == 1)
			type = 'c';
		else
			type = 0;
	}
	return (type);
}

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
		reutrn(ERROR);
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
}