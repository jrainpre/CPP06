#pragma once

#include <string>
#include <cctype>
#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
	static void convert_from_char(char *_char, int *_int, float *_float, double *_double, std::string input);
	static void convert_from_int(char *_char, int *_int, float *_float, double *_double, std::string input);
	static void convert_from_float(char *_char, int *_int, float *_float, double *_double, std::string input);
	static void convert_from_double(char *_char, int *_int, float *_float, double *_double, std::string input);
	static void print_char(char _char, int _int, int type);
	static void print_int(int _int, int type);
	static void print_float(float _float, std::string input, int _type);
	static void print_double(double _double, std::string input, int _type);
	static int type_detection(std::string input);
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
public:
	static void convert(const std::string& input);
	~ScalarConverter();
};
