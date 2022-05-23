#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Machin( "Machin", 10 );
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
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}