#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main(int ac, const char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return 1;
	}
	try 
	{
	std::ifstream input(av[1]);
	BitcoinExchange exchange(input);
	exchange.printReport();
	// exchange.printInput();
	// exchange.printDataBase();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// exchange.printDataBase();
}