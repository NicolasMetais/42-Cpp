#include <ScalarConverter.hpp>

int	main(int arc, char **arv)
{
	if (arc == 2)
	{
		ScalarConverter::convert(arv[1]);
	}
	return (0);
}