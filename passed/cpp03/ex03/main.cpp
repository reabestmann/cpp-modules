#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamy("Diamy");

    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    diamy.attack("Enemy");
    diamy.takeDamage(40);
    diamy.beRepaired(20);
    diamy.guardGate();
    diamy.highFivesGuys();
    diamy.whoAmI();
    diamy.takeDamage(80);
    diamy.attack("Enemy");
    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
