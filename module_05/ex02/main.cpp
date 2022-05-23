#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	Bureaucrat Machin( "Machin", 5 );
	Bureaucrat truc;

	while (Machin.getGrade() != 1)
	{
		try
		{
		}

		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		++Machin;
	}

	std::cout << Machin << std::endl;

	return (0);
}