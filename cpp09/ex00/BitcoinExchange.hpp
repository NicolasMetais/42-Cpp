#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <utility>

class BitcoinExchange {
	private:
		std::string filename;
		std::map<std::string, float> btc;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void extractData();
		void compare();

};