#include <iter.hpp>

void print(std::string &str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	std::string array[] = { "test", "test1" };
	iter(array, 2, print);
}