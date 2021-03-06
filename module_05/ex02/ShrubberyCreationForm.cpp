#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <ostream>
#include <fstream>
class Form;

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & copy ) : Form(copy)
{
	*this = copy;
	return ;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->_isSigned = rhs.getIsSigned();
	return *this;
}

void ShrubberyCreationForm::beSigned( Bureaucrat & bureaucrat )
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->_isSigned = true;
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}

void ShrubberyCreationForm::beExecuted( std::string target ) const
{
	std::string outfile = target + "_Shrubbery";
	std::ofstream ofs (outfile.c_str());
	if (!ofs.is_open())
	{
		std::cout << "Can't open " << outfile << std::endl;
		return ;
	}
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o" << std::endl;
	ofs << "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'" << std::endl;
	ofs << "   `&%/ ` /%&'    |.|        / '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "jgs // ._///_/__/  ,/_//__//.  /_//__/_" << std::endl;
	ofs.close();
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (_isSigned == 0)
		throw ShrubberyCreationForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw ShrubberyCreationForm::GradeTooLowException();
	this->beExecuted( _target );
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

// std::ostream & operator<<( std::ostream & o , Form const & rhs )
// {
// 	o	<< "\t- Name: " << rhs.getName() << std::endl
// 		<< "\t- Signed: " << (rhs.getIsSigned() ? "yes" : "no") << std::endl
// 		<< "\t- Grade to sign: " << rhs.getGradeToSign() << std::endl
// 		<< "\t- Grade to execute: " << rhs.getGradeToExec() << std::endl
// 		<< "\t- Target: " << rhs.getTarget() << std::endl;
// 	return (o);
// }