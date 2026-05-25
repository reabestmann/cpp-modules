#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	_type = cpy._type;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
        _type = other._type;
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Virtual Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "*woofwoofwoof*" << std::endl;
}
