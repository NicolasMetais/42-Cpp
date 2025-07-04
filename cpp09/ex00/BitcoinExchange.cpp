#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() : filename("") {};

BitcoinExchange::BitcoinExchange(std::string filename) : filename(filename) {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
		filename = other.filename;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		filename = other.filename;
	return *this;
};

int	getMaxDay(int year, int month) {
	static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month < 1 || month > 12)
		return (-1);
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return (29);
	return days[month - 1];
};

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

bool	isDate(std::string date) {
	int year;
	int month;
	int day;
	int maxDay;

	if (date.length() < 10)
	{
		std::cerr << "Error: bad input " << date << std::endl;
			return (false);
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!std::isdigit(static_cast<unsigned char>(date[i])))
			{
				std::cerr << "Error: bad input " << date << std::endl;
				return (false);
			}
		}
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				std::cerr << "Error: bad input " << date << std::endl;
				return (false);
			}
		}
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1900 || year > 2025)
	{
		std::cerr << "Error: bad input " << date << std::endl;
		return (false);
	}
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: bad input " << date << std::endl;
		return (false);
	}
	maxDay = getMaxDay(year, month);
	if (day < 1 || day > maxDay)
	{
		std::cerr << "Error: bad input " << date << std::endl;
		return (false);
	}
	return (true);
};

bool	isvalidNum(std::string val) {
	double	num;
	bool	dot;
	int 	i;

	i = 0;
	dot = false;
	if (val.empty()) 
	{
			std::cerr << "Error: bad input " << val << std::endl;
			return (false);
	}
	if (val[0] == '-' && val.length() > 1)
		i++;
	for (; val[i]; i++)
	{
		if (val[i] == '.')
		{
			if (dot)
			{
				std::cerr << "Error: bad input " << val << std::endl;
				return (false);
			}
			dot = true;
		}
		else if (!std::isdigit(val[i]))
		{
			std::cerr << "Error: bad input " << val << std::endl;
			return (false);
		}
	}
	num = std::atof(val.c_str());
	if (num < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
			return (false);
	}
	if (num > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: too large a number." << std::endl;
			return (false);
	}
	return (true);
}

float toFloat(const std::string& str)
{
	std::istringstream iss(str);
	float val;
	iss >> val;
	return val;
}

void	BitcoinExchange::extractData()
{
	std::ifstream	file;
	std::string		line;

	file.open("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error \n Could not open : data.csv" << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if(line.empty() || !isDate(line.substr(0, 10)) || !isvalidNum(line.substr(11)))
			continue ;
		btc.insert(std::make_pair(line.substr(0, 10), toFloat(line.substr(11))));
	}
	file.close();

};

void BitcoinExchange::compare() {
	std::ifstream	file;
	std::string		line;

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error \n Could not open file : " << filename << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string value;
		float		convVal;
		std::istringstream iss(line);

		if (line.empty())
			continue ;
		if (!std::getline(iss, date, '|') || !std::getline(iss, value))
		{
			std::cerr << "Error: bad input " << line << std::endl;
			continue ;
		}
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);
		if(!isDate(date) || !isvalidNum(value))
			continue ;
		convVal = toFloat(value);
		std::map<std::string, float>::iterator it = btc.lower_bound(date);
		if (it == btc.end() | it->first != date) {
			if (it == btc.begin())
			{
				std::cerr << "Error \n No date available" << date << std::endl;
				continue ;
			}
			--it;
		}
		std::cout << date << " => " << convVal << " = " << convVal * it->second << std::endl;
	}
	file.close();
}