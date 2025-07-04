#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib>

class RPN {
	private:
		std::stack<int> stack;
		std::string 	input;

	public:
		RPN();
		RPN(std::string numbers);
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);
		~RPN();
		bool isTokenValid(std::string token);
		void calculator();
};