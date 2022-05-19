#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
std::cout << std::endl;
std::cout << "---------------------NEW-TESTS-FOR-EX02-------------------------" << std::endl;
std::cout << std::endl;

	FragTrap newFrag;
std::cout << std::endl;
std::cout << std::endl;
	FragTrap Fragy("Fragy");

	Fragy.highFiveGuys();


std::cout << std::endl;
std::cout << "---------------------OLD-TESTS-FOR-EX01-------------------------" << std::endl;
std::cout << std::endl;


	ScavTrap noArg;
std::cout << std::endl;
	ScavTrap Scavy("Scavy");
std::cout << std::endl;
	ClapTrap Clapy("Clapy");

	std::cout << "Scavy's name is " << Scavy.getName() << std::endl;

	Clapy.attack("Scavy");
	Scavy.takeDamage(Clapy.getAttackDamage());
	Scavy.attack("Clapy");
	Clapy.takeDamage(Scavy.getAttackDamage());
	Clapy.attack("Scavy");
	Scavy.takeDamage(Clapy.getAttackDamage());
	Scavy.attack("Clapy");
	Clapy.takeDamage(Scavy.getAttackDamage());
	Scavy.guardGate();

std::cout << std::endl;
std::cout << "---------------------OLD-TESTS-FROM-EX00------------------------" << std::endl;
std::cout << std::endl;

	ClapTrap player0;
	ClapTrap player1("player1");
	ClapTrap player2("player2");
std::cout << std::endl;
	player2.attack( "player1" );
	player1.takeDamage( player2.getAttackDamage() );
	player1.beRepaired( 91 );

std::cout << std::endl;
	
	player2.setAttackDamage( 100 );

std::cout << std::endl;
	
	player2.attack( "player1" );
	player1.takeDamage( player2.getAttackDamage() );
	player1.beRepaired( 91 );

std::cout << std::endl;
	
	player2.attack( "player1" );
	player1.takeDamage( player2.getAttackDamage() );
	player1.beRepaired( 91 );
std::cout << std::endl;
std::cout << "-------------------------DESTRUCTION---------------------------" << std::endl;
std::cout << std::endl;


}