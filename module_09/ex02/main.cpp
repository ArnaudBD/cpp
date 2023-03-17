#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cerr << "Usage: ./PmergeMe [integers]" << std::endl;
		return 0;
	}
	try {

		PmergeMe<std::list<int> > list(ac, av);
		std::cout << "Before: ";
		list.printContainer();
		list.setStart();
		list.setContainer(list.mergeInsertSort(list.getContainer()));
		list.setEnd();

		PmergeMe<std::vector<int> > vector(ac, av);
		vector.setStart();
		vector.setContainer(vector.mergeInsertSort(vector.getContainer()));
		vector.setEnd();

		PmergeMe<std::deque<int> > deque(ac, av);
		deque.setStart();
		deque.setContainer(deque.mergeInsertSort(deque.getContainer()));
		deque.setEnd();

		std::cout << "After: ";
		list.printContainer();

		list.printTime();
		vector.printTime();
		deque.printTime();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}	
}