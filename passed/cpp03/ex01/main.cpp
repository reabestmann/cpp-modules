#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Guardian");
	
	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
	
	std::cout << "\n=== Testing death ===" << std::endl;
	scav.takeDamage(100);
	scav.attack("Enemy");  // Should fail
	
	std::cout << "\n=== Destruction (reverse order!) ===" << std::endl;
	return 0;
}