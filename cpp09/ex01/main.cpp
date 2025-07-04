#include <RPN.hpp>

int main(int arc, char **arv)
{
	if (arc == 2)
	{
		RPN Polish(arv[1]);
		try {
			Polish.calculator();
		}
		catch (std::runtime_error &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "./RPN \"1 2 +\"" << std::endl;
}