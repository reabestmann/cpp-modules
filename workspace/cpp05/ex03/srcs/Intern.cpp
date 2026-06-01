#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (i)
			{
				case 0: return new ShrubberyCreationForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new PresidentialPardonForm(target);
			}
		}
	}

	std::cerr << "Error: Form " << name << " doesn't exist, Intern cries" << std::endl;
	
	return NULL;
}
