#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parameterized Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING nOISES *" << std::endl;

	static int seed = 0;
	if (seed == 0)
		seed = time(NULL);
	srand(seed++); // sets seed for rand -> otherwise same starting point every time (NOT random)
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " robotomy failed!" << std::endl;
}
