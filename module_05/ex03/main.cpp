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

	Form* formulaire = guy.makeForm( "ShrubberyCreationForm", "Balcon");

try{
	AgentAdmin.executeForm( "ShrubberyCreationForm" );
}
catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
}
try{
	AgentAdmin.signForm( *formulaire );
	formulaire->execute( AgentAdmin );
}
catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
			std::cout << "______________________________________" << std::endl;
}
	delete formulaire;
	return (0);
}