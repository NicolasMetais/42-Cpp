#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Span {
	private:
		std::vector<int> tab;
		unsigned int n;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int newNum);
		void addNumbers(int randomNum);
		int shortestSpan();
		int longestSpan();
};