#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
private:
	std::multimap<std::string, double> _input;
	std::map<std::string, double> _data;

	BitcoinExchange();

public:
	BitcoinExchange(std::ifstream & );
	BitcoinExchange & operator=(const BitcoinExchange& other);
	BitcoinExchange(const BitcoinExchange& other);

	~BitcoinExchange();


	void printReport();

};

#endif