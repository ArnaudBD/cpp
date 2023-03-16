#include "RPN.hpp"

RPN::RPN( std::string const & str ) : _input(str) {
	parse();
}

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN::~RPN() {}

RPN & RPN::operator=(RPN const & rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
	}
	return *this;
}

void RPN::parse() {
	for (size_t i = 0; i < _input.size(); i++) {
		if (isdigit(_input[i]))
			continue;
		else if (_input[i] == '+')
			continue;
		else if (_input[i] == '-')
			continue;
		else if (_input[i] == '*')
			continue;
		else if (_input[i] == '/')
			continue;
		else if (_input[i] == ' ')
			continue;
		else
			throw std::runtime_error("Invalid input");
	}
}

int RPN::countOperators( std::stack<int> stack ) const {
	int count = 0;
	while (!stack.empty()) {
		if (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')
			count++;
		stack.pop();
	}
	return count;
}

void RPN::add() {
	if (_stack.size() < 2)
		throw std::runtime_error("Cannot add on less than 2 numbers");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "end add" << std::endl;
}

void RPN::sub() {
	if (_stack.size() < 2)
		throw std::runtime_error("Cannot substract on less than 2 numbers");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a - b);
}

void RPN::mul() {
	if (_stack.size() < 2)
		throw std::runtime_error("Cannot multiply on less than 2 numbers");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::div() {
	if (_stack.size() < 2)
		throw std::runtime_error("Cannot divide on less than 2 numbers");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a / b);
}

void RPN::print() const {
	if (_stack.empty())
		throw std::runtime_error("Stack is empty");
	std::cout << _stack.top() << std::endl;
}

void RPN::pop() {
	if (_stack.empty())
		throw std::runtime_error("Stack is empty");
	_stack.pop();
}

void RPN::execute() {
	int i = 0;
	while (_input[i]) {
		if (isdigit(_input[i])) {
			_stack.push(_input[i] - '0');
			if (!_input[i + 1])
				throw std::runtime_error("Invalid input");
		} else if (_input[i] != ' ') {
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough numbers to perform operation");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			switch (_input[i]) {
			case '+' :
				_stack.push(a + b);
				break;
			case '-' :
				_stack.push(a - b);
				break;
			case '*'  :
				_stack.push(a * b);
				break;
			case '/' :
				if (b == 0)
					throw std::runtime_error("Cannot divide by 0");
				_stack.push(a / b);
				break;
			}
		}
		i++;
	}
}