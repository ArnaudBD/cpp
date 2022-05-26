#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern guy;
	Bureaucrat AgentAdmin("Marie-Micheline", 2);

	Form* paperasse = guy.makeForm( "ShrubberyCreationForm", "Balcon");

try{
	AgentAdmin.executeForm( *paperasse );
}
catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
}
try{
	AgentAdmin.signForm( *paperasse );
	paperasse->execute( AgentAdmin );
}
catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
}
	delete paperasse;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> FROM EX02 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	try {
		Bureaucrat bidule("Bidule", 15 );
		std::cout << bidule << std::endl;
		ShrubberyCreationForm formulaire( "Jardin2petunia" );
		std::cout << formulaire << std::endl;
		// bidule.signForm( formulaire );
		bidule.executeForm( formulaire );
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}


std::cout << "===========================================================================" << std::endl;

	Bureaucrat machin( "machin", 5 );
	Bureaucrat truc ("Truc", 14 );
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

		catch(const std::exception& e)
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