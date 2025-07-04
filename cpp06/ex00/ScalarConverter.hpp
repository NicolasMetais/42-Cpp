#pragma once
#include <iostream>

class ScalarConverter {
	public:
		static void convert(const std::string& val);
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

};