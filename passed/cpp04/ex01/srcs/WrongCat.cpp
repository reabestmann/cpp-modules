#include "WrongCat.hpp"
#include "Brain.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	_brain = new Brain();
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	_brain = cpy._brain;
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
    {
		WrongAnimal::operator=(other);
		_brain = other._brain;
	}
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	delete _brain;
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "* wrongmiau *" << std::endl;
}

Brain*	WrongCat::getBrain() const
{
	return	_brain;
}