// #include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main()
{
	std::ifstream values("input.txt");
	std::ifstream amounts("BTC-USD.csv");

	std::multimap<std::string, double> amountsMap;

int i = 0;
	while (i < 20) //!amounts.eof())
	{
		i++;
		std::string date;
		double value;

		std::getline(values, date, '|');

		amountsMap.insert(std::pair<std::string, double>(date, value));
	}

	for (std::multimap<std::string, double>::reverse_iterator it = amountsMap.rbegin(); it != amountsMap.rend(); ++it)
	{
		std::cout << "date: " << it->first << " " << "amount: " << it->second << std::endl;
	}

}