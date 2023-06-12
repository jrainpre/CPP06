#include "ScalarConverter.hpp"

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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert_from_char(char *_char, int *_int, float *_float, double *_double, std::string input)
{
	*_char = input[0];
	*_int = static_cast<int>(*_char);
	*_float = static_cast<float>(*_char);
	*_double = static_cast<double>(*_char);
}

void ScalarConverter::convert_from_int(char *_char, int *_int, float *_float, double *_double, std::string input)
{
	std::istringstream ss(input);
	ss >> *_int;
	*_char = static_cast<char>(*_int);
	*_float = static_cast<float>(*_int);
	*_double = static_cast<double>(*_int);
}

void ScalarConverter::convert_from_float(char *_char, int *_int, float *_float, double *_double, std::string input)
{
		
	std::istringstream ss(input);
	ss >> *_float;
	*_int = static_cast<int>(*_float);
	*_char = static_cast<char>(*_float);
	*_double = static_cast<double>(*_float);
}

void ScalarConverter::convert_from_double(char *_char, int *_int, float *_float, double *_double, std::string input)
{
	std::istringstream ss(input);
	ss >> *_double;
	*_int = static_cast<int>(*_double);
	*_char = static_cast<char>(*_double);
	*_float = static_cast<float>(*_double);
}

void ScalarConverter::print_char(char _char, int _int, int _type)
{
	if (_type == PSEUDO_DOUBLE)
		std::cout << "char: impossible" << std::endl;
	else if (_type == PSEUDO_FLOAT)
		std::cout << "char: impossible" << std::endl;
	{
		std::cout << "char: ";
		if (std::isprint(_char) && _int > 0)
			std::cout << "'" << _char << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void ScalarConverter::print_int(int _int, int _type)
{
	if (_type == PSEUDO_DOUBLE)
		std::cout << "char: impossible" << std::endl;
	else if (_type == PSEUDO_FLOAT)
		std::cout << "char: impossible" << std::endl;
	else
	std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::print_float(float _float, std::string input, int _type)
{
	if (_type == INT)
		std::cout << "float: " << _float << ".0f" << std::endl;
	else if (_type == CHAR)
		std::cout << "float: " << _float << ".0f" << std::endl;
	else if (_type == FLOAT)
		std::cout << "float: " << _float << "f" << std::endl;
	else if (_type == DOUBLE)
		std::cout << "float: " << _float << "f" << std::endl;
	else if (_type == PSEUDO_FLOAT)
		std::cout << "float: " << input << std::endl;
	else if (_type == PSEUDO_DOUBLE)
		std::cout << "float: " << input <<  'f' << std::endl;
}

void ScalarConverter::print_double(double _double, std::string input, int _type)
{
	if (_type == INT)
		std::cout << "double: " << _double << ".0" << std::endl;
	else if (_type == CHAR)
		std::cout << "double: " << _double << ".0" << std::endl;
	else if (_type == FLOAT)
		std::cout << "double: " << _double << std::endl;
	else if (_type == DOUBLE)
		std::cout << "double: " << _double << std::endl;
	else if (_type == PSEUDO_FLOAT)
		std::cout << "double: " << input.erase(input.length() -1) << std::endl;
	else if (_type == PSEUDO_DOUBLE)
		std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	int _type = 0;
	int _int = 0;
	float _float = 0.0f;
	double _double = 0.0;
	char _char = 0;

	_type = type_detection(input);
	switch (_type)
	{
	case CHAR:
		convert_from_char(&_char, &_int, &_float, &_double, input);
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case INT:
		convert_from_int(&_char, &_int, &_float, &_double, input);
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case FLOAT:
		convert_from_float(&_char, &_int, &_float, &_double, input);
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case DOUBLE:
		convert_from_double(&_char, &_int, &_float, &_double, input);
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case PSEUDO_FLOAT:
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case PSEUDO_DOUBLE:
		print_char(_char, _int, _type);
		print_int(_int, _type);
		print_float(_float, input, _type);
		print_double(_double, input, _type);
		break;
	case ERROR:
		std::cout << "Error: invalid input" << std::endl;
		break;
	}

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