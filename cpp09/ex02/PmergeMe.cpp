#include <PmergeMe.hpp>

PmergeMe::PmergeMe() : vec(), deq() {};

PmergeMe::PmergeMe(const PmergeMe& other){
	vec = other.vec;
	deq = other.deq;
};

const PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return (*this);
};

PmergeMe::~PmergeMe() {};

void PmergeMe::printValues(std::vector<int>& tab) {
	std::vector<int>::iterator it = tab.begin();
	for (; it != tab.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
};

void PmergeMe::sort() {
	clock_t start_vec = clock();
	FordJohnson(vec);
	clock_t end_vec = clock();
	clock_t start_deq = clock();
	FordJohnson(deq);
	clock_t end_deq = clock();
	std::cout << "After : ";
	printValues(vec);
	double duration = 1000000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration << " us" << std::endl;
	duration = 1000000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << duration << " us" << std::endl;
}

void PmergeMe::insertValues(int num) {
	vec.push_back(num);
	deq.push_back(num);
};

void PmergeMe::parseValues(char **arv) {
	double	num;
	for (int i = 0; arv[i]; i++)
	{
		std::string arg(arv[i]);
		if (arg.empty())
            throw std::runtime_error("Error: empty");
		for (int j = 0; arg[j]; j++)
		{
			if (arg[0] == '+' || (arg[0] == '-' && arg.size() > 1))
				continue ;
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("Error : not a valid number '" + arg + "'");
		}
		if (arg[0] == '-')
			throw std::runtime_error("Error : i sort only positive numbers '" + arg + "'");
		num = std::atof(arv[i]);
		if (num > std::numeric_limits<int>::max())
			throw std::runtime_error("Error : overflow '" + arg + "'");
		insertValues(num);
	}
	std::cout << "Before : ";
	printValues(vec);
};


