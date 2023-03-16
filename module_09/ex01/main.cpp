#include "RPN.hpp"

int main(int ac, char *av[]) {
	try {
		if (ac != 2)
			throw std::runtime_error("Bad number of arguments");
		std::string input = av[1];
	
		RPN stack(av[1]);
		stack.execute();
		stack.print();
		return 0;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}