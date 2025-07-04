#include <RPN.hpp>

RPN::RPN() : stack() , input("") {};

RPN::RPN(std::string numbers) : stack() , input(numbers) {};

RPN::RPN(const RPN& other) {
	stack = other.stack;
	input = other.input;
};

const RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
	{
		stack = other.stack;
		input = other.input;
	}
	return (*this);
};

RPN::~RPN() {};

bool RPN::isTokenValid(std::string token) {
	if (token == "*" || token == "/" || token == "+" || token == "-")
		return (true);
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token[i]))
		return (false);
	}
	int num;
	num = std::atoi(token.c_str());
	if (num < 0 || num > 9)
		return (false);
	return (true);
};



void	RPN::calculator() {
	std::istringstream 	iss(input);
	std::string			token;
	int					a;
	int					b;

	while (iss >> token)
	{
		if (!isTokenValid(token))
			throw std::runtime_error("Error: invalid token '" + token + "'");
		if(std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else 
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: not enough operands '" + token + "'");
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			switch (token[0]) {
				case '+' :
					stack.push(b + a);
					break ;
				case '/' :
					if (a == 0)
						throw std::runtime_error("Error: division by zero");
					stack.push(b / a);
					break ;
				case '*' :
					stack.push(b * a);
					break ;
				case '-' :
					stack.push(b - a);
					break ;
			}
		}
	}
	std::cout << stack.top() << std::endl;
};
