#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.attack("Enemy");  // Should fail (dead)
	clap.beRepaired(5);     // Should fail (dead)
	
	return 0;
}