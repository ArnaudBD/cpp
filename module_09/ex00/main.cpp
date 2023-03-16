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
	BitcoinExchange exchange(std::ifstream(av[1]));
	exchange.printReport();
}