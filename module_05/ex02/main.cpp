#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm formulaire( "Jardin" );
	formulaire.beExecuted( "test" );
std::cout << "1111111111111111111111111111111111111111111111111111111" << std::endl;
	RobotomyRequestForm formulaire2( "Arnaud" );
	formulaire2.beExecuted( "Arnaud" );
std::cout << "2222222222222222222222222222222222222222222222222222222" << std::endl;


	Bureaucrat machin( "machin", 5 );
	Bureaucrat truc;

	while (machin.getGrade() != 1)
	{
		try
		{
			std::cout << machin << std::endl << formulaire << std::endl;
			if (machin.getGrade() == 2)
				machin.signForm( formulaire );
			formulaire.execute(machin);
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
		catch(const ShrubberyCreationForm::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const ShrubberyCreationForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const ShrubberyCreationForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		++machin;
	}

	std::cout << machin << std::endl;

	return (0);
}