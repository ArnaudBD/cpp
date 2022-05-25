#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	try {
		
		ShrubberyCreationForm formulaire( "Jardin2petunia" );
		std::cout << formulaire << std::endl;
		formulaire.beExecuted( "test" );
		std::cout << "1111111111111111111111111111111111111111111111111111111" << std::endl;
		RobotomyRequestForm formulaire2( "Arnaud" );
		std::cout << formulaire2 << std::endl;
		formulaire2.beExecuted( "Arnaud" );
		std::cout << "2222222222222222222222222222222222222222222222222222222" << std::endl;
		PresidentialPardonForm formulaire3( "Damien" );
		std::cout << formulaire3 << std::endl;
		formulaire3.beExecuted( "Damien" );
		std::cout << "3333333333333333333333333333333333333333333333333333333" << std::endl;
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
		catch(const RobotomyRequestForm::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const RobotomyRequestForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const RobotomyRequestForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const PresidentialPardonForm::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const PresidentialPardonForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const PresidentialPardonForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}


std::cout << "===========================================================================" << std::endl;

	Bureaucrat machin( "machin", 5 );
	Bureaucrat truc;
	PresidentialPardonForm formulaire( "petitPapier" );
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
		catch(const PresidentialPardonForm::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const PresidentialPardonForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		catch(const PresidentialPardonForm::NotSignedException& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		++machin;
	}

	std::cout << "*******************************************************************" << std::endl;
	std::cout << machin << std::endl;

	return (0);
}