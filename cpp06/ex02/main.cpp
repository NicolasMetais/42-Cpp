#include <Base.hpp>
#include <ctime>
#include <cstdlib>



Base* createA() {
	return new A();
}

Base* createB() {
	return new B();
}

Base* createC() {
	return new C();
}

Base *generate(void)
{
	Base* (*generator[])() = {createA, createB, createC};

	int result = rand() % 3;
	return (generator[result]());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) )
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Nothing" << std::endl;
}


void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (...) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (...) {
				std::cout << "invalid" << std::endl;
			}
		}
	}
}

int	main(void)
{
    srand(time(NULL));
	Base *test = generate(); 
	Base *test1 = generate();

	Base *empty = NULL;

	identify(test);
	identify(test1);
	identify(*test);
	identify(*test1);

	identify(empty);

	delete test;
	delete test1;

	return (0);
}