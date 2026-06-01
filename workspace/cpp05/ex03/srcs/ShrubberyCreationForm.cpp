#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Parameterized Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file!" << std::endl;
		return;
	}

	file << "       /\\      " << std::endl;
    file << "     //\\/\\     " << std::endl;
    file << "    //\\/\\/\\    " << std::endl;
    file << "   /\\/\\/\\/\\   " << std::endl;
    file << "  /\\/\\/\\/\\/\\  " << std::endl;
    file << "       ||      " << std::endl;
    file << "       ||      " << std::endl;
    file.close();
}