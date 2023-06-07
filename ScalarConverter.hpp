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
	e_type _type;
	void convert_from_char();
	void convert_from_int();
	void convert_from_float();
	void convert_from_double();
public:
	ScalarConverter(/* args */);
	~ScalarConverter();
};

ScalarConverter::ScalarConverter(/* args */)
{
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
	std::cout << "float: " << _float << "f" << std::endl;
}