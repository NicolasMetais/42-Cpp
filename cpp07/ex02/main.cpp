#include <Array.hpp>

int main(void)
{
	Array<int> a(3);
	a[0] = 42;
	a[1] = 0;
	a[2] = 2234;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
}