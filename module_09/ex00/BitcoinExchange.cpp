#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::ifstream & input) {
	std::string date;
	std::ifstream dataBase("data.csv", std::ifstream::in);

	fillDataBase(dataBase);
	fillInput(input);
	// std::multimap<std::string, float>::iterator it = _input.find("date");
	// _input.erase(it);
	// _data.erase("date");
}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::calculateAmount(std::string date, float amount) {
	std::map<std::string, float>::iterator it;
	it = _data.find(date);
	if (it == _data.end()) {
		it = _data.lower_bound(date);
		if (it == _data.begin()) 
			return 0.00;	
		it--;
	}
	return amount * it->second;
}

void BitcoinExchange::printReport() {
	for (std::multimap<std::string, float>::iterator it = _input.begin(); it != _input.end(); ++it)
	{
		if (parseDate(it->first) == true && parseValue(it->second) == true){
			std::cout 	<< it->first 
						<< " => " 
						<< it->second 
						<< " = " 
						<< this->calculateAmount(it->first, it->second) 
						<< std::endl;
		}
	}
}

void BitcoinExchange::printDataBase() {
	for (std::map<std::string, float>::iterator it = this->_data.begin(); it != _data.end(); ++it)
	{
		std::cout << "Date: " << it->first << " " << "Exchange Rate: " << it->second << std::endl;
	}
}

void BitcoinExchange::printInput() {
	for (std::multimap<std::string, float>::iterator it = this->_input.begin(); it != _input.end(); ++it)
	{
		std::cout << "Date: " << it->first << " " << "Amount: " << it->second << std::endl;
	}
}

void BitcoinExchange::fillDataBase(std::ifstream &dataBase) {
	std::string line;
	std::string date;
	std::string value;

	if (!dataBase.is_open()) {
		std::cerr << "Error: File not found" << std::endl;
		exit(1);
	}
	while (std::getline(dataBase, line)){
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value);
		if(value.empty() || std::strstr(date.c_str(), "date")) {
			continue;
		} else {
			this->_data.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
	}
}

void BitcoinExchange::fillInput(std::ifstream &input) {
	std::string line;
	std::string date;
	std::string value;

	if (!input.is_open()) {
		std::cerr << "Error: File not found" << std::endl;
		exit(1);
	}

	while (std::getline(input, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, value);
		if(value.empty() || std::strstr(date.c_str(), "date")) {
			continue;
		} else {
			this->_input.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
	}
}

bool BitcoinExchange::parseValue(float value) {
	if (value < 0) {
		std::cerr << "Invalid value: has to be a positive number. Current is " << value << std::endl;
		return false;
	} else if (value > 1000.00) {
		std::cerr << "Invalid value: has to be less than 1000. Current is " << value << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::parseDate(std::string date ) {
	std::string year;
	std::string month;
	std::string day;

	std::stringstream ss(date);
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day, ' ');
	if (date.find('\n') != std::string::npos){
		std::cerr << "Wrong format: "<< date << std::endl;
		return false;
	}
	if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
		std::cerr << "Invalid date format: " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1) {
		std::cerr << "Invalid month: " << date << std::endl;
		return false;
	} else if (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(year.c_str()) < 2009) {
		std::cerr << "Bitcoin did not exist at that time! " << date << std::endl;
		return false;
	} else if (atoi(year.c_str()) > 2023) {
		std::cerr << "Bitcoin does not exist in the future! " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) == 2 && atoi(day.c_str()) > 29) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) == 4 && atoi(day.c_str()) > 30) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) == 6 && atoi(day.c_str()) > 30) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) == 9 && atoi(day.c_str()) > 30) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(month.c_str()) == 11 && atoi(day.c_str()) > 30) {
		std::cerr << "Invalid day: " << date << std::endl;
		return false;
	} else if (atoi(year.c_str()) == 2009 && atoi(month.c_str()) == 1 && atoi(day.c_str()) < 3) {
		std::cerr << "Bitcoin did not exist at that time: " << date << std::endl;
		return false;
	}

	return true;
}
