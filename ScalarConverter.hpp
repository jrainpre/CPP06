#pragma once

#include <string>
#include <cctype>
#include <iostream>

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

class ScalarConverter
{
private:
	std::string _input;
	int _int;
	float _float;
	double _double;
	char _char;
	int _type;
	void convert_from_char();
	void convert_from_int();
	void convert_from_float();
	void convert_from_double();
	void print_char();
	void print_int();
	void print_float();
	void print_double();
	int type_detection(std::string input);
public:
	ScalarConverter(std::string input);
	~ScalarConverter();
};

ScalarConverter::ScalarConverter(std::string input)
{
	_input = input;
	_type = type_detection(input);
	if (_type == ERROR || _type == NOTYPE)
	{
		std::cout << "Error: invalid input" << std::endl;
		return;
	}
	if (_type == CHAR)
		convert_from_char();
	else if (_type == INT)
		convert_from_int();
	else if (_type == FLOAT)
		convert_from_float();
	else if (_type == DOUBLE)
		convert_from_double();

}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert_from_char()
{
	_char = _input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void ScalarConverter::convert_from_int()
{
	_int = std::stoi(_input);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::convert_from_float()
{
	_float = std::stof(_input);
	_int = static_cast<int>(_float);
	_char = static_cast<char>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::convert_from_double()
{
	_double = std::stod(_input);
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_double);
	_float = static_cast<float>(_double);
}

void ScalarConverter::print_char()
{
	std::cout << "char: ";
	if (std::isprint(_char))
		std::cout << "'" << _char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::print_int()
{
	std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::print_float()
{
	if (_type == INT)
		std::cout << "float: " << _float << ".0f" << std::endl;
	else if (_type == FLOAT)
		std::cout << "float: " << _input << std::endl;
	else if (_type == DOUBLE)
		std::cout  << "float: " << _float << "f" << std::endl;
	else if (_type == CHAR)

}

void ScalarConverter::print_double()
{
	std::cout << "double: " << _double << std::endl;
}







int ScalarConverter::type_detection(std::string input)
{
	//check double pseudo literals
	if (input == "nan" || input == "-inf" || input == "+inf")
		return (PSEUDO_DOUBLE);
	if (input == "nanf" || input == "-inff" || input == "+inff")
		return (PSEUDO_FLOAT);
	//check char
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (CHAR);
	if (input.length() == 1 && !std::isdigit(input[0]))
		return(ERROR);
	//check valid floatin point or int
	int point = 0;
	int f = 0;
	if (std::isdigit(input[0]) || ((input[0] == '-' || input[0] == '+') && std::isdigit(input[1])))
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (i == 0 && (input[i] == '-' || input[i] == '+'))
				continue;
			else
			if (std::isdigit(input[i]))
				continue;
			else if (input[i] == '.')
			{
				point++;
				if (point > 1)
					return (ERROR);
			}
			else if (input[i] == 'f')
			{
				f++;
				if (f > 1 || (i != (input.length() - 1) ))
					return (ERROR);
			}
			else
				return (ERROR);
		}
		if (!point)
			return (INT);
		else if (f && point)
			return (FLOAT);
		else if (point)
		    return (DOUBLE);
	}
	return (ERROR);
}