#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	Bureaucrat Machin( "Machin", 5 );
	Bureaucrat truc;
	Form formulaire("Feuille d'inscription", 3, 2);
	Form papier;

	while (Machin.getGrade() != 1)
	{
		try
		{
			std::cout 	<< Machin << std::endl
						<< formulaire << std::endl;
			Machin.signForm( formulaire );
			std::cout << "______________________________________" << std::endl;
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

	// try
	// {
	// 	Form paperasse("Dossier inportant", 300, 1);
	// }
	// catch(const Form::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// 	std::cout << "______________________________________" << std::endl;
	// }


	std::cout << Machin << std::endl;

	return (0);
}