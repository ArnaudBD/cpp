#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class RPN {
public:
	RPN(std::string const & str);
	~RPN();

	void parse();
	int countOperators( std::stack<int> ) const;

	void execute();
	void add();
	void sub();
	void mul();
	void div();
	void print() const;
	void pop();
private:
	std::stack<int> _stack;
	std::string _input;

	RPN();
	RPN(RPN const & src);
	RPN & operator=(RPN const & rhs);
};

#endif