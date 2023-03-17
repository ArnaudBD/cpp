#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

class BitcoinExchange
{
private:
	std::multimap<std::string, float> _input;
	std::map<std::string, float> _data;

	BitcoinExchange();
	BitcoinExchange & operator=( const BitcoinExchange& other );
	BitcoinExchange( const BitcoinExchange& other );

public:
	BitcoinExchange( std::ifstream & );

	~BitcoinExchange();


	void printReport();
	void printDataBase();
	void printInput();

	bool parseDate( std::string );
	bool parseValue( float );

	void fillDataBase( std::ifstream & );
	void fillInput( std::ifstream & );

	float calculateAmount( std::string, float );
};

#endif