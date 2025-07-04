#include <ScalarConverter.hpp>
#include <cctype>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {};

enum t_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

char parseChar(const std::string& str) {
	char result;
	result = str[0];
	return result;
}

t_type	detectType(const std::string& val)
{
	if (val == "+inf" || val == "-inf" || val == "nan")
		return DOUBLE;
	if (val == "+inff" || val == "-inff" || val == "nanf")
		return FLOAT;
	if (val.length() == 1 && !std::isdigit(val[0]))
		return CHAR;
	if (val.find(".") != std::string::npos && val[val.length() - 1] == 'f')
		return FLOAT;
	if (val.find(".") != std::string::npos)
		return DOUBLE;
	return INT;
}
void	convertData(const std::string val, t_type type, float *f, char *c, int *i, double *d, bool *i_possible, bool *c_possible, bool *f_possible, bool *d_possible)
{
	if (val == "nan" || val == "nanf")
    {
        *d = NAN;
        *f = NAN;
        *i_possible = false;
        *c_possible = false;
        *f_possible = true;
        *d_possible = true;
        return;
    }
    if (val == "+inf" || val == "+inff")
    {
        *d = INFINITY;
        *f = INFINITY;
        *i_possible = false;
        *c_possible = false;
        *f_possible = true;
        *d_possible = true;
        return;
    }
    if (val == "-inf" || val == "-inff")
    {
        *d = -INFINITY;
        *f = -INFINITY;
        *i_possible = false;
        *c_possible = false;
        *f_possible = true;
        *d_possible = true;
        return;
    }
	switch (type) {
		case INT:
		{
			long l = std::atof(val.c_str());
			if (l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
			{
				if (l >= 0 && l <= 127)
				{
					*c = static_cast<char>(l);
					*c_possible = true;
				}
				*i_possible = true;
				*i = l;
			}
			*f = static_cast<float>(l);
			*d = static_cast<double>(l);
			*d_possible = true;
			*f_possible = true;
			break ;
		}
		case CHAR:
		{
			*c = parseChar(val);
			*i = static_cast<int>(*c);
			*f = static_cast<float>(*c);
			*d = static_cast<double>(*c);
			*c_possible = true;
			*i_possible = true;
			*d_possible = true;
			*f_possible = true;
			break ;
		}
		case FLOAT:
		{
			*f = std::atof(val.c_str());
			*d = static_cast<double>(*f);
			*f_possible = true;
			*d_possible = true;
			if (*f >= static_cast<float>(std::numeric_limits<int>::min()) && *f <= static_cast<float>(std::numeric_limits<int>::max()))
			{
				*i = static_cast<int>(*f);
				*i_possible = true;
			}
			*c = static_cast<char>(*f);
			*c_possible = true;
			break ;
		}
		case DOUBLE:
		{
			*d = std::atof(val.c_str());
			*d_possible = true;
			*f = static_cast<float>(*d);
			if (*d >= -std::numeric_limits<float>::max() && *d <= std::numeric_limits<float>::max())
				*f_possible = true;
			if (*d >= static_cast<double>(std::numeric_limits<int>::min()) && *d <= static_cast<double>(std::numeric_limits<int>::max()))
			{	
				*i_possible = true;
				*i = static_cast<int>(*d);
			}
			if (*d >= std::numeric_limits<char>::min() && *d <= std::numeric_limits<char>::max())
			{
    			*c_possible = true;
				*c = static_cast<char>(*d);
			}
			break ;
		}
	}
}

int	precision(const std::string& val)
{
	size_t	point;
	size_t end;
	int	preci;

	point = val.find('.');
	if (point == std::string::npos)
		return (1);
	end = val.find_first_not_of("0123456789", point + 1);
	if (end == std::string::npos)
		end = val.length();
	preci = end - point - 1;
	if ((val[val.length() - 1]) == 'f' && end == val.length())
		preci -= 1;
	if (preci < 0)
		return (1);
	else
	return (preci);
}

void	printData(std::string val, float f, char c, int i, double d, bool i_possible, bool c_possible, bool f_possible, bool d_possible)
{
	int prec;

	prec = precision(val);
	std::cout << "char: ";
	if (!c_possible || ((f_possible && (f != static_cast<int>(f))) || (d_possible && d != static_cast<int>(d))))
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: ";
	if (!i_possible)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: ";
	if (!f_possible)
		std::cout << "Impossible" << std::endl;
	else
	{
		if (std::isnan(f))
			std::cout << "nanf" << std::endl;
		else if (std::isinf(f))
		{
			if (f < 0)
				std::cout << "-inff" << std::endl;
			else
				std::cout << "+inff" << std::endl;
		}
		else
			std::cout << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
	}
	std::cout << "double: ";
	if (!d_possible)
		std::cout << "Impossible" << std::endl;
	else
	{
		if (std::isnan(d))
			std::cout << "nan" << std::endl;
		else if (std::isinf(d))
		{
			if (d < 0)
				std::cout << "-inf" << std::endl;
			else
				std::cout << "+inf" << std::endl;
		}
		else
		std::cout << std::fixed << std::setprecision(prec) << d << std::endl;
	}
}

void ScalarConverter::convert(const std::string& val)
{
	float	f;
	char	c;
	int 	i;
	double	d;
	bool	i_possible;
	bool	c_possible;
	bool	f_possible;
	bool	d_possible;

	c_possible = false;
	i_possible = false;
	f_possible = false;
	d_possible = false;
	if (val.empty())
		return ;
	t_type	type = detectType(val);
	convertData(val, type, &f, &c, &i, &d, &i_possible, &c_possible, &f_possible, &d_possible);
	printData(val, f,c,i,d, i_possible, c_possible, f_possible, d_possible);
};
