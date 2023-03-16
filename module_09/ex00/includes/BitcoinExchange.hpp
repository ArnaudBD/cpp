#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>

class BitcoinExchange
{
private:
	std::multimap<std::string, double> _amounts;
	std::map<std::string, double> _values;

	BitcoinExchange();

public:
	BitcoinExchange(std::istream & values, std::istream & amounts);
	BitcoinExchange & operator=(const BitcoinExchange& other);
	BitcoinExchange(const BitcoinExchange& other);

	~BitcoinExchange();

	std::multimap<std::string, double> getAmounts(stre) const;
	std::map<std::string, double> getValues() const;

	void addAmount(std::string date, double amount);
	void addValue(std::string date, double value);
	void printReport(std::multimap<std::string, double> amounts, std::map<std::string, double> values);

};

#endif