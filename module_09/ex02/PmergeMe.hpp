#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <deque>
#include <iterator>
#include <exception>
#include <ctime>
#include <typeinfo>
#include <cstring>
#include <iomanip>

template <class Container>
class PmergeMe {
private:
	Container _container;
	clock_t _start;
	clock_t _end;

	PmergeMe() {}
	PmergeMe(PmergeMe const & src) {
		*this = src;
		return;
	}

	PmergeMe & operator=(PmergeMe const & rhs) {
		if (this != &rhs) {
			_container = rhs._container;
		}
		return *this;
	}

public:
	typedef typename Container::iterator iterator;

	PmergeMe( int ac, char **av) {
		if (!parse(ac, av)) {
			throw std::runtime_error("Usage: ./PmergeMe [list of positive integers]");
		return;
		}
		fillContainer(ac, av);
		return;
	}

	~PmergeMe() {}

	bool parse(int ac, char **av) {
		for (int i = 1; i < ac; i++) {
			for (size_t j = 0; j < strlen(av[i]); j++) {
				std::string max = "2147483647";
				if (!isdigit(av[i][j]) 
					|| strlen(av[i]) > 10
					|| (strlen(av[i]) == 10 
						&& av[i][j] > max[j])) {
					return false;
				}
			}
		}
		return true;
	}

	void fillContainer(int ac, char **av) {
		for (int i = 1; i < ac; i++) {
			_container.push_back(atoi(av[i]));
		}
		return;
	}

	void printContainer() {
		for (iterator it = _container.begin(); it != _container.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		return;
	}

	void printTime() {
		std::string type = typeid(_container).name();
		if (strstr(type.c_str(), "vector")) {
			type = "vector";
		} else if (strstr(type.c_str(), "list")) {
			type = "list";
		} else if (strstr(type.c_str(), "deque")) {
			type = "deque";
		}
		float(time) = float(_end - _start) / (float(CLOCKS_PER_SEC) / 1000000.00);
		std::cout << "Time to process a range of " << _container.size() << " elements with std::" << type << " : " << time << " us" << std::endl;
	}

	Container getContainer() {
		return _container;
	}

	clock_t getStart() {
		return _start;
	}

	clock_t getEnd() {
		return _end;
	}

	void setStart() {
		_start = clock();
	}

	void setEnd() {
		_end = clock();
	}

	void setContainer(Container container) {
		_container = container;
	}

	Container mergeInsertSort( Container input ) { 
		if (input.size() <= 1) {
			return input;
		}
		iterator it = input.begin();
		std::advance (it, input.size() / 2);
		Container left(input.begin(), it);
		Container right( it, input.end());
		if (left.size() > 10) {
			left = mergeInsertSort(left);
		} else {
			left = insertSort(left);
		}
		if (right.size() > 10) {
			right = mergeInsertSort(right);
		} else {
			right = insertSort(right);
		}
		return merge(left, right);
	}

	Container merge(Container left, Container right) {
		Container result;
		while (left.size() > 0 || right.size() > 0) {
			if (left.size() > 0 && right.size() > 0) {
				if (left.front() <= right.front()) {
					result.push_back(left.front());
					left.erase(left.begin());
				} else {
					result.push_back(right.front());
					right.erase(right.begin());
				}
			} else if (left.size() > 0) {
				result.push_back(left.front());
				left.erase(left.begin());
			} else if (right.size() > 0) {
				result.push_back(right.front());
				right.erase(right.begin());
			}
		}
		return result;
	}

	Container insertSort(Container container) {
		for (iterator it = container.begin(); it != container.end(); it++) {
			iterator it2 = it;
			while (it2 != container.begin() && *it2 < *(--it2)) {
				std::swap(*++it2, *(--it2));
			}
		}
		return container;
	}
};

#endif