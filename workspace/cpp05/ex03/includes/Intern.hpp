#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <AForm.hpp>

class ShrubberyCreationForm;
class PresidentialPardonForm;
class RobotomyRequestForm;

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
};

#endif
