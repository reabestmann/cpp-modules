#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating warriors ===" << std::endl;
    ClapTrap clappy("Clappy");
    FragTrap fraggy("Fraggy");
    ScavTrap scavy("Scavy");

    std::cout << "\n=== FIGHT! FragTrap vs ClapTrap ===" << std::endl;
    fraggy.attack(clappy.getName());
    clappy.takeDamage(fraggy.getAttackDamage());
    
    clappy.attack(fraggy.getName());
    fraggy.takeDamage(clappy.getAttackDamage());
    
    std::cout << "\n=== ROUND 2! FragTrap vs ScavTrap ===" << std::endl;
    fraggy.attack(scavy.getName());
    scavy.takeDamage(fraggy.getAttackDamage());
    
    scavy.attack(fraggy.getName());
    fraggy.takeDamage(scavy.getAttackDamage());
    
    std::cout << "\n=== FragTrap needs a break ===" << std::endl;
    fraggy.beRepaired(10);
    fraggy.highFivesGuys();
    
    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}

/*
int main()
{
	std::cout << "=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Motivator");
	
	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	frag.attack("Enemy");
	frag.takeDamage(30);
	frag.beRepaired(10);
	frag.highFivesGuys();
	
	std::cout << "\n=== Testing death ===" << std::endl;
	frag.takeDamage(100);
	frag.attack("Enemy");  // Should fail


	std::cout << "\n=== Destruction (reverse order!) ===" << std::endl;
	return 0;
}*/