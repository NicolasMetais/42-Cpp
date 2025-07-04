#include <Serialize.hpp>

int	main(void)
{
	Data test;

	test.i = 2;
	test.str = "test";
	std::cout << &test << std::endl;
	std::cout << test.str << " " << test.i << std::endl;

	uintptr_t ptr = Serialize::serialize(&test);
	Data *newData = Serialize::deserialize(ptr);

	std::cout << newData << std::endl;
	std::cout << newData->str << " " << newData->i << std::endl;

	if (&test == newData)
		std::cout << "serialization worked" << std::endl;
	else
		std::cout << "nope" << std::endl;
	return (0);
}