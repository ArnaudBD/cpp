#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::ifstream & input) {
	std::string date;
	double value;
	std::ifstream dataBase;

	fillDataBase(dataBase);
	fillInput(input);
}

void printReport() {
	for (std::multimap<std::string, double>::reverse_iterator it = this->_input.rbegin(); it != this->_input.rend(); ++it)
	{
		std::cout << "date: " << it->first << " " << "amount: " << it->second * this->_data[it->first] << std::endl;
}

void fillDataBase(std::ifstream & dataBase) {
	std::string date;
	double value;
	while (dataBase >> date >> value) {
		this->_data.insert(std::pair<std::string, double>(date, value));
	}
}

void fillInput(std::ifstream & input) {
	std::string date;
	double value;
	while (std::getline(input, date, ',') && std::getline(input, value)) {
		this->_input.insert(std::pair<std::string, double>(date, value));
	}
}