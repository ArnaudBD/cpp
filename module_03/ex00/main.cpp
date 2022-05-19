#include "ClapTrap.hpp"

int main()
{
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
}