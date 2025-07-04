#include <Span.hpp>

Span::Span() : tab(), n(0) {};

Span::Span(unsigned int n) : tab(), n(n) {};

Span::Span(const Span& other) : tab(other.tab) , n(other.n) {};

Span& Span::operator=(const Span& other) {
	if (this != &other)
	{
		tab = other.tab;
		n = other.n;
	}
	return *this;
};

Span::~Span() {};

void Span::addNumber(int newNum) {
	if (tab.size() >= n)
		throw std::runtime_error("the container is full");
	tab.push_back(newNum);
};

void Span::addNumbers(int randomNum) {
	int newNum;
	if (tab.size() >= n)
		throw std::runtime_error("container full");
	if (tab.size() + randomNum > n)
		throw std::runtime_error("not enough space");
	for (int i = 0; i < randomNum; i++)
	{
		newNum = rand() % 200;
		this->addNumber(newNum);
	}
};

int Span::shortestSpan() {
	if (tab.size() < 2)
		throw std::runtime_error("tab too small");
	int minSpan = std::numeric_limits<int>::max();
	std::vector<int>tmp = tab;
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); ++it)
	{
		int span = *(it + 1) - *it;
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
};

int Span::longestSpan() {
	if (tab.size() < 2)
		throw std::runtime_error("tab too small");
	std::vector<int>tmp = tab;
	std::sort(tmp.begin(), tmp.end());
	int maxSpan = tmp.back() - tmp.front();
	return maxSpan;
};