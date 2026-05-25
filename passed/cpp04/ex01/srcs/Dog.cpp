#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	_brain = new Brain(*cpy._brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Virtual Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "*woofwoofwoof*" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return	_brain;
}