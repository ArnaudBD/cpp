#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat Machin( "Machin", 10 );
	try
	{
		std::cout << Machin.getGrade() << std::endl;

		Machin.setGrade( 5 );
		std::cout << Machin.getGrade() << std::endl;

		--Machin;
		std::cout << Machin.getGrade() << std::endl;

		for (int i = Machin.getGrade() ; i > 0 ; i--)
		{
			++Machin;
			std::cout << Machin.getGrade() << std::endl;
		}

	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << Machin << std::endl;

	return (0);
}